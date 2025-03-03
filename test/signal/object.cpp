//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/range/size.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/base.hpp>
#include <fcppt/signal/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <functional>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
fcppt::signal::object<
	void ()
>
signal_type;

}

TEST_CASE(
	"signal::object",
	"[signal]"
)
{
	int counter{
		0
	};

	auto const add(
		[
			&counter
		](
			int const _value
		)
		{
			counter +=
				_value;
		}
	);

	auto const con_size(
		[](
			signal_type const &_sig
		)
		{
			return
				fcppt::range::size(
					_sig.connections()
				);
		}
	);

	signal_type sig{};

	REQUIRE(
		sig.empty()
	);

	{
		fcppt::signal::auto_connection const con1(
			sig.connect(
				signal_type::function{
					std::bind(
						add,
						1
					)
				}
			)
		);

		CHECK(
			con_size(
				sig
			)
			==
			1u
		);

		REQUIRE(
			counter
			==
			0
		);

		sig();

		REQUIRE(
			counter
			==
			1
		);

		{
			fcppt::signal::auto_connection const con2(
				sig.connect(
					signal_type::function{
						std::bind(
							add,
							2
						)
					}
				)
			);

			CHECK(
				con_size(
					sig
				)
				==
				2u
			);

			sig();

			REQUIRE(
				counter
				==
				4
			);
		}

		CHECK(
			con_size(
				sig
			)
			==
			1u
		);
	}

	CHECK(
		con_size(
			sig
		)
		==
		0u
	);

	REQUIRE(
		sig.empty()
	);

	sig();

	REQUIRE(
		counter
		==
		4
	);
}

TEST_CASE(
	"signal::object move",
	"[signal]"
)
{
	signal_type sig{};

	int counter{
		0
	};

	fcppt::signal::auto_connection const con1(
		sig.connect(
			signal_type::function{
				[
					&counter
				]{
					++counter;
				}
			}
		)
	);

	signal_type sig2(
		std::move(
			sig
		)
	);

	CHECK(
		counter
		==
		0
	);

	sig2();

	CHECK(
		counter
		==
		1
	);

	sig =
		std::move(
			sig2
		);

	sig();

	CHECK(
		counter
		==
		2
	);

	CHECK(
		counter
		==
		2
	);
}
