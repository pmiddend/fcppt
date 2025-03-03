//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/unit.hpp>
#include <fcppt/unit_comparison.hpp>
#include <fcppt/unit_output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"unit",
	"[various]"
)
{
	static_assert(
		sizeof(
			fcppt::unit
		)
		==
		1u,
		""
	);

	CHECK(
		fcppt::unit{}
		==
		fcppt::unit{}
	);

	CHECK_FALSE(
		fcppt::unit{}
		!=
		fcppt::unit{}
	);
}
