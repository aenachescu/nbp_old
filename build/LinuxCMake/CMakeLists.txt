cmake_minimum_required (VERSION 3.17)
project(NBP)

include("${CMAKE_SOURCE_DIR}/SamplesConfig.cmake")

option(CODE_COVERAGE "enable code coverage" OFF)
option(SAMPLE_SLEEP "enable sleep in every test from samples" OFF)

# Default compiler and linker flags
set(DEFAULT_FLAGS "-Wall -Wextra -Werror -Wconversion")
set(COMPILER_FLAG "-DNBP_COMPILER_GCC")
set(OS_FLAG "-DNBP_OS_LINUX")
set(SANITIZERS "")

if(SAMPLE_SLEEP MATCHES ON)
set(SAMPLE_FLAGS "")
else()
set(SAMPLE_FLAGS "-DSAMPLE_DISABLE_SLEEP")
endif()

unset(SAMPLE_FLAGS CACHE)

if(CODE_COVERAGE MATCHES ON)
set(GCOV_FLAGS "-fprofile-arcs -ftest-coverage")
set(GCOV_LINK_FLAGS "-lgcov --coverage")
else()
set(GCOV_FLAGS "")
set(GCOV_LINK_FLAGS "")
endif()

unset(CODE_COVERAGE CACHE)

CMAKE_DEPENDENT_OPTION

set(CFLAGS "${DEFAULT_FLAGS} ${GCOV_FLAGS} ${OS_FLAG} ${COMPILER_FLAG} ${SANITIZERS} ${SAMPLE_FLAGS}")
set(LFLAGS "${GCOV_LINK_FLAGS}")

message("${CFLAGS}")
message("${LFLAGS}")

# Creating targets
set(SAMPLES_SOURCE_DIR "${CMAKE_SOURCE_DIR}/../../samples")
set(SAMPLES_BIN_DIR "${CMAKE_BINARY_DIR}/../../bin")
set(NBP_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/../../include")

foreach(SAMPLE SAMPLE_CFLAGS SAMPLE_LFLAGS IN ZIP_LISTS SAMPLES SAMPLES_CFLAGS SAMPLES_LFLAGS)
    set(SAMPLE_TARGET_NAME "${SAMPLE}_sample")
    set(SAMPLE_BIN_DIR "${SAMPLES_BIN_DIR}/${SAMPLE_TARGET_NAME}")

    message(STATUS "Configuring ${SAMPLE} with \n---- CFLAGS: ${SAMPLE_CFLAGS} \n---- LFLAGS: ${SAMPLE_LFLAGS}")

    FILE(GLOB SAMPLE_SOURCES "${SAMPLES_SOURCE_DIR}/${SAMPLE}/*.c")

    add_executable(${SAMPLE_TARGET_NAME} ${SAMPLE_SOURCES})
    target_include_directories(${SAMPLE_TARGET_NAME} PUBLIC ${NBP_INCLUDE_DIR})

    set_target_properties( ${SAMPLE_TARGET_NAME}
        PROPERTIES
        COMPILE_FLAGS "${CFLAGS} ${SAMPLE_CFLAGS}"
        LINK_FLAGS "${LFLAGS} ${SAMPLE_LFLAGS}"
        ARCHIVE_OUTPUT_DIRECTORY ${SAMPLE_BIN_DIR}
        LIBRARY_OUTPUT_DIRECTORY ${SAMPLE_BIN_DIR}
        RUNTIME_OUTPUT_DIRECTORY ${SAMPLE_BIN_DIR}
    )
endforeach()
