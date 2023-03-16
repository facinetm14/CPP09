/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:44:39 by fakouyat          #+#    #+#             */
/*   Updated: 2023/03/14 13:44:39 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTC_EXCHANGE_HPP
# define BTC_EXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <string>
# include <list>
# include <cstdlib>
# include <sstream>
# include <iomanip>
# define BAD_INPUT -1
# define NOT_POSITVE -2
# define TOO_LARGE -3
# define VALID_INPUT 1

class BitcoinExchange {

	private:
		static std::map<std::string, double>	db_btc;
		static bool 							db_status;
		

		//std::string		get_date_btc(const std::string & data)	const;
		double			get_value(const std::string & data) const;
		void			init_databse(const std::string & db_path, bool mode) const;
		void			display_exchange(const std::string & infile) const;
		int				is_valid_input( const std::string & input_line, std::string & input_date,\
										double* input_nb_btc ) const;
		bool			is_valid_year(const std::string & year) const;
		bool			is_valid_month(const std::string & month) const;
		bool			is_valid_day(const std::string & day) const;
		int				is_valid_input_nb_btc(double input_nb_btc) const;
	
	public:
		BitcoinExchange(void);
		~BitcoinExchange();
		void	display_values( const std::string & db_path, const std::string & infile,\
								bool mode = false );

};

#endif