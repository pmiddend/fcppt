//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_MAKE_BASE_HPP_INCLUDED
#define FCPPT_PARSE_MAKE_BASE_HPP_INCLUDED

#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/parse/base_fwd.hpp>
#include <fcppt/parse/base_unique_ptr.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/detail/concrete_impl.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Ch,
	typename Skipper,
	typename Parser
>
fcppt::parse::base_unique_ptr<
	fcppt::parse::result_of<
		Parser
	>,
	Ch,
	Skipper
>
make_base(
	Parser &&_parser
)
{
	return
		fcppt::unique_ptr_to_base<
			fcppt::parse::base<
				fcppt::parse::result_of<
					Parser
				>,
				Ch,
				Skipper
			>
		>(
			fcppt::make_unique_ptr<
				fcppt::parse::detail::concrete<
					fcppt::type_traits::remove_cv_ref_t<
						Parser
					>,
					Ch,
					Skipper
				>
			>(
				std::forward<
					Parser
				>(
					_parser
				)
			)
		);
}

}
}

#endif
