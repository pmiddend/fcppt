//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/reference_impl.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::tree swap",
	"[container],[tree]"
)
{
	typedef
	fcppt::container::tree::object<
		int
	>
	i_tree;

	i_tree tree1(
		10
	);

	tree1.push_back(
		20
	);

	i_tree tree2(
		30
	);

	swap(
		tree1,
		tree2
	);

	CHECK(
		tree1.value()
		==
		30
	);

	CHECK(
		tree2.value()
		==
		10
	);

	CHECK_FALSE(
		tree2.empty()
	);

	fcppt::optional::maybe(
		tree2.front(),
		[]{
			CHECK(
				false
			);
		},
		[](
			fcppt::reference<
				i_tree
			> const _tree
		)
		{
			CHECK(
				_tree.get().value()
				==
				20
			);
		}
	);
}
