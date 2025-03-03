//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_LABEL_IMPL_HPP_INCLUDED
#define FCPPT_RECORD_LABEL_IMPL_HPP_INCLUDED

#include <fcppt/record/label_decl.hpp>
#include <fcppt/record/detail/element_init_impl.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Tag
>
template<
	typename Arg
>
fcppt::record::detail::element_init<
	Tag,
	fcppt::type_traits::remove_cv_ref_t<
		Arg
	>
>
fcppt::record::label<
	Tag
>::operator=(
	Arg &&_arg
)
{
	return
		fcppt::record::detail::element_init<
			Tag,
			fcppt::type_traits::remove_cv_ref_t<
				Arg
			>
		>(
			std::forward<
				Arg
			>(
				_arg
			)
		);
}

#endif
