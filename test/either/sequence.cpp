//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/catch/either.hpp>
#include <fcppt/catch/movable.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/sequence.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"either::sequence",
	"[either]"
)
{
	typedef
	fcppt::either::object<
		std::string,
		int
	>
	either_int;

	typedef
	std::vector<
		either_int
	>
	either_int_vector;

	typedef
	std::vector<
		int
	>
	int_vector;

	typedef
	fcppt::either::object<
		std::string,
		int_vector
	>
	result_type;

	CHECK(
		fcppt::either::sequence<
			int_vector
		>(
			either_int_vector{
				either_int{
					42
				},
				either_int{
					std::string(
						"failure"
					)
				},
				either_int{
					10
				},
				either_int{
					std::string(
						"failure2"
					)
				}
			}
		)
		==
		result_type{
			std::string{
				"failure"
			}
		}
	);

	CHECK(
		fcppt::either::sequence<
			int_vector
		>(
			either_int_vector{
				either_int{
					10
				},
				either_int{
					20
				}
			}
		)
		==
		result_type{
			int_vector{
				10,
				20
			}
		}
	);
}

TEST_CASE(
	"either::sequence move",
	"[either]"
)
{
	typedef
	fcppt::catch_::movable<
		int
	>
	int_movable;

	typedef
	fcppt::either::object<
		std::string,
		int_movable
	>
	either_int;

	typedef
	std::vector<
		either_int
	>
	either_int_vector;

	typedef
	std::vector<
		int_movable
	>
	int_vector;

	typedef
	fcppt::either::object<
		std::string,
		int_vector
	>
	result_type;

	CHECK(
		fcppt::either::sequence<
			int_vector
		>(
			fcppt::container::make<
				either_int_vector
			>(
				either_int{
					int_movable{
						10
					}
				},
				either_int{
					int_movable{
						20
					}
				}
			)
		)
		==
		result_type{
			fcppt::container::make<
				int_vector
			>(
				int_movable{
					10
				},
				int_movable{
					20
				}
			)
		}
	);
}
