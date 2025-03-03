//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/use.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/container/tuple/map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <tuple>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::tuple::map",
	"[container],[tuple]"
)
{
	std::tuple<
		std::integral_constant<
			int,
			2
		>,
		std::integral_constant<
			int,
			3
		>
	> const result{
		fcppt::container::tuple::map(
			std::make_tuple(
				std::integral_constant<
					int,
					1
				>{},
				std::integral_constant<
					int,
					2
				>{}
			),
			[](
				auto const _arg
			)
			{
				return
					std::integral_constant<
						int,
						std::remove_const_t<
							decltype(
								_arg
							)
						>::value
						+
						1u
					>{};
			}
		)
	};

	FCPPT_USE(
		result
	);
}

TEST_CASE(
	"container::tuple::map move",
	"[container],[tuple]"
)
{
	typedef
	fcppt::catch_::movable<
		int
	>
	int_movable;

	FCPPT_MAKE_STRONG_TYPEDEF(
		int_movable,
		strong_int_movable
	);

	CHECK(
		fcppt::container::tuple::map(
			std::make_tuple(
				int_movable{
					1
				}
			),
			[](
				int_movable &&_value
			)
			{
				return
					strong_int_movable{
						std::move(
							_value
						)
					};
			}
		)
		==
		std::make_tuple(
			strong_int_movable{
				int_movable{
					1
				}
			}
		)
	);
}
