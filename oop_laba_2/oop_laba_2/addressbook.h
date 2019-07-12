#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "messages.h"

class AddressBook
{

public:

	AddressBook()
	{

	}

	AddressBook(AddressBook const &a);

	AddressBook & operator = (const AddressBook &a);

private:	

	struct zapis
	{
		std::string name;
		std::string number;
	};

	std::vector<zapis> kniga;

	void replace_name(std::string number, std::string new_name);
	
	void replace_number(std::string name, std::string new_number);

	unsigned int find_n_symbols(std::string str, std::string findstr) const;

	void kniga_sort();

public:	

	// ���������� ���������� ������� � �����
	unsigned int getEntriesCount() const;

	/* ��������� ��� � ����� �������� � ���� �����. ���� ���������� ������ � ����� ������, � ����� ����������,
	 �� ����� ������� ��������. ���� ���������� ������ � ����� �� ������� ��������, �� ���������� ���, 
	 ������� ������� ������ ��� ��������, � ��������� �����. ���� �� �����, �� ������ �������� ��� �� ���������������� �����, 
	 �������� ����� ������*/	
	void addEntry(std::string name, std::string number); 
	
	// ���������� true, ���� ����� ������� ����������
	bool hasEntryByName(std::string name) const; 

	// ���������� true, ���� ����� ����� �������� ����������
	bool hasEntryByPhoneNumber(std::string number) const;

	// ��������� ��� �������� � ���� ������ � ���������� ��������� � ��� ����� ��������
	std::string getPhoneNumber(std::string name) const;

	// ��������� ����� �������� � ���� ������ � ���������� ��� ���������� � ��� ��������
	std::string getName(std::string number) const;

	// ��������� ��� �������� � ���� ������ � ������� ��������������� ������ �� �����
	void removeEntryByName(std::string name);

	// ��������� ����� �������� � ���� ������ � ������� ��������������� ������ �� �����
	void removeEntryByPhoneNumber(std::string number);

	// ��������� ��� �������� � ����� �������� � ���� ����� � ������� ��������������� ������ �� �����
	void removeEntry(std::string name, std::string number);

	// ��������� �������� ����� �������� � ���� ������ � ������������ ����� ���������� ������� ����� ��� ��������, ������������ �� ������� ��������
	unsigned int getEntriesCountByName(std::string fragment) const;

	// ��������� �������� ������ �������� � ���� ������ � ������������ ����� ���������� ������� ����� ����� ��������, ������������ �� ������� ��������
	unsigned int getEntriesCountByPhoneNumber(std::string fragment) const;

	// ���������� ������������� �� �������� ������������������ ���� ���������, ������������ � �����
	std::vector<std::string> createOrdered(void);
	
	// ������������� �������� ������ ����� � �������� �����, ��������� ������ � ������� �<���> - <�����>\n�, ������������� �� �������� �� ����� ��������
	friend std::ostream & operator << (std::ostream &stream_, AddressBook &a);

};
