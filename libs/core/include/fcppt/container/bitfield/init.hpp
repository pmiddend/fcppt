//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_INIT_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_INIT_HPP_INCLUDED

#include <fcppt/container/bitfield/object_impl.hpp>
#include <fcppt/container/bitfield/detail/make_range.hpp>


namespace fcppt
{
namespace container
{
namespace bitfield
{

/**
\brief Initialize a bitfield using a function

\ingroup fcpptcontainerbitfield

Every bit of \a Result with index <code>e</code> is set to
<code>_function(e)</code>.

\tparam Result Must be a bitfield.

\tparam Function Must be callable as <code>bool (Result::element_type)</code>.
*/
template<
	typename Result,
	typename Function
>
Result
init(
	Function const &_function
)
{
	Result result(
		Result::null()
	);

	typedef
	typename
	Result::element_type
	element_type;

	for(
		element_type const value
		:
		fcppt::container::bitfield::detail::make_range<
			element_type,
			typename
			Result::static_size
		>()
	)
		result.set(
			value,
			_function(
				value
			)
		);

	return
		result;
}

}
}
}

#endif
