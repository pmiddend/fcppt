#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>

namespace without_strong_typedef
{
//! [strong_typedef_for_named_parameters_without_strong_typedef_without_typedef]
void f(int,bool,char);
//! [strong_typedef_for_named_parameters_without_strong_typedef_without_typedef]
}

namespace without_strong_typedef
{
//! [strong_typedef_for_named_parameters_without_strong_typedef_with_typedef]
typedef
int
vertex_count;

typedef
bool
enable_culling;

typedef
char
draw_char;

void f(vertex_count,enable_culling,draw_char) {}
//! [strong_typedef_for_named_parameters_without_strong_typedef_with_typedef]
}

namespace without_strong_typedef
{
void g()
{
//! [strong_typedef_for_named_parameters_without_strong_typedef_with_typedef_call_test]
f(100,true,'c');
f(true,100,'c');
f(true,'c',100);
f(100,'c',true);
f('c',true,100);
f('c',100,true);
//! [strong_typedef_for_named_parameters_without_strong_typedef_with_typedef_call_test]
}
}

//! [strong_typedef_for_named_parameters_with_strong_typedef]
#include <fcppt/strong_typedef.hpp>

namespace with_strong_typedef
{
FCPPT_MAKE_STRONG_TYPEDEF(
	int,
	vertex_count);

FCPPT_MAKE_STRONG_TYPEDEF(
	bool,
	enable_culling);

FCPPT_MAKE_STRONG_TYPEDEF(
	char,
	draw_char);

void f(vertex_count,enable_culling,draw_char) {}
}
//! [strong_typedef_for_named_parameters_with_strong_typedef]

namespace with_strong_typedef
{
void named_parameters_call_test()
{
//! [strong_typedef_for_named_parameters_with_strong_typedef_call_test]
f(
	vertex_count(100),
	enable_culling(false),
	draw_char('c'));
//! [strong_typedef_for_named_parameters_with_strong_typedef_call_test]
}
}

//! [strong_typedef_for_overloading_guards_definitions]
FCPPT_MAKE_STRONG_TYPEDEF(
        float,
        distance);

FCPPT_MAKE_STRONG_TYPEDEF(
        float,
        speed);

// While we're at it, add another type for the time!
FCPPT_MAKE_STRONG_TYPEDEF(
        float,
        time);
//! [strong_typedef_for_overloading_guards_definitions]

namespace jogger
{
distance elapsed_distance(0.0f);
speed current_speed(0.0f);
void update(time);
}

//! [strong_typedef_for_overloading_guards_example]
void
jogger::update(time tick_delta)
{
        elapsed_distance += distance(current_speed.get() * tick_delta.get());
}
//! [strong_typedef_for_overloading_guards_example]

//! [strong_typedef_is_same]
FCPPT_MAKE_STRONG_TYPEDEF(
	        int,
	        first);

FCPPT_MAKE_STRONG_TYPEDEF(
	        int,
	        second);

BOOST_STATIC_ASSERT((
	!boost::is_same<first,second>::value));
//! [strong_typedef_is_same]

int main() {}
