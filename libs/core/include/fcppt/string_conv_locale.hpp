//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRING_CONV_LOCALE_HPP_INCLUDED
#define FCPPT_STRING_CONV_LOCALE_HPP_INCLUDED

#include <fcppt/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Returns the default locale to use when converting strings

\ingroup fcpptstring
*/
FCPPT_DETAIL_SYMBOL
std::locale
string_conv_locale();

}

#endif
