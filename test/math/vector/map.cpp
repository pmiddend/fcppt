//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/to_signed.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/map.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::vector::map",
	"[math],[vector]"
)
{
	typedef
	fcppt::math::vector::static_<
		int,
		2
	>
	i2_vector;

	typedef
	fcppt::math::vector::static_<
		unsigned,
		2
	>
	ui2_vector;

	CHECK(
		fcppt::math::vector::map(
			ui2_vector{
				10u,
				20u
			},
			[](
				unsigned const _val
			)
			{
				return
					fcppt::cast::to_signed(
						_val
					);
			}
		)
		==
		i2_vector(
			10,
			20
		)
	);
}
