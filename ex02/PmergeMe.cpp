/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:16:10 by fakouyat          #+#    #+#             */
/*   Updated: 2023/03/17 16:16:10 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}
PmergeMe::~PmergeMe(void) {}

void	PmergeMe::merge_me(char** args, int len)
{
	int i = 1, tmp, j;
	this->_size = len;
	float bench_vec, bench_deq;

	while (args[i])
	{
		j = 0;
		if (args[i][0] == '\0')
		{
			std::cout << "Error: Bad input\n";
			return ;
		}
		while (args[i][j])
		{
			if (!isdigit(args[i][j]))
			{
				std::cout << "Error: Bad input\n";
				return ;
			}
			j++;
		}
		std::stringstream ss(args[i]);
		ss >> tmp;
		this->_vec.push_back(tmp);
		this->_deq.push_back(tmp);
		i++;
	}
	clock_t start = clock();
	merge_insert_sort(this->_vec);
	bench_vec = (float)(clock() - start);

	start = clock();
	merge_insert_sort(this->_deq);
	bench_deq = (float)(clock() - start);
	(void)bench_deq;
	(void)bench_vec;
}
