//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/cast/float_to_int_fun.hpp>
#include <fcppt/math/vector/output.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/math/vector/structure_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>


namespace
{

void
float_to_int()
{
// ![float_to_int_fun]
	typedef
	fcppt::math::vector::static_<
		float,
		2
	>
	vec_2f;

	typedef
	fcppt::math::vector::static_<
		int,
		2
	>
	vec_2i;

	auto const res(
		fcppt::math::vector::structure_cast<
			vec_2i,
			fcppt::cast::float_to_int_fun
		>(
			vec_2f(
				1.f,
				2.f
			)
		)
	);

	std::cout
		<< res
		<< '\n';
// ![float_to_int_fun]
}

}

int
main()
{
	float_to_int();
}
