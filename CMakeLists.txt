cmake_minimum_required(VERSION 3.25...3.28)

# Declare project details
project(
    MyCProject
    VERSION 1.0.0
    DESCRIPTION "Modern production-ready C application template"
    LANGUAGES C
)

# ------------------------------------------------------------------------------
# 1. Global Configuration & Safety Checks
# ------------------------------------------------------------------------------

# Prevent in-source builds (forces out-of-source builds in build/)
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(FATAL_ERROR "In-source builds are disabled. Create a separate build folder: 'mkdir build && cd build'")
endif()

# Default to Release mode if build type is unspecified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose build type: Debug Release RelWithDebInfo MinSizeRel" FORCE)
endif()

# Export compile_commands.json for clangd LSP indexing
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Enforce strict standard compliance (C17 standard, no proprietary extensions)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF) # Forces -std=c17 instead of -std=gnu17

# ------------------------------------------------------------------------------
# 2. Build Options (Configurable via command line)
# ------------------------------------------------------------------------------
option(ENABLE_CLANG_TIDY "Run clang-tidy static analysis during compilation" ON)
option(ENABLE_CLANG_FORMAT "Enable clang-format helper target" ON)
option(ENABLE_CPPCHECK   "Run cppcheck analysis during compilation" OFF)
option(WARNINGS_AS_ERRORS "Treat compiler warnings as errors (-Werror)" OFF)
option(ENABLE_SANITIZERS "Enable ASan & UBSan in Debug builds" ON)

# ------------------------------------------------------------------------------
# 3. Static Analysis Integration (clang-tidy / cppcheck)
# ------------------------------------------------------------------------------
if(ENABLE_CLANG_TIDY)
    find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
    if(CLANG_TIDY_EXE)
        message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
        # Tells CMake to run clang-tidy automatically on every C file compiled
        set(CMAKE_C_CLANG_TIDY "${CLANG_TIDY_EXE}")
    else()
        message(WARNING "ENABLE_CLANG_TIDY is ON, but clang-tidy executable was not found.")
    endif()
endif()

if(ENABLE_CPPCHECK)
    find_program(CPPCHECK_EXE NAMES "cppcheck")
    if(CPPCHECK_EXE)
        message(STATUS "cppcheck found: ${CPPCHECK_EXE}")
        set(CMAKE_C_CPPCHECK "${CPPCHECK_EXE};--enable=warning,style,performance;--inline-suppr;--quiet")
    else()
        message(WARNING "ENABLE_CPPCHECK is ON, but cppcheck executable was not found.")
    endif()
endif()

if(ENABLE_CLANG_FORMAT)
    find_program(CLANG_FORMAT_EXE NAMES "clang-format")
    if(CLANG_FORMAT_EXE)
        message(STATUS "clang-format found: ${CLANG_FORMAT_EXE}")

        file(GLOB_RECURSE PROJECT_C_SOURCES CONFIGURE_DEPENDS
            "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
            "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
        )

        add_custom_target(format
            COMMAND ${CLANG_FORMAT_EXE} -i ${PROJECT_C_SOURCES}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMENT "Formatting C sources with clang-format"
            VERBATIM
        )
    else()
        message(WARNING "ENABLE_CLANG_FORMAT is ON, but clang-format executable was not found.")
    endif()
endif()

# ------------------------------------------------------------------------------
# 4. Target Definition
# ------------------------------------------------------------------------------

# Collect all C source files under src/, including nested course/exercise folders.
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
)

add_executable(my_app ${PROJECT_SOURCES})

# Target-scoped include paths (Public/Private separation)
target_include_directories(my_app
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# ------------------------------------------------------------------------------
# 5. Compiler Warnings & Flags (GCC / Clang / MSVC)
# ------------------------------------------------------------------------------
set(GCC_CLANG_WARNINGS
    -Wall
    -Wextra
    -Wpedantic
    -Wshadow
    -Wconversion
    -Wdouble-promotion
    -Wnull-dereference
    -Wformat=2
    -Wimplicit-fallthrough
    -Wundef
)

set(MSVC_WARNINGS
    /W4
    /permissive-
)

if(WARNINGS_AS_ERRORS)
    list(APPEND GCC_CLANG_WARNINGS -Werror)
    list(APPEND MSVC_WARNINGS /WX)
endif()

if(MSVC)
    target_compile_options(my_app PRIVATE ${MSVC_WARNINGS})
else()
    target_compile_options(my_app PRIVATE ${GCC_CLANG_WARNINGS})
endif()

# ------------------------------------------------------------------------------
# 6. Runtime Sanitizers (Debug Mode Only)
# ------------------------------------------------------------------------------
if(ENABLE_SANITIZERS AND CMAKE_BUILD_TYPE STREQUAL "Debug" AND NOT MSVC)
    message(STATUS "Sanitizers enabled: AddressSanitizer (ASan) + UndefinedBehaviorSanitizer (UBSan)")
    target_compile_options(my_app PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(my_app PRIVATE -fsanitize=address,undefined)
endif()
