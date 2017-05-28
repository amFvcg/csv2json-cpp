#pragma once
#include <string>

template<typename T>
T convert(const std::string& item)
{
    return (T)item;
}

template<>
int convert<int>(const std::string& x)
{
    return std::stoi(x);
}

template<>
std::string convert<std::string>(const std::string& v)
{
    return v;
}

template<>
double convert<double>(const std::string& v)
{
    return std::stod(v);
}

template<>
bool convert<bool>(const std::string& v)
{
    return std::stoi(v);
}
