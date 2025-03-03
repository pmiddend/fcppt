//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/grid/make_pos_ref_crange.hpp>
#include <fcppt/container/grid/make_pos_ref_crange_start_end.hpp>
#include <fcppt/container/grid/make_pos_ref_range.hpp>
#include <fcppt/container/grid/make_pos_ref_range_start_end.hpp>
#include <fcppt/container/grid/min_from_pos.hpp>
#include <fcppt/container/grid/object.hpp>
#include <fcppt/container/grid/pos.hpp>
#include <fcppt/container/grid/sup_from_pos.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/null.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::grid: pos refrange",
	"[container],[grid]"
)
{
	typedef
	fcppt::container::grid::pos<
		std::size_t,
		2
	>
	element_type;

	typedef
	fcppt::container::grid::object<
		element_type,
		2
	>
	dim2_grid;

	typedef
	fcppt::container::grid::min_from_pos<
		dim2_grid::pos
	>
	min;

	typedef
	fcppt::container::grid::sup_from_pos<
		dim2_grid::pos
	>
	sup;

	typedef
	dim2_grid::pos
	pos;

	dim2_grid grid(
		dim2_grid::dim(
			4u,
			6u
		),
		fcppt::math::vector::null<
			pos
		>()
	);

	for(
		auto const element
		:
		fcppt::container::grid::make_pos_ref_range(
			grid
		)
	)
		element.value()
		=
		element.pos();

	for(
		auto const element
		:
		fcppt::container::grid::make_pos_ref_crange(
			grid
		)
	)
		CHECK(
			element.value()
			==
			element.pos()
		);

	grid =
		dim2_grid(
			dim2_grid::dim(
				4u,
				6U
			),
			fcppt::math::vector::null<
				element_type
			>()
		);

	for(
		auto const element
		:
		fcppt::container::grid::make_pos_ref_range_start_end(
			grid,
			min{
				pos(
					1u,
					1U
				)
			},
			sup{
				pos(
					3u,
					3u
				)
			}
		)
	)
		element.value()
		=
		element.pos();

	for(
		auto const element
		:
		fcppt::container::grid::make_pos_ref_crange_start_end(
			grid,
			min{
				pos(
					1u,
					1u
				)
			},
			sup{
				pos(
					3u,
					3u
				)
			}
		)
	)
		CHECK(
			element.value()
			==
			element.pos()
		);


	bool loop_empty(
		true
	);

	for(
		auto const element
		:
		fcppt::container::grid::make_pos_ref_range_start_end(
			grid,
			min{
				fcppt::math::vector::null<
					pos
				>()
			},
			sup{
				fcppt::math::vector::null<
					pos
				>()
			}
		)
	)
		loop_empty =
			false;

	CHECK(
		loop_empty
	);

	for(
		auto const element
		:
		fcppt::container::grid::make_pos_ref_range_start_end(
			grid,
			min{
				fcppt::math::vector::null<
					pos
				>()
			},
			sup{
				pos(
					0u,
					1u
				)
			}
		)
	)
		loop_empty =
			false;

	CHECK(
		loop_empty
	);

	for(
		auto const element
		:
		fcppt::container::grid::make_pos_ref_range_start_end(
			grid,
			min{
				fcppt::math::vector::null<
					pos
				>()
			},
			sup{
				pos(
					1u,
					0u
				)
			}
		)
	)
		loop_empty =
			false;

	CHECK(
		loop_empty
	);
}
