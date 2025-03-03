//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/reference_comparison.hpp>
#include <fcppt/reference_to_const.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"reference_to_const",
	"[ref]"
)
{
	int value{
		0
	};

	CHECK(
		fcppt::reference_to_const(
			fcppt::make_ref(
				value
			)
		)
		==
		fcppt::make_cref(
			value
		)
	);
}
