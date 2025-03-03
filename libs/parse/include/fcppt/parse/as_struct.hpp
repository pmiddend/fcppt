//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_AS_STRUCT_HPP_INCLUDED
#define FCPPT_PARSE_AS_STRUCT_HPP_INCLUDED

#include <fcppt/parse/convert_impl.hpp>
#include <fcppt/parse/make_convert.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/type_traits/is_std_tuple.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <tuple>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

/**
\brief Creates a parser that converts a tuple into a struct.

\ingroup fcpptparse

\tparam Parser A parser whose result is a <code>std::tuple</code>.
*/
template<
	typename Result,
	typename Parser
>
fcppt::parse::convert<
	fcppt::type_traits::remove_cv_ref_t<
		Parser
	>,
	Result
>
as_struct(
	Parser &&_parser
)
{
	static_assert(
		fcppt::type_traits::is_std_tuple<
			fcppt::parse::result_of<
				Parser
			>
		>::value
	);

	return
		fcppt::parse::make_convert(
			std::forward<
				Parser
			>(
				_parser
			),
			[](
				fcppt::parse::result_of<
					Parser
				> &&_tuple
			)
			{
				return
					std::apply(
						[](
							auto &&... _args
						)
						{
							return
								Result{
									std::forward<
										decltype(
											_args
										)
									>(
										_args
									)...
								};
						},
						std::move(
							_tuple
						)
					);
			}
		);
}

}
}

#endif
