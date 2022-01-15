#include "icecream.h"

Icecream::Icecream(const std::string &flavor) : m_flavor(flavor) {};
Icecream* Icecream::clone(){
    return new Icecream(m_flavor);
};
Icecream::~Icecream(){};
const std::string Icecream::getFlavor() {
    return m_flavor;
};
