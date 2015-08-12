//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional_combine.hpp>
#include <fcppt/string.hpp>
#include <fcppt/log/format/chain.hpp>
#include <fcppt/log/format/function.hpp>
#include <fcppt/log/format/optional_function.hpp>


fcppt::log::format::optional_function
fcppt::log::format::chain(
	fcppt::log::format::optional_function const &_parent,
	fcppt::log::format::optional_function const &_child
)
{
	return
		fcppt::optional_combine(
			_parent,
			_child,
			[](
				fcppt::log::format::function const &_func1,
				fcppt::log::format::function const &_func2
			)
			{
				return
					fcppt::log::format::function(
						[
							_func1,
							_func2
						](
							fcppt::string const &_arg
						)
						{
							return
								_func1(
									_func2(
										_arg
									)
								);
						}
					);
			}
		);
}
