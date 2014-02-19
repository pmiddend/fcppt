set(
	CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS
	ON
)

#Disallow in source builds everywhere
if(
	"${CMAKE_BINARY_DIR}"
	STREQUAL
	"${CMAKE_SOURCE_DIR}"
)
	message(
		FATAL_ERROR
		"In-source builds are not permitted. Make a separate folder for building:\nmkdir build; cd build; cmake ..\nBefore that, remove the files that cmake just created:\nrm -rf CMakeCache.txt CMakeFiles"
	)
endif()

include(
	CMakeDetermineCXXCompiler
)

include(
	CheckCXXCompilerFlag
)

if(
	FCPPT_WINE_TOOLCHAIN
)
	# TODO: Put this somewhere else! It doesn't work in toolchain files.
	set(
		CMAKE_SHARED_LIBRARY_SUFFIX
		".dll.so"
	)

	set(
		WIN32
		TRUE
	)
endif()

# Define locations for installations
# These don't have an FCPPT_ prefix because they have to be set by the user

set(
	INSTALL_BINARY_DIR
	"${CMAKE_INSTALL_PREFIX}/bin"
	CACHE
	STRING
	"Custom binary installation directory"
)

# Some distributions set CMAKE_INSTALL_LIBDIR to handle multilib. Also, some of
# them use an absolute path, some use a relative path. We have chosen an
# absolute path here, so please change it in the build if your distribution is
# using relative paths.
if(
	"${CMAKE_INSTALL_LIBDIR}"
	STREQUAL
	""
)
	set(
		FCPPT_UTILS_DEFAULT_INSTALL_LIB_DIR
		"${CMAKE_INSTALL_PREFIX}/lib"
	)
else()
	set(
		FCPPT_UTILS_DEFAULT_INSTALL_LIB_DIR
		"${CMAKE_INSTALL_LIBDIR}"
	)
endif()

set(
	INSTALL_LIBRARY_DIR
	"${FCPPT_UTILS_DEFAULT_INSTALL_LIB_DIR}"
	CACHE
	STRING
	"Custom library installation directory"
)

set(
	INSTALL_INCLUDE_DIR
	"${CMAKE_INSTALL_PREFIX}/include"
	CACHE
	STRING
	"Custom include installation directory"
)

set(
	INSTALL_DATA_DIR_BASE
	"${CMAKE_INSTALL_PREFIX}/share"
	CACHE
	STRING
	"Custom data installation directory without suffixes"
)

set(
	INSTALL_DATA_DIR
	"${INSTALL_DATA_DIR_BASE}/${PROJECT_NAME}"
	CACHE
	STRING
	"Custom data installation directory"
)

set(
	INSTALL_DOC_DIR_BASE
	"${INSTALL_DATA_DIR_BASE}/doc"
	CACHE
	STRING
	"Custom doc installation directory without suffixes"
)

set(
	INSTALL_DOC_DIR
	"${INSTALL_DOC_DIR_BASE}/${PROJECT_NAME}"
	CACHE
	STRING
	"Custom doc installation directory"
)

set(
	INSTALL_PKGCONFIG_DIR
	"${INSTALL_LIBRARY_DIR}/pkgconfig"
	CACHE
	STRING
	"Custom pkgconfig installation directory"
)

set(
	FCPPT_UTILS_CURRENT_DIRECTORY
	"${CMAKE_ROOT}"
)

set(
	FCPPT_UTILS_PROJECT_SOURCE_DIR
	"${${PROJECT_NAME}_SOURCE_DIR}"
)

set(
	FCPPT_UTILS_PROJECT_BINARY_DIR
	"${${PROJECT_NAME}_BINARY_DIR}"
)

set(
	FCPPT_UTILS_INSTALL_PREFIX_IS_PREFIX_OF_CMAKE_ROOT
	FALSE
)

set(
	FCPPT_UTILS_LOOP_VAR
	TRUE
)

while(
	FCPPT_UTILS_LOOP_VAR
)
	if(
		"${CMAKE_INSTALL_PREFIX}"
		STREQUAL "${FCPPT_UTILS_CURRENT_DIRECTORY}"
	)
		set(
			FCPPT_UTILS_INSTALL_PREFIX_IS_PREFIX_OF_CMAKE_ROOT
			TRUE
		)

		break()
	endif()

	get_filename_component(
		FCPPT_UTILS_NEW_CURRENT_DIRECTORY
		"${FCPPT_UTILS_CURRENT_DIRECTORY}"
		PATH
	)

	if(
		"${FCPPT_UTILS_NEW_CURRENT_DIRECTORY}"
		STREQUAL
		"${FCPPT_UTILS_CURRENT_DIRECTORY}"
	)
		break()
	endif()

	set(
		FCPPT_UTILS_CURRENT_DIRECTORY
		"${FCPPT_UTILS_NEW_CURRENT_DIRECTORY}"
	)
endwhile()

unset(
	FCPPT_UTILS_CURRENT_DIRECTORY
)

unset(
	FCPPT_UTILS_NEW_CURRENT_DIRECTORY
)

unset(
	FCPPT_UTILS_LOOP_VAR
)

if(
	FCPPT_UTILS_INSTALL_PREFIX_IS_PREFIX_OF_CMAKE_ROOT
)
	set(
		FCPPT_UTILS_CMAKE_MODULE_DIR
		"${CMAKE_ROOT}/Modules"
	)
else()
	set(
		FCPPT_UTILS_CMAKE_MODULE_DIR
		"${INSTALL_DATA_DIR_BASE}/cmake/Modules"
	)
endif()

set(
	INSTALL_CMAKEMODULES_DIR
	"${FCPPT_UTILS_CMAKE_MODULE_DIR}"
	CACHE
	STRING
	"Custom cmake module installation directory"
)

set(
	INSTALL_CMAKECONFIG_DIR_BASE
	"${INSTALL_LIBRARY_DIR}/cmake"
	CACHE
	STRING
	"Custom cmake config installation directory without suffixes"
)

set(
	INSTALL_CMAKECONFIG_DIR
	"${INSTALL_CMAKECONFIG_DIR_BASE}/${PROJECT_NAME}"
	CACHE
	STRING
	"Custom cmake module installation directory"
)

set(
	INSTALL_SYSCONFIG_DIR_BASE
	"${CMAKE_INSTALL_PREFIX}/etc"
	CACHE
	STRING
	"Custom config installation directory"
)

# cmake-2.8.3 is required for this to work
if(
	"${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang"
)
	set(
		FCPPT_UTILS_COMPILER_IS_CLANGPP ON
	)
endif()

if(
	"${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel"
)
	set(
		FCPPT_UTILS_COMPILER_IS_INTELCPP ON
	)
endif()

# Setup default compiler flags

if(
	CMAKE_COMPILER_IS_GNUCXX OR FCPPT_UTILS_COMPILER_IS_CLANGPP
)
	set(
		CMAKE_CXX_FLAGS_RELEASE
		"-O3 -fomit-frame-pointer -DNDEBUG"
	)

	# cmake tries to grep for warning messages which will fail in a lot of cases
	set(
		CMAKE_REQUIRED_FLAGS_BASE "-Wall -Werror -pedantic"
	)

	set(
		CMAKE_REQUIRED_FLAGS ${CMAKE_REQUIRED_FLAGS_BASE}
	)

	CHECK_CXX_COMPILER_FLAG(
		"-fvisibility=hidden"
		FCPPT_UTILS_HAVE_GCC_VISIBILITY
	)

	list(
		APPEND
		FCPPT_UTILS_COMPILE_OPTIONS
		"-std=c++11"
		"-pedantic-errors"
		"-Wall"
		"-Wextra"
		"-Wcast-align"
		"-Wcast-qual"
		"-Wconversion"
		"-Wconversion-null"
		"-Wdelete-non-virtual-dtor"
		"-Weffc++"
		"-Wfloat-equal"
		"-Winit-self"
		"-Wmissing-declarations"
		"-Wnon-virtual-dtor"
		"-Wold-style-cast"
		"-Woverloaded-virtual"
		"-Wredundant-decls"
		"-Wsign-promo"
		"-Wsign-conversion"
		"-Wshadow"
		"-Wstrict-aliasing=1"
		"-Wuninitialized"
		"-Wunused"
		"-Wunused-function"
		#currently, -Wundef cannot be disabled via a pragma
	)

	if(
		FCPPT_UTILS_COMPILER_IS_CLANGPP
	)
		list(
			APPEND
			FCPPT_UTILS_COMPILE_OPTIONS
			"-Wconditional-uninitialized"
			"-Wdocumentation"
			"-Wextra-semi"
			"-Wimplicit-fallthrough"
			"-Wundef"
			"-Wunneeded-member-function"
			"-Wunused-member-function"
		)
	else()
		list(
			APPEND
			FCPPT_UTILS_COMPILE_OPTIONS
			"-Wdouble-promotion"
			"-Wlogical-op"
			"-Wmaybe-uninitialized"
			"-Wunused-local-typedefs"
		)
	endif()

	if(
		FCPPT_UTILS_HAVE_GCC_VISIBILITY
	)
		option(
			FCPPT_ENABLE_VISIBILITY_HIDDEN
			"Enable -fvisbility=hidden"
			TRUE
		)
	endif()

	if(
		FCPPT_ENABLE_VISIBILITY_HIDDEN
	)
		list(
			APPEND
			FCPPT_UTILS_COMPILE_OPTIONS
			"-fvisibility=hidden"
		)
	endif()
elseif(
	MSVC
)
	list(
		APPEND
		FCPPT_UTILS_COMPILE_OPTIONS
		"/W4 /Wall /EHa /D_BIND_TO_CURRENT_VCLIBS_VERSION=1"
		"/wd4435 /wd4996 /wd4061 /wd4350 /wd4371 /wd4503 /wd4514 /wd4710 /wd4711 /wd4714 /wd4738 /wd4820"
	)

	# /W4 warnings
	#4996 - unsafe standard C++ functions

	# /Wall warnings
	#4061 - warning for not handled cases in switchs even with default
	#4350 - behaviour change due to implicit conversions (needed for unique_ptr)
	#4371 - layout of class may have changed from previous compiler version
	#4435 - layout change because of virtual base class
	#4503 - decorated name length exceeded
	#4514 - unreferenced inline function removed
	#4710 - function not inlined
	#4711 - function selected for automatic inline expansion
	#4714 - function marked as __forceinline not inlined
	#4738 - storing 32-bit float result in memory
	#4820 - byte padding after data members
endif()

# setup platform specific flags
if(
	UNIX
)
	# we need -fPIC for libraries on AMD64
	if("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "x86_64")
		list(
			APPEND
			FCPPT_UTILS_COMPILE_OPTIONS
			"-fPIC"
		)
	endif()

	# To check for linker flags, CMAKE_REQUIRED_FLAGS has to be expanded
	function(
		fcppt_check_gcc_linker_flag
		FLAG
		VARIABLE
	)
		set(
			CMAKE_REQUIRED_FLAGS
			"${CMAKE_REQUIRED_FLAGS_BASE} ${FLAG}"
		)

		CHECK_CXX_COMPILER_FLAG(
			""
			${VARIABLE}
		)
	endfunction()

	fcppt_check_gcc_linker_flag(
		"-Wl,--as-needed"
		FCPPT_UTILS_HAVE_AS_NEEDED_LINKER_FLAG
	)

	fcppt_check_gcc_linker_flag(
		"-Wl,--no-undefined"
		FCPPT_UTILS_HAVE_NO_UNDEFINED_LINKER_FLAG
	)

	fcppt_check_gcc_linker_flag(
		"-Wl,--no-copy-dt-needed-entries"
		FCPPT_UTILS_HAVE_NO_COPY_DT_NEEDED_ENTRIES_LINKER_FLAG
	)

	# TODO: Remove global setting of SHARED_LINKER_FLAGS
	if(FCPPT_UTILS_HAVE_AS_NEEDED_LINKER_FLAG)
		set(
			CMAKE_SHARED_LINKER_FLAGS
			"-Wl,--as-needed ${CMAKE_SHARED_LINKER_FLAGS}"
		)
	endif()

	if(FCPPT_UTILS_HAVE_NO_UNDEFINED_LINKER_FLAG)
		set(
			CMAKE_SHARED_LINKER_FLAGS
			"-Wl,--no-undefined ${CMAKE_SHARED_LINKER_FLAGS}"
		)
	endif()

	if(FCPPT_UTILS_HAVE_NO_COPY_DT_NEEDED_ENTRIES_LINKER_FLAG)
		set(
			CMAKE_SHARED_LINKER_FLAGS
			"-Wl,--no-copy-dt-needed-entries ${CMAKE_SHARED_LINKER_FLAGS}"
		)
		set(
			CMAKE_EXE_LINKER_FLAGS
			"-Wl,--no-copy-dt-needed-entries ${CMAKE_EXE_LINKER_FLAGS}"
		)
	endif()
endif()

# Ignore Boost's deprecated features
set(
	FCPPT_UTILS_COMPILE_DEFINITIONS
	"BOOST_FILESYSTEM_NO_DEPRECATED"
	"BOOST_SYSTEM_NO_DEPRECATED"
	"BOOST_THREAD_DONT_PROVIDE_DEPRECATED_FEATURES_SINCE_V3_0_0"
)

# configure standard CMake build paths
set(
	EXECUTABLE_OUTPUT_PATH
	${FCPPT_UTILS_PROJECT_BINARY_DIR}/bin
)

set(
	LIBRARY_OUTPUT_PATH
	${FCPPT_UTILS_PROJECT_BINARY_DIR}/lib
)

option(
	FCPPT_UTILS_BUILD_HEADERS
	"Build header files as well. This is useful for compile_commands.json. Don't use it to do an actual build."
	FALSE
)

function(
	fcppt_utils_add_headers
	ALL_FILES
)
	foreach(
		CUR_FILE
		${ALL_FILES}
	)
		get_filename_component(
			CUR_EXT
			"${CUR_FILE}"
			EXT
		)

		if(
			"${CUR_EXT}"
			STREQUAL
			".hpp"
		)
			set_source_files_properties(
				"${CUR_FILE}"
				PROPERTIES
				LANGUAGE
				"CXX"
			)
		endif()
	endforeach()

	unset(
		CUR_EXT
	)
endfunction()

macro(
	fcppt_utils_add_source_groups
	ALL_FILES
)
	foreach(
		CURFILE
		${ALL_FILES}
	)
		get_filename_component(
			REL_PATH
			"${CURFILE}"
			PATH
		)

		string(
			REPLACE
			"/"
			"\\"
			GROUPFOLDER
			${REL_PATH}
		)

		source_group(
			${GROUPFOLDER}
			FILES
			${CURFILE}
		)
	endforeach()

	if(
		FCPPT_UTILS_BUILD_HEADERS
	)
		fcppt_utils_add_headers(
			"${ALL_FILES}"
		)
	endif()
endmacro()

macro(
	fcppt_utils_append_source_dir
	FILES
	RESULT
)
	foreach(
		CUR_FILE
		${FILES}
	)
		set(
			WHOLE_FILE
			${FCPPT_UTILS_PROJECT_SOURCE_DIR}/${CUR_FILE}
		)

		set(
			${RESULT}
			${${RESULT}}
			${WHOLE_FILE}
		)
	endforeach()
endmacro()

macro(
	fcppt_utils_append_source_dir_and_make_groups
	FILES
	RESULT
)
	unset(
		TEMP_RESULT
	)

	foreach(
		CUR_FILE
		${FILES}
	)
		set(
			WHOLE_FILE
			${FCPPT_UTILS_PROJECT_SOURCE_DIR}/${CUR_FILE}
		)

		get_filename_component(
			REL_PATH
			${CUR_FILE}
			PATH
		)

		string(
			REPLACE
			"/"
			"\\"
			GROUPFOLDER
			${REL_PATH}
		)

		source_group(
			${GROUPFOLDER}
			FILES
			${WHOLE_FILE}
		)

		set(
			TEMP_RESULT
			${TEMP_RESULT}
			${WHOLE_FILE}
		)
	endforeach()

	set(
		${RESULT}
		"${${RESULT}};${TEMP_RESULT}"
	)

	if(
		FCPPT_UTILS_BUILD_HEADERS
	)
		fcppt_utils_add_headers(
			"${${RESULT}}"
		)
	endif()
endmacro()

set(
	FCPPT_UTILS_TARGETS_CONFIG
	"${PROJECT_NAME}Targets"
)

set(
	FCPPT_UTILS_BUILD_CONFIG_DIR
	"${FCPPT_UTILS_PROJECT_BINARY_DIR}/config"
)

set(
	FCPPT_UTILS_BUILD_CONFIG
	"${FCPPT_UTILS_BUILD_CONFIG_DIR}/${FCPPT_UTILS_TARGETS_CONFIG}.cmake"
)

function(
	fcppt_utils_prepare_config
)
	file(
		REMOVE
		"${FCPPT_UTILS_BUILD_CONFIG}"
	)

	file(
		WRITE
		"${FCPPT_UTILS_BUILD_CONFIG}"
		""
	)
endfunction()

macro(
	fcppt_utils_export_install_target
	TARGETNAME
)
	export(
		TARGETS
		${TARGETNAME}
		FILE
		"${FCPPT_UTILS_BUILD_CONFIG}"
		APPEND
	)

	install(
		TARGETS
		${TARGETNAME}
		DESTINATION
		"${INSTALL_LIBRARY_DIR}"
		EXPORT
		"${FCPPT_UTILS_TARGETS_CONFIG}"
	)
endmacro()

set(
	FCPPT_UTILS_SOURCE_INCLUDE_DIR
	${FCPPT_UTILS_PROJECT_SOURCE_DIR}/include
)

set(
	FCPPT_UTILS_BINARY_INCLUDE_DIR
	${FCPPT_UTILS_PROJECT_BINARY_DIR}/include
)

function(
	fcppt_utils_generate_config
)

	set(
		INCLUDE_DIR_VAR
		${PROJECT_NAME}_INCLUDE_DIR
	)

	set(
		CONFIG_NAME
		"${PROJECT_NAME}-config.cmake"
	)

	# Make build dir config
	set(
		${INCLUDE_DIR_VAR}
		"${FCPPT_UTILS_SOURCE_INCLUDE_DIR};${FCPPT_UTILS_BINARY_INCLUDE_DIR}"
	)

	set(
		CONFIG_IN_FILE
		"${FCPPT_UTILS_PROJECT_SOURCE_DIR}/${CONFIG_NAME}.in"
	)

	configure_file(
		${CONFIG_IN_FILE}
		"${FCPPT_UTILS_BUILD_CONFIG_DIR}/${CONFIG_NAME}"
		@ONLY
	)

	# Make installable config
	set(
		${INCLUDE_DIR_VAR}
		"${INSTALL_INCLUDE_DIR}"
	)

	set(
		CONFIG_DEST
		"${FCPPT_UTILS_BUILD_CONFIG_DIR}/install-config/${CONFIG_NAME}"
	)

	configure_file(
		${CONFIG_IN_FILE}
		"${CONFIG_DEST}"
		@ONLY
	)

	install(
		FILES
		"${CONFIG_DEST}"
		DESTINATION
		"${INSTALL_CMAKECONFIG_DIR}"
	)

	if(
		NOT FCPPT_UTILS_NO_TARGETS
	)
		install(
			EXPORT
			"${FCPPT_UTILS_TARGETS_CONFIG}"
			DESTINATION
			"${INSTALL_CMAKECONFIG_DIR}"
		)
	endif()
endfunction()

macro(
	fcppt_utils_handle_so_version
	CACHE_VAR
	OUT_VAR
	DEFAULT_VERSION
)
	set(
		"${CACHE_VAR}"
		""
		CACHE
		STRING
		"The custom .so version to use. If empty, the default will be used."
	)

	if(
		"${CACHE_VAR}"
		STREQUAL
		""
	)
		set(
			"${OUT_VAR}"
			"${DEFAULT_VERSION}"
		)
	else()
		set(
			"${OUT_VAR}"
			"${${CACHE_VAR}}"
		)
	endif()
endmacro()

function(
	fcppt_utils_set_so_version
	TARGET
	VERSION
)
	if(
		# TODO: How do we know we are building with wine?
		NOT FCPPT_WINE_TOOLCHAIN
	)
		set_target_properties(
			${TARGETN}
			PROPERTIES
			VERSION
			${VERSION}
		)
	endif()
endfunction()

function(
	fcppt_utils_add_dummy_target
	TARGET_NAME
	TARGET_FILES
)
	set(
		LIBNAME
		"${TARGET_NAME}_dummy"
	)

	add_library(
		"${LIBNAME}"
		STATIC
		${TARGET_FILES}
	)

	set_target_properties(
		"${LIBNAME}"
		PROPERTIES
		LINKER_LANGUAGE
		"CXX"
	)
endfunction()

function(
	fcppt_utils_set_target_compiler_flags
	TARGET_NAME
)
	target_compile_definitions(
		${TARGET_NAME}
		PRIVATE
		${FCPPT_UTILS_COMPILE_DEFINITIONS}
	)

	set_target_properties(
		${TARGET_NAME}
		PROPERTIES
		COMPILE_OPTIONS
		"${FCPPT_UTILS_COMPILE_OPTIONS}"
	)
endfunction()

function(
	fcppt_utils_add_target_include_dir
	TARGET_NAME
)
	target_include_directories(
		${TARGET_NAME}
		INTERFACE
		"$<INSTALL_INTERFACE:${INSTALL_INCLUDE_DIR}>"
		"$<BUILD_INTERFACE:${FCPPT_UTILS_SOURCE_INCLUDE_DIR}>"
		"$<BUILD_INTERFACE:${FCPPT_UTILS_BINARY_INCLUDE_DIR}>"
	)
endfunction()

function(
	fcppt_utils_interface_static_link
	TARGET_NAME
	VARIANT
	LINK_FLAG
)
	if(
		${VARIANT} STREQUAL "STATIC"
	)
		target_compile_definitions(
			${TARGET_NAME}
			INTERFACE
			${LINK_FLAG}
		)
	endif()
endfunction()
