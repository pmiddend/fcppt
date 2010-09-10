//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_IFSTREAM_HPP_INCLUDED
#define FCPPT_IO_IFSTREAM_HPP_INCLUDED

#include <fcppt/filesystem/config.hpp>
#include <fcppt/char_type.hpp>
#include <boost/filesystem/fstream.hpp>

namespace fcppt
{
namespace io
{

typedef boost::filesystem::basic_ifstream<
	char_type
> ifstream;

}
}

#endif
