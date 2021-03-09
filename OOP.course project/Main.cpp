#include "pch.h"
#include "myException.h"
#include "Subscription.h"
#include "BNF.h"

//1. Фамилия и инициалы клиента
//
//2. Возраст клиента
//
//3. Номер телефона
//
//4. срок действия абонемента
//
//Вывести абонемента с самыим большим сроком действия абонемента 
//
//Сортировка методом простых вставок по фамилии и инициалам.
//
//Список номеров клиентов.

int main()
{
	try {
		setlocale(LC_ALL, "Rus");

		string file;
		cout << "Введите название файла: \n";
		cin >> file;

		vector<Subscription> vec_sub;

		inputSubscriptions(vec_sub, file); //  ввод из файла

		outAllSubscriptions(vec_sub); // вывод в файл

		insertSortByFullname(vec_sub); // сортировка вставками по фамилии и инициалам

		mostValidity(vec_sub); // подписка с самым длительным сроком действия

		listCellphones(vec_sub); // список всех телефонов

	}
	catch (myException& ex) {
		cerr << ex.getError() << endl;
		return -1;
	}
	catch (const char* errorString) {
		cerr << errorString << endl;
		return -1;
	}

	return 0;
}
