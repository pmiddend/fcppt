//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/literal.hpp>
#include <fcppt/text.hpp>
#include <fcppt/time/exception.hpp>
#include <fcppt/time/std_time.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ctime>
#include <fcppt/config/external_end.hpp>


std::time_t
fcppt::time::std_time()
{
	std::time_t const ret(
		std::time(
			nullptr
		)
	);

	if(
		ret
		==
		fcppt::literal<
			std::time_t
		>(
			-1
		)
	)
		throw
			fcppt::time::exception{
				FCPPT_TEXT("std_time() failed!")
			};

	return
		ret;
}
