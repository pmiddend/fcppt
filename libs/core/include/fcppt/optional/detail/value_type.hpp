//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_DETAIL_VALUE_TYPE_HPP_INCLUDED
#define FCPPT_OPTIONAL_DETAIL_VALUE_TYPE_HPP_INCLUDED

#include <fcppt/optional/is_object.hpp>
#include <fcppt/type_traits/value_type.hpp>


namespace fcppt
{
namespace optional
{
namespace detail
{

template<
	typename Optional
>
struct value_type
{
	static_assert(
		fcppt::optional::is_object<
			Optional
		>::value,
		"Optional must be an optional"
	);

	typedef
	fcppt::type_traits::value_type<
		Optional
	>
	type;
};

}
}
}

#endif
