//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_METAL_DETAIL_INDEX_OF_HPP_INCLUDED
#define FCPPT_METAL_DETAIL_INDEX_OF_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <metal/list/contains.hpp>
#include <metal/list/find.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace metal
{
namespace detail
{

template<
	typename List,
	typename Type
>
struct index_of
{
	static_assert(
		::metal::contains<
			List,
			Type
		>::value
	);

	typedef
	::metal::find<
		List,
		Type
	>
	type;
};

}
}
}

#endif
