/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:38:02 by fakouyat          #+#    #+#             */
/*   Updated: 2023/03/14 14:38:02 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool BitcoinExchange::db_status = false;
std::map<std::string, double> BitcoinExchange::db_btc = std::map<std::string, double>() ;

void	BitcoinExchange::init_databse(const std::string & db_path, bool mode) const
{
	std::string	line, date_btc;
	std::size_t delim;
	double		value_btc;
	
	if ((mode == false) && BitcoinExchange::db_status)
		return ;
	std::ifstream db_fd(db_path.c_str());
	if(db_fd.is_open())
	{
		getline(db_fd, line);
		while(getline(db_fd, line))
		{
			date_btc = "";
			delim = line.find(',');
			if (delim != std::string::npos)
			{
				date_btc = line.substr(0, delim);
				value_btc = std::atof(line.substr(delim + 1).c_str());
				BitcoinExchange::db_btc[date_btc] = value_btc;
			}
			else
			{
				std::cout << "Data not well formated\n";
				exit(0);
			}
		}
		BitcoinExchange::db_status = true;
	}
	else
	{
		std::cout << "Data base not found.\n";
		exit(0);
	}
	db_fd.close();
}

void	BitcoinExchange::display_values( const std::string & db_path, const std::string & infile,
										 bool mode)
{
	this->init_databse(db_path, mode);
	this->display_exchange(infile);
}

void	BitcoinExchange::display_exchange(const std::string & infile) const
{
	std::ifstream	input(infile.c_str());
	std::string		input_line, input_date = "pas mal";
	int				checker;
	double			value_btc = 0.0, input_nb_btc = 0.0;	
	if (input.is_open())
	{
		getline(input, input_line);
		while(getline(input, input_line))
		{
			checker = this->is_valid_input(input_line, input_date, &input_nb_btc);
			if (checker == BAD_INPUT)
				std::cout << "Error: bad input => " << input_line << "\n";
			else if (checker == NOT_POSITVE)
				std::cout << "Error: Not a posiitve number." << "\n";
			else if (checker == TOO_LARGE)
				std::cout << "Error: too large a number." << "\n";
			else
			{
				
				value_btc = this->get_value(input_date);
				std::cout << input_date << " => " << input_nb_btc << " = " << value_btc * input_nb_btc << "\n";
			}
		}
	}
	else
	{
		std::cout << "infile not found\n";
		exit(0);
	}
	input.close();

}

int	BitcoinExchange::is_valid_input( const std::string & input_line, std::string & input_date,\
									 double* input_nb_btc ) const
{
	size_t	delim, date_sep1, date_sep2;
	std::string year, m, d;

	delim = input_line.find('|');
	if (delim == std::string::npos)
		return BAD_INPUT;
	if (input_line[delim - 1] != ' ' || input_line[delim + 1] != ' ')
			return BAD_INPUT;
	date_sep1 = input_line.find('-');
	if (date_sep1 == std::string::npos)
		return BAD_INPUT;
	year = input_line.substr(0, date_sep1);
	if (!this->is_valid_year(year))
		return BAD_INPUT;
	date_sep2 = input_line.find('-', date_sep1 + 1);
	if (date_sep2 == std::string::npos)
		return BAD_INPUT;
	m = input_line.substr(date_sep1 + 1, date_sep2 - (date_sep1 + 1));
	if (!this->is_valid_month(m))
		return BAD_INPUT;
	d = input_line.substr(date_sep2 + 1, delim - 1 - (date_sep2 + 1));
	if (!this->is_valid_day(d))
		return BAD_INPUT;
	input_date = input_line.substr(0, delim - 1);
	*input_nb_btc = std::atof(input_line.substr(delim + 2).c_str());
	return (this->is_valid_input_nb_btc(*input_nb_btc));
}

double	BitcoinExchange::get_value(const std::string & input_date) const
{
	std::map<std::string, double>::iterator it;
	it = BitcoinExchange::db_btc.find(input_date);
	if (it != BitcoinExchange::db_btc.end())
		return it->second;
	it = BitcoinExchange::db_btc.upper_bound(input_date);
	if (it != db_btc.begin())
		--it;
	return it->second;
}

bool	BitcoinExchange::is_valid_year(const std::string & year) const
{
	if (year.size() != 4)
		return false;
	if (std::atoi(year.c_str()) <= 0)
		return false;
	return true;
}

bool	BitcoinExchange::is_valid_month(const std::string & month) const
{
	int	tmp;

	if (month.size() != 2)
		return false;
	tmp = std::atoi(month.c_str());
	if (tmp <= 0 || tmp > 12)
		return false;
	return true;
}

bool	BitcoinExchange::is_valid_day(const std::string & day) const
{
	int	tmp;

	if (day.size() !=  2)
		return false;
	tmp = std::atoi(day.c_str());
	if (tmp <= 0 || tmp > 31)
		return false;
	return true;
}

int		BitcoinExchange::is_valid_input_nb_btc(double input_nb_btc) const
{
	if (input_nb_btc > 1000.0)
		return TOO_LARGE;
	if (input_nb_btc == 0.0)
		return BAD_INPUT;
	if (input_nb_btc < 0.0)
		return NOT_POSITVE;
	return VALID_INPUT;
}

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::~BitcoinExchange() {}
