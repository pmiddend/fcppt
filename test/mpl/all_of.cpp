//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/mpl/all_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


int
main()
{
	static_assert(
		fcppt::mpl::all_of<
			boost::mpl::vector2<
				int,
				long
			>,
			std::is_integral<
				boost::mpl::_1
			>
		>::value,
		""
	);

	static_assert(
		!fcppt::mpl::all_of<
			boost::mpl::vector2<
				float,
				int
			>,
			std::is_integral<
				boost::mpl::_1
			>
		>::value,
		""
	);
}
