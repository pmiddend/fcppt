//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_SET_UNION_HPP_INCLUDED
#define FCPPT_CONTAINER_SET_UNION_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

/**
\brief Returns the union of two sets

\ingroup fcpptcontainer

\tparam Set Must be an associative container
*/
template<
	typename Set
>
Set
set_union(
	Set const &_a,
	Set const &_b
)
{
	Set result;

	::std::set_union(
		_a.begin(),
		_a.end(),
		_b.begin(),
		_b.end(),
		::std::inserter(
			result,
			result.begin()
		)
	);

	return
		result;
}

}
}

#endif
