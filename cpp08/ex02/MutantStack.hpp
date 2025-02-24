#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP


#include <iostream>
#include <deque>
#include <iterator>
#include <stack>
template<typename T, typename Container = std::deque<T> >
class MutantStack
{
    private:
        Container x;
    public:
        typedef typename Container::iterator iterator;
        MutantStack();
        ~MutantStack();
        bool empty() const;
        size_t size() const;
        T& top();
        const T& top() const;
        void push(const T& value);
        void pop();
		iterator begin();
        iterator end();
};

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
    return x.begin();
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
    return x.end();
}

template<typename T, typename Container>
bool operator<(const MutantStack<T, Container> &x, const MutantStack<T, Container> &y);
template<typename T, typename Container>
bool operator>(const MutantStack<T, Container>&x, const MutantStack<T, Container>&y);
template<typename T, typename Container>
bool operator<=(const MutantStack<T, Container>&x, const MutantStack<T, Container>&y);
template<typename T, typename Container>
bool operator>=(const MutantStack<T, Container>&x, const MutantStack<T, Container>&y);
template<typename T, typename Container>
bool operator!=(const MutantStack<T, Container>&x, const MutantStack<T, Container>&y);

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack()
{
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
}

template <typename T, typename Container>
bool MutantStack<T, Container>::empty() const
{
    return x.empty();
}

template <typename T, typename Container>
size_t MutantStack<T, Container>::size() const
{
    return x.size();
}

template <typename T, typename Container>
T &MutantStack<T, Container>::top()
{
    return x.back();
}

template <typename T, typename Container>
const T &MutantStack<T, Container>::top() const
{
    return x.back();
}

template <typename T, typename Container>
void MutantStack<T, Container>::push(const T &value)
{
    x.push_back(value);
}

template <typename T, typename Container>
void MutantStack<T, Container>::pop()
{
    x.pop_back();
}

template <typename T, typename Container>
bool operator>(const MutantStack<T, Container> &x, const MutantStack<T, Container> &y)
{
    return (x.c > y.c);
}

template <typename T, typename Container>
bool operator<=(const MutantStack<T, Container> &x, const MutantStack<T, Container> &y)
{
    return (x.c <= y.c);
}

template <typename T, typename Container>
bool operator>=(const MutantStack<T, Container> &x, const MutantStack<T, Container> &y)
{
    return (x.c >= y.c);
}

template <typename T, typename Container>
bool operator!=(const MutantStack<T, Container> &x, const MutantStack<T, Container> &y)
{
    return !(x.c == y.c);
}

#endif
