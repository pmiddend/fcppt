//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/metal/as_tuple.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/list/list.hpp>
#include <tuple>
#include <fcppt/config/external_end.hpp>


int
main()
{
	static_assert(
		std::is_same<
			fcppt::metal::as_tuple<
				metal::list<
					int,
					float
				>
			>,
			std::tuple<
				int,
				float
			>
		>::value,
		""
	);
}
