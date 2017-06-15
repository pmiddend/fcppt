//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_STATE_HPP_INCLUDED
#define FCPPT_OPTIONS_STATE_HPP_INCLUDED

#include <fcppt/args_vector.hpp>
#include <fcppt/optional_string_fwd.hpp>
#include <fcppt/string.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/options/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <map>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

/**
\brief A parse state.

\ingroup fcpptoptions

A parse state contains a list of unconsumed arguments, flags and options.
*/
class state
{
public:
	typedef
	unsigned
	flag_count;

	FCPPT_MAKE_STRONG_TYPEDEF(
		bool,
		is_short
	);

	typedef
	std::pair<
		fcppt::string,
		is_short
	>
	name_pair;

	typedef
	std::map<
		name_pair,
		flag_count
	>
	flag_map;

	typedef
	std::map<
		name_pair,
		fcppt::args_vector
	>
	options_map;

	FCPPT_OPTIONS_DETAIL_SYMBOL
	state(
		fcppt::args_vector &&,
		flag_map &&,
		options_map &&
	);

	FCPPT_OPTIONS_DETAIL_SYMBOL
	fcppt::optional_string
	pop_arg();

	FCPPT_OPTIONS_DETAIL_SYMBOL
	bool
	pop_flag(
		fcppt::string const &,
		is_short
	);

	FCPPT_OPTIONS_DETAIL_SYMBOL
	fcppt::optional_string
	pop_option(
		fcppt::string const &,
		is_short
	);

	FCPPT_OPTIONS_DETAIL_SYMBOL
	fcppt::args_vector const &
	leftover_args() const;

	FCPPT_OPTIONS_DETAIL_SYMBOL
	flag_map const &
	leftover_flags() const;

	FCPPT_OPTIONS_DETAIL_SYMBOL
	options_map const &
	leftover_options() const;

	FCPPT_OPTIONS_DETAIL_SYMBOL
	bool
	empty() const;
private:
	fcppt::args_vector args_;

	flag_map flags_;

	options_map options_;
};

}
}

#endif
