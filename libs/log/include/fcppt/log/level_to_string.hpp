//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_LEVEL_TO_STRING_HPP_INCLUDED
#define FCPPT_LOG_LEVEL_TO_STRING_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/log/level_fwd.hpp>
#include <fcppt/log/detail/symbol.hpp>


namespace fcppt
{
namespace log
{

/**
\brief Converts a log level to its string representation

\ingroup fcpptlog

Converts a log level given by \a level to its enumerator name as a string.
*/
FCPPT_LOG_DETAIL_SYMBOL
fcppt::string
level_to_string(
	fcppt::log::level
);

}
}

#endif
