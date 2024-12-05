#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string n, Weapon& W) : name(n), W_A(W) {}

void HumanA::attack() {
    std::cout << name << " attacks with their " << W_A.getType() << std::endl;
}