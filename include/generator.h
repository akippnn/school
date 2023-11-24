// generator.h

#pragma once
#include <coroutine>

template <typename T>
struct Generator {
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;

    struct promise_type {
        T current_value;

        auto get_return_object();
        auto initial_suspend() noexcept;
        auto final_suspend() noexcept;
        void unhandled_exception();
        auto yield_value(T value);
    };

    handle_type coroutine_handle;

    bool move_next();
    T current_value();

    ~Generator();
};
