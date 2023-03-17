/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:50:28 by fakouyat          #+#    #+#             */
/*   Updated: 2023/03/16 18:50:28 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Error: program should only 1 argument\n";
		return (0);
	}
	RPN rpn;
	rpn.execute_operation(argv[1]);
	return (0);
}