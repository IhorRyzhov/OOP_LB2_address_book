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

	// возвращает количество записей в книге
	unsigned int getEntriesCount() const;

	/* принимает имя и номер телефона в виде строк. Если существует запись с таким именем, а номер отличается,
	 то номер следует обновить. Если существует запись с таким же номером телефона, но отличается имя, 
	 следует удалить старое имя контакта, и сохранить новое. Если ни имени, ни номера телефона еще не регистрировалось ранее, 
	 добавить новую запись*/	
	void addEntry(std::string name, std::string number); 
	
	// возвращает true, если такой контакт существует
	bool hasEntryByName(std::string name) const; 

	// возвращает true, если такой номер телефона существует
	bool hasEntryByPhoneNumber(std::string number) const;

	// принимает имя контакта в виде строки и возвращает связанный с ним номер телефона
	std::string getPhoneNumber(std::string name) const;

	// принимает номер телефона в виде строки и возвращает имя связанного с ним контакта
	std::string getName(std::string number) const;

	// принимает имя контакта в виде строки и удаляет соответствующую запись из книги
	void removeEntryByName(std::string name);

	// принимает номер телефона в виде строки и удаляет соответствующую запись из книги
	void removeEntryByPhoneNumber(std::string number);

	// принимает имя контакта и номер телефона в виде строк и удаляет соответствующую запись из книги
	void removeEntry(std::string name, std::string number);

	// принимает фрагмент имени контакта в виде строки и подсчитывает какое количество записей имеет имя контакта, начинающееся на искомый фрагмент
	unsigned int getEntriesCountByName(std::string fragment) const;

	// принимает фрагмент номера телефона в виде строки и подсчитывает какое количество записей имеет номер телефона, начинающийся на искомый фрагмент
	unsigned int getEntriesCountByPhoneNumber(std::string fragment) const;

	// возвращает упорядоченную по алфавиту последовательность имен контактов, содержащихся в книге
	std::vector<std::string> createOrdered(void);
	
	// Перегруженный оператор вывода книги в выходной поток, выводящий записи в формате “<имя> - <номер>\n”, упорядоченных по алфавиту по имени контакта
	friend std::ostream & operator << (std::ostream &stream_, AddressBook &a);

};
