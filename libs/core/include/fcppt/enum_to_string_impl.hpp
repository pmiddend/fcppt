//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENUM_TO_STRING_IMPL_HPP_INCLUDED
#define FCPPT_ENUM_TO_STRING_IMPL_HPP_INCLUDED

#include <fcppt/enum_to_string_impl_fwd.hpp>
#include <fcppt/enum_names.hpp>
#include <fcppt/enum_names_array.hpp>
#include <fcppt/string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Customization point to convert an enum to a string.

\ingroup fcpptenum

The default implementation uses \link fcppt::enum_names\endlink.

\tparam Enum Must be an enum type
*/
template<
	typename Enum,
	typename Enable
>
struct enum_to_string_impl
{
	static_assert(
		std::is_enum<
			Enum
		>::value,
		"Enum must be an enum type"
	);

	static
	fcppt::string
	get(
		Enum const _enum
	)
	{
		return
			fcppt::enum_names<
				Enum
			>()[
				_enum
			];
	}
};

}

#endif
