//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_AT_OPTIONAL_HPP_INCLUDED
#define FCPPT_CONTAINER_AT_OPTIONAL_HPP_INCLUDED

#include <fcppt/make_ref.hpp>
#include <fcppt/container/to_value_type.hpp>
#include <fcppt/optional/reference.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Returns an element as an optional at a given position.

\ingroup fcpptcontainer

If \a _index is in the range of \a _container, the element at \a _index is
returned. Otherwise, the result is the empty optional.

\tparam Container Must be a random-access container.
*/
template<
	typename Container
>
fcppt::optional::reference<
	fcppt::container::to_value_type<
		Container
	>
>
at_optional(
	Container &_container,
	typename Container::size_type const _index
)
{
	typedef
	fcppt::optional::reference<
		fcppt::container::to_value_type<
			Container
		>
	>
	result_type;

	return
		_index
		<
		_container.size()
		?
			result_type{
				fcppt::make_ref(
					_container[
						_index
					]
				)
			}
		:
			result_type()
		;
}

}
}

#endif
