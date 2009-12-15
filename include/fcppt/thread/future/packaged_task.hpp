#ifndef FCPPT_THREAD_FUTURE_PACKAGED_TASK_HPP_INCLUDED
#define FCPPT_THREAD_FUTURE_PACKAGED_TASK_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/thread/future/detail/task_object.hpp>
#include <fcppt/thread/future/task_moved.hpp>
#include <fcppt/thread/future/already_retrieved.hpp>
#include <fcppt/thread/future/unique_object.hpp>

namespace fcppt
{
namespace thread
{
namespace future
{
template<typename T>
class packaged_task
{
//FCPPT_NONCOPYABLE(packaged_task)
private:
	packaged_task(
		packaged_task &);
	packaged_task &operator=(
		packaged_task &);
public:
	template<class F>
	explicit packaged_task(
		F const &);

	template<class F>
	explicit packaged_task(
		boost::detail::thread_move_t<F>);

	packaged_task(
		boost::detail::thread_move_t<packaged_task>);

	packaged_task &operator=(
		boost::detail::thread_move_t<packaged_task>);

	void swap(
		packaged_task &);

	unique_object<T> object();

	void operator()();
private:
	typedef fcppt::shared_ptr<detail::task_base<T> > task_ptr;
	task_ptr task_;
	bool future_obtained_;
};
}
}
}

template<typename T>
template<class F>
fcppt::thread::future::packaged_task<T>::packaged_task(
	F const &_f)
:
	task_(
		new detail::task_object<T,F>(
			_f)),
	future_obtained_(
		false)
{
}

template<typename T>
template<class F>
fcppt::thread::future::packaged_task<T>::packaged_task(
	boost::detail::thread_move_t<F> _f)
:
	task_(
		new detail::task_object<T,F>(
			_f)),
	future_obtained_(
		false)
{
}

template<typename T>
fcppt::thread::future::packaged_task<T>::packaged_task(
	boost::detail::thread_move_t<packaged_task> _f)
:
	future_obtained_(
		_f->future_obtained_)
{
	task_.swap(
		_f->task_);
}

template<typename T>
fcppt::thread::future::packaged_task<T> &
fcppt::thread::future::packaged_task<T>::operator=(
	boost::detail::thread_move_t<packaged_task> rhs)
{
	packaged_task temp(
		rhs);
	swap(
		temp);
	return *this;
}

template<typename T>
void fcppt::thread::future::packaged_task<T>::swap(
	packaged_task &rhs)
{
	task_.swap(
		rhs.task_);
	std::swap(
		future_obtained_,
		rhs.future_obtained_);
}

template<typename T>
fcppt::thread::future::unique_object<T>
fcppt::thread::future::packaged_task<T>::object()
{
	if (!task_)
		throw task_moved();
	if (!future_obtained_)
	{
		future_obtained_ = true;
		return
			unique_object<T>(
				task_);
	}
	throw already_retrieved();
}

template<typename T>
void fcppt::thread::future::packaged_task<T>::operator()()
{
	if (!task_)
		throw task_moved();
	task_->run();
}

#endif // FCPPT_THREAD_FUTURE_PACKAGED_TASK_HPP_INCLUDED
