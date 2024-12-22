#ifndef LST_HPP
#define LST_HPP

#include "AMateria.hpp"

typedef struct s_lst
{
    AMateria *m;
    struct s_lst* next;
} t_lst;

class lst
{
    private:
        s_lst *head;
    public:
        lst();
        ~lst();
        t_lst* new_lst(AMateria *x);
        void add_back(t_lst *n);
};

#endif