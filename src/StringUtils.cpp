#include "StringUtils.h"
#include <iostream>

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept{
    auto cpy_str = str;
    return cpy_str.substr(start, cpy_str.length()-1);
}

std::string Capitalize(const std::string &str) noexcept{
    auto cpy_str = str;
    cpy_str[0] = toupper(str[0]);
    return cpy_str;
}

std::string Upper(const std::string &str) noexcept{
    auto cpy_str = str;
    for(size_t i = 0; i < cpy_str.length(); i++)
    {
        cpy_str[i] = toupper(str[i]);
    }
    return cpy_str;
}

std::string Lower(const std::string &str) noexcept{
    auto cpy_str = str;
    for(size_t i = 0; i < cpy_str.length(); i++)
    {
        cpy_str[i] = tolower(str[i]);
    }
    return cpy_str;
}

//https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/ HELPEFGULWEFWEG
std::string LStrip(const std::string &str) noexcept{
    std::string cpy_str = str;

    for(size_t i = 0; i < cpy_str.length(); i++)
    {
        if(isspace(cpy_str[i]))
        {
            cpy_str.erase(cpy_str.begin() +i);
        }
    }
    return cpy_str;
}

std::string RStrip(const std::string &str) noexcept{
    std::string cpy_str = str;

    for(size_t i = cpy_str.length() - 1; i > 0; i--)
    {
        if(isspace(cpy_str[i-1]))
        {
            cpy_str.erase(cpy_str.begin() +i -1);
        }
    }
    return cpy_str;
}

std::string Strip(const std::string &str) noexcept{
    std::string cpy_str;

    for(size_t i = 0; i < str.length(); i++)
    {
        if(!isspace(str[i]))
        {
            cpy_str += str[i];
        }

    }
    return cpy_str;
}

std::string Center(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    // Replace code here
    return "";
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    // Replace code here
    return {};
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    // Replace code here
    return "";
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    // Replace code here
    return "";
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    // Replace code here
    return 0;
}

};