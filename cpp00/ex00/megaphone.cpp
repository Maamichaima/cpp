#include <iostream>

int main(int c, char **v)
{
    int i;
    int j;

    i = 1;
    if(c == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    while(v[i])
    {
        j = 0;
        while(v[i][j])
        {
            std::cout << (char)toupper(v[i][j]);
            j++;
        }
        i++;
    }
    std::cout << std:: endl;
    return 0;
}