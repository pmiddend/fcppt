//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_VARIANT_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/variant/object_decl.hpp>
#include <fcppt/variant/size_type.hpp>
#include <fcppt/variant/detail/get_unsafe_impl.hpp>
#include <fcppt/variant/detail/has_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <variant>
#include <fcppt/config/external_end.hpp>


template<
	typename Types
>
template<
	typename U
>
fcppt::variant::object<
	Types
>::object(
	U const &_other
)
:
	impl_{
		_other
	}
{
	static_assert(
		fcppt::variant::detail::has_type<
			Types,
			U
		>::value,
		"Invalid variant type"
	);
}

template<
	typename Types
>
template<
	typename U,
	typename
>
fcppt::variant::object<
	Types
>::object(
	U &&_other
)
:
	impl_{
		std::move(
			_other
		)
	}
{
	static_assert(
		fcppt::variant::detail::has_type<
			Types,
			fcppt::type_traits::remove_cv_ref_t<
				U
			>
		>::value,
		"Invalid variant type"
	);
}

template<
	typename Types
>
template<
	typename U
>
U &
fcppt::variant::object<
	Types
>::get_unsafe()
{
	return
		fcppt::variant::detail::get_unsafe_impl<
			Types,
			U
		>(
			this->impl_
		);
}

template<
	typename Types
>
template<
	typename U
>
U const &
fcppt::variant::object<
	Types
>::get_unsafe() const
{
	return
		fcppt::variant::detail::get_unsafe_impl<
			Types,
			U
		>(
			this->impl_
		);
}

template<
	typename Types
>
fcppt::variant::size_type
fcppt::variant::object<
	Types
>::type_index() const
{
	return
		this->impl_.index();
}

template<
	typename Types
>
bool
fcppt::variant::object<
	Types
>::is_invalid() const
{
	return
		this->type_index()
		==
		std::variant_npos;
}

template<
	typename Types
>
typename
fcppt::variant::object<
	Types
>::std_type &
fcppt::variant::object<
	Types
>::impl()
{
	return
		this->impl_;
}

template<
	typename Types
>
typename
fcppt::variant::object<
	Types
>::std_type const &
fcppt::variant::object<
	Types
>::impl() const
{
	return
		this->impl_;
}

#endif
