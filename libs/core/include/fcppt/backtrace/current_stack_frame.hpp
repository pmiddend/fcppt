//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BACKTRACE_CURRENT_STACK_FRAME_HPP_INCLUDED
#define FCPPT_BACKTRACE_CURRENT_STACK_FRAME_HPP_INCLUDED

#include <fcppt/backtrace/stack_frame.hpp>
#include <fcppt/backtrace/stack_limit.hpp>
#include <fcppt/detail/symbol.hpp>


namespace fcppt
{
namespace backtrace
{

FCPPT_DETAIL_SYMBOL
fcppt::backtrace::stack_frame
current_stack_frame(
	fcppt::backtrace::stack_limit const &
);

}
}

#endif
