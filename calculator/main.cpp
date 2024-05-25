#include <iostream>
#include "calc.h"

void strip_space(std::string& str)
{
    while(str.find(" ") != std::string::npos) str.erase(str.find(" "), 1);
}

int main()
{
    std::cout << "Welcome to ccalc\n";
    calc cal;
    std::string x;
    while(1)
    {
        std::cout << ">>> ";
        std::getline(std::cin, x);
        strip_space(x);
        if(x.find("clear") != std::string::npos) cal.Clear();
        else cal.calculate(x);
        std::cout << cal.Get() << '\n';
    }
}
