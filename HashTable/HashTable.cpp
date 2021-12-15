#include "HashTable.h"
#include <algorithm>
#include <iostream>
#include <fstream>

std::ostream& operator<<(std::ostream& os, const Company& company)
{
	os << "Name: " << company.name << "\n";
	os << "Tax Id Number: " << company.taxIdNum << "\n";
	os << "Address: " << company.address << "\n";
	return os;
}

int hashString(const std::string& name)
{
	uint64_t value = 0;
	uint64_t power = 1;
	std::string noSpace = name;

	//remove all spaces in name
	noSpace.erase(std::remove(noSpace.begin(), noSpace.end(), ' '), noSpace.end());

	//s contains LENGTH last characters of noSpace
	std::string s = noSpace.substr(std::max(static_cast<int>(noSpace.size()) - LENGTH, 0), LENGTH);

	for (const auto& ch : s)
	{
		value = (value + static_cast<uint64_t>(ch) * power) % M;
		power = (power * P) % M;
	}
	return static_cast<int>(value);
}

HashTable::HashTable()
{
	Company empty;
	buckets.resize(M, empty);
}

int HashTable::size()
{
	return buckets.size();
}

void HashTable::insert(const Company& company)
{
	int hashValue = hashString(company.name);

	while (!buckets.at(hashValue).name.empty())
	{
		if (hashValue == M - 1)
		{
			hashValue = 0;
		}
		else
		{
			hashValue++;
		}
	}
	buckets.at(hashValue) = company;
}

void HashTable::readFile(const std::string& filename)
{
	std::fstream file;
	Company company;

	file.open(filename, std::ios::in);
	if (!file)
	{
		std::cerr << "Cannot open file!\n";
		return;
	}

	std::getline(file, company.name, '|');
	std::getline(file, company.taxIdNum, '|');
	std::getline(file, company.address);
	while (!file.eof())
	{
		std::getline(file, company.name, '|');
		std::getline(file, company.taxIdNum, '|');
		std::getline(file, company.address);
		insert(company);
	}
	file.close();
}

Company HashTable::find(const std::string& name)
{
	auto hashValue = hashString(name);
	auto i = 0;

	if (buckets.at(hashValue).name.empty()) return Company();
	while (i < buckets.size())
	{
		if (name == buckets.at(hashValue).name)
		{
			return buckets.at(hashValue);
		}
		else
		{
			hashValue++;
		}
	}
	return Company();
}
