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
	this->merge_insert_sort(this->_vec);
	this->merge_insert_sort(this->_deq);
}


void	PmergeMe::merge_insert_sort(std::vector<int> & vec)
{
	int 							straggler;
	std::vector<std::vector<int> >	pairs;
	bool							is_strag =	false;
	if (vec.size() % 2 != 0)
	{
		straggler = *(vec.end() - 1);
		vec.pop_back();
		is_strag = true;
	}
	pairs = this->creat_pairs(vec);
	sort_by_larger_value(pairs);
	vec.clear();
	for (int i = (int)(pairs.size() - 1); i >= 0; --i)
	{
		vec.push_back(pairs[i][0]);
		std::cout << pairs[i][0] << " - ";
		std::cout << pairs[i][1] << "\n";
	}
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		insert_at_right_place(vec, pairs[i][1]);
	}
	if (is_strag)
		insert_at_right_place(vec, straggler);
	std::reverse(vec.begin(), vec.end());
	std::cout << "sorted\n";
	for (size_t i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << "\n";
	}
	
}

void	PmergeMe::merge_insert_sort(std::deque<int> & deq)
{
	(void)deq;
}

std::vector<std::vector<int> >	PmergeMe::creat_pairs(std::vector<int> & vec)
{
	std::vector<std::vector<int> > all_pairs;
	std::vector<int> pair;
	for (size_t i = 0; i < vec.size(); i++)
	{
		if (i % 2 != 0)
		{
			if (vec[i] > vec[i - 1])
			{
				pair.push_back(vec[i - 1]);
				pair.push_back(vec[i]);
			}
			else
			{
				pair.push_back(vec[i]);
				pair.push_back(vec[i - 1]);
			}
			all_pairs.push_back(pair);
			pair.clear();
		}
	}
	return all_pairs;
}

void	PmergeMe::sort_by_larger_value(std::vector<std::vector<int> > & pairs)
{
	mergeSort(pairs, 0, pairs.size() - 1);
}

void	PmergeMe::insert_at_right_place(std::vector<int> & v, int value)
{
	std::vector<int>::iterator left = v.begin();
	std::vector<int>::iterator right = v.end();
	while (left != right)
	{
		if (*left < value)
		{
			v.insert(left, value);
			break ;
		}
		if (*(right - 1) > value)
		{
			v.insert(right, value);
			break ;
		}
		left++;
		right--;
	}
}