//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/either/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"either::object",
	"[either]"
)
{
	typedef
	fcppt::either::object<
		std::string,
		int
	>
	either;

	SECTION(
		"test failure"
	)
	{
		either const test1(
			std::string(
				"failure"
			)
		);

		REQUIRE(
			test1.has_failure()
		);

		CHECK(
			test1.get_failure_unsafe()
			==
			std::string(
				"failure"
			)
		);
	}

	SECTION(
		"test success"
	)
	{
		either const test2( 42
		);

		REQUIRE(
			test2.has_success()
		);

		CHECK(
			test2.get_success_unsafe()
			==
			42
		);
	}
}
