//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_FORMAT_DEFAULT_LEVEL_HPP_INCLUDED
#define FCPPT_LOG_FORMAT_DEFAULT_LEVEL_HPP_INCLUDED

#include <fcppt/log/level_fwd.hpp>
#include <fcppt/log/detail/symbol.hpp>
#include <fcppt/log/format/function.hpp>


namespace fcppt
{
namespace log
{
namespace format
{

/**
\brief Creates a default formatter for a level stream.

\ingroup fcpptlog

Creates a default formatter for a level stream with the level of \a level.
This formatter prints the level's string in front as obtained by #fcppt::log::level_to_string. It also appends a newline at the end.
*/
FCPPT_LOG_DETAIL_SYMBOL
fcppt::log::format::function
default_level(
	fcppt::log::level level
);

}
}
}

#endif
