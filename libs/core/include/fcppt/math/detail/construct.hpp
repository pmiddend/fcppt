//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_CONSTRUCT_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_CONSTRUCT_HPP_INCLUDED

#include <fcppt/use.hpp>
#include <fcppt/algorithm/array_init.hpp>
#include <fcppt/algorithm/array_push_back.hpp>
#include <fcppt/math/at_c.hpp>
#include <fcppt/math/from_array.hpp>
#include <fcppt/math/detail/assert_static_storage.hpp>
#include <fcppt/math/detail/static_storage_impl.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Dest,
	typename Src
>
inline
Dest
construct(
	Src const &_src,
	typename Src::value_type const &_value
)
{
	static_assert(
		Dest::static_size::value
		==
		Src::static_size::value
		+
		1u,
		""
	);

	FCPPT_MATH_DETAIL_ASSERT_STATIC_STORAGE(
		typename
		Dest::storage_type
	);

	typedef
	fcppt::math::detail::static_storage<
		typename
		Src::value_type,
		Src::static_size::value
	>
	src_storage;

	return
		fcppt::math::from_array<
			Dest
		>(
			fcppt::algorithm::array_push_back(
				fcppt::algorithm::array_init<
					typename
					src_storage::array_type
				>(
					[
						&_src
					](
						auto const _index
					)
					{
						FCPPT_USE(
							_index
						);

						return
							fcppt::math::at_c<
								_index()
							>(
								_src
							);
					}
				),
				_value
			)
		);
}

}
}
}

#endif
