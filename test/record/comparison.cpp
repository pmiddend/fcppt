//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/comparison.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/output.hpp>
#include <fcppt/record/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	record_comparison
)
{
FCPPT_PP_POP_WARNING

	FCPPT_RECORD_MAKE_LABEL(
		int_label
	);

	FCPPT_RECORD_MAKE_LABEL(
		bool_label
	);

	typedef
	fcppt::record::element<
		int_label,
		int
	>
	int_element;

	typedef
	fcppt::record::element<
		bool_label,
		bool
	>
	bool_element;

	typedef
	fcppt::record::variadic<
		int_element,
		bool_element
	>
	record1;

	typedef
	fcppt::record::variadic<
		bool_element,
		int_element
	>
	record2;

	BOOST_CHECK_EQUAL(
		record1(
			int_label{} = 42,
			bool_label{} = false
		),
		record2(
			int_label{} = 42,
			bool_label{} = false
		)
	);

	BOOST_CHECK_EQUAL(
		record1(
			int_label{} = 42,
			bool_label{} = false
		),
		record1(
			int_label{} = 42,
			bool_label{} = false
		)
	);

	BOOST_CHECK(
		record1(
			int_label{} = 42,
			bool_label{} = false
		)
		!=
		record1(
			int_label{} = 42,
			bool_label{} = true
		)
	);
}
