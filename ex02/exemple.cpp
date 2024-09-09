#include <iostream>
#include <iomanip>
#include <ctime>

int main() {
    // Obtenir le temps actuel depuis l'époque
    std::time_t now = std::time(0);
    std::tm* now_tm = std::localtime(&now);

    // Afficher la date et l'heure dans un format lisible
    std::cout << "Date et heure actuelles : "
              << (now_tm->tm_year + 1900) << '-'  // Année
              << (now_tm->tm_mon + 1) << '-'  // Mois
              << now_tm->tm_mday << ' '  // Jour
              << now_tm->tm_hour << ':'  // Heure
              << now_tm->tm_min << ':'  // Minutes
              << now_tm->tm_sec << std::endl;  // Secondes

    return 0;
}

