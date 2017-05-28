#include "mapping.h"

#include <fstream>
#include <boost/algorithm/string.hpp>

Mapping do_mapping(std::string line)
{
    std::vector<std::string> fields;
    boost::split(fields, line, boost::is_any_of("="));
}

Mappings read_mapping(std::string filename)
{
    std::ifstream file(filename);
    Mappings mappings;
    if (!file)
    {
        return mappings;
    }
    std::string line;
    while( std::getline(file, line) )
    {
        mappings.emplace_back(do_mapping(line));
    }
    return mappings;
}
