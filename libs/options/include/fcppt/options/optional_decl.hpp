//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_OPTIONAL_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_OPTIONAL_DECL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/optional/object_fwd.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/optional_fwd.hpp>
#include <fcppt/options/result_fwd.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/record/element_to_type.hpp>
#include <fcppt/record/map_elements.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/types/args.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

/**
\brief An optional parser.

\ingroup fcpptoptions

Wraps a parser such that it may fail. The result type is a record that adds one
layer of \link fcppt::optional::object\endlink to the elements of the result
type of \a Parser.

\see fcppt::options::make_optional
*/
template<
	typename Parser
>
class optional
{
public:
	explicit
	optional(
		Parser const &
	);

	explicit
	optional(
		Parser &&
	);

	optional(
		optional const &
	);

	optional(
		optional &&
	);

	optional &
	operator=(
		optional const &
	);

	optional &
	operator=(
		optional &&
	);

	~optional();

	typedef
	fcppt::record::map_elements<
		fcppt::options::result_of<
			Parser
		>,
		::brigand::bind<
			fcppt::optional::object,
			::brigand::bind<
				fcppt::record::element_to_type,
				::brigand::_1
			>
		>
	>
	result_type;

	fcppt::options::result<
		result_type
	>
	parse(
		fcppt::options::state &
	) const;

	fcppt::options::flag_name_set
	flag_names() const;

	fcppt::options::option_name_set
	option_names() const;

	fcppt::string
	usage() const;
private:
	Parser parser_;
};

}
}

#endif
