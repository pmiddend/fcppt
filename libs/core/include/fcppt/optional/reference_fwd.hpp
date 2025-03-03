//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_REFERENCE_FWD_HPP_INCLUDED
#define FCPPT_OPTIONAL_REFERENCE_FWD_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/optional/object_fwd.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief Optional of a reference

\ingroup fcpptoptional
*/
template<
	typename T
>
using
reference
=
fcppt::optional::object<
	fcppt::reference<
		T
	>
>;

}
}

#endif
