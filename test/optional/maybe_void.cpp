//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_ref.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/unique_ptr.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"optional::maybe_void",
	"[optional]"
)
{
	typedef
	fcppt::optional::object<
		int
	>
	optional_int;

	int result{
		0
	};

	fcppt::optional::maybe_void(
		optional_int(
			10
		),
		[
			&result
		](
			int const _val
		)
		{
			result =
				_val;
		}
	);

	CHECK(
		result
		==
		10
	);

	fcppt::optional::maybe_void(
		optional_int(),
		[
			&result
		](
			int const _val
		)
		{
			result =
				_val;
		}
	);

	CHECK(
		result
		==
		10
	);

	optional_int temp(
		0
	);

	fcppt::optional::maybe_void(
		temp,
		[](
			int &_val
		)
		{
			_val = 30;
		}
	);

	CHECK(
		temp
		==
		optional_int(
			30
		)
	);
}

TEST_CASE(
	"optional::maybe_void ref",
	"[optional]"
)
{
	int result{
		0
	};

	typedef
	fcppt::optional::reference<
		int
	>
	optional_int_ref;

	fcppt::optional::maybe_void(
		optional_int_ref{
			fcppt::make_ref(
				result
			)
		},
		[](
			fcppt::reference<
				int
			> const _val
		)
		{
			_val.get() = 42;
		}
	);

	CHECK(
		result
		==
		42
	);
}

TEST_CASE(
	"optional::maybe_void move",
	"[optional]"
)
{
	typedef
	fcppt::unique_ptr<
		int
	>
	int_unique_ptr;

	typedef
	fcppt::optional::object<
		int_unique_ptr
	>
	optional_int_unique_ptr;

	fcppt::optional::maybe_void(
		optional_int_unique_ptr(
			fcppt::make_unique_ptr<
				int
			>(
				42
			)
		),
		[](
			int_unique_ptr &&_ptr
		)
		{
			CHECK(
				*_ptr
				==
				42
			);
		}
	);
}
