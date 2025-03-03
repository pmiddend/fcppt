//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_EXTEND_BOUNDING_BOX_HPP_INCLUDED
#define FCPPT_MATH_BOX_EXTEND_BOUNDING_BOX_HPP_INCLUDED

#include <fcppt/make_homogenous_pair.hpp>
#include <fcppt/use.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/box/init_max.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/vector/at.hpp>
#include <fcppt/preprocessor/const.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace box
{

/**
\brief Extend a box to fit a point in it

\ingroup fcpptmathbox

The result will either be the same box (if the point is contained in the box)
or a box that's just big enough to hold the given point.
*/
template<
	typename T,
	fcppt::math::size_type N
>
fcppt::math::box::object<
	T,
	N
>
extend_bounding_box(
	fcppt::math::box::object<
		T,
		N
	> const _box,
	typename
	fcppt::math::box::object<
		T,
		N
	>::vector const _pos
)
{
	return
		fcppt::math::box::init_max<
			fcppt::math::box::object<
				T,
				N
			>
		>(
			[
				&_pos,
				&_box
			](
				auto const _index
			)
			{
				FCPPT_USE(
					_index
				);

				return
					fcppt::make_homogenous_pair(
						std::min(
							fcppt::math::vector::at<
								_index()
							>(
								_pos
							),
							fcppt::math::vector::at<
								_index()
							>(
								_box.pos()
							)
						),
						std::max(
							fcppt::math::vector::at<
								_index()
							>(
								_pos
							),
							fcppt::math::vector::at<
								_index()
							>(
								_box.max()
							)
						)
					);
			}
		);
}

/**
\brief Take the bounding box of two boxes

\ingroup fcpptmathbox
*/
template<
	typename T,
	fcppt::math::size_type N
>
fcppt::math::box::object<
	T,
	N
>
extend_bounding_box(
	fcppt::math::box::object<
		T,
		N
	> const &_box1,
	fcppt::math::box::object<
		T,
		N
	> const &_box2
)
{
	return
		fcppt::math::box::init_max<
			fcppt::math::box::object<
				T,
				N
			>
		>(
			[
				&_box1,
				&_box2
			](
				auto const _index
			)
			{
				FCPPT_USE(
					_index
				);

				return
					fcppt::make_homogenous_pair(
						std::min(
							fcppt::math::vector::at<
								_index()
							>(
								_box1.pos()
							),
							fcppt::math::vector::at<
								_index()
							>(
								_box2.pos()
							)
						),
						std::max(
							fcppt::math::vector::at<
								_index()
							>(
								_box1.max()
							),
							fcppt::math::vector::at<
								_index()
							>(
								_box2.max()
							)
						)
					);
			}
		);
}

}
}
}

#endif
