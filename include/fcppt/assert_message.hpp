//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSERT_MESSAGE_HPP_INCLUDED
#define FCPPT_ASSERT_MESSAGE_HPP_INCLUDED

#include <fcppt/preprocessor/stringize.hpp>
#include <fcppt/preprocessor/file.hpp>
#include <fcppt/preprocessor/function.hpp>
#include <fcppt/assertion_failed.hpp>

/// Runtime assert macro that throws an assertion_failed if the condition does not hold with an additional message
#define FCPPT_ASSERT_MESSAGE(\
	cond,\
	message\
)\
if(\
	!(cond)\
)\
	throw fcppt::assertion_failed(\
		FCPPT_PP_FILE,\
		__LINE__,\
		FCPPT_PP_FUNCTION,\
		FCPPT_PP_STRINGIZE(\
			cond\
		),\
		message\
	)

#endif
