//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_DETAIL_STATIC_STORAGE_FWD_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_DETAIL_STATIC_STORAGE_FWD_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/static_storage_fwd.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{
namespace detail
{

template<
	typename T,
	fcppt::math::size_type R,
	fcppt::math::size_type C
>
using static_storage
=
fcppt::math::detail::static_storage<
	T,
	R * C
>;

}
}
}
}

#endif
