//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_PRODUCT_DECL_HPP_INCLUDED
#define FCPPT_OPTIONS_PRODUCT_DECL_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_result_fwd.hpp>
#include <fcppt/options/product_fwd.hpp>
#include <fcppt/options/result_of.hpp>
#include <fcppt/options/state_fwd.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/disjoint_product.hpp>


namespace fcppt
{
namespace options
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4625)
FCPPT_PP_DISABLE_VC_WARNING(4626)

/**
\brief A product of two parsers.

\ingroup fcpptoptions

This parser first applies its left parser and if that succeeds also applies its
right parser. Use #fcppt::options::apply to create a product of
two or more parsers. The result type is a record that contains the elements of
<em>both</em> \a Left and \a Right. Therefore, \a Left and \a Right must have
<em>disjoint</em> label sets.

\see fcppt::options::apply
*/
template<
	typename Left,
	typename Right
>
class product
{
public:
	product(
		Left &&,
		Right &&
	);

	typedef
	fcppt::record::disjoint_product<
		fcppt::options::result_of<
			Left
		>,
		fcppt::options::result_of<
			Right
		>
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
private:
	void
	check_disjoint() const;

	Left left_;

	Right right_;
};

FCPPT_PP_POP_WARNING

}
}

#endif
