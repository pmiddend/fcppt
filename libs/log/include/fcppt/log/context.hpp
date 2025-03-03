//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_CONTEXT_HPP_INCLUDED
#define FCPPT_LOG_CONTEXT_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/log/const_level_stream_array_ref.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/level_stream_array.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/name_fwd.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/optional_level_fwd.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <mutex>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace log
{

/**
\brief A logger context manages log levels

\ingroup fcpptlog
*/
class context
{
	FCPPT_NONCOPYABLE(
		context
	);
public:
	/**
	\brief Constructs a context

	\param root The root log level which will be the default for new log locations

	\param streams The stream sinks to use for all log locations
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	context(
		fcppt::log::optional_level const &root,
		fcppt::log::level_stream_array const &streams
	);

	FCPPT_LOG_DETAIL_SYMBOL
	~context();

	/**
	\brief Updates the log level at a location

	Note that every location below is also updated.
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	void
	set(
		fcppt::log::location const &,
		fcppt::log::optional_level const &
	);

	/**
	\brief Gets the current log level for a location
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	fcppt::log::optional_level
	get(
		fcppt::log::location const &
	) const;

	/**
	\brief The level streams of this context
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	fcppt::log::const_level_stream_array_ref
	level_streams() const;
private:
	typedef
	std::lock_guard<
		std::mutex
	>
	lock_guard;

	fcppt::log::detail::context_tree const &
	root() const;

	static
	fcppt::log::detail::context_tree &
	cast_tree(
		fcppt::log::detail::context_tree const &,
		lock_guard const &
	);

	fcppt::log::detail::context_tree const &
	find_location(
		fcppt::log::location const &
	);

	fcppt::log::detail::context_tree const &
	find_location_impl(
		fcppt::log::location const &,
		lock_guard const &
	);

	fcppt::log::detail::context_tree const &
	find_child(
		fcppt::log::detail::context_tree const &,
		fcppt::log::name const &
	);

	friend class fcppt::log::object;

	mutable std::mutex mutex_;

	fcppt::log::detail::context_tree tree_;

	fcppt::log::level_stream_array const streams_;
};

}
}

#endif
