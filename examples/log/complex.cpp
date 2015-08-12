//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/exception.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/make_int_range.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/log/_.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/debug.hpp>
#include <fcppt/log/define_context.hpp>
#include <fcppt/log/define_object.hpp>
#include <fcppt/log/error.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/parameters.hpp>
#include <fcppt/log/print_locations.hpp>
#include <fcppt/log/tree_function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <functional>
#include <fcppt/config/external_end.hpp>


//! [context_declaration]
namespace engine
{

// Function to retrieve the global log context
fcppt::log::context &
log_context();

}
//! [context_declaration]

//! [logger_parameters]
namespace engine
{

// Helper function to create our logger parameters
inline
fcppt::log::parameters
logger_parameters(
	fcppt::log::location const &_location
)
{
	return
		fcppt::log::parameters(
			fcppt::io::cout(),
			fcppt::log::level::debug
		)
		.context_location(
			engine::log_context(),
			_location
		);
}

}
//! [logger_parameters]

//! [engine_location]
namespace engine
{

// Helper function to return the engine's log location
inline
fcppt::log::location
logger_location()
{
	return
		fcppt::log::location(
			FCPPT_TEXT("engine")
		);
}

}
//! [engine_location]

//! [declare_engine_root_logger]
namespace engine
{

// The engine's root logger
fcppt::log::object &
root_logger();

}
//! [declare_engine_root_logger]

//! [declare_subsystem_loggers]
// Define two subsystem loggers.
namespace engine
{
namespace renderer
{

fcppt::log::object &
logger();

}

namespace audio
{

fcppt::log::object &
logger();

}
}
//! [declare_subsystem_loggers]

//! [context_definition]
//
// Translation unit for the global log context
//

FCPPT_LOG_DEFINE_CONTEXT(
	engine::log_context
)
//! [context_definition]

//! [define_engine_root_logger]
//
// Translation unit for the root logger
//

namespace
{

fcppt::log::object root_logger_obj(
	engine::logger_parameters(
		engine::logger_location()
	)
);

}

fcppt::log::object &
engine::root_logger()
{
	return
		root_logger_obj;
}
//! [define_engine_root_logger]

//! [define_subsystem_renderer]
//
// Translation unit for the renderer logger
//
namespace
{

fcppt::log::object renderer_logger_obj(
	engine::logger_parameters(
		engine::logger_location()
		/
		FCPPT_TEXT("renderer")
	)
);

}

fcppt::log::object &
engine::renderer::logger()
{
	return
		renderer_logger_obj;
}

//! [define_subsystem_renderer]

// [define_subsystem_audio]

//
// Translation unit for the audio logger
//

FCPPT_LOG_DEFINE_OBJECT(
	engine::audio::logger,
	engine::logger_parameters(
		engine::logger_location()
		/
		FCPPT_TEXT("audio")
	)
)

//! [define_subsystem_audio]

int
main(
	int argc,
	char **argv
)
try
{
//! [print_locations]
	fcppt::log::print_locations(
		fcppt::io::cout(),
		engine::log_context(),
		engine::logger_location()
	);
//! [print_locations]

//! [main]
	// Each command line parameter specifies a logger to activate.
	// Example: "./example renderer" will activate the renderer's logger so we can
	// diagnose a problem there.
	for(
		int const index
		:
		fcppt::make_int_range(
			1,
			argc
		)
	)
		engine::log_context().apply(
			engine::logger_location()
			/
			fcppt::from_std_string(
				argv[
					index
				]
			),
			fcppt::log::tree_function{
				std::bind(
					&fcppt::log::object::enable,
					std::placeholders::_1,
					true
				)
			}
		);
//! [main]
	FCPPT_LOG_DEBUG(
		engine::renderer::logger(),
		fcppt::log::_
			<< FCPPT_TEXT("test")
	)

	FCPPT_LOG_DEBUG(
		engine::audio::logger(),
		fcppt::log::_
			<< FCPPT_TEXT("test")
	)
}
catch(
	fcppt::exception const &_error
)
{
	fcppt::io::cerr()
		<< _error.string()
		<< FCPPT_TEXT('\n');

	return EXIT_FAILURE;
}
