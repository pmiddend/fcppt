//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_STATE_DECL_HPP_INCLUDED
#define FCPPT_PARSE_STATE_DECL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <istream>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Ch
>
class state
{
public:
	typedef
	std::basic_istream<
		Ch
	>
	stream_type;

	explicit
	state(
		fcppt::reference<
			stream_type
		>
	);

	stream_type &
	stream() const;
private:
	fcppt::reference<
		stream_type
	> stream_;
};

}
}

#endif
