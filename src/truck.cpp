#include <iostream>
#include "truck.h"

Truck::Truck(bool leaveOnDestruction)
: m_leaveOnDestruction(leaveOnDestruction) {};
Truck::Truck(const Truck &other) {};
Truck& Truck::operator=(const Truck &other) {
};
Truck::~Truck() {
    if (m_leaveOnDestruction) leave();
};

void Truck::addIcecreamFlavor(Icecream *icecream) {
    m_flavors.push_back(icecream->getFlavor());
};
void Truck::printAvailableFlavors() const {
    for (int i=0; i<m_flavors.size(); i++) {
        std::cout << m_flavors[i] << std::endl;
    }
};

bool Truck::deliver() const {
    std::cout << "delivered" << std::endl;
};
void Truck::arrive() const {
    std::cout << m_arrivalMessage << std::endl;
};
void Truck::leave() const {
    std::cout << "leave" << std::endl;
};

void Truck::setLeaveOnDestruction(bool value) {
    m_leaveOnDestruction = value;
};
void Truck::setArrivalMessage(const std::string &message) {
    m_arrivalMessage = message;
};
void Truck::clearFlavors() {
    m_flavors.clear();
};
