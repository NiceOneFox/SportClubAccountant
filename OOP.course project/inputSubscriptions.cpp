#include "pch.h"
#include "Subscription.h"

void inputSubscriptions(vector<Subscription> & vec_sub, const string & file)
{
	string fullname;
	string age;
	string cellphone;
	string validity;
	int line = 0;

	ifstream fin(file, ios::in);
	if (!fin.is_open())
		throw "Файл не найден";
	else {
		for (; getline(fin, fullname, '|'); line++) {
			getline(fin, age, '|');
			getline(fin, cellphone, '|');
			getline(fin, validity);

			Subscription temp;
			temp.setFullname(fullname, line);
			temp.setAge(age, line);
			temp.setCellphone(cellphone, line);
			temp.setValidity(validity, line);

			vec_sub.push_back(temp);
		}
	}
}