//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_MAKE_IF_HPP_INCLUDED
#define FCPPT_OPTIONAL_MAKE_IF_HPP_INCLUDED

#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief Creates an optional depending on a boolean

\ingroup fcpptoptional

If \a _is_set is true, then <code>_function()</code> is returned
as an optional. Otherwise, the empty optional is returned.

\tparam Function A function callable as <code>R ()</code> where <code>R</code>
is the result type.
*/
template<
	typename Function
>
inline
fcppt::optional::object<
	std::result_of_t<
		Function()
	>
>
make_if(
	bool const _is_set,
	Function const &_function
)
{
	typedef
	fcppt::optional::object<
		std::result_of_t<
			Function()
		>
	>
	result_type;

	return
		_is_set
		?
			result_type{
				_function()
			}
		:
			result_type{}
		;
}

}
}

#endif
