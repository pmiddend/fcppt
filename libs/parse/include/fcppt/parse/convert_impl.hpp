//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_CONVERT_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_CONVERT_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/convert_decl.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Parser,
	typename Convert
>
fcppt::parse::convert<
	Parser,
	Convert
>::convert(
	Parser &&_parser,
	Convert &&_convert
)
:
	parser_{
		std::move(
			_parser
		)
	},
	convert_{
		std::move(
			_convert
		)
	}
{
}

template<
	typename Parser,
	typename Convert
>
template<
	typename Ch,
	typename Skipper
>
fcppt::parse::result<
	typename
	fcppt::parse::convert<
		Parser,
		Convert
	>::result_type
>
fcppt::parse::convert<
	Parser,
	Convert
>::parse(
	fcppt::reference<
		fcppt::parse::state<
			Ch
		>
	> const _state,
	fcppt::parse::context<
		Skipper
	> const &_context
) const
{
	return
		fcppt::optional::map(
			fcppt::parse::deref(
				this->parser_
			).parse(
				_state,
				_context
			),
			[
				this
			](
				fcppt::parse::result_of<
					Parser
				> &&_result
			)
			{
				return
					this->convert_(
						std::move(
							_result
						)
					);
			}
		);
}

#endif
