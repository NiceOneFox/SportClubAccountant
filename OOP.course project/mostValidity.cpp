#include "pch.h"
#include "Subscription.h"

void mostValidity(vector<Subscription> & vec_sub)
{
	Subscription max;
	for (size_t i = 0; i < vec_sub.size(); i++) {
     if (vec_sub[i].validity_ > max.validity_)
		   max = vec_sub[i];
	}

	ofstream fout("output.txt", ios::app);
	if (!fout.is_open())
		throw "Файл не найден";
	else {
	  fout << "   ===Subscription with most time validity===" << endl;
		fout << " =FULLNAME=" << "       =AGE=" << "  =CELLPHONE=" << "    =VALIDITY=" << endl;
		fout << "+-------------------------------------------------+\n";
		fout << "|" << setw(18) << left << max.fullname_ << setw(6) << left << max.age_ <<
		  setw(18) << left  << max.cellphone_ << setw(7) << left << max.validity_ << "|" << endl;
		fout << "+-------------------------------------------------+\n";
		fout << endl;
		fout.close();
	}
}