//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_STRINGSTREAM_HPP_INCLUDED
#define FCPPT_IO_STRINGSTREAM_HPP_INCLUDED

#include <fcppt/char_type.hpp>
#include <sstream>

namespace fcppt
{
namespace io
{

typedef std::basic_stringstream<
	char_type
> stringstream;

}
}

#endif
