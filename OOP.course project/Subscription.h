#pragma once
class Subscription
{
public:
	Subscription(); // конструктор без параметров
	~Subscription();

	Subscription(string & fullname, int age, unsigned long long cellphone, int validity):
	  fullname_(fullname), age_(age), cellphone_(cellphone), validity_(validity)
  {}

	Subscription(const Subscription & other); // конструктор копирования

	string getFullname() { return fullname_; }
	int getAge() { return age_; }
	unsigned long long getCellphone() { return cellphone_; }
	int getValidity() { return validity_; }

	void setFullname (string fullname,  int index);
	void setAge      (string age,       int index);
	void setCellphone(string cellphone, int index);
	void setValidity (string validity,  int index);
	
	Subscription & operator ++(); // префиксный инкремент

	friend Subscription operator ++(Subscription &sub, int); // постфиксный

	bool operator ==(const Subscription & other);

	friend bool operator == (const Subscription & sub1, const Subscription & sub2);

	friend bool operator != (const Subscription & sub1, const Subscription & sub2);

	Subscription& operator =(const Subscription & other);

	friend bool operator >  (const Subscription & sub1, const Subscription & sub2);

	friend bool operator >= (const Subscription & sub1, const Subscription & sub2);

	friend bool operator <  (const Subscription & sub1, const Subscription & sub2);

	friend bool operator <= (const Subscription & sub1, const Subscription & sub2);

	friend ostream& operator <<(ostream& os, const Subscription & sub);

	friend istream& operator >>(istream& is, Subscription & sub);

	
	friend void mostValidity(vector<Subscription> & vec_sub);

	friend void outAllSubscriptions(vector<Subscription> & vec_sub);

	friend void inputSubscriptions(vector<Subscription> & vec_sub, const string & file);

private:
  string fullname_; // фио
	int age_;
	unsigned long long cellphone_;
	int validity_; // срок действия
};

void listCellphones(vector<Subscription> vec_sub);

template<class T>
void insertSortByFullname(std::vector<T> & vec_s)
{
	for (size_t i = 1; i < vec_s.size(); i++)
	{
		if (vec_s[i] < vec_s[i - 1])
		{
			T temp = move(vec_s[i]);

			int idx = i;
			for (; idx != 0 && temp < vec_s[idx - 1]; idx--)
			{
				vec_s[idx] = move(vec_s[idx - 1]);
			}
			vec_s[idx] = temp;
		}
	}
}

