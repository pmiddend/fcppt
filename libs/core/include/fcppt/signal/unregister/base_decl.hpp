//          Copyright Carl Philipp Reh 2009 - 2017.
//          Copyright Philipp Middendorf 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SIGNAL_UNREGISTER_BASE_DECL_HPP_INCLUDED
#define FCPPT_SIGNAL_UNREGISTER_BASE_DECL_HPP_INCLUDED

#include <fcppt/function.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/intrusive/list_decl.hpp>
#include <fcppt/signal/auto_connection_fwd.hpp>
#include <fcppt/signal/unregister/base_fwd.hpp>
#include <fcppt/signal/unregister/function.hpp>
#include <fcppt/signal/unregister/detail/concrete_connection_fwd.hpp>


namespace fcppt
{
namespace signal
{
namespace unregister
{

/**
\brief A base class for signals providing unlinking.
\tparam T The signal's function type
\ingroup fcpptsignal

See the \link fcpptsignal module documentation \endlink for more information on
unlinking.
*/
template<
	typename T
>
class base
{
	FCPPT_NONCOPYABLE(
		base
	);
public:
	/**
	\brief A typedef for the function's return type
	*/
	typedef
	T
	function_signature;

	/**
	\brief A typedef for the wrapped function
	*/
	typedef
	fcppt::function<
		T
	>
	function;

	/**
	\brief Connect a callback to this signal
	*/
	fcppt::signal::auto_connection
	connect(
		function const &,
		fcppt::signal::unregister::function const &
	);

	/**
	\brief Return if the signal has connections attached to it.
	*/
	bool
	empty() const;
protected:
	typedef
	fcppt::signal::unregister::detail::concrete_connection<
		function_signature
	>
	concrete_connection;

	typedef
	fcppt::intrusive::list<
		concrete_connection
	>
	connection_list;

	base();

	base(
		base &&
	);

	base &
	operator=(
		base &&
	);

	~base();

	connection_list &
	connections() const;
private:
	mutable connection_list connections_;
};

}
}
}

#endif
