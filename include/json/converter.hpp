#pragma once

#include <tuple>
#include <utility>

#include <json.hpp>

namespace detail {
    template<class X, class T, size_t ... Is>
    nlohmann::json to_json(const T& t, std::index_sequence<Is...>)
    {
        nlohmann::json j = nlohmann::json::object({{X::Names(Is), std::get<Is>(t)}...});
        return j;
    }
}

template<typename T, typename ... TArgs>
nlohmann::json to_json(const std::tuple<TArgs...>& t)
{
    return detail::to_json<T>(t, std::index_sequence_for<TArgs...>{});
}

template<typename T>
nlohmann::json to_json(const T& t)
{
    return to_json<T>(t.value);
}

