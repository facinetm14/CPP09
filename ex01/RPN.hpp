#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stack>
# include <sstream>
# include <cstdlib>
# include <cstring>
# include <exception>

class RPN {

	private:
		std::stack<double> result;
		bool	is_operation(char c);
		void	operate(double op1, double op2, char opt);
		void 	operate_unaire(char opt);

	public:
		void	execute_operation(char * expr);
		RPN(void);
		~RPN(void);
};

#endif