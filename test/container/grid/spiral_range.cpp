//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/grid/make_spiral_range.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/math/diff.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::grid spiral_range",
	"[container],[grid]"
)
{
	typedef
	int
	int_type;

	typedef
	fcppt::container::grid::pos<
		int_type,
		2
	>
	pos;

	typedef
	std::vector<
		pos
	>
	pos_vector;

	pos_vector positions{};

	positions.reserve(
		100
	);

	auto const manhattan_distance(
		[](
			pos const _p1,
			pos const _p2
		)
		{
			return
				fcppt::math::diff(
					_p1.x(),
					_p2.y()
				)
				+
				fcppt::math::diff(
					_p1.y(),
					_p2.y()
				);
		}
	);

	pos const start(
		5,
		5
	);

	for(
		int_type distance = 0;
		distance < 4;
		++distance
	)
	{
		pos_vector result{};

		for(
			auto const cur
			:
			fcppt::container::grid::make_spiral_range(
				pos(
					5,
					5
				),
				2
			)
		)
			result.push_back(
				cur
			);

		REQUIRE_FALSE(
			result.empty()
		);

		pos_vector::const_iterator it(
			result.begin()
		);

		CHECK(
			manhattan_distance(
				*it,
				start
			)
			==
			0
		);

		++it;

		for(
			int_type cur = 1;
			cur < distance;
			++cur
		)
		{
			int_type const count(
				cur * 4
			);

			for(
				int_type i = 0;
				i < count;
				++i
			)
				CHECK(
					manhattan_distance(
						*it++,
						start
					)
					==
					cur
				);
		}
	}
}
