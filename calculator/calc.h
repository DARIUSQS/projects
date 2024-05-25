#pragma once
#include <iostream>

#include <cstdint>
class calc
{
    private:
        long double value = 0;
        int index = 0;
        long double expression(const std::string& src);
        long double first_degree(const std::string& src);
        long double second_degree(const std::string& src);
        long double factor(const std::string& src);
        long double constant(const std::string& src);
    public:
        void calculate(const std::string& expression);
        long double Get() const;
        void Clear();
};
