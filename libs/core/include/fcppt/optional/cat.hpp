//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_CAT_HPP_INCLUDED
#define FCPPT_OPTIONAL_CAT_HPP_INCLUDED

#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/algorithm/range_element_type.hpp>
#include <fcppt/optional/maybe_void.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief Removes empty optionals from a range

\ingroup fcpptoptional

For every element \em e in \a _source, if \em e is set to <code>x</code>, then
<code>x</code> is inserted into the target container.

\tparam Source Must be a container of optionals

\tparam TargetContainer Must be a container whose value type matches that of
the optionals from \a Source
*/
template<
	typename TargetContainer,
	typename Source
>
TargetContainer
cat(
	Source &&_source
)
{
	TargetContainer result;

	for(
		fcppt::algorithm::range_element_type<
			Source
		> element
		:
		_source
	)
		fcppt::optional::maybe_void(
			element,
			[
				&result
			](
				auto &&_element
			)
			{
				result.insert(
					result.end(),
					fcppt::move_if_rvalue<
						Source
					>(
						_element
					)
				);
			}
		);

	return
		result;
}

}
}

#endif
