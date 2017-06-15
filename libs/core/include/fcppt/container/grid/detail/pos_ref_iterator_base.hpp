//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GRID_DETAIL_POS_REF_ITERATOR_BASE_HPP_INCLUDED
#define FCPPT_CONTAINER_GRID_DETAIL_POS_REF_ITERATOR_BASE_HPP_INCLUDED

#include <fcppt/container/grid/pos_ref_iterator_fwd.hpp>
#include <fcppt/container/grid/pos_reference_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace grid
{
namespace detail
{

template<
	typename Grid
>
using pos_ref_iterator_base
=
boost::iterator_facade<
	fcppt::container::grid::pos_ref_iterator<
		Grid
	>,
	typename
	Grid::value_type,
	std::forward_iterator_tag,
	fcppt::container::grid::pos_reference<
		Grid
	>,
	typename
	Grid::difference_type
>;

}
}
}
}

#endif
