#include <iostream>
#include <examples/custom_type.hpp>
#include <parsers.hpp>

int main()
{
    std::cout << "Parse from string:" << parse<MyType>("0,1,2,3") << std::endl;
    return 0;
}
