cmake_minimum_required(VERSION 3.20)

# Helper — builds one example from a single .cpp file
function(add_corogram_example name)
    add_executable(${name} ${name}.cpp)
    target_link_libraries(${name} PRIVATE corogram::corogram)

    # Put all example binaries in build/examples/ for clarity
    set_target_properties(${name} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/examples"
    )
endfunction()

add_corogram_example(echo_bot)
add_corogram_example(inline_keyboard)
add_corogram_example(reply_keyboard)
add_corogram_example(inline_query)
add_corogram_example(poll_bot)
add_corogram_example(fsm_form)
add_corogram_example(error_handling)
add_corogram_example(router_compose)
add_corogram_example(text_builder)
add_corogram_example(webhook_bot)
add_corogram_example(media_bot)
add_corogram_example(chat_actions)

# redis_fsm requires hiredis
if(COROGRAM_HAS_HIREDIS)
    add_corogram_example(redis_fsm)
else()
    message(STATUS "corogram examples: redis_fsm skipped (hiredis not found)")
endif()