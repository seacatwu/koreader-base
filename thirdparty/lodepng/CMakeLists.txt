PROJECT(lodepng)
cmake_minimum_required(VERSION 2.8.3)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/../cmake_modules")
include("koreader_thirdparty_common")
include("koreader_thirdparty_git")

enable_language(C)

assert_var_defined(CC)
assert_var_defined(CFLAGS)
assert_var_defined(SONAME)
assert_var_defined(OUTPUT_PATH)

ep_get_source_dir(SOURCE_DIR)

if (APPLE)
    set(BUILD_CMD sh -c "${CC} -shared ${CFLAGS} lodepng.c -o ${OUTPUT_PATH}/${SONAME}")
else()
    set(BUILD_CMD sh -c "${CC} -shared ${CFLAGS} -Wl,-E -Wl,-soname=${SONAME} lodepng.c -o ${OUTPUT_PATH}/${SONAME}")
endif()

ko_write_gitclone_script(
    GIT_CLONE_SCRIPT_FILENAME
    https://github.com/lvandeve/lodepng.git
    db9cc960fc1fec9075fb455c617a2e0cdd7c6fb2
    ${SOURCE_DIR}
)

include(ExternalProject)
ExternalProject_Add(
    ${PROJECT_NAME}
    DOWNLOAD_COMMAND ${CMAKE_COMMAND} -P ${GIT_CLONE_SCRIPT_FILENAME}
    BUILD_IN_SOURCE 1
    PATCH_COMMAND ${CMAKE_COMMAND} -E copy lodepng.cpp lodepng.c
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ${BUILD_CMD}
    # skip install
    INSTALL_COMMAND ""
)
