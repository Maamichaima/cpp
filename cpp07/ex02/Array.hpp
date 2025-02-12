#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
// #include<stdlib.h>

template <typename T>
class Array
{
	private:
		T *array;
		size_t _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		T&	operator[](size_t index);
		void	*operator new[](size_t n);
		size_t	size();
		Array(int size);
		~Array();
};

template <typename T>
Array<T>::Array(): array(NULL), _size(0)
{
}
template <typename T>
Array<T>::Array(unsigned int n)
{
	array = new T[n];
}

template <typename T>
Array<T>::Array(const Array &other)
{
	*this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if(this != &other)
	{
		//shdow 
		this->array = other.array;
		this->_size = other._size;
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
	if (index >= _size || index < 0)
		throw(std::exception());// wach hadi ola chi haja khra 
	return array[index];
}

template <typename T>
void *Array<T>::operator new[](size_t n)
{
	return ::operator new(n);
}

template <typename T>
inline size_t Array<T>::size()
{
	return this->_size;
}

// void *operator new[](size_t n) throw()
// {
// 	// if(n < 0)
// 	// 	throw(std::bad_alloc);
// 	return ::operator new(n);
// }

template <typename T>
inline Array<T>::Array(int size)
{
	this->_size = size;
	this->array = new T[size];
}

template <typename T>
Array<T>::~Array()
{
	// delete 
}

#endif