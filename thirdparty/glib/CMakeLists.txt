PROJECT(glib)
cmake_minimum_required(VERSION 2.8.3)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/../cmake_modules")
include("koreader_thirdparty_common")
include("koreader_thirdparty_git")

enable_language(C CXX)

assert_var_defined(CC)
assert_var_defined(CFLAGS)
assert_var_defined(LDFLAGS)
assert_var_defined(HOST_OPTS)
assert_var_defined(WITH_LIBICONV)
assert_var_defined(ENABLE_SHARED)
assert_var_defined(LIBFFI_DIR)
assert_var_defined(ZLIB_DIR)

ep_get_source_dir(SOURCE_DIR)
ep_get_binary_dir(BINARY_DIR)

# in order to support legacy PocketBook 4.x firmware we should get rid of
# eventfd@GLIBC_2.7 and pipe2@GLIB_2.9
set(gen_arm_config "glib_cv_stack_grows=no\\n")
set(gen_arm_config "${gen_arm_config}glib_cv_uscore=no\\n")
set(gen_arm_config "${gen_arm_config}glib_cv_eventfd=no\\n")
set(gen_arm_config "${gen_arm_config}ac_cv_func_pipe2=no\\n")
set(gen_arm_config "${gen_arm_config}ac_cv_func_posix_getpwuid_r=no\\n")
set(gen_arm_config "${gen_arm_config}ac_cv_func_posix_getgrgid_r=no\\n")
# disable getpwuid, getgrgid and timegm for > android-12
set(gen_arm_config "${gen_arm_config}ac_cv_func_getpwuid_r=no\\n")
set(gen_arm_config "${gen_arm_config}ac_cv_func_getgrgid_r=no\\n")
set(gen_arm_config "${gen_arm_config}ac_cv_func_timegm=no\\n")
set(gen_arm_config sh -c "printf \"${gen_arm_config}\" > arm_cache.conf")

set(CFG_ENV_VAR "CC=\"${CC} -std=gnu89\"")
set(CFG_ENV_VAR "${CFG_ENV_VAR} LIBFFI_CFLAGS=\"-I${LIBFFI_DIR}/include\"")
set(CFG_ENV_VAR "${CFG_ENV_VAR} LIBFFI_LIBS=\"-L${LIBFFI_DIR}/.libs -lffi\"")
set(CFG_ENV_VAR "${CFG_ENV_VAR} ZLIB_CFLAGS=\"-I${ZLIB_DIR}/include\"")
set(CFG_ENV_VAR "${CFG_ENV_VAR} ZLIB_LIBS=\"-L${ZLIB_DIR} -lz\"")
set(CFG_OPTS "--with-libiconv=\"${WITH_LIBICONV}\" --with-threads=posix --prefix=${BINARY_DIR} --without-included-gettext --with-gettext=no --enable-shared=${ENABLE_SHARED} --disable-libelf --with-pcre=internal --disable-selinux --disable-compile-warnings")
if(${ENABLE_SHARED} STREQUAL "false")
    set(CFG_OPTS "${CFG_OPTS} --enable-static=true")
else()
    set(CFG_OPTS "${CFG_OPTS} --disable-static")
endif()
set(CFG_OPTS "${CFG_OPTS} CFLAGS=\"${CFLAGS}\" LDFLAGS=\"${LDFLAGS} -Wl,-rpath-link,${ZLIB_DIR}/lib -Wl,-rpath-link,${LIBFFI_DIR}/.libs -Wl,-rpath-link,${BINARY_DIR}/gmodule/.libs\" ${HOST_OPTS}")
set(CFG_CMD sh -c "${CFG_ENV_VAR} ${SOURCE_DIR}/configure ${CFG_OPTS}")

ko_write_gitclone_script(
    GIT_CLONE_SCRIPT_FILENAME
    https://github.com/GNOME/glib.git
    2.48.0
    ${SOURCE_DIR}
)

include(ExternalProject)
ExternalProject_Add(
    ${PROJECT_NAME}
    DOWNLOAD_COMMAND ${CMAKE_COMMAND} -P ${GIT_CLONE_SCRIPT_FILENAME}
    PATCH_COMMAND NOCONFIGURE=1 ./autogen.sh
    CONFIGURE_COMMAND COMMAND ${gen_arm_config} COMMAND ${CFG_CMD}
    BUILD_COMMAND $(MAKE) -j${PARALLEL_JOBS}
    INSTALL_COMMAND $(MAKE) -j${PARALLEL_JOBS} install
)
