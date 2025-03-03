//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_COPY_VALUE_HPP_INCLUDED
#define FCPPT_OPTIONAL_COPY_VALUE_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief Copies the value of an optional reference

\ingroup fcpptoptional
*/
template<
	typename Type
>
fcppt::optional::object<
	std::remove_cv_t<
		Type
	>
>
copy_value(
	fcppt::optional::reference<
		Type
	> const &_opt
)
{
	return
		fcppt::optional::map(
			_opt,
			[](
				fcppt::reference<
					Type
				> const _ref
			)
			{
				return
					_ref.get();
			}
		);
}

}
}

#endif
