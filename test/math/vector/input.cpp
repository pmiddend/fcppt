//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/no_init.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/istringstream.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/input.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::vector input",
	"[math],[vector]"
)
{
	typedef
	fcppt::math::vector::static_<
		unsigned,
		2
	>
	ui2_vector;

	SECTION(
		"input success"
	)
	{
		fcppt::io::istringstream stream{
			FCPPT_TEXT("(42, 3)")
		};

		ui2_vector result(
			fcppt::no_init{}
		);

		REQUIRE(
			stream
				>> result
		);

		CHECK(
			result
			==
			ui2_vector{
				42u,
				3u
			}
		);
	}

	SECTION(
		"input failure"
	)
	{
		fcppt::io::istringstream stream{
			FCPPT_TEXT("(42, 3")
		};

		ui2_vector result(
			fcppt::no_init{}
		);

		CHECK_FALSE(
			stream
				>> result
		);
	}
}
