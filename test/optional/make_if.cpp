//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/const.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"optional::make_if",
	"[optional]"
)
{
	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	CHECK(
		fcppt::optional::make_if(
			true,
			fcppt::const_(
				42
			)
		)
		==
		optional_int{
			42
		}
	);

	CHECK(
		fcppt::optional::make_if(
			false,
			fcppt::const_(
				42
			)
		)
		==
		optional_int{}
	);
}
