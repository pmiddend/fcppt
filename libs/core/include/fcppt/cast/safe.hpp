//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_SAFE_HPP_INCLUDED
#define FCPPT_CAST_SAFE_HPP_INCLUDED

#include <fcppt/cast/detail/safe.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief A cast that prohibits lossy conversions

\ingroup fcpptcasts

This cast converts arithmetic types like #fcppt::cast::safe_numeric does.
For every other type the conversion is done implicitly.
More specifically, this means that for arithmetic types the restrictions of #fcppt::cast::safe_numeric must hold,
and for every other type \a Source must be implicitly convertible to \a Dest.

\tparam Dest Can be any type

\tparam Source Can be any type
*/
template<
	typename Dest,
	typename Source
>
inline
constexpr
Dest
safe(
	Source const &_source
)
{
	return
		fcppt::cast::detail::safe<
			Dest
		>(
			_source
		);
}

}
}

#endif
