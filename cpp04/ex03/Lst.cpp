#include "Lst.hpp"

t_lst* Lst::new_lst(AMateria *x)
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

Lst::Lst()
{
    head = NULL;
}

Lst::~Lst()
{
	t_lst *tmp;
    while (head)
    {
        delete head->m;
		tmp = head;
        head = head->next;
		delete tmp;
    }
}

void Lst::add_back(t_lst *n)
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
Lst::Lst(const Lst& x)
{
    (*this) = x;
}
Lst& Lst::operator=(const Lst& other)
{
    if(this != &other)
    {
        this->head = other.head;
    }
    return (*this);
}