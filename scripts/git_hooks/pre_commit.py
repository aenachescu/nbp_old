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

import subprocess
import sys

def get_changed_files():
    files = []

    proc = subprocess.Popen(
        ['git', 'diff', '--cached', '--name-only'],
        stdout=subprocess.PIPE
    )
    output = proc.communicate()[0]

    if proc.returncode != 0:
        print("git diff failed: " + str(proc.returncode))
        sys.exit(1)

    for line in output.split(b'\n'):
        files.append(line)

    return files

def generate_single_header():
    proc = subprocess.Popen(
        [
            'python',
            './scripts/generate_single_header/generate_single_header.py',
            'include/nbp.h',
            '-o',
            'single_header/nbp.h',
            '-rl',
            '-rig',
            '-ric'
        ],
        stdout=subprocess.PIPE
    )

    output = proc.communicate()[0]
    if proc.returncode != 0:
        print("failed to generate single header: " + str(proc.returncode))
        print(output)
        return False

    return True

def add_single_header():
    proc = subprocess.Popen(
        ['git', 'add', 'single_header/nbp.h'],
        stdout=subprocess.PIPE
    )
    output = proc.communicate()[0]

    if proc.returncode != 0:
        print("git add single header failed: " + str(proc.returncode))
        print(output)
        return False

    return True

def stash_unstaged_changes():
    proc = subprocess.Popen(
        ['git', 'stash', '--keep-index', '--include-untracked'],
        stdout=subprocess.PIPE
    )
    output = proc.communicate()[0]

    if proc.returncode != 0:
        print("git stash unstaged changes failed: " + str(proc.returncode))
        print(output)
        return False

    return True

def stash_pop():
    proc = subprocess.Popen(
        ['git', 'stash', 'pop'],
        stdout=subprocess.PIPE
    )
    output = proc.communicate()[0]

    if proc.returncode != 0:
        print("git stash pop failed: " + str(proc.returncode))
        print(output)
        return False

    return True

generateSingleHeader = False

files = get_changed_files()
for filepath in files:
    if filepath.startswith(b"include/"):
        generateSingleHeader = True
        break

if generateSingleHeader:
    print("generating single header...")
    if not stash_unstaged_changes():
        sys.exit(1)
    if not generate_single_header():
        stash_pop()
        sys.exit(1)
    if not add_single_header():
        stash_pop()
        sys.exit(1)
    if not stash_pop():
        sys.exit(1)
