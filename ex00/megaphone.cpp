#include <iostream>
using namespace std;

int main(int c, char **v)
{
    int i;
    int j;

    i = 1;
    if(c == 1)
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    while(v[i])
    {
        j = 0;
        while(v[i][j])
        {
            if(v[i][j] >= 'a' && v[i][j] <= 'z')
                cout << (char)toupper(v[i][j]);
            else
                cout << v[i][j];
            j++;
        }
        i++;
    }
    return 0;
}