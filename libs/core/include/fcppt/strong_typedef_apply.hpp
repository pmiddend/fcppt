//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRONG_TYPEDEF_APPLY_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_APPLY_HPP_INCLUDED

#include <fcppt/is_strong_typedef.hpp>
#include <fcppt/move_if_rvalue.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/strong_typedef_tag.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/lambda/always.hpp>
#include <metal/lambda/bind.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/trait.hpp>
#include <metal/list/all_of.hpp>
#include <metal/list/list.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Applies a function to multiple strong typedefs.

\ingroup fcpptstrongtypedef

Returns a strong typedef with the same tag type and value
<code>_function(_strong_typedef.get(), _strongs_typedefs.get()...)</code>.

\tparam StrongTypedef1 Must be an #fcppt::strong_typedef.

\tparam StrongTypedefs Must all be #fcppt::strong_typedef.

\tparam Function Must be a function callable as
<code>R (StrongTypedef1::value_type, StrongTypedefs::value_type...)</code>,
where <code>R</code> is the result type.
*/
template<
	typename StrongTypedef1,
	typename Function,
	typename... StrongTypedefs
>
inline
auto
strong_typedef_apply(
	Function const &_function,
	StrongTypedef1 &&_strong_typedef1,
	StrongTypedefs &&... _strong_typedefs
)
->
fcppt::strong_typedef<
	decltype(
		_function(
			fcppt::move_if_rvalue<
				StrongTypedef1
			>(
				_strong_typedef1.get()
			),
			fcppt::move_if_rvalue<
				StrongTypedefs
			>(
				_strong_typedefs.get()
			)...
		)
	),
	fcppt::strong_typedef_tag<
		fcppt::type_traits::remove_cv_ref_t<
			StrongTypedef1
		>
	>
>
{
	typedef
	fcppt::type_traits::remove_cv_ref_t<
		StrongTypedef1
	>
	strong_typedef1;

	static_assert(
		fcppt::is_strong_typedef<
			strong_typedef1
		>::value,
		"StrongTypedef1 must be a strong typedef"
	);

	typedef
	::metal::list<
		fcppt::type_traits::remove_cv_ref_t<
			StrongTypedefs
		>...
	>
	strong_typedefs;

	typedef
	fcppt::strong_typedef_tag<
		strong_typedef1
	>
	input_tag;

	static_assert(
		::metal::all_of<
			strong_typedefs,
			::metal::trait<
				fcppt::is_strong_typedef
			>
		>::value,
		"StrongTypedefs must all be strong typedefs"
	);

	static_assert(
		::metal::all_of<
			strong_typedefs,
			::metal::bind<
				::metal::trait<
					std::is_same
				>,
				::metal::always<
					input_tag
				>,
				::metal::lambda<
					fcppt::strong_typedef_tag
				>
			>
		>::value,
		"All strong typedefs must have the same tag type"
	);

	return
		fcppt::strong_typedef<
			decltype(
				_function(
					fcppt::move_if_rvalue<
						StrongTypedef1
					>(
						_strong_typedef1.get()
					),
					fcppt::move_if_rvalue<
						StrongTypedefs
					>(
						_strong_typedefs.get()
					)...
				)
			),
			input_tag
		>(
			_function(
				fcppt::move_if_rvalue<
					StrongTypedef1
				>(
					_strong_typedef1.get()
				),
				fcppt::move_if_rvalue<
					StrongTypedefs
				>(
					_strong_typedefs.get()
				)...
			)
		);
}

}

#endif
