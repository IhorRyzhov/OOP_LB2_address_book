#include "stdafx.h"
#include "addressbook.h"

void AddressBook :: replace_name(std::string number, std::string new_name)
{
	for (unsigned int i = 0; i < kniga.size(); i++)
	{
		if (kniga[i].number == number)
		{
			kniga[i].name = new_name;
		}
	}
}

void AddressBook :: replace_number(std::string name, std::string new_number)
{
	for (unsigned int i = 0; i < kniga.size(); i++)
	{
		if (kniga[i].name == name)
		{
			kniga[i].number = new_number;
		}
	}
}

unsigned  int AddressBook :: find_n_symbols(std::string str, std::string findstr) const
{
	unsigned int count = 0;

	for (unsigned int i = 0; i < (unsigned int)str.size(); i++)
	{
		if (str[i] == findstr[i])
		{
			count++;
		}
		else
		{
			break;
		}
	}

	return count;
}

void AddressBook :: kniga_sort()
{
	bool flag;
	zapis p;

	if (kniga.size() >= 2)
	{
		while (1)
		{
			for (unsigned int i = 0; i < (unsigned int)(kniga.size() - 1); i++)
			{
				if (kniga[i].name > kniga[i + 1].name)
				{
					flag = 1;
					p = kniga[i];
					kniga[i] = kniga[i + 1];
					kniga[i + 1] = p;
				}
			}

			if (flag == 0)
			{
				break;
			}

			flag = 0;
		}
	}
}


// возвращает количество записей в книге
unsigned int AddressBook :: getEntriesCount() const
{
	return (unsigned int)kniga.size();
}

/* принимает имя и номер телефона в виде строк. Если существует запись с таким именем, а номер отличается,
то номер следует обновить. Если существует запись с таким же номером телефона, но отличается имя,
следует удалить старое имя контакта, и сохранить новое. Если ни имени, ни номера телефона еще не регистрировалось ранее,
добавить новую запись*/
void  AddressBook :: addEntry(std::string name, std::string number) //  добавляет новую запись
{
	if (name.size() == 0)
	{
		throw std::logic_error("Name cannot be empty");
	}

	if (number.size() == 0)
	{
		throw std::logic_error("Phone number cannot be empty");
	}

	if ((hasEntryByName(name)) && (hasEntryByPhoneNumber(number))) // если такой контакт существует && такой номер телефона существует
	{
		removeEntryByPhoneNumber(number);
		replace_number(name, number);
		return;
	}

	if (hasEntryByName(name)) // если такой контакт существует
	{
		replace_number(name, number);
		return;
	}

	if (hasEntryByPhoneNumber(number)) // если такой номер телефона существует
	{
		replace_name(number, name);
		return;
	}

	kniga.push_back({ name, number });
}

// возвращает true, если такой контакт существует
bool AddressBook :: hasEntryByName(std::string name) const
{
	for (unsigned int i = 0; i < (unsigned int)kniga.size(); i++)
	{
		if (kniga[i].name == name)
		{
			return true;
		}
	}

	return false;
}

// возвращает true, если такой номер телефона существует
bool AddressBook :: hasEntryByPhoneNumber(std::string number) const
{
	for (unsigned int i = 0; i < (unsigned int)kniga.size(); i++)
	{
		if (kniga[i].number == number)
		{
			return true;
		}
	}

	return false;
}

// принимает имя контакта в виде строки и возвращает связанный с ним номер телефона
std::string AddressBook :: getPhoneNumber(std::string name) const
{
	if (name.size() == 0)
	{
		throw std::logic_error("Name cannot be empty");
	}

	for (unsigned int i = 0; i < (unsigned int)kniga.size(); i++)
	{
		if (kniga[i].name == name)
		{
			return kniga[i].number;
		}
	}

	throw std::logic_error("Entry does not exist");
}

// принимает номер телефона в виде строки и возвращает имя связанного с ним контакта
std::string AddressBook :: getName(std::string number) const
{
	if (number.size() == 0)
	{
		throw std::logic_error("Phone number cannot be empty");
	}

	for (unsigned int i = 0; i < (unsigned int)kniga.size(); i++)
	{
		if (kniga[i].number == number)
		{
			return kniga[i].name;
		}
	}

	throw std::logic_error("Entry does not exist");
}

// принимает имя контакта в виде строки и удаляет соответствующую запись из книги
void AddressBook :: removeEntryByName(std::string name)
{
	if (name.size() == 0)
	{
		throw std::logic_error("Name cannot be empty");
	}

	for (unsigned int i = 0; i < (unsigned int)kniga.size(); i++)
	{
		if (kniga[i].name == name)
		{
			kniga.erase(kniga.begin() + i);
			return;
		}
	}

	throw std::logic_error("Entry does not exist");
}

// принимает номер телефона в виде строки и удаляет соответствующую запись из книги
void AddressBook :: removeEntryByPhoneNumber(std::string number)
{
	if (number.size() == 0)
	{
		throw std::logic_error("Phone number cannot be empty");
	}

	for (unsigned int i = 0; i < (unsigned int)kniga.size(); i++)
	{
		if (kniga[i].number == number)
		{
			kniga.erase(kniga.begin() + i);
			return;
		}
	}

	throw std::logic_error("Entry does not exist");
}

// принимает имя контакта и номер телефона в виде строк и удаляет соответствующую запись из книги
void AddressBook :: removeEntry(std::string name, std::string number)
{
	if (name.size() == 0)
	{
		throw std::logic_error("Name cannot be empty");
	}

	if (number.size() == 0)
	{
		throw std::logic_error("Phone number cannot be empty");
	}

	for (unsigned int i = 0; i < (unsigned int)kniga.size(); i++)
	{
		if ((kniga[i].name == name) && (kniga[i].number == number))
		{
			kniga.erase(kniga.begin() + i);
			return;
		}
	}

	throw std::logic_error("Entry does not exist");
}

// принимает фрагмент имени контакта в виде строки и подсчитывает какое количество записей имеет имя контакта, начинающееся на искомый фрагмент
unsigned int AddressBook :: getEntriesCountByName(std::string fragment) const
{
	unsigned int size = fragment.size(); 
	unsigned int count = 0;

	for (unsigned int i = 0; i < (unsigned int)kniga.size(); i++)
	{
		if (find_n_symbols(kniga[i].name, fragment) == size)
		{
			count++;
		}
	}

	return count;
}

// принимает фрагмент номера телефона в виде строки и подсчитывает какое количество записей имеет номер телефона, начинающийся на искомый фрагмент
unsigned int AddressBook :: getEntriesCountByPhoneNumber(std::string fragment) const
{
	unsigned int size = fragment.size();
	unsigned int count = 0;

	for (unsigned int i = 0; i < (unsigned int)kniga.size(); i++)
	{
		if (find_n_symbols(kniga[i].number, fragment) == size)
		{
			count++;
		}
	}

	return count;
}

// возвращает упорядоченную по алфавиту последовательность имен контактов, содержащихся в книге
std::vector<std::string> AddressBook :: createOrdered(void)
{
	std::vector<std::string> mas;

	for (unsigned int i = 0; i < (unsigned int)kniga.size(); i++)
	{
		mas.push_back(kniga[i].name);
	}

	// пузырек :)

	bool flag;
	std::string p;

	if (mas.size() >= 2)
	{
		while (1)
		{
			for (unsigned int i = 0; i < (unsigned int)(mas.size() - 1); i++)
			{
				if (mas[i] > mas[i + 1])
				{
					flag = 1;
					p = mas[i];
					mas[i] = mas[i + 1];
					mas[i + 1] = p;
				}
			}

			if (flag == 0)
			{
				break;
			}

			flag = 0;
		}
	}

	return mas;
}

// Перегруженный оператор вывода книги в выходной поток, выводящий записи в формате “<имя> - <номер>\n”, упорядоченных по алфавиту по имени контакта
std::ostream & operator << (std::ostream &stream_, AddressBook &a)
{
	a.kniga_sort();

	for (unsigned int i = 0; i < (unsigned int)a.kniga.size(); i++)
	{
		stream_ << a.kniga[i].name << " - " << a.kniga[i].number << "\n";
	}

	return stream_;
}