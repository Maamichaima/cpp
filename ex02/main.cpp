#include <iostream>

// Define a namespace
namespace MyNamespace {
    int myVariable = 42;

    void myFunction() {
        std::cout << "Hello from MyNamespace!" << std::endl;
    }
}

// Define another namespace
// namespace AnotherNamespace {
//     int myVariable = 100;

//     void myFunction() {
//         std::cout << "Hello from AnotherNamespace!" << std::endl;
//     }
// }

int main() {
    // Access variables and functions inside namespaces
    myFunction();                 // Calls function from MyNamespace
    // AnotherNamespace::myFunction();            // Calls function from AnotherNamespace

    // std::cout << myVariable << std::endl;    // Outputs 42
    // std::cout << AnotherNamespace::myVariable << std::endl; // Outputs 100

    return 0;
}
