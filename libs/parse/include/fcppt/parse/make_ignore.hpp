//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_MAKE_IGNORE_HPP_INCLUDED
#define FCPPT_PARSE_MAKE_IGNORE_HPP_INCLUDED

#include <fcppt/parse/ignore_impl.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Parser
>
fcppt::parse::ignore<
	fcppt::type_traits::remove_cv_ref_t<
		Parser
	>
>
make_ignore(
	Parser &&_parser
)
{
	return
		fcppt::parse::ignore<
			fcppt::type_traits::remove_cv_ref_t<
				Parser
			>
		>{
			std::forward<
				Parser
			>(
				_parser
			)
		};
}

}
}

#endif
