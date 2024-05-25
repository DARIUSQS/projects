#include "calc.h"
#include <cmath>

long double calc::expression(const std::string& src)
{
    long double result = first_degree(src);
    while(index < src.size() && (src[index] == '+' || src[index] == '-'))
    {
        index++;
        if(src[index - 1] == '+') result += first_degree(src);
        else result -= first_degree(src); 
    }
    return result;
}

long double calc::first_degree(const std::string& src)
{
    long double result = second_degree(src);
    while(index < src.size() && (src[index] == '*' || src[index] == '/'))
    {
        index++;
        if(src[index - 1] == '*') result *= second_degree(src);
        else result /= second_degree(src);
    }
    return result;
}

long double calc::second_degree(const std::string& src)
{
    long double result;
    if(index < src.size() && src[index] == '(')
    {
        index++;
        result = expression(src);
        index++;
    } else 
    {
        result = constant(src);
    }
    return result;
}

long double calc::factor(const std::string& src)
{
    long double result = constant(src);
    return result;
}

long double calc::constant(const std::string& src)
{
    long double result = 0;
    while (index < src.size() && src[index] >= '0' && src[index] <= '9')
    {
        result = int(result)  * 10 + src[index] - '0';
        index++;
    }
    return result;
}

void calc::calculate(const std::string& str)
{
    index = 0;
    if(index < str.size() && (str[index] <= '0' || str[index] >= '9'))
    {
        index++;
        if(str[index - 1] == '*') value *= expression(str);
        else if(str[index - 1] == '/') value /= expression(str);
        else if(str[index - 1] == '-') value -= expression(str);
        else value += expression(str);
    }
    else value += expression(str);
}

long double calc::Get() const
{
    return value;
}

void calc::Clear()
{
    value = 0;
}
