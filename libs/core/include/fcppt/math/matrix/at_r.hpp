//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_AT_R_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_AT_R_HPP_INCLUDED

#include <fcppt/container/to_reference_type.hpp>
#include <fcppt/math/size_type.hpp>
#include <fcppt/math/detail/checked_access.hpp>
#include <fcppt/math/matrix/is_matrix.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

/**
\brief Access a row using a compile-time constant

\ingroup fcpptmathmatrix

\tparam Matrix Must be an #fcppt::math::matrix::object.
*/
template<
	fcppt::math::size_type Index,
	typename Matrix
>
inline
fcppt::container::to_reference_type<
	std::remove_reference_t<
		Matrix
	>
>
at_r(
	Matrix &_value
)
{
	static_assert(
		fcppt::math::matrix::is_matrix<
			std::remove_cv_t<
				Matrix
			>
		>::value,
		"Matrix must be a matrix"
	);

	return
		fcppt::math::detail::checked_access<
			Index
		>(
			_value
		);
}

}
}
}

#endif
