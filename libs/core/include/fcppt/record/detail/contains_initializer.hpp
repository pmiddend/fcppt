//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_DETAIL_CONTAINS_INITIALIZER_HPP_INCLUDED
#define FCPPT_RECORD_DETAIL_CONTAINS_INITIALIZER_HPP_INCLUDED

#include <fcppt/record/element_to_label.hpp>
#include <fcppt/record/detail/label_is_same.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/lambda/partial.hpp>
#include <metal/lambda/trait.hpp>
#include <metal/list/any_of.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace record
{
namespace detail
{

template<
	typename Args,
	typename Element
>
using
contains_initializer
=
::metal::any_of<
	Args,
	::metal::partial<
		::metal::trait<
			fcppt::record::detail::label_is_same
		>,
		fcppt::record::element_to_label<
			Element
		>
	>
>;

}
}
}

#endif
