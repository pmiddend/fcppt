#!/bin/sh
function update_cmake_file()
{
	local cmakefile="$1"

	update_cmake \
		"${cmakefile}" \
		"${@:2}" \
		|| exit -1

	mv "${cmakefile}".new "${cmakefile}" || exit -1
}

update_cmake_file \
	src/CMakeLists.txt \
	FCPPT_CORE_FILES \
	-n \
	include/fcppt \
	-r \
	include/fcppt/algorithm \
	include/fcppt/alignment \
	include/fcppt/assert \
	include/fcppt/backtrace \
	include/fcppt/chrono \
	include/fcppt/config \
	include/fcppt/container \
	include/fcppt/detail \
	include/fcppt/endianness \
	include/fcppt/error \
	include/fcppt/function \
	include/fcppt/impl \
	include/fcppt/io \
	include/fcppt/log \
	include/fcppt/math \
	include/fcppt/mpl \
	include/fcppt/preprocessor \
	include/fcppt/random \
	include/fcppt/signal \
	include/fcppt/spirit_traits \
	include/fcppt/time \
	include/fcppt/tr1 \
	include/fcppt/type_traits \
	include/fcppt/variant \
	-n \
	src \
	-r \
	src/backtrace \
	src/config \
	src/endianness \
	src/error \
	src/include \
	src/io \
	src/log \
	src/signal \
	src/time \
	|| exit -1

update_cmake_file \
	src/filesystem/CMakeLists.txt \
	FCPPT_FILESYSTEM_FILES \
	include/fcppt/filesystem \
	src/filesystem \
	|| exit -1

update_cmake_file \
	src/thread/CMakeLists.txt \
	FCPPT_THREAD_FILES \
	include/fcppt/thread \
	src/thread \
	|| exit -1
