//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/noncopyable.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/set.hpp>
#include <fcppt/record/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"record::object",
	"[record]"
)
{
	class copy_only
	{
	public:
		explicit
		copy_only(
			int const _value
		)
		:
			value_(
				_value
			)
		{
		}

		copy_only(
			copy_only const &
		) = default;

		int
		value() const
		{
			return
				value_;
		}
	private:
		int value_;
	};

	class move_only
	{
		FCPPT_NONCOPYABLE(
			move_only
		);
	public:
		explicit
		move_only(
			int const _value
		)
		:
			value_{
				_value
			},
			valid_{
				true
			}
		{
		}

		move_only(
			move_only &&_other
		)
		:
			value_{
				_other.value_
			},
			valid_{
				_other.valid_
			}
		{
			_other.valid_ =
				false;
		}

		move_only &
		operator=(
			move_only &&_other
		)
		{
			value_ =
				_other.value_;

			valid_ =
				_other.valid_;

			_other.valid_ =
				false;

			return
				*this;
		}

		~move_only()
		{
		}

		int
		value() const
		{
			CHECK(
				valid_
			);

			return
				value_;
		}
	private:
		int value_;

		bool valid_;
	};

	FCPPT_RECORD_MAKE_LABEL(
		int_label
	);

	FCPPT_RECORD_MAKE_LABEL(
		bool_label
	);

	FCPPT_RECORD_MAKE_LABEL(
		copy_only_label
	);

	FCPPT_RECORD_MAKE_LABEL(
		move_only_label
	);

	typedef
	fcppt::record::variadic<
		fcppt::record::element<
			int_label,
			int
		>,
		fcppt::record::element<
			bool_label,
			bool
		>,
		fcppt::record::element<
			copy_only_label,
			copy_only
		>,
		fcppt::record::element<
			move_only_label,
			move_only
		>
	>
	my_record;

	int const arg1{
		4
	};

	my_record test{
		int_label{} =
			arg1,
		bool_label{} =
			true,
		copy_only_label{} =
			copy_only(
				42
			),
		move_only_label{} =
			move_only{
				10
			}
	};

	CHECK(
		fcppt::record::get<
			int_label
		>(
			test
		)
		==
		4
	);

	CHECK(
		fcppt::record::get<
			bool_label
		>(
			test
		)
	);

	CHECK(
		fcppt::record::get<
			copy_only_label
		>(
			test
		).value()
		==
		42
	);

	CHECK(
		fcppt::record::get<
			move_only_label
		>(
			test
		).value()
		==
		10
	);

	my_record test2(
		std::move(
			test
		)
	);

	CHECK(
		fcppt::record::get<
			int_label
		>(
			test2
		)
		==
		4
	);

	CHECK(
		fcppt::record::get<
			bool_label
		>(
			test2
		)
	);

	CHECK(
		fcppt::record::get<
			move_only_label
		>(
			test2
		).value()
		==
		10
	);

	fcppt::record::set<
		bool_label
	>(
		test2,
		false
	);

	CHECK_FALSE(
		fcppt::record::get<
			bool_label
		>(
			test2
		)
	);

	fcppt::record::set<
		move_only_label
	>(
		test2,
		move_only{
			100
		}
	);

	CHECK(
		fcppt::record::get<
			move_only_label
		>(
			test2
		).value()
		==
		100
	);

	fcppt::record::get<
		int_label
	>(
		test2
	) =
		42;

	CHECK(
		fcppt::record::get<
			int_label
		>(
			test2
		)
		==
		42
	);
}
