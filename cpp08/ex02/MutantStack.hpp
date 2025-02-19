#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP


#include <iostream>
#include <deque>
#include <iterator>
#include <stack>
template<typename T, typename Container = std::deque<T>>
class MutantStack
{
    private:
        Container x;
    public:
        MutantStack();
        ~MutantStack();
        bool empty() const;
        size_t size() const;
        T& top();
        const T& top() const;
        void push(const T& value);
        void pop();
        class iterator : public std::iterator
        {
            int x;
        };
        MutantStack::iterator begin()
        {
            return this->begin();
        }
};

template<typename T, typename Container = std::deque<T>>
bool operator<(const MutantStack<T, Container> &x, const MutantStack<T, Container> &y);
template<typename T, typename Container = std::deque<T>>
bool operator>(const MutantStack<T, Container>&x, const MutantStack<T, Container>&y);
template<typename T, typename Container = std::deque<T>>
bool operator<=(const MutantStack<T, Container>&x, const MutantStack<T, Container>&y);
template<typename T, typename Container = std::deque<T>>
bool operator>=(const MutantStack<T, Container>&x, const MutantStack<T, Container>&y);
template<typename T, typename Container = std::deque<T>>
bool operator!=(const MutantStack<T, Container>&x, const MutantStack<T, Container>&y);

template <typename T, typename Container>
inline MutantStack<T, Container>::MutantStack()
{
}

template <typename T, typename Container>
inline MutantStack<T, Container>::~MutantStack()
{
}

template <typename T, typename Container>
inline bool MutantStack<T, Container>::empty() const
{
    return x.empty();
}

template <typename T, typename Container>
inline size_t MutantStack<T, Container>::size() const
{
    return x.size();
}

template <typename T, typename Container>
inline T &MutantStack<T, Container>::top()
{
    return x.back();
}

template <typename T, typename Container>
inline const T &MutantStack<T, Container>::top() const
{
    return x.back();
}

template <typename T, typename Container>
inline void MutantStack<T, Container>::push(const T &value)
{
    x.push_back(value);
}

template <typename T, typename Container>
inline void MutantStack<T, Container>::pop()
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
