//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_COMPONENTWISE_EQUAL_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_COMPONENTWISE_EQUAL_HPP_INCLUDED

#include <fcppt/tag_type.hpp>
#include <fcppt/use.hpp>
#include <fcppt/algorithm/all_of.hpp>
#include <fcppt/math/diff.hpp>
#include <fcppt/math/int_range_count.hpp>
#include <fcppt/math/detail/linear_access.hpp>
#include <fcppt/type_traits/value_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Range1,
	typename Range2,
	typename T
>
inline
bool
componentwise_equal(
	Range1 const &_r1,
	Range2 const &_r2,
	T const &_epsilon
)
{
	static_assert(
		std::is_floating_point<
			fcppt::type_traits::value_type<
				Range1
			>
		>::value
		&&
		std::is_floating_point<
			fcppt::type_traits::value_type<
				Range2
			>
		>::value,
		"componentwise_equal can only be used on ranges of floating point type"
	);

	static_assert(
		Range1::dim_wrapper::value
		==
		Range2::dim_wrapper::value,
		"Ranges of different size in componentwise_equal"
	);

	return
		fcppt::algorithm::all_of(
			fcppt::math::int_range_count<
				Range1::dim_wrapper::value
			>{},
			[
				&_r1,
				&_r2,
				_epsilon
			](
				auto const _index
			)
			{
				FCPPT_USE(
					_index
				);

				typedef
				fcppt::tag_type<
					decltype(
						_index
					)
				>
				index;

				return
					fcppt::math::diff(
						fcppt::math::detail::linear_access<
							index::value
						>(
							_r1.storage()
						),
						fcppt::math::detail::linear_access<
							index::value
						>(
							_r2.storage()
						)
					)
					<
					_epsilon;
			}
		);
}

}
}
}

#endif
