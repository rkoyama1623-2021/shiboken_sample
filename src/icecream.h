#pragma once

#include <string>

class Icecream
{
public:
    Icecream(const std::string &flavor);
    virtual Icecream *clone();
    virtual ~Icecream();
    virtual const std::string getFlavor();

private:
    std::string m_flavor;
};
