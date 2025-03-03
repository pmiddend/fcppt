//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/catch/optional.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"catch::optional",
	"[catch]"
)
{
	typedef
	fcppt::optional::object<
		fcppt::string
	>
	optional;

	CHECK(
		optional{
			fcppt::string{
				FCPPT_TEXT("test")
			}
		}
		==
		optional{
			fcppt::string{
				FCPPT_TEXT("test")
			}
		}
	);
}
