#include "lst.hpp"

t_lst* lst::new_lst(AMateria *x)
{
    t_lst *c;
    
    c = new t_lst;
    c->m = x;
    c->next = NULL;
    return c;
}
void add_back(t_lst **head, t_lst *n)
{
    if(!head)
        return ;
    if(!(*head))
    {
        *head = n;
        return ;
    }
    t_lst *tmp;
    tmp = *head;
    while(tmp && tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = n;
}

lst::lst()
{
    head = NULL;
}

lst::~lst()
{
    while (head)
    {
        delete head;
        head = head->next;
    }
    
}

void lst::add_back(t_lst *n)
{
    if(!(head))
    {
        head = n;
        return ;
    }
    t_lst *tmp;
    tmp = head;
    while(tmp && tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = n;
}