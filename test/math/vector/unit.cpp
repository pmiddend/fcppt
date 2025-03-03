//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/unit.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::vector::unit",
	"[math[,[vector]"
)
{
	typedef
	fcppt::math::vector::static_<
		int,
		3
	>
	int3_vector;

	CHECK(
		fcppt::math::vector::unit<
			int3_vector
		>(
			2
		)
		==
		int3_vector{
			0,
			0,
			1
		}
	);
}
