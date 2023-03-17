#ifndef P_MERGE_ME_HPP
# define P_MERGE_ME_HPP

# include <iostream>
# include <deque>
# include <vector>
# include <sstream>

class	PmergeMe {

	private:
		std::vector<int> _vec;
		std::deque<int> _deq;
		int				_size;
		void	merge_insert_sort(std::vector<int> & vec);
		void	merge_insert_sort(std::deque<int> & deq);
	public:
		void	merge_me(char**	args, int len);
		PmergeMe(void);
		~PmergeMe(void);
};

#endif