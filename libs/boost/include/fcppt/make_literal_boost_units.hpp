//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MAKE_LITERAL_BOOST_UNITS_HPP_INCLUDED
#define FCPPT_MAKE_LITERAL_BOOST_UNITS_HPP_INCLUDED

#include <fcppt/check_literal_conversion.hpp>
#include <fcppt/make_literal_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/units/dimensionless_type.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/unit.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Literal specialization for boost.units

\ingroup fcpptboost
*/
template<
	typename Unit,
	typename Type
>
struct make_literal<
	boost::units::quantity<
		Unit,
		Type
	>
>
{
	typedef
	boost::units::quantity<
		boost::units::unit<
			boost::units::dimensionless_type,
			typename
			Unit::system_type
		>,
		Type
	>
	decorated_type;

	template<
		typename Fundamental
	>
	static
	decorated_type
	get(
		Fundamental const _fundamental
	)
	{
		FCPPT_CHECK_LITERAL_CONVERSION(
			Type,
			Fundamental
		);

		return
			decorated_type::from_value(
				static_cast<
					Type
				>(
					_fundamental
				)
			);
	}
};

}

#endif
