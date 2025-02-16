#include "easyfind.hpp"

int main()
{
	std::vector<int> v;

	v.push_back(1);
	v.push_back(8);
	v.push_back(1);
	v.push_back(0);
	try
    {
        std::vector<int>::iterator x = easyfind(v, 1);
        std::cout << "Element found at position: " << std::distance(v.begin(), x) << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}