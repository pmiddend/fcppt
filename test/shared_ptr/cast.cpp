//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/const_pointer_cast.hpp>
#include <fcppt/dynamic_pointer_cast.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/static_pointer_cast.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

struct base
{
	virtual
	~base()
	{
	}
};

struct derived
:
	base
{
};

typedef
fcppt::shared_ptr<
	base
>
base_ptr;

typedef
fcppt::shared_ptr<
	derived
>
derived_ptr;

}

TEST_CASE(
	"dynamic_pointer_cast",
	"[smartptr]"
)
{
	base_ptr const ptr(
		fcppt::make_shared_ptr<
			derived
		>()
	);

	{
		fcppt::optional::object<
			derived_ptr
		> const ptr2(
			fcppt::dynamic_pointer_cast<
				derived
			>(
				ptr
			)
		);

		CHECK(
			ptr2.has_value()
		);

		fcppt::optional::maybe(
			ptr2,
			[]{
				CHECK(
					false
				);
			},
			[
				&ptr
			](
				derived_ptr const &_ptr2
			)
			{
				CHECK(
					ptr.use_count()
					==
					_ptr2.use_count()
				);
			}
		);
	}

	CHECK(
		ptr.use_count()
		==
		1l
	);
}

TEST_CASE(
	"static_pointer_cast",
	"[smartptr]"
)
{
	base_ptr const ptr(
		fcppt::make_shared_ptr<
			derived
		>()
	);

	{
		derived_ptr const ptr2(
			fcppt::static_pointer_cast<
				derived
			>(
				ptr
			)
		);

		CHECK(
			ptr.use_count()
			==
			ptr2.use_count()
		);
	}

	CHECK(
		ptr.use_count()
		==
		1l
	);
}

TEST_CASE(
	"const_pointer_cast",
	"[smartptr]"
)
{
	typedef
	fcppt::shared_ptr<
		base const
	>
	const_base_ptr;

	const_base_ptr const ptr(
		fcppt::make_shared_ptr<
			base
		>()
	);

	{
		base_ptr const ptr2(
			fcppt::const_pointer_cast<
				base
			>(
				ptr
			)
		);

		CHECK(
			ptr.use_count()
			==
			ptr2.use_count()
		);
	}

	CHECK(
		ptr.use_count()
		==
		1l
	);
}
