#ifndef RPN_HPP
#define RPN_HPP

#include<iostream>
#include<stack>
#include <fstream>
#include <sstream>


int calcul(std::stack<std::string> &arg);
std::stack<std::string> split(const std::string& str, char delimiter);

#endif