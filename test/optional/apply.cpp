//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional/apply.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"optional::apply",
	"[optiona;]"
)
{
	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	typedef
	fcppt::optional::object<
		unsigned
	>
	optional_unsigned;

	typedef
	fcppt::optional::object<
		std::string
	>
	optional_string;

	CHECK(
		fcppt::optional::apply(
			[](
				int const _val1,
				unsigned const _val2
			)
			{
				return
					std::to_string(
						_val1
					)
					+
					std::to_string(
						_val2
					);
			},
			optional_int(
				10
			),
			optional_unsigned(
				20u
			)
		)
		==
		optional_string(
			std::string(
				"1020"
			)
		)
	);

	CHECK(
		fcppt::optional::apply(
			[](
				int,
				unsigned
			)
			{
				return
					std::string{};
			},
			optional_int(),
			optional_unsigned(
				20
			)
		)
		==
		optional_string()
	);
}
