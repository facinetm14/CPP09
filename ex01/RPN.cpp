#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

void	RPN::execute_operation(char* expr)
{
	int			operand_1, operand_2, opr, i, tmp_len;
	char		tmp[11];
	
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
				operand_1 = this->result.top();
				this->result.pop();
				operand_2 = this->result.top();
				this->result.pop();
				this->operate(operand_1, operand_2, expr[i]);
			}
			else if (this->result.size() == 1)
				this->operate_unaire(expr[i]);
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

void RPN::operate(int op1, int op2, char opt)
{
	int tmp_result;

	if (opt == '+')
		tmp_result = op1 + op2;
	else if (opt == '-')
		tmp_result = op2 - op1;
	else if (opt == '/')
		tmp_result = op2 / op1;
	else if (opt == '*')
		tmp_result = op1 * op2;
	this->result.push(tmp_result);
}

void RPN::operate_unaire(char opt)
{
	int tmp_result;
	int operand;

	operand = this->result.top();
	this->result.pop();
	if (opt == '-')
		tmp_result = operand * (-1);
	else
		tmp_result = operand;
	this->result.push(tmp_result);
}