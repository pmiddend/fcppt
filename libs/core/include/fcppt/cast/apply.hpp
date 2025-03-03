//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_APPLY_HPP_INCLUDED
#define FCPPT_CAST_APPLY_HPP_INCLUDED


namespace fcppt
{
namespace cast
{

/**
\brief Applies a cast to a source

\ingroup fcpptcasts
*/
template<
	typename Fun,
	typename Res,
	typename Src
>
constexpr
decltype(
	auto
)
apply(
	Src &&_src
)
{
	return
		Fun :: template execute <
			Res
		>(
			_src
		);
}

}
}

#endif
