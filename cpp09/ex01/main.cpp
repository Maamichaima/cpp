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
	if(str[0] == '+' || str[0] == '-' || str[0] == '/' || str[0] == '*')
		return 1;
	return 0;
}

int is_num(std::string str)
{
	if(!isnumber(str[0]))
		return 0;
	return 1;
}

int is_valid(std::string str)
{
	if(!isnumber(str[0]) && !is_operator(str))
		return 0;
	return 1;
}

int all_good(std::stack<std::string> arg)
{
	while(!arg.empty())
	{
		if(arg.top().length() != 1 || !is_valid(arg.top()))
			return 0;
		arg.pop();
	}
	return 1;
}

int calcule_two_num(int left, int right, std::string opp)
{
	if(opp == "+")
		return left + right;
	else if(opp == "-")
		return right - left;
	else if(opp == "/")
		return left / right;
	else if(opp == "*")
		return left * right;
	return 0;
}

int calcul(std::stack<std::string> &arg)
{
	int result = 0;
	int left, right;

	std::stack<int> st;
	std::stack<int> just_num;
	while(!arg.empty())
	{
		if(is_num(arg.top()))
		{
			just_num.push(atoi(arg.top().c_str()));
			result = just_num.top();
		}
		else if(is_operator(arg.top()) && just_num.size() >= 2)
		{
			left = just_num.top();
			just_num.pop();
			right = just_num.top();
			just_num.pop();
			result = calcule_two_num(left, right, arg.top());
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

int main(int c, char **av)
{
	try
	{
		if(c != 2)
			throw std::runtime_error("ERROR");
		std::stack<std::string> arg;
		arg = split(av[1], ' ');
		if(!all_good(arg))
			throw std::runtime_error("ERROR");
		int result = calcul(arg);
		std::cout << result;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
