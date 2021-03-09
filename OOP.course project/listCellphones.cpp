#include "pch.h"
#include "Subscription.h"
void listCellphones(vector<Subscription> vec_sub)
{
	ofstream fout("output.txt", ios::app);
	if (!fout.is_open())
		throw "Файл не найден";
	else {
		fout <<" =CELLPHONES=" << endl;
		fout << "+-----------+" << endl;
	  for (size_t i = 0; i < vec_sub.size(); i++) {
		  fout << "|" << vec_sub[i].getCellphone() << "|" << endl;
			fout << "+-----------+" << endl;
	  }
	}
}