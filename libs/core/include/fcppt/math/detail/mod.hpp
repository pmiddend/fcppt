//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_MOD_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_MOD_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <cmath>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename T
>
inline
std::enable_if_t<
	std::is_floating_point<
		T
	>::value,
	T
>
mod(
	T const &_a,
	T const &_b
)
{
	return
		std::fmod(
			_a,
			_b
		);
}

template<
	typename T
>
inline
std::enable_if_t<
	std::is_unsigned<
		T
	>::value,
	T
>
mod(
	T const &_a,
	T const &_b
)
{
	return
		_a % _b;
}

}
}
}

#endif
