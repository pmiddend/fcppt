//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/metal/from_number.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/number/number.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


int
main()
{
	static_assert(
		std::is_same_v<
			fcppt::metal::from_number<
				int,
				metal::number<
					5
				>
			>,
			std::integral_constant<
				int,
				5
			>
		>
	);
}
