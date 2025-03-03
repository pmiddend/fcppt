//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PREPROCESSOR_DISABLE_CLANG_WARNING_H_INCLUDED
#define FCPPT_PREPROCESSOR_DISABLE_CLANG_WARNING_H_INCLUDED

#include <fcppt/preprocessor/detail/disable_clang_warning.h>


/**
\brief Disables a given clang warning (does nothing on other compilers)

\ingroup fcpptpreprocessor

Disables the clang warning denoted by \a warning_name

\param warning_name The full command line option of the warning to disable

\see \ref preprocessor_warnings
*/
#define FCPPT_PP_DISABLE_CLANG_WARNING(\
	warning_name\
)\
FCPPT_PP_DETAIL_DISABLE_CLANG_WARNING(\
	warning_name\
)

#endif
