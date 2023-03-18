/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fakouyat <fakouyat@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:08:12 by fakouyat          #+#    #+#             */
/*   Updated: 2023/03/14 14:08:12 by fakouyat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char*argv[])
{
	std::string db_path = "./data.csv";
	if (argc != 2)
	{
		std::cout << "Error: could not open file.\n";
		return (0);
	}
	BitcoinExchange btc;
	btc.display_values(db_path, argv[1]);

	return (0);
}