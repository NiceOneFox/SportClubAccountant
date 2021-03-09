#pragma once

class myException
{
private:
	string error_;
	int line_;

public:
	myException() {}
	~myException() {}

	myException(string error, int line) :error_(error), line_(line) {}

	string getError(void)
	{
		cout << error_ << " в " << line_ + 1 << " строке " << endl;
		return "";
	}
};

