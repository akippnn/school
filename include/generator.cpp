// generator.cpp

#include "generator.h"

template <typename T>
auto Generator<T>::promise_type::get_return_object() {
    return Generator{handle_type::from_promise(*this)};
}

template <typename T>
auto Generator<T>::promise_type::initial_suspend() noexcept {
    return std::suspend_always{};
}

template <typename T>
auto Generator<T>::promise_type::final_suspend() noexcept {
    return std::suspend_always{};
}

template <typename T>
void Generator<T>::promise_type::unhandled_exception() {
    std::terminate();
}

template <typename T>
auto Generator<T>::promise_type::yield_value(T value) {
    current_value = value;
    return std::suspend_always{};
}

template <typename T>
bool Generator<T>::move_next() {
    coroutine_handle.resume();
    return !coroutine_handle.done();
}

template <typename T>
T Generator<T>::current_value() {
    return coroutine_handle.promise().current_value;
}

template <typename T>
Generator<T>::~Generator() {
    if (coroutine_handle)
        coroutine_handle.destroy();
}

// Explicit instantiation for the types you expect to use
template struct Generator<int>;  // Example with int, adapt as needed
