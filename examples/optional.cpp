//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional/bind.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace
{

//! [optional_example_bad]
void
optional_example_bad(
	fcppt::optional::object<
		unsigned
	> const _opt
)
{
	if(
		_opt.has_value()
	)
		std::cout
			<< _opt.get_unsafe()
			<< '\n';
	else
		std::cout
			<< "No value\n";
}
//! [optional_example_bad]

//! [optional_example_good]
void
optional_example_good(
	fcppt::optional::object<
		unsigned
	> const _opt
)
{
	fcppt::optional::maybe(
		_opt,
		[]{
			std::cout
				<< "No value\n";
		},
		[](
			unsigned const _val
		)
		{
			std::cout
				<< _val
				<< '\n';
		}
	);
}
//! [optional_example_good]

void
optional_copy()
{
//! [optional_copy]
	typedef fcppt::optional::object<
		unsigned
	> optional_uint;

	unsigned int1{
		5u
	};

	// opt takes a copy of int1
	optional_uint opt{
		int1
	};

	int1 = 10u;

	// The value of opt will still be 5u
	std::cout << (opt != optional_uint{int1}) << '\n';
//! [optional_copy]
}

void
optional_bind()
{
//! [optional_bind]
	typedef fcppt::optional::object<
		unsigned
	> optional_uint;

	typedef fcppt::optional::object<
		std::string
	> optional_string;

	optional_string const value{
		fcppt::optional::bind(
			optional_uint{3u},
			[](
				unsigned const _val
			)
			{
				return
					optional_string(
						std::to_string(
							_val
						)
					);
			}
		)
	};

	std::cout << (value == optional_string{"3"}) << '\n';
//! [optional_bind]

//! [optional_map]
	optional_string const value2{
		fcppt::optional::map(
			optional_uint{3u},
			[](
				unsigned const _val
			)
			{
				return
					std::to_string(
						_val
					);
			}
		)
	};

	std::cout << (value == optional_string{"3"}) << '\n';
//! [optional_map]
}

void
from_optional()
{
//! [from_optional]
	typedef
	fcppt::optional::object<
		unsigned
	>
	optional_uint;

	unsigned const value{
		fcppt::optional::from(
			optional_uint(),
			[]{
				return
					42u;
			}
		)
	};

	std::cout << (value == 42u) << '\n';
//! [from_optional]
}

}

int
main()
{
	optional_example_bad(
		fcppt::optional::object<
			unsigned
		>(
			0
		)
	);

	optional_example_good(
		fcppt::optional::object<
			unsigned
		>(
			0
		)
	);

	optional_copy();

	optional_bind();

	from_optional();
}
