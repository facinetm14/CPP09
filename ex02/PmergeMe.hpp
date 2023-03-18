#ifndef P_MERGE_ME_HPP
# define P_MERGE_ME_HPP

# include <iostream>
# include <deque>
# include <vector>
# include <sstream>
# include <algorithm>

class	PmergeMe {

	private:
		std::vector<int>				_vec;
		std::deque<int> 				_deq;
		int								_size;
		void							merge_insert_sort(std::vector<int> & vec);
		void							merge_insert_sort(std::deque<int> & deq);
		std::vector<std::vector<int> >	creat_pairs(std::vector<int> & vec);
		void							sort_by_larger_value(std::vector<std::vector<int> > & pairs);
		void							insert_at_right_place(std::vector<int> & v, int value);
	public:
		void							merge_me(char**	args, int len);
		PmergeMe(void);
		~PmergeMe(void);
	private:

		template<typename T>
		void	mergeSort(T & v, size_t l, size_t r)
		{
			size_t m = (l + r) / 2;
			if (l < r)
			{
				mergeSort(v, l, m);
				mergeSort(v, m + 1, r);
			}
			merge_sorted(v, l, m, r);
		}

		template<typename T>
		void	merge_sorted(T & v, size_t left, size_t mid, size_t right)
		{
			T tmp(right + 1);
			size_t i = left, j = mid + 1, k = left;
			while (i <= mid && j <= right)
			{
				if (v[i] < v[j])
				{
					tmp[k] = v[i];
					k++;
					i++;
				}
				else
				{
					tmp[k] = v[j];
					k++;
					j++;
				}
			}
			while (i <= mid)
			{
				tmp[k] = v[i];
				k++;
				i++;
			}
			while (j <= right)
			{
				tmp[k] = v[j];
				k++;
				j++;
			}
			i = left;
			while (i <= right)
			{
				v[i] = tmp[i];
				i++;
			}
		}
};

#endif