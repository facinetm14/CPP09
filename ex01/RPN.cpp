#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

void	RPN::execute_operation(char* expr)
{
	double			operand_1, operand_2, opr;
	char		tmp[11];
	int			i, tmp_len;
	if (!expr)
	{
		std::cout << "ERROR\n";
		return ;
	}
	i = 0;
	while (expr[i])
	{
		if (expr[i] == ' ')
			++i;
		else if (expr[i] && isdigit(expr[i]))
		{
			tmp_len = 0;
			while(expr[i] && isdigit(expr[i]))
			{
				tmp[tmp_len] = expr[i];
				++i;
				tmp_len++;
			}
			tmp[tmp_len] = '\0';
			opr = std::atoi(tmp);
			this->result.push(opr);
			memset(tmp, '\0', tmp_len);
		}
		else if (expr[i] && this->is_operation(expr[i]))
		{
			if (this->result.size() >= 2)
			{
				operand_2 = this->result.top();
				this->result.pop();
				operand_1 = this->result.top();
				this->result.pop();
				this->operate(operand_1, operand_2, expr[i]);
			}
			else
			{
				std::cout << "ERROR\n";
				return ;
			}
			++i;
		}
		else
		{
			std::cout << "ERROR\n";
			return ;
		}
	}
	i--;
	while (expr[i] == ' ')
		i--;
	if (!is_operation(expr[i]))
		std::cout << "Error\n";
	else
		std::cout << this->result.top() << "\n";
}

bool	RPN::is_operation(char c)
{
	if (c == '-' || c == '+')
		return true;
	if (c == '*' || c == '/')
		return true;
	return false;
}

void RPN::operate(double op1, double op2, char opt)
{
	double tmp_result;

	if (opt == '+')
		tmp_result = op1 + op2;
	else if (opt == '-')
		tmp_result = op2 - op1;
	else if (opt == '/')
		tmp_result = op1 / op2;
	else if (opt == '*')
		tmp_result = op1 * op2;
	this->result.push(tmp_result);
}