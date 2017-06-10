//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/enum_input.hpp>
#include <fcppt/io/istream_fwd.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_input.hpp>
#include <fcppt/log/level_strings.hpp>


fcppt::io::istream &
fcppt::log::operator>>(
	fcppt::io::istream &_stream,
	fcppt::log::level &_level
)
{
	return
		fcppt::enum_input(
			_stream,
			_level
		);
}
