//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_DETAIL_ALTERNATIVE_RESULT_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_ALTERNATIVE_RESULT_HPP_INCLUDED

#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/list/front.hpp>
#include <metal/list/size.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{
namespace detail
{

template<
	typename List
>
using
alternative_result
=
std::conditional_t<
	::metal::size<
		List
	>::value
	==
	1u,
	::metal::front<
		List
	>,
	fcppt::variant::object<
		List
	>
>;

}
}
}

#endif
