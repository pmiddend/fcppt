//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/reference_impl.hpp>
#include <fcppt/container/tree/object_impl.hpp>
#include <fcppt/container/tree/to_root.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <iterator>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"container::tree::to_root",
	"[container],[tree]"
)
{
	typedef
	fcppt::container::tree::object<
		int
	>
	i_tree;

	i_tree tree(
		1
	);

	fcppt::reference<
		i_tree
	> const child{
		tree.push_back(
			2
		)
	};

	fcppt::reference<
		i_tree
	> const child_2{
		child.get().push_back(
			3
		)
	};

	typedef
	fcppt::container::tree::to_root<
		i_tree const
	>
	traversal_type;

	traversal_type const trav(
		child_2.get()
	);

	REQUIRE(
		std::distance(
			trav.begin(),
			trav.end()
		)
		==
		3
	);

	traversal_type::iterator it(
		trav.begin()
	);

	CHECK(
		it->value()
		==
		3
	);

	++it;

	CHECK(
		it->value()
		==
		2
	);

	++it;

	CHECK(
		it->value()
		==
		1
	);

	++it;

	CHECK(
		it
		==
		trav.end()
	);
}
