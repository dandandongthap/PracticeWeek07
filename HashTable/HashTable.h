#pragma once

#include <string>
#include <vector>

constexpr auto M = 100019;
constexpr auto P = 31;
constexpr auto LENGTH = 18;

class Company
{
public:
	std::string name;
	std::string taxIdNum;
	std::string address;

	Company()
	{
		this->name = "";
		this->taxIdNum = "";
		this->address = "";
	}
	Company(std::string name, std::string taxIdNum, std::string address)
	{
		this->name = name;
		this->taxIdNum = taxIdNum;
		this->address = address;
	}

	friend std::ostream& operator<<(std::ostream& os, const Company& company);
};

std::ostream& operator<<(std::ostream& os, const Company& company);

int hashString(const std::string& name);

class HashTable
{
public:
	HashTable();
	int size();
	void insert(const Company& company);
	void readFile(const std::string& filename);
	Company find(const std::string& name);
private:
	std::vector<Company> buckets;
};
