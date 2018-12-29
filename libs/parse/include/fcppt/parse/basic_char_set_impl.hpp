//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_BASIC_CHAR_SET_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_BASIC_CHAR_SET_IMPL_HPP_INCLUDED

#include <fcppt/const.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/container/contains.hpp>
#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/parse/basic_char_impl.hpp>
#include <fcppt/parse/basic_char_set_decl.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <initializer_list>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Ch
>
fcppt::parse::basic_char_set<
	Ch
>::basic_char_set(
	std::initializer_list<
		Ch
	> const &_inits
)
:
	basic_char_set(
		char_set_type{
			_inits
		}
	)
{
}

template<
	typename Ch
>
fcppt::parse::basic_char_set<
	Ch
>::basic_char_set(
	char_set_type &&_chars
)
:
	chars_{
		std::move(
			_chars
		)
	}
{
}

template<
	typename Ch
>
template<
	typename Skipper
>
fcppt::parse::result<
	typename
	fcppt::parse::basic_char_set<
		Ch
	>::result_type
>
fcppt::parse::basic_char_set<
	Ch
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
	fcppt::parse::basic_char<
		Ch
	> const parser{};

	return
		fcppt::optional::bind(
			parser.parse(
				_state,
				_context
			),
			[
				this
			](
				Ch const _result
			)
			{
				return
					fcppt::optional::make_if(
						fcppt::container::contains(
							this->chars_,
							_result
						),
						fcppt::const_(
							_result
						)
					);
			}
		);
}

template<
	typename Ch
>
typename
fcppt::parse::basic_char_set<
	Ch
>::char_set_type const &
fcppt::parse::basic_char_set<
	Ch
>::chars() const
{
	return
		this->chars_;
}

#endif
