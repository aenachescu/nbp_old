#!/usr/bin/env python

# https://github.com/aenachescu/nbp
#
# Licensed under the MIT License <http://opensource.org/licenses/MIT>.
# SPDX-License-Identifier: MIT
# Copyright (c) 2019-2020 Alin Enachescu <https://github.com/aenachescu>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

import argparse
import logging
import re
import os
import sys

outputFile = None
removeLicense = False
removeIncludeGuard = False
removeIncludeComments = False

includeRegex = re.compile(r'#include "(?P<file>[^"]+)"')
includeGuardRegex = re.compile(r'#ifndef (?P<name>.+)')

includedFiles = []

def remove_license(lines):
    if not lines[0].startswith('/*'):
        logging.error("Not found licence start")
        return False

    linesCopy = list(lines)
    for line in linesCopy:
        lines.pop(0)
        if line.find('*/') != -1:
            if lines[0] == '\n':
                lines.pop(0)
            return True

    logging.error("Not found license end")
    return False

def remove_include_guard(lines):
    includeGuardStart = None
    includeGuardEnd = None
    includeGuardName = None
    skipEndif = 0

    for i in range(len(lines)):
        if includeGuardStart == None:
            isIncludeGuard = includeGuardRegex.match(lines[i])
            if isIncludeGuard:
                includeGuardStart = i
                includeGuardName = isIncludeGuard.group('name')
        else:
            if lines[i].startswith('#if'):
                skipEndif += 1
            elif lines[i].startswith('#endif'):
                if skipEndif == 0:
                    includeGuardEnd = i
                    break
                else:
                    skipEndif -= 1

    if includeGuardStart == None:
        logging.error("Not found include guard")
        return False

    if includeGuardEnd == None:
        logging.error("Not found include guard end")
        return False

    defineGuard = "#define " + includeGuardName + "\n"
    if lines[includeGuardStart + 1] != defineGuard:
        logging.error("Unexpected guard; expected [%s], actual [%s]", defineGuard, lines[includeGuardStart + 1])
        return False

    lines.pop(includeGuardEnd)
    if lines[includeGuardEnd - 1] == "\n":
        lines.pop(includeGuardEnd - 1)

    lines.pop(includeGuardStart)
    lines.pop(includeGuardStart)
    if lines[includeGuardStart] == "\n":
        lines.pop(includeGuardStart)

    return True

def remove_include_comments(lines):
    lineNum = 0
    includeLines = []

    for line in lines:
        isInclude = includeRegex.match(line)
        if isInclude:
            includeLines.append(lineNum)

        lineNum += 1

    for num in reversed(includeLines):
        while num > 0:
            num -= 1
            if lines[num].startswith('//'):
                lines.pop(num)
            else:
                break

    return

def processing_file(filePath, topFile):
    global outputFile
    global removeLicense
    global removeIncludeGuard
    global removeIncludeComments

    if filePath in includedFiles:
        logging.info("File already included: %s", filePath)
        return True

    includedFiles.append(filePath)

    logging.info("Processing file %s", filePath)

    path = os.path.dirname(filePath)

    inputFile = open(filePath, 'rb')
    lines = inputFile.readlines()
    inputFile.close()

    if not topFile and removeLicense:
        if not remove_license(lines):
            return False

    if not topFile and removeIncludeGuard:
        if not remove_include_guard(lines):
            return False

    if removeIncludeComments:
        remove_include_comments(lines)

    bAfterInclude = False

    for line in lines:
        if bAfterInclude:
            if line == '\n':
                continue
            bAfterInclude = False

        isInclude = includeRegex.match(line)
        if isInclude:
            logging.debug("Found file include: %s", isInclude.group('file'))
            inputFilePath = os.path.abspath(os.path.join(path, isInclude.group('file')))
            if not processing_file(inputFilePath, False):
                return False
            outputFile.write('\n')
            bAfterInclude = True
            continue

        outputFile.write(line)

    return True

if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description=r"Generates single-header library from the given top-level file."
    )

    parser.add_argument(
        'file',
        help='top-level file'
    )
    parser.add_argument(
        '-o',
        '--output',
        help='the file where the single-header library will be generated',
        default='output.h'
    )
    parser.add_argument(
        '-v',
        '--verbose',
        help='verbose console output',
        action='store_true'
    )
    parser.add_argument(
        '-rl',
        '--remove-license',
        help='remove license from the beginning of the file, excluding input file',
        action='store_true'
    )
    parser.add_argument(
        '-rig',
        '--remove-include-guard',
        help='remove include guard from files, excluding input file',
        action='store_true'
    )
    parser.add_argument(
        '-ric',
        '--remove-include-comments',
        help='if there are comments above include directive then they will be removed',
        action='store_true'
    )

    args = parser.parse_args()
    if args.verbose:
        logging.basicConfig(level=logging.DEBUG)
    else:
        logging.basicConfig(level=logging.ERROR)

    if args.remove_license:
        removeLicense = True

    if args.remove_include_guard:
        removeIncludeGuard = True

    if args.remove_include_comments:
        removeIncludeComments = True

    inputFilePath = os.path.abspath(os.path.join(os.getcwd(), args.file))

    outputFile = open(args.output, 'w')

    bSuccess = processing_file(inputFilePath, True)

    outputFile.close()

    if not bSuccess:
        sys.exit(1)