#ifndef P_MERGE_ME_HPP
# define P_MERGE_ME_HPP

# include <iostream>
# include <deque>
# include <vector>
# include <sstream>
# include <algorithm>
# include <ctime>

class	PmergeMe {

	private:
		std::vector<int>				_vec;
		std::deque<int> 				_deq;
		int								_size;
		//std::vector<std::vector<int> >	creat_pairs(std::vector<int> & vec);
		//void							sort_by_larger_value(std::vector<std::vector<int> > & pairs);
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

		template<typename T>
		void				merge_insert_sort(T & vec)
		{
			int 							straggler;
			std::vector<T>					pairs;
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
			
		}

		template <typename T>
		void				insert_at_right_place(T & v, int value)
		{
			typename T::iterator left = v.begin();
			typename T::iterator right = v.end();
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

		template <typename T>
		std::vector<T>		creat_pairs(T & vec)
		{
			std::vector<T> all_pairs;
			T	pair;
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

		template <typename T>
		void				sort_by_larger_value(std::vector<T> & pairs)
		{
			mergeSort(pairs, 0, pairs.size() - 1);
		}

	public:
		void							merge_me(char**	args, int len);
		PmergeMe(void);
		~PmergeMe(void);
};


#endif