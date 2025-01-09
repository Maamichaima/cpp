#include "Bureaucrat.hpp"
#include <cstdlib>  // Pour rand() et srand()
#include <ctime>    // Pour time()

int main()
{
    srand(time(NULL)); // Initialisation de la graine aléatoire
    Bureaucrat b("hhhh");
	// b.decrementGrade();
	// b.decrementGrade();
	std::cout << b;
}

