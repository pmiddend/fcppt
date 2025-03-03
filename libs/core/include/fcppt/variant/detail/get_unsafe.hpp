//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_GET_UNSAFE_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_GET_UNSAFE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Type,
	typename Variant
>
inline
std::conditional_t<
	std::is_const_v<
		Variant
	>,
	Type const &,
	Type &
>
get_unsafe(
	Variant &_object
)
{
	return
		_object. template get_unsafe<
			Type
		>();
}

}
}
}

#endif
