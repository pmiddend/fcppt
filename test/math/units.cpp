//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/is_zero_boost_units.hpp>
#include <fcppt/math/vector/arithmetic.hpp>
#include <fcppt/math/vector/comparison.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/optional/comparison.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/time.hpp>
#include <boost/units/systems/si/velocity.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math units",
	"[math]"
)
{
	typedef
	int
	unit_type;

	typedef
	boost::units::quantity<
		boost::units::si::length,
		unit_type
	>
	length;

	typedef
	boost::units::quantity<
		boost::units::si::time,
		unit_type
	>
	time;

	typedef
	boost::units::quantity<
		boost::units::si::velocity,
		unit_type
	>
	velocity;

	typedef
	fcppt::math::vector::static_<
		length,
		2
	>
	length2;

	typedef
	fcppt::math::vector::static_<
		time,
		2
	>
	time2;

	typedef
	fcppt::math::vector::static_<
		velocity,
		2
	>
	velocity2;

	length2 const l1(
		length(
			-100
			*
			boost::units::si::meter
		),
		length(
			200
			*
			boost::units::si::meter
		)
	);

	time2 const t1(
		time(
			4
			*
			boost::units::si::second
		),
		time(
			2
			*
			boost::units::si::second
		)
	);

	CHECK(
		l1
		/
		t1
		==
		fcppt::optional::make(
			velocity2{
				-25
				*
				boost::units::si::meter
				/
				boost::units::si::second
				,
				100
				*
				boost::units::si::meter
				/
				boost::units::si::second
			}
		)
	);
}
