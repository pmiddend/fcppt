//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_FLAG_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_FLAG_DECL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/active_value.hpp>
#include <fcppt/options/flag_fwd.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/inactive_value.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_result_fwd.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/record/element_fwd.hpp>
#include <fcppt/record/variadic_fwd.hpp>


namespace fcppt
{
namespace options
{

/**
\brief A flag parser.

\ingroup fcpptoptions

A flag parser matches the next command-line parameter that is equal to its
short name ("-f") or its long name ("--flag"). If there is such a command-line
parameter, then the flag is <em>on</em>, otherwise it is <em>off</em>. The
result of a flag is a record that has a single element with label \a Label and
type \a Type.  In case the flag is off, the result will be the flag's inactive
value, otherwise it will be that flag's active value.

\tparam Label An #fcppt::record::label.

\tparam Type The type of the flag's value.
*/
template<
	typename Label,
	typename Type
>
class flag
{
public:
	typedef
	fcppt::options::active_value<
		Type
	>
	active_value;

	typedef
	fcppt::options::inactive_value<
		Type
	>
	inactive_value;

	/**
	\brief Constructs a flag parser.

	\note The active and the inactive value must be different.

	\param short_name An optional short name ("-f") this parser will match.

	\param long_name The long name ("--flag") this parser will match.

	\param active The value of the parser in case its flag is encountered.

	\param inactive The value of the parser in case its flag is <em>not</em> encountered.

	\param help_text Optional help text for this flag.
	*/
	flag(
		fcppt::options::optional_short_name &&short_name,
		fcppt::options::long_name &&long_name,
		active_value &&active,
		inactive_value &&inactive,
		fcppt::options::optional_help_text &&help_text
	);

	typedef
	fcppt::record::element<
		Label,
		Type
	>
	element_type;

	typedef
	fcppt::record::variadic<
		element_type
	>
	result_type;

	fcppt::options::parse_result<
		result_type
	>
	parse(
		fcppt::options::state &&,
		fcppt::options::parse_context const &
	) const;

	fcppt::options::flag_name_set
	flag_names() const;

	fcppt::options::option_name_set
	option_names() const;

	fcppt::string
	usage() const;

	fcppt::options::optional_short_name const &
	short_name() const;

	fcppt::options::long_name const &
	long_name() const;
private:
	fcppt::options::optional_short_name short_name_;

	fcppt::options::long_name long_name_;

	active_value active_value_;

	inactive_value inactive_value_;

	fcppt::options::optional_help_text help_text_;
};

}
}

#endif
