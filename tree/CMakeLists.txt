cmake_minimum_required(VERSION 3.16)

# =========================================================
# PROJECT
# =========================================================
project(binary C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# =========================================================
# OPTIONS (optional toggles)
# =========================================================
option(BUILD_TESTS "Build unit tests" ON)
option(ENABLE_WARNINGS "Enable strict warnings" ON)

# =========================================================
# OUTPUT DIRECTORIES (clean build)
# =========================================================
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# =========================================================
# INCLUDE DIRECTORIES (IDE VISIBILITY + COMPILER)
# =========================================================
set(PROJECT_INCLUDE_DIRS
        ${CMAKE_SOURCE_DIR}/includes
)

include_directories(${PROJECT_INCLUDE_DIRS})

# =========================================================
# SOURCES (MAIN PROJECT)
# =========================================================
set(SRC_FILES
        sources/main.c
        sources/source.c
)

# =========================================================
# HEADERS (IDE VISIBILITY ONLY)
# =========================================================
set(HEADER_FILES
        includes/include.h
        includes/test.h

        includes/sub_includes/include_define.h
        includes/sub_includes/include_include.h
        includes/sub_includes/include_prototype.h
        includes/sub_includes/include_typedef.h
)

# =========================================================
# EXECUTABLE
# =========================================================
add_executable(${PROJECT_NAME}
        ${SRC_FILES}
        ${HEADER_FILES}
)

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE_DIRS})

# =========================================================
# LIBRARY COMPILERS
# =========================================================

#add_custom_target(<target name> ALL
#        COMMAND make
#        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/<library name>
#)

#set(<library name upper> ${CMAKE_SOURCE_DIR}/lib/<library name>/lib<library name>.a)

#add_dependencies(${PROJECT_NAME} <target name>)

#target_link_libraries(${PROJECT_NAME} PRIVATE ${<library name upper>})

#target_link_libraries(${PROJECT_NAME} PRIVATE
#        ${CMAKE_SOURCE_DIR}/lib/<library name>/lib<library name>.a
#        <necessary flags>
#)

# =========================================================
# COMPILER WARNINGS (EPITECH STYLE)
# =========================================================
if (ENABLE_WARNINGS)
    if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(${PROJECT_NAME} PRIVATE
                -Wall
                -Wextra
                -Werror
                -Wuninitialized
        )
    endif()
endif()

# =========================================================
# DEBUG FLAGS
# =========================================================
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PRIVATE DEBUG=1)
    target_compile_options(${PROJECT_NAME} PRIVATE -g3)
endif()

# =========================================================
# TEST EXECUTABLE (optional separation)
# =========================================================
if (BUILD_TESTS)
    add_executable(${PROJECT_NAME}_tests
            tests/test_file.c
            tests/test_redirect.c
            ${SRC_FILES}
    )

    target_include_directories(${PROJECT_NAME}_tests PRIVATE ${PROJECT_INCLUDE_DIRS})

    if (ENABLE_WARNINGS)
        target_compile_options(${PROJECT_NAME}_tests PRIVATE
                -Wall -Wextra -Werror -Wshadow -Wpedantic
        )
    endif()
endif()

# =========================================================
# IDE HELP (CLion / compilation database)
# =========================================================
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# =========================================================
# END
# =========================================================