//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_REPEAT_HPP_INCLUDED
#define FCPPT_ALGORITHM_REPEAT_HPP_INCLUDED

#include <fcppt/literal.hpp>


namespace fcppt
{
namespace algorithm
{

/**
\brief Calls a function a number of times

\ingroup fcpptalgorithm

Calls \a _function \a _count times.

\tparam Count An integer type

\tparam Function A function callable as <code>void ()</code>.
*/
template<
	typename Count,
	typename Function
>
void
repeat(
	Count const _count,
	Function const &_function
)
{
	for(
		Count index(
			fcppt::literal<
				Count
			>(
				0
			)
		);
		index < _count;
		++index
	)
		_function();
}

}
}

#endif
