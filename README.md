# Shiboken sample
## Features
Sample program based on [https://doc.qt.io/qtforpython/shiboken2/examples/samplebinding.html](https://doc.qt.io/qtforpython/shiboken2/examples/samplebinding.html).

## Requirement
OS: Ubuntu 18.04

## Installation
```bash
sudo apt install build-essential cmake
sudo apt install shiboken libshiboken-dev
cd /path/to/shiboken_sample
mkdir build && cd build
cmake ..
make
```

## Usage
```bash
cd /path/to/shiboken_sample/build
# In Python
>>> import Universe
>>> ice1 = Universe.Icecream("strawberry")
>>> ice2 = Universe.Icecream("vanilla")
>>> truck = Universe.Truck(True)
>>> truck.addIcecreamFlavor(ice1)
>>> truck.addIcecreamFlavor(ice2)
>>> truck.printAvailableFlavors()
strawberry
vanilla
>>> del truck
leave
```
