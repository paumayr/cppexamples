#pragma once

#include <string>

class Person
{
	std::string firstName;
	std::string lastName;

public:
	Person();
	~Person();

	void setFirstName(const std::string& firstName);
	const std::string& getFirstName() const;

	void setLastName(const std::string& lastName);
	const std::string& getLastName() const;

	std::string getFullName() const;
};