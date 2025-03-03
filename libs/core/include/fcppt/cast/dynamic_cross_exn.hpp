//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_DYNAMIC_CROSS_EXN_HPP_INCLUDED
#define FCPPT_CAST_DYNAMIC_CROSS_EXN_HPP_INCLUDED

#include <fcppt/cast/detail/dynamic_exn.hpp>
#include <fcppt/type_traits/is_base_of.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Converts between references of unrelated types using
<code>dynamic_cast</code> and provides additional error information

\ingroup fcpptcasts

This cast is the same as #fcppt::cast::dynamic_exn  but only works
on unrelated types.

\tparam Dest The type to cast to. Must be a reference type. Must not inherit from \a Src.

\tparam Src A cv-qualified non-reference type.

\see #fcppt::cast::dynamic_exn
*/
template<
	typename Dest,
	typename Src
>
inline
std::enable_if_t<
	std::is_reference<
		Dest
	>::value,
	Dest
>
dynamic_cross_exn(
	Src &_src
)
{
	static_assert(
		!fcppt::type_traits::is_base_of<
			std::remove_cv_t<
				Src
			>,
			fcppt::type_traits::remove_cv_ref_t<
				Dest
			>
		>::value,
		"dynamic_cross_exn can only be used on unrelated types"
	);

	return
		fcppt::cast::detail::dynamic_exn<
			Dest
		>(
			_src
		);
}

}
}

#endif
