//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/assert_complete.hpp>

namespace
{

//! [assert_complete]
template<
	typename T
>
void
std_delete(
	T *const _param
)
{
	FCPPT_ASSERT_COMPLETE(
		T
	);

	delete _param;
}
//! [assert_complete]

struct complete
{
};

}

int main()
{
	complete *const ptr(
		new complete
	);

	std_delete(
		ptr
	);
}
