#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
// int main()
// {
// 	ClapTrap a("gg");
// 	ScavTrap s;
// 	a.attack("hadik");
// 	a.takeDamage(9);
// 	a.takeDamage(-1);
// 	a.takeDamage(9);
// 	// a.beRepaired(5);
// }
#include <iostream>
#include <string>

// Classe de base
class Animal {
protected:
    std::string name;

public:
    // Constructeur
    Animal(const std::string& name) : name(name) {
        std::cout << "Animal " << name << " created." << std::endl;
    }

    // Destructeur
    virtual ~Animal() {
        std::cout << "Animal " << name << " destroyed." << std::endl;
    }

    // Méthode virtuelle pour le son de l'animal
    virtual void makeSound() const {
        std::cout << name << " makes a generic animal sound." << std::endl;
    }
};

// Classe dérivée
class Dog : public Animal {
public:
    // Constructeur
    Dog(const std::string& name) : Animal(name) {
        std::cout << "Dog " << name << " created." << std::endl;
    }

    // Destructeur
    ~Dog() {
        std::cout << "Dog " << name << " destroyed." << std::endl;
    }

    // Surcharge de la méthode makeSound()
    void makeSound() {
        std::cout << name << " barks: Woof! Woof!" << std::endl;
    }
};

// Fonction principale
int main() {
    Animal* genericAnimal = new Animal("GenericAnimal");
    genericAnimal->makeSound();

    std::cout << "-----" << std::endl;

    Animal* myDog = new Dog("Buddy");
    myDog->makeSound();

    std::cout << "-----" << std::endl;

    // Libération de la mémoire
    delete genericAnimal;
    delete myDog;

    return 0;
}
