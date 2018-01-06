//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ALGORITHM_DETAIL_SOURCE_SIZE_HPP_INCLUDED
#define FCPPT_ALGORITHM_DETAIL_SOURCE_SIZE_HPP_INCLUDED

#include <fcppt/public_config.hpp>
#include <fcppt/algorithm/detail/mpl_size_type.hpp>
#include <fcppt/container/size.hpp>
#include <fcppt/container/size_result_type.hpp>
#include <fcppt/type_traits/is_brigand_sequence.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/size.hpp>
#if defined(FCPPT_BOOST_SUPPORT)
#include <boost/mpl/is_sequence.hpp>
#include <boost/mpl/size.hpp>
#endif
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace algorithm
{
namespace detail
{

template<
	typename Source,
	typename Enable = void
>
struct source_size
{
	static
	fcppt::container::size_result_type<
		Source
	>
	get(
		Source const &_source
	)
	{
		return
			fcppt::container::size(
				_source
			);
	}
};

template<
	typename Source
>
struct source_size<
	Source,
	typename
	std::enable_if<
		fcppt::type_traits::is_brigand_sequence<
			Source
		>::value
	>::type
>{
	static
	typename
	fcppt::algorithm::detail::mpl_size_type<
		Source
	>::type
	get(
		Source const &
	)
	{
		return
			::brigand::size<
				Source
			>::value;
	}
};

#if defined(FCPPT_BOOST_SUPPORT)
template<
	typename Source
>
struct source_size<
	Source,
	typename
	std::enable_if<
		boost::mpl::is_sequence<
			Source
		>::value
	>::type
>{
	static
	typename
	fcppt::algorithm::detail::mpl_size_type<
		Source
	>::type
	get(
		Source const &
	)
	{
		return
			boost::mpl::size<
				Source
			>::value;
	}
};
#endif

}
}
}

#endif
