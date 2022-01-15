#pragma once

#include <vector>
#include "icecream.h"

class Truck {
public:
    Truck(bool leaveOnDestruction = false);
    Truck(const Truck &other);
    Truck& operator=(const Truck &other);
    ~Truck();

    void addIcecreamFlavor(Icecream *icecream);
    void printAvailableFlavors() const;

    bool deliver() const;
    void arrive() const;
    void leave() const;

    void setLeaveOnDestruction(bool value);
    void setArrivalMessage(const std::string &message);

private:
    void clearFlavors();

    bool m_leaveOnDestruction = false;
    std::string m_arrivalMessage = "A new icecream truck has arrived!\n";
    std::vector<std::string> m_flavors;
};
