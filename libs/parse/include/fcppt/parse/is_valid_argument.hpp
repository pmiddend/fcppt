//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_IS_VALID_ARGUMENT_HPP_INCLUDED
#define FCPPT_PARSE_IS_VALID_ARGUMENT_HPP_INCLUDED

#include <fcppt/parse/deref_type.hpp>
#include <fcppt/parse/is_parser.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Type
>
using
is_valid_argument
=
fcppt::parse::is_parser<
	fcppt::parse::deref_type<
		fcppt::type_traits::remove_cv_ref_t<
			Type
		>
	>
>;

}
}

#endif
