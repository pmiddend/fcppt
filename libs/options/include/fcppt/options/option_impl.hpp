//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_OPTION_IMPL_HPP_INCLUDED
#define FCPPT_OPTIONS_OPTION_IMPL_HPP_INCLUDED

#include <fcppt/extract_from_string.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/optional_string.hpp>
#include <fcppt/output_to_fcppt_string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/either/apply.hpp>
#include <fcppt/either/bind.hpp>
#include <fcppt/either/from_optional.hpp>
#include <fcppt/either/join.hpp>
#include <fcppt/either/map.hpp>
#include <fcppt/either/map_failure.hpp>
#include <fcppt/either/object_impl.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/options/flag_name_set.hpp>
#include <fcppt/options/long_name.hpp>
#include <fcppt/options/missing_error.hpp>
#include <fcppt/options/option_decl.hpp>
#include <fcppt/options/option_name.hpp>
#include <fcppt/options/option_name_set.hpp>
#include <fcppt/options/optional_help_text.hpp>
#include <fcppt/options/optional_short_name.hpp>
#include <fcppt/options/other_error.hpp>
#include <fcppt/options/parse_context_fwd.hpp>
#include <fcppt/options/parse_error.hpp>
#include <fcppt/options/parse_result.hpp>
#include <fcppt/options/pretty_type.hpp>
#include <fcppt/options/short_name.hpp>
#include <fcppt/options/state.hpp>
#include <fcppt/options/state_with_value.hpp>
#include <fcppt/options/detail/check_short_long_names.hpp>
#include <fcppt/options/detail/help_text.hpp>
#include <fcppt/options/detail/long_or_short_name.hpp>
#include <fcppt/options/detail/type_annotation.hpp>
#include <fcppt/options/detail/use_option.hpp>
#include <fcppt/options/detail/use_option_result.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/record/element.hpp>
#include <fcppt/record/variadic.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Label,
	typename Type
>
fcppt::options::option<
	Label,
	Type
>::option(
	fcppt::options::optional_short_name &&_short_name,
	fcppt::options::long_name &&_long_name,
	optional_default_value &&_default_value,
	fcppt::options::optional_help_text &&_help_text
)
:
	short_name_(
		std::move(
			_short_name
		)
	),
	long_name_(
		std::move(
			_long_name
		)
	),
	default_value_(
		std::move(
			_default_value
		)
	),
	help_text_{
		std::move(
			_help_text
		)
	}
{
	fcppt::options::detail::check_short_long_names(
		this->short_name_,
		this->long_name_
	);
}

template<
	typename Label,
	typename Type
>
fcppt::options::parse_result<
	typename
	fcppt::options::option<
		Label,
		Type
	>::result_type
>
fcppt::options::option<
	Label,
	Type
>::parse(
	fcppt::options::state &&_state,
	fcppt::options::parse_context const &
) const
{
	typedef
	fcppt::either::object<
		fcppt::options::parse_error,
		fcppt::optional_string
	>
	flag_result;

	typedef
	fcppt::either::object<
		fcppt::options::parse_error,
		result_type
	>
	inner_result;

	auto const map_result(
		[](
			fcppt::options::detail::use_option_result const &_result
		)
		->
		flag_result
		{
			return
				fcppt::either::map_failure(
					_result,
					[](
						fcppt::options::detail::missing_option_argument const &_error
					)
					{
						return
							fcppt::options::parse_error{
								fcppt::options::other_error{
									FCPPT_TEXT("Missing option for ")
									+
									_error.get()
								}
							};
					}
				);
		}
	);

	auto const get_default_value(
		[
			&_state,
			this
		]()
		->
		inner_result
		{
			FCPPT_PP_PUSH_WARNING
			FCPPT_PP_DISABLE_GCC_WARNING(-Wattributes)

			return
				fcppt::either::from_optional(
					fcppt::optional::map(
						this->default_value_.get(),
						[](
							Type const &_value
						)
						{
							return
								result_type{
									Label{} =
										_value
								};
						}
					),
					[
						&_state,
						this
					]{
						return
							fcppt::options::parse_error{
								fcppt::options::missing_error{
									std::move(
										_state
									),
									FCPPT_TEXT("Missing option ")
									+
									fcppt::options::detail::long_or_short_name(
										this->long_name_,
										this->short_name_
									)
									+
									FCPPT_TEXT('.')
								}
							};
					}
				);

			FCPPT_PP_POP_WARNING
		}
	);

	auto const make_value(
		[
			this
		](
			fcppt::string const &_string
		)
		->
		inner_result
		{
			FCPPT_PP_PUSH_WARNING
			FCPPT_PP_DISABLE_GCC_WARNING(-Wattributes)

			return
				fcppt::either::from_optional(
					fcppt::optional::map(
						fcppt::extract_from_string<
							Type
						>(
							_string
						),
						[](
							Type &&_value
						)
						{
							return
								result_type{
									Label{} =
										std::move(
											_value
										)
								};
						}
					),
					[
						this,
						&_string
					]{
						return
							fcppt::options::parse_error{
								fcppt::options::other_error{
									FCPPT_TEXT("Failed to convert \"")
									+
									_string
									+
									FCPPT_TEXT("\" to ")
									+
									fcppt::options::pretty_type<
										Type
									>()
									+
									FCPPT_TEXT(" for option ")
									+
									fcppt::options::detail::long_or_short_name(
										this->long_name_,
										this->short_name_
									)
									+
									FCPPT_TEXT('.')
								}
							};
					}
				);

			FCPPT_PP_POP_WARNING
		}
	);

	auto const make_or_default_value(
		[
			get_default_value,
			make_value
		](
			fcppt::optional_string const &_opt_value
		)
		->
		inner_result
		{
			return
				fcppt::optional::maybe(
					_opt_value,
					get_default_value,
					make_value
				);
		}
	);

	flag_result const long_found{
		map_result(
			fcppt::options::detail::use_option(
				fcppt::make_ref(
					_state
				),
				long_name_.get(),
				fcppt::options::detail::flag_is_short{
					false
				}
			)
		)
	};

	auto const combine_results(
		[
			make_or_default_value,
			make_value,
			this
		](
			fcppt::optional_string const &_long_value_opt,
			fcppt::optional_string const &_short_value_opt
		)
		->
		inner_result
		{
			FCPPT_PP_PUSH_WARNING
			FCPPT_PP_DISABLE_GCC_WARNING(-Wattributes)

			return
				fcppt::optional::maybe(
					_long_value_opt,
					[
						&_short_value_opt,
						make_or_default_value
					]()
					->
					inner_result
					{
						return
							make_or_default_value(
								_short_value_opt
							);
					},
					[
						make_value,
						&_short_value_opt,
						this
					](
						fcppt::string const &_long_value
					)
					->
					inner_result
					{
						return
							_short_value_opt.has_value()
							?
								inner_result{
									fcppt::options::parse_error{
										fcppt::options::other_error{
											FCPPT_TEXT("Cannot specify both long and short name at once: ")
											+
											fcppt::options::detail::long_or_short_name(
												this->long_name_,
												this->short_name_
											)
										}
									}
								}
							:
								make_value(
									_long_value
								)
							;
					}
				);

			FCPPT_PP_POP_WARNING
		}
	);

	return
		fcppt::either::map(
			fcppt::optional::maybe(
				short_name_,
				[
					make_or_default_value,
					&long_found
				]()
				->
				inner_result
				{
					return
						fcppt::either::bind(
							long_found,
							make_or_default_value
						);
				},
				[
					combine_results,
					map_result,
					&long_found,
					&_state
				](
					fcppt::options::short_name const &_short_name
				)
				->
				inner_result
				{
					flag_result const short_found{
						map_result(
							fcppt::options::detail::use_option(
								fcppt::make_ref(
									_state
								),
								_short_name.get(),
								fcppt::options::detail::flag_is_short{
									true
								}
							)
						)
					};

					return
						fcppt::either::join(
							fcppt::either::apply(
								combine_results,
								long_found,
								short_found
							)
						);
				}
			),
			[
				&_state
			](
				result_type &&_result
			)
			{
				return
					fcppt::options::state_with_value<
						result_type
					>{
						std::move(
							_state
						),
						std::move(
							_result
						)
					};
			}
		);
}

template<
	typename Label,
	typename Type
>
fcppt::options::flag_name_set
fcppt::options::option<
	Label,
	Type
>::flag_names() const
{
	return
		fcppt::options::flag_name_set{};
}

template<
	typename Label,
	typename Type
>
fcppt::options::option_name_set
fcppt::options::option<
	Label,
	Type
>::option_names() const
{
	fcppt::options::option_name_set result{
		fcppt::options::option_name{
			fcppt::string{
				this->long_name_.get()
			},
			fcppt::options::option_name::is_short{
				false
			}
		}
	};

	fcppt::optional::maybe_void(
		this->short_name_,
		[
			&result
		](
			fcppt::options::short_name const &_short_name
		)
		{
			result.insert(
				fcppt::options::option_name{
					fcppt::string{
						_short_name.get()
					},
					fcppt::options::option_name::is_short{
						true
					}
				}
			);
		}
	);

	return
		result;
}

template<
	typename Label,
	typename Type
>
fcppt::string
fcppt::options::option<
	Label,
	Type
>::usage() const
{
	return
		(
			default_value_.get().has_value()
			?
				FCPPT_TEXT("[ ")
			:
				FCPPT_TEXT("")
		)
		+
		fcppt::options::detail::long_or_short_name(
			long_name_,
			short_name_
		)
		+
		fcppt::options::detail::type_annotation<
			Type
		>()
		+
		(
			fcppt::optional::maybe(
				default_value_.get(),
				[]{
					return
						fcppt::string{};
				},
				[](
					Type const &_value
				)
				{
					return
						FCPPT_TEXT(" / ")
						+
						fcppt::output_to_fcppt_string(
							_value
						);
				}
			)
		)
		+
		(
			default_value_.get().has_value()
			?
				FCPPT_TEXT(" ]")
			:
				FCPPT_TEXT("")
		)
		+
		fcppt::options::detail::help_text(
			help_text_
		);
}

#endif
