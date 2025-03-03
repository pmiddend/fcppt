//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_INACTIVE_VALUE_FWD_HPP_INCLUDED
#define FCPPT_OPTIONS_INACTIVE_VALUE_FWD_HPP_INCLUDED

#include <fcppt/strong_typedef_fwd.hpp>
#include <fcppt/options/inactive_value_tag.hpp>


namespace fcppt
{
namespace options
{

/**
\brief A strong typedef used as a parser's inactive value

\ingroup fcpptoptions
*/
template<
	typename Type
>
using
inactive_value
=
fcppt::strong_typedef<
	Type,
	fcppt::options::inactive_value_tag
>;

}
}

#endif
