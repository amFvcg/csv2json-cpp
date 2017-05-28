#pragma once

#include <string>
#include <tuple>
#include <vector>

#include "json.hpp"

#include "converters.hpp"
#include "json/converter.hpp"



std::vector<std::string> split(std::string s, const char sep=',')
{
    std::vector<std::string> v;
    size_t pos = 0;
    auto it = s.find(sep, pos);
    while( it != std::string::npos )
    {
        v.emplace_back(s.substr(pos, it-pos));
        pos = it+1;
        it = s.find(sep, pos);
    }
    v.emplace_back(s.substr(pos, s.size()));
    return v;
}

namespace detail {
    template<typename T, size_t ... Is>
    T from_vector(const std::vector<std::string>& v, std::index_sequence<Is...>)
    {
        return std::make_tuple(convert<typename std::tuple_element<Is, T>::type>(v[Is])...);
    }
}

template<typename T, typename ... TArgs>
T from_vector(const std::vector<std::string>&v, const std::tuple<TArgs...>&)
{
    return detail::from_vector<T>(v, std::index_sequence_for<TArgs...>{});
}

template< typename MyType >
nlohmann::json parse(std::string input_string)
{
    auto fields = split(input_string, ','); 
    if (fields.size() != std::tuple_size<typename MyType::Value>::value)
    {
       //log
        return nlohmann::json::object();
    }
    
    MyType mt;
    mt.value = from_vector<typename MyType::Value>(fields, mt.value);
    
    return to_json(mt);
}

