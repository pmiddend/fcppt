//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_cref.hpp>
#include <fcppt/parse/base_unique_ptr.hpp>
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/deref.hpp>
#include <fcppt/parse/epsilon.hpp>
#include <fcppt/parse/make_base.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"parse::base",
	"[parse]"
)
{
	fcppt::parse::base_unique_ptr<
		char,
		char,
		fcppt::parse::epsilon
	> const parser{
		fcppt::parse::make_base<
			char,
			fcppt::parse::epsilon
		>(
			fcppt::parse::char_{}
		)
	};

	CHECK(
		parser.get_pointer()
		==
		&fcppt::parse::deref(
			parser
		)
	);

	CHECK(
		parser.get_pointer()
		==
		&fcppt::parse::deref(
			fcppt::make_cref(
				parser
			)
		)
	);
}
