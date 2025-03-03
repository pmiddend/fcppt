//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_GET_HPP_INCLUDED
#define FCPPT_RECORD_GET_HPP_INCLUDED

#include <fcppt/record/label_value_type.hpp>
#include <fcppt/record/object_impl.hpp>


namespace fcppt
{
namespace record
{

/**
\brief Gets an element from a record

\ingroup fcpptrecord

Returns the element identified by \a Label from \a _arg.
*/
template<
	typename Label,
	typename Types
>
inline
fcppt::record::label_value_type<
	fcppt::record::object<
		Types
	>,
	Label
> const &
get(
	fcppt::record::object<
		Types
	> const &_arg
)
{
	return
		_arg. template get<
			Label
		>();
}

/**
\brief Gets an element from a record

\ingroup fcpptrecord

Returns the element identified by \a Label from \a _arg.
*/
template<
	typename Label,
	typename Types
>
inline
fcppt::record::label_value_type<
	fcppt::record::object<
		Types
	>,
	Label
> &
get(
	fcppt::record::object<
		Types
	> &_arg
)
{
	return
		_arg. template get<
			Label
		>();
}

}
}

#endif
