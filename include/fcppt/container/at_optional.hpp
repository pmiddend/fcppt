//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_AT_OPTIONAL_HPP_INCLUDED
#define FCPPT_CONTAINER_AT_OPTIONAL_HPP_INCLUDED

#include <fcppt/container/to_reference_type.hpp>
#include <fcppt/optional/object_impl.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Returns an element as an optional

\ingroup fcpptcontainer

If \a _index is in the range of \a _container, the element at \a _index is
returned.  Otherwise, the result is an empty optional.
*/
template<
	typename Container
>
fcppt::optional::object<
	fcppt::container::to_reference_type<
		Container
	>
>
at_optional(
	Container &_container,
	typename Container::size_type const _index
)
{
	typedef
	fcppt::optional::object<
		fcppt::container::to_reference_type<
			Container
		>
	>
	result_type;

	return
		_index
		<
		_container.size()
		?
			result_type(
				_container[
					_index
				]
			)
		:
			result_type()
		;
}

}
}

#endif
