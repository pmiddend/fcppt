//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/object.hpp>
#include <fcppt/optional/output.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/get.hpp>
#include <fcppt/record/make_label.hpp>
#include <fcppt/record/map.hpp>
#include <fcppt/record/permute.hpp>
#include <fcppt/record/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	record_map
)
{
FCPPT_PP_POP_WARNING

	FCPPT_RECORD_MAKE_LABEL(
		int_label
	);

	FCPPT_RECORD_MAKE_LABEL(
		move_only_label
	);

	typedef
	fcppt::record::variadic<
		fcppt::record::element<
			int_label,
			fcppt::optional::object<
				int
			>
		>,
		fcppt::record::element<
			move_only_label,
			fcppt::optional::object<
				fcppt::unique_ptr<
					int
				>
			>
		>
	>
	result_type;

	result_type const result{
		fcppt::record::permute<
			result_type
		>(
			fcppt::record::map(
				fcppt::record::variadic<
					fcppt::record::element<
						int_label,
						int
					>,
					fcppt::record::element<
						move_only_label,
						fcppt::unique_ptr<
							int
						>
					>
				>{
					int_label{} =
						42,
					move_only_label{} =
						fcppt::make_unique_ptr<
							int
						>(
							100
						)
				},
				[](
					auto &&_value
				)
				{
					return
						fcppt::optional::make(
							std::forward<
								decltype(
									_value
								)
							>(
								_value
							)
						);
				}
			)
		)
	};

	BOOST_CHECK_EQUAL(
		fcppt::record::get<
			int_label
		>(
			result
		),
		fcppt::optional::make(
			42
		)
	);

	BOOST_CHECK(
		fcppt::record::get<
			move_only_label
		>(
			result
		).has_value()
	);
}
