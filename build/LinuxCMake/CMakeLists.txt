cmake_minimum_required (VERSION 3.17)
project(NBP)

include("${CMAKE_SOURCE_DIR}/SamplesConfig.cmake")

option(CODE_COVERAGE "enable code coverage" OFF)
option(SAMPLE_SLEEP "enable sleep in every test from samples" OFF)
option(ADDRESS_SANITIZER "enable address sanitizer" OFF)
option(THREAD_SANITIZER "enable thread sanitizer" OFF)
option(LEAK_SANITIZER "enable leak sanitizer" OFF)
option(UNDEFINED_BEHAVIOR_SANITIZER "enable UB sanitizer" OFF)

set(CMAKE_VERBOSE_MAKEFILE on)

# Default compiler and linker flags
set(DEFAULT_FLAGS "-Wall -Wextra -Werror -Wconversion")
set(DEBUG_FLAG "")
set(OPTIMIZATION_FLAG "-O2")
set(OS_FLAG "-DNBP_OS_LINUX")
set(SANITIZERS "")
set(GCOV_FLAGS "")
set(GCOV_LINK_FLAGS "")
set(SAMPLE_FLAGS "")

if(NOT DEFINED COMPILER)
set(CMAKE_C_COMPILER "gcc")
else()
set(CMAKE_C_COMPILER "${COMPILER}")
endif()
unset(COMPILER CACHE)

if(NOT DEFINED COMPILER_FLAG)
set(NBP_COMPILER_FLAG "-DNBP_COMPILER_GCC")
else()
set(NBP_COMPILER_FLAG "${COMPILER_FLAG}")
endif()
unset(COMPILER_FLAG CACHE)

if(SAMPLE_SLEEP MATCHES OFF)
set(SAMPLE_FLAGS "-DSAMPLE_DISABLE_SLEEP")
endif()
unset(SAMPLE_SLEEP CACHE)

if(CODE_COVERAGE MATCHES ON)
set(GCOV_FLAGS "-fprofile-arcs -ftest-coverage")
set(DEBUG_FLAG "-g")
set(OPTIMIZATION_FLAG "")
set(GCOV_LINK_FLAGS "-lgcov --coverage")
endif()
unset(CODE_COVERAGE CACHE)

if(ADDRESS_SANITIZER MATCHES ON)
set(SANITIZERS "-fsanitize=address,pointer-compare,pointer-subtract")
set(DEBUG_FLAG "-g")
set(OPTIMIZATION_FLAG "")
endif()
unset(ADDRESS_SANITIZER CACHE)

if(THREAD_SANITIZER MATCHES ON)
set(SANITIZERS "-fsanitize=thread")
set(DEBUG_FLAG "-g")
set(OPTIMIZATION_FLAG "")
endif()
unset(THREAD_SANITIZER CACHE)

if(LEAK_SANITIZER MATCHES ON)
set(SANITIZERS "-fsanitize=leak")
set(DEBUG_FLAG "-g")
set(OPTIMIZATION_FLAG "")
endif()
unset(LEAK_SANITIZER CACHE)

if(UNDEFINED_BEHAVIOR_SANITIZER MATCHES ON)
set(SANITIZERS "-fsanitize=undefined,shift,integer-divide-by-zero,unreachable,vla-bound,null,return,signed-integer-overflow,bounds,bounds-strict,alignment,object-size,float-divide-by-zero,float-cast-overflow,nonnull-attribute,returns-nonnull-attribute,bool,enum,vptr,pointer-overflow,builtin -fuse-ld=gold")
set(DEBUG_FLAG "-g")
set(OPTIMIZATION_FLAG "")
endif()
unset(UNDEFINED_BEHAVIOR_SANITIZER CACHE)

set(CFLAGS "${DEFAULT_FLAGS} ${DEBUG_FLAG} ${OPTIMIZATION_FLAG} ${GCOV_FLAGS} ${OS_FLAG} ${NBP_COMPILER_FLAG} ${SANITIZERS} ${SAMPLE_FLAGS}")
set(LFLAGS "${GCOV_LINK_FLAGS} ${SANITIZERS} -lpthread -pthread")

message("Compiler: ${CMAKE_C_COMPILER}")
message("CFLAGS: ${CFLAGS}")
message("LFLAGS: ${LFLAGS}")

# Creating targets
set(SAMPLES_SOURCE_DIR "${CMAKE_SOURCE_DIR}/../../samples")
set(SAMPLES_BIN_DIR "${CMAKE_BINARY_DIR}/../../bin")
set(NBP_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/../../include")

foreach(SAMPLE SAMPLE_CFLAGS SAMPLE_LFLAGS IN ZIP_LISTS SAMPLES SAMPLES_CFLAGS SAMPLES_LFLAGS)
    set(SAMPLE_TARGET_NAME "${SAMPLE}_sample")
    set(SAMPLE_BIN_DIR "${SAMPLES_BIN_DIR}/${SAMPLE_TARGET_NAME}")

    message(STATUS "Configuring ${SAMPLE} with\n"
        "---- SAMPLE_CFLAGS: ${SAMPLE_CFLAGS}\n"
        "---- SAMPLE_LFLAGS: ${SAMPLE_LFLAGS}"
    )

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
