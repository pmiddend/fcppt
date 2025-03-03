//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_DETAIL_FROM_NUMBER_HPP_INCLUDED
#define FCPPT_METAL_DETAIL_FROM_NUMBER_HPP_INCLUDED

#include <fcppt/type_traits/safe_integral_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/number/number.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace metal
{
namespace detail
{

template<
	typename Dest,
	typename Number
>
struct from_number;

template<
	typename Dest,
	::metal::int_ Value
>
struct from_number<
	Dest,
	::metal::number<
		Value
	>
>
{
	typedef
	fcppt::type_traits::safe_integral_cast<
		Dest,
		::metal::number<
			Value
		>
	>
	type;
};

}
}
}

#endif
