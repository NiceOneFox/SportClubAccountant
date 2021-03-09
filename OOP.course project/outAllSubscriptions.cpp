#include "pch.h"
#include "Subscription.h"

void outAllSubscriptions(vector<Subscription> & vec_sub)
{
	ofstream fout("output.txt", ios::out);
	if (!fout.is_open())
		throw "Файл не найден";
	else {
		fout << " =FULLNAME=" << "       =AGE=" << "  =CELLPHONE=" << "    =VALIDITY=" << endl;
		fout << "+-------------------------------------------------+\n";
		for (size_t i = 0; i < vec_sub.size(); i++) {
			fout << "|" << setw(18) << left << vec_sub[i].fullname_ << setw(6) << left << vec_sub[i].age_ <<
				setw(18) << left << vec_sub[i].cellphone_ << setw(7) << left << vec_sub[i].validity_ << "|" << endl;
			fout << "+-------------------------------------------------+\n";
		}

		fout << endl;
		fout.close();
	}
}