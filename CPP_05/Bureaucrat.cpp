/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlorion <nlorion@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:23:56 by nlorion           #+#    #+#             */
/*   Updated: 2023/07/10 12:57:19 by nlorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// *********************** CONSTRUCTOR / DESTRUCTOR ****************************

Bureaucrat::Bureaucrat()
{
	(std::string&)m_name = "Henry";
	m_grade = 1;
	std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : m_name(name), m_grade(grade)
{
	std::cout << "Bureaucrat overload constructor" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const& copy)
{
	std::cout << "Bureaucrat constructor copy" << std::endl;
	(std::string&)m_name = copy.m_name;
	m_grade = copy.m_grade;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		(std::string&)m_name = rhs.m_name;
		m_grade = rhs.m_grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor" << std::endl;
}

// ******************** SETTER *************************

void	Bureaucrat::setName(const std::string name)
{
	(std::string&)m_name = name;
}

void	Bureaucrat::setGrade(int grade)
{
	GradeTooHighException(grade);
	GradeTooLowException(grade);
}

// ******************** GETTER *************************

void	Bureaucrat::getName(void)
{

}

void	Bureaucrat::getGrade(void)
{
	setGrade();
}

void	Bureaucrat::GradeTooHighException(int grade)
{
	try
	{
		if (grade < 1)
			throw std::string("High grade can't be inferior to 1\n");
		else
			this->m_grade = grade;
	}
	catch(std::string const& str)
	{
		std::cerr << str << std::endl;
	}
}

void	Bureaucrat::GradeTooLowException(int grade)
{
	try
	{
		if (grade > 150)
			throw std::string("Low grade can't be superior to 150\n");
		else
			this->m_grade = grade;
	}
	catch(std::string const& str)
	{
		std::cerr << str << std::endl;
	}
}
