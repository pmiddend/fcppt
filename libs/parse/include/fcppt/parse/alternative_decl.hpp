//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_ALTERNATIVE_DECL_HPP_INCLUDED
#define FCPPT_PARSE_ALTERNATIVE_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/alternative_fwd.hpp>
#include <fcppt/parse/alternative_result.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/tag.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>


namespace fcppt
{
namespace parse
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

/**
\brief Tries two parsers in succession. Uses the result of the first one that does not fail.

\ingroup fcpptparse

This parser first saves the current position <code>p</code>.
It then tries the parser \a Left.
If it succeeds then its result is returned.
Otherwise, the parser backtracks to position <code>p</code> and returns the result of \a Right
(which might fail or not).

See #fcppt::parse::alternative_result on this parser's result type.
*/
template<
	typename Left,
	typename Right
>
class alternative
:
	private fcppt::parse::tag
{
public:
	alternative(
		Left &&,
		Right &&
	);

	typedef
	fcppt::parse::alternative_result<
		fcppt::parse::result_of<
			Left
		>,
		fcppt::parse::result_of<
			Right
		>
	>
	result_type;

	template<
		typename Ch,
		typename Skipper
	>
	fcppt::parse::result<
		Ch,
		result_type
	>
	parse(
		fcppt::reference<
			fcppt::parse::state<
				Ch
			>
		>,
		fcppt::parse::context<
			Skipper
		> const &
	) const;
private:
	Left left_;

	Right right_;
};

FCPPT_PP_POP_WARNING

}
}

#endif
