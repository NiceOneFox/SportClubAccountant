#include "pch.h"
#include "BNF.h"

bool BNF::isFullname(string fullname, int index)
{
	int size = fullname.length();
	if (fullname[0] != toupper(fullname[0]))
		throw myException("Фамилия начинается не с заглавной буквы ", index);

	for (int i = 1; i < size; i++) {

		if (!(fullname[i] >= 'a' && fullname[i] <= 'z'))
			if (fullname[i] != ' ')
				throw myException("В фамилии посторонний элемен или заглавная буква ", index);

		if (fullname[i] == ' ') { // проверка инициалов
			if (fullname[i + 1] != toupper(fullname[i + 1]) ||
				fullname[i + 3] != toupper(fullname[i + 3]))
				throw myException("Инициалы написы не с заглавной буквы", index);

			if (fullname[i + 2] != '.' || fullname[i + 4] != '.')
				throw myException("После инициалов отсутствует точка", index);

			if (size != i + 5)
				throw myException("ФИО содержит посторонние символы после инициалов", index);
			break;
		}
	}
	return true;
}

bool BNF::isAge(string age, int index)
{
  int size = age.length();
  if (size >= 4)
	  throw myException("Возраст содержит недопустимо большое число", index);
	for (int i = 0; i < size; i++) {
		if (!(age[i] >= '0' && age[i] <= '9'))
			throw myException("Возраст содержит недопустимые символы ", index);
	}
	return true;
}

bool BNF::isCellphone(string cellphone, int index)
{
	int size = cellphone.length();
	if (size != 11)
		throw myException("Номер телефона не содержит 11 цифр", index);
	if (cellphone[0] != '8')
		throw myException("Номер телефона начинается не с цифры 8", index);
	for (int i = 1; i < size; i++) {
		if (!(cellphone[i] >= '0' && cellphone[i] <= '9'))
			throw myException("Номер телефона содержит не только цифры", index);
	}

	return true;
}

bool BNF::isValidity(string validity, int index)
{
  int size = validity.length();
	for (int i = 0; i < size; i++) {
		if (!(validity[i] >= '0' && validity[i] <= '9'))
			throw myException("Срок действия абонемента содержит не только цифры", index);
	}

	return true;
}
