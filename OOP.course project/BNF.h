#pragma once
#include "myException.h"
class BNF
{
public:
  
	bool static isFullname (string fullname, int index);

	bool static isAge      (string age, int index);

	bool static isCellphone(string cellphone, int index);

	bool static isValidity (string validity, int index);

};

