/*
 * This file is part of shiboken_sample
 *
 * Copyright (C) Ryo Koyama.
 *
 * Contact: Ryo Koyama <ryo(dot)koyama[at]outlook(dot)jp>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * version 2.1 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 */
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
