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
		cout << error_ << " � " << line_ + 1 << " ������ " << endl;
		return "";
	}
};

