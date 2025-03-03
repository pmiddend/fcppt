//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/text.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_to_string.hpp>
#include <fcppt/log/format/default_level.hpp>
#include <fcppt/log/format/function.hpp>
#include <fcppt/log/format/inserter.hpp>
#include <fcppt/log/format/prefix_string.hpp>
#include <fcppt/log/format/suffix_string.hpp>


fcppt::log::format::function
fcppt::log::format::default_level(
	fcppt::log::level const _level
)
{
	return
		fcppt::log::format::inserter(
			fcppt::log::format::prefix_string{
				fcppt::log::level_to_string(
					_level
				)
				+
				FCPPT_TEXT(": ")
			},
			fcppt::log::format::suffix_string{
				FCPPT_TEXT("\n")
			}
		);
}
