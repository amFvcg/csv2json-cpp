#pragma once
#include <string>
#include <list>
#include <tuple>

using MyMapping = std::tuple<
    int,
    std::string
>;


std::string to_str(MyMapping& object, int item)
{
    static const std::array<std::string, std::tuple_size<MyMapping>::value> field_names {
        "One",
        "Two"
    };
    return field_names[item];
}

struct Mapping
{

};

using Mappings = std::list<Mapping>;

//struct Mappings
//{
//
//};

Mapping do_mapping(std::string line);

Mappings read_mapping(std::string filename);
