//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DETAIL_AUTO_CONTEXT_HPP_INCLUDED
#define FCPPT_LOG_DETAIL_AUTO_CONTEXT_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/optional_context_location.hpp>
#include <fcppt/log/detail/auto_context_fwd.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/format/const_object_ptr.hpp>


namespace fcppt
{
namespace log
{
namespace detail
{

class auto_context
{
	FCPPT_NONCOPYABLE(
		auto_context
	);
public:
	auto_context(
		fcppt::log::optional_context_location const &,
		fcppt::log::object &
	);

	~auto_context();

	fcppt::log::detail::context_tree const *
	node() const;
private:
	fcppt::log::context *const context_;

	fcppt::log::detail::context_tree *const node_;
};

}
}
}

#endif
