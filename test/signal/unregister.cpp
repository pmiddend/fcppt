//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object.hpp>
#include <fcppt/signal/unregister/base.hpp>
#include <fcppt/signal/unregister/function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <functional>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
fcppt::signal::object<
	void (),
	fcppt::signal::unregister::base
>
signal_type;

}

TEST_CASE(
	"signal unregister",
	"[signal]"
)
{
	std::vector<
		int
	> values{};

	signal_type::function const empty_function{
		[]{}
	};

	auto const unregister(
		[
			&values
		](
			int const _value
		)
		{
			values.push_back(
				_value
			);
		}
	);

	signal_type sig;

	{
		fcppt::signal::auto_connection const con1(
			sig.connect(
				empty_function,
				fcppt::signal::unregister::function{
					std::bind(
						unregister,
						42
					)
				}
			)
		);
	}

	REQUIRE(
		values.size()
		==
		1u
	);

	CHECK(
		values.back()
		==
		42
	);

	{
		fcppt::signal::auto_connection const con2(
			sig.connect(
				empty_function,
				fcppt::signal::unregister::function{
					std::bind(
						unregister,
						100
					)
				}
			)
		);
	}

	REQUIRE(
		values.size()
		==
		2u
	);

	CHECK(
		values.back()
		==
		100
	);
}

TEST_CASE(
	"signal unregister move",
	"[signals]"
)
{
	signal_type sig{};

	bool done{
		false
	};

	bool unregistered{
		false
	};

	{
		fcppt::signal::auto_connection const con1(
			sig.connect(
				signal_type::function{
					[
						&done
					]{
						done = true;
					}
				},
				fcppt::signal::unregister::function{
					[
						&unregistered
					]
					{
						unregistered = true;
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
			sig.empty()
		);

		sig2();

		CHECK(
			done
		);
	}

	CHECK(
		unregistered
	);
}
