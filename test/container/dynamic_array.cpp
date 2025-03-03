//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/container/dynamic_array.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>


template
class
fcppt::container::dynamic_array<
	int
>;

TEST_CASE(
	"container::dynamic_array",
	"[container]"
)
{
	typedef
	fcppt::container::dynamic_array<
		int
	>
	int_array;

	int_array array1{
		10
	};

	CHECK(
		std::distance(
			array1.data(),
			array1.data_end()
		)
		==
		10
	);

	CHECK(
		array1.size()
		==
		10u
	);

	int_array array2{
		0
	};

	CHECK(
		array2.size()
		==
		0u
	);
}
