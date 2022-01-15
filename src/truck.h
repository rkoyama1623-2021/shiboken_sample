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
