//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_OPTION_NAME_HPP_INCLUDED
#define FCPPT_OPTIONS_OPTION_NAME_HPP_INCLUDED

#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/string.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/options/option_name_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>


namespace fcppt
{
namespace options
{

/**
\brief An option name that may be for a short or long option

\ingroup fcpptoptions
*/
class option_name
{
public:
	FCPPT_MAKE_STRONG_TYPEDEF(
		bool,
		is_short
	);

	FCPPT_OPTIONS_DETAIL_SYMBOL
	option_name(
		fcppt::string &&,
		is_short
	);

	fcppt::string name_;

	is_short is_short_;
};

}
}

#endif
