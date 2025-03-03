//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/algorithm/fold.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/container/make_move_range.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <functional>
#include <utility>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"algorithm::fold"
	"[algorithm]"
)
{
	typedef
	std::vector<
		int
	>
	int_vector;

	typedef
	std::vector<
		int_vector
	>
	int_vector_vector;

	CHECK(
		fcppt::algorithm::fold(
			int_vector_vector{
				int_vector{
					1,
					2
				},
				int_vector{
					3,
					4
				}
			},
			0,
			[](
				int_vector const &_vec,
				int const _sum
			)
			{
				return
					fcppt::algorithm::fold(
						_vec,
						_sum,
						std::plus<
							int
						>()
					);
			}
		)
		==
		10
	);
}

TEST_CASE(
	"algorithm::fold move"
	"[algorithm]"
)
{
	typedef
	fcppt::catch_::movable<
		int
	>
	int_movable;

	typedef
	std::vector<
		int_movable
	>
	int_vector;

	int_vector vector{
		fcppt::container::make<
			int_vector
		>(
			int_movable{
				1
			}
		)
	};

	CHECK(
		fcppt::algorithm::fold(
			fcppt::container::make_move_range(
				std::move(
					vector
				)
			),
			0,
			[](
				int_movable &&_element,
				int const _sum
			)
			{
				return
					_element.value()
					+
					_sum;
			}
		)
		==
		1
	);
}
