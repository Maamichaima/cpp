#include "RPN.hpp"

std::stack<std::string> split(const std::string& str, char delimiter){
    std::stack<std::string> result;
    std::stack<std::string> revers;
    std::stringstream ss(str);
    std::string item;

    while (getline(ss, item, delimiter))
    {
        if(item.length() == 0)
            continue;
		result.push(item);
    }
	while(!result.empty())
	{
		revers.push(result.top());
		result.pop();
	}
    return revers;
}

void print(std::stack<int> st)
{
    while (!st.empty())
	{
        std::cout << st.top() << " ";
        st.pop();
    }
}

int is_operator(std::string str)
{
	if(str.size() != 1)
		return 0;
	if(str[0] == '+' || str[0] == '-' || str[0] == '/' || str[0] == '*')
		return 1;
	return 0;
}


int is_valid(std::string str)
{
	if(!isdigit(str[0]) && !is_operator(str))
		return 0;
	return 1;
}

int is_digit(std::string str)
{
	int i = 0;
	if(str[0] == '-' || str[i] == '+')
		i++;
	if(!str[i])
		return 0;
	while (str[i])
	{
		if(!isdigit(str[i]))
			return 0;
		i++;
	}
	return 1;
}

int is_num(std::string str)
{
	if(is_digit(str))
	{
		double nb = atof(str.c_str());
		if(nb > 10)
			return 0;
		return 1;
	}
	return 0;
}

int calcul_two_num(int left, int right, std::string opp)
{
	if(opp == "+")
		return left + right;
	else if(opp == "-")
		return right - left;
	else if(opp == "/")
	{
		if(left == 0)
			throw std::runtime_error("NAN");
		return right / left;
	}
	else if(opp == "*")
		return left * right;
	return 0;
}

int calcul(std::stack<std::string> &arg)
{
	double result = 0;
	double left, right;

	std::stack<double> just_num;
	while(!arg.empty())
	{
		if(is_num(arg.top()))
		{
			just_num.push(atof(arg.top().c_str()));
			result = just_num.top();
		}
		else if(is_operator(arg.top()) && just_num.size() >= 2)
		{
			left = just_num.top();
			just_num.pop();
			right = just_num.top();
			just_num.pop();
			result = calcul_two_num(left, right, arg.top());
			just_num.push(result);
		}
		else
			throw std::runtime_error("ERROR");
		arg.pop();
	}
	if(just_num.size() > 1)
		throw std::runtime_error("ERROR");
	return result;
}