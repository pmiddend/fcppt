//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_IS_STATIC_ROW_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_IS_STATIC_ROW_HPP_INCLUDED

#include <fcppt/type_traits/is_std_array.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{

/**
\brief Checks if a type is an #fcppt::container::grid::static_row.

\ingroup fcpptcontainergrid
*/
template<
	typename Type
>
using
is_static_row
=
fcppt::type_traits::is_std_array<
	Type
>;

}
}
}

#endif
