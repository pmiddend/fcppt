//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/unit_comparison.hpp>
#include <fcppt/unit_output.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/epsilon.hpp>
#include <fcppt/parse/int.hpp>
#include <fcppt/parse/literal.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/operators/alternative.hpp>
#include <fcppt/variant/comparison.hpp>
#include <fcppt/variant/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"parse::alternative",
	"[parse]"
)
{
	auto const parser(
		fcppt::parse::int_<int>{}
		|
		fcppt::parse::literal{'X'}
		|
		fcppt::parse::char_{}
	);

	typedef
	fcppt::parse::result_of<
		decltype(
			parser
		)
	>
	result_type;

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{},
			fcppt::parse::epsilon{}
		).has_failure()
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				"42"
			},
			fcppt::parse::epsilon{}
		)
		==
		fcppt::parse::make_success<
			char
		>(
			result_type{
				42
			}
		)
	);
}


TEST_CASE(
	"parse::alternative backtrack",
	"[parse]"
)
{
	auto const parser(
		fcppt::parse::literal{'X'}
		|
		fcppt::parse::char_{}
	);

	typedef
	fcppt::parse::result_of<
		decltype(
			parser
		)
	>
	result_type;

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{},
			fcppt::parse::epsilon{}
		).has_failure()
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				"X"
			},
			fcppt::parse::epsilon{}
		)
		==
		fcppt::parse::make_success<
			char
		>(
			result_type{
				fcppt::unit()
			}
		)
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				"Y"
			},
			fcppt::parse::epsilon{}
		)
		==
		fcppt::parse::make_success<
			char
		>(
			result_type{
				'Y'
			}
		)
	);
}
