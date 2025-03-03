//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/math/box/comparison.hpp>
#include <fcppt/math/box/object_impl.hpp>
#include <fcppt/math/box/output.hpp>
#include <fcppt/math/box/stretch_absolute.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"math::box::stretch_absolute",
	"[math],[box]"
)
{
	typedef
	fcppt::math::box::object<
		int,
		2
	>
	signed_box_type;

	CHECK(
		fcppt::math::box::stretch_absolute(
			signed_box_type{
				signed_box_type::vector(
					10,
					12
				),
				signed_box_type::dim(
					24,
					26
				)
			},
			signed_box_type::vector(
				2,
				5
			)
		)
		==
		signed_box_type(
			signed_box_type::vector(
				8,
				7
			),
			signed_box_type::dim(
				28,
				36
			)
		)
	);
}
