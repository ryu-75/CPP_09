/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:16:03 by nlorion           #+#    #+#             */
/*   Updated: 2023/07/10 12:57:24 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class	Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat&	operator=(Bureaucrat const &rhs);
		void	setName(const std::string name);
		void	setGrade(int grade);
		void	getName(void);
		void	getGrade(void);
		void	GradeTooHighException(int grade);
		void	GradeTooLowException(int grade);
		~Bureaucrat();
	private:
		const std::string	m_name;
		int	m_grade;
};
