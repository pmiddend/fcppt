//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/widen.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	codecvt_widen
)
{
FCPPT_PP_POP_WARNING

	// shouldn't need any multi byte characters
	char const *const input(
		"foobar"
	);

	// test this multiple times
	// because there was a corruption issue
	for(
		unsigned i = 0;
		i < 3;
		++i
	)
	{
		std::wstring const output(
			fcppt::widen(
				input
			)
		);

		BOOST_CHECK_EQUAL(
			output.size(),
			6u
		);
	}
}
