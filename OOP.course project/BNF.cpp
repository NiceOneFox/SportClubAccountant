#include "pch.h"
#include "BNF.h"

bool BNF::isFullname(string fullname, int index)
{
	int size = fullname.length();
	if (fullname[0] != toupper(fullname[0]))
		throw myException("������� ���������� �� � ��������� ����� ", index);

	for (int i = 1; i < size; i++) {

		if (!(fullname[i] >= 'a' && fullname[i] <= 'z'))
			if (fullname[i] != ' ')
				throw myException("� ������� ����������� ������ ��� ��������� ����� ", index);

		if (fullname[i] == ' ') { // �������� ���������
			if (fullname[i + 1] != toupper(fullname[i + 1]) ||
				fullname[i + 3] != toupper(fullname[i + 3]))
				throw myException("�������� ������ �� � ��������� �����", index);

			if (fullname[i + 2] != '.' || fullname[i + 4] != '.')
				throw myException("����� ��������� ����������� �����", index);

			if (size != i + 5)
				throw myException("��� �������� ����������� ������� ����� ���������", index);
			break;
		}
	}
	return true;
}

bool BNF::isAge(string age, int index)
{
  int size = age.length();
  if (size >= 4)
	  throw myException("������� �������� ����������� ������� �����", index);
	for (int i = 0; i < size; i++) {
		if (!(age[i] >= '0' && age[i] <= '9'))
			throw myException("������� �������� ������������ ������� ", index);
	}
	return true;
}

bool BNF::isCellphone(string cellphone, int index)
{
	int size = cellphone.length();
	if (size != 11)
		throw myException("����� �������� �� �������� 11 ����", index);
	if (cellphone[0] != '8')
		throw myException("����� �������� ���������� �� � ����� 8", index);
	for (int i = 1; i < size; i++) {
		if (!(cellphone[i] >= '0' && cellphone[i] <= '9'))
			throw myException("����� �������� �������� �� ������ �����", index);
	}

	return true;
}

bool BNF::isValidity(string validity, int index)
{
  int size = validity.length();
	for (int i = 0; i < size; i++) {
		if (!(validity[i] >= '0' && validity[i] <= '9'))
			throw myException("���� �������� ���������� �������� �� ������ �����", index);
	}

	return true;
}
