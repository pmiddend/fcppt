//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_BOX_INIT_MAX_HPP_INCLUDED
#define FCPPT_MATH_BOX_INIT_MAX_HPP_INCLUDED

#include <fcppt/math/box/detail/init.hpp>
#include <fcppt/math/vector/init.hpp>


namespace fcppt
{
namespace math
{
namespace box
{

/**
\brief Initializes a box from pairs of min and max positions

\ingroup fcpptmathbox

Initializes an object of type \a Box by calling \a _function for every index.
The result \a _function must be a homogenous pair where <code>first</code> is
the min position and <code>second</code> is the max position.

\tparam Box Must be a box

\tparam Function A (polymorphic) function of type
<code>fcppt::homogenous_pair<Box::value_type> (Index)</code>
*/
template<
	typename Box,
	typename Function
>
inline
Box
init_max(
	Function const &_function
)
{
	return
		fcppt::math::box::detail::init<
			Box
		>(
			[](
				auto const &_init
			)
			{
				return
					fcppt::math::vector::init<
						typename
						Box::vector
					>(
						_init
					);
			},
			_function
		);
}

}
}
}

#endif
