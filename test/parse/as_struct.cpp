//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/strong_typedef_comparison.hpp>
#include <fcppt/strong_typedef_output.hpp>
#include <fcppt/either/comparison.hpp>
#include <fcppt/either/output.hpp>
#include <fcppt/parse/as_struct.hpp>
#include <fcppt/parse/char.hpp>
#include <fcppt/parse/epsilon.hpp>
#include <fcppt/parse/make_success.hpp>
#include <fcppt/parse/parse_string.hpp>
#include <fcppt/parse/operators/sequence.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <ostream>
#include <string>
#include <tuple>
#include <fcppt/config/external_end.hpp>


namespace
{

struct my_struct
{
	my_struct(
		char const _x,
		char const _y
	)
	:
		x_{
			_x
		},
		y_{
			_y
		}
	{
	}

	char x_;

	char y_;
};

bool
operator==(
	my_struct const &_left,
	my_struct const &_right
)
{
	return
		std::tie(
			_left.x_,
			_left.y_
		)
		==
		std::tie(
			_right.x_,
			_right.y_
		);
}

std::ostream &
operator<<(
	std::ostream &_stream,
	my_struct const &_value
)
{
	return
		_stream
		<< '('
		<< _value.x_
		<< ','
		<< _value.y_
		<< ')';
}

}

TEST_CASE(
	"parse::as_struct",
	"[parse]"
)
{
	auto const parser(
		fcppt::parse::as_struct<
			my_struct
		>(
			fcppt::parse::char_{}
			>>
			fcppt::parse::char_{}
		)
	);

	CHECK(
		fcppt::parse::parse_string(
			parser,
			std::string{
				"XY"
			},
			fcppt::parse::epsilon{}
		)
		==
		fcppt::parse::make_success<
			char
		>(
			my_struct{
				'X',
				'Y'
			}
		)
	);
}
