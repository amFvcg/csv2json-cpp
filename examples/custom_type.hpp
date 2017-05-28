#pragma once

#include <string>
#include <tuple>

struct MyType 
{
    using Value = std::tuple<
        int,
        bool,
        double,
        std::string
        >;
    static const std::string Names(size_t i) {
        static const std::array<std::string, std::tuple_size<Value>::value> names { 
        "IntField",
        "BoolField",
        "DoubleField",
        "StringField"
        };
        return names[i];
    }
    Value value;
};

