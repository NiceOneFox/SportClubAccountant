#include "pch.h"
#include "Subscription.h"
#include "BNF.h"


Subscription::Subscription()
{
  fullname_ = "";
	age_ = 0;
	cellphone_ = 0;
	validity_ = 0;
}


Subscription::~Subscription()
{
}

Subscription::Subscription(const Subscription & other)
{
  fullname_ = other.fullname_;
	age_ = other.age_;
	cellphone_ = other.cellphone_;
	validity_ = other.validity_;
}

void Subscription::setFullname(string fullname, int index)
{
  if(BNF::isFullname(fullname, index))
	  fullname_ = fullname;
}

void Subscription::setAge(string age, int index)
{
  if(BNF::isAge(age, index))
	  age_ = stoi(age);
}

void Subscription::setCellphone(string cellphone, int index)
{
  if (BNF::isCellphone(cellphone, index))
	  cellphone_ = stoull(cellphone);
}

void Subscription::setValidity(string validity, int index)
{
  if(BNF::isValidity(validity, index))
	  validity_ = stoi(validity);
}

Subscription & Subscription::operator++()
{
	age_ += 1;
	return *this;
}

bool Subscription::operator==(const Subscription & other)
{
	if (age_ == other.age_)
		return true;

	return false;
}

Subscription & Subscription::operator=(const Subscription & other)
{
	fullname_ = other.fullname_;
	age_ = other.age_;
	cellphone_ = other.cellphone_;
	validity_ = other.validity_;
	return *this;
}

Subscription operator++(Subscription & sub, int)
{
	Subscription temp = sub;
	sub.cellphone_++;
	return temp;
}

bool operator==(const Subscription & sub1, const Subscription & sub2)
{
	if (sub1.validity_ == sub2.validity_)
	  return true;

  return false;
}

bool operator!=(const Subscription & sub1, const Subscription & sub2)
{
	if (sub1.validity_ != sub2.validity_)
		return true;

	return false;
}

bool operator>(const Subscription & sub1, const Subscription & sub2)
{
	if (sub1.fullname_ > sub2.fullname_)
		return true;

	return false;
}

bool operator>=(const Subscription & sub1, const Subscription & sub2)
{
	if (sub1.fullname_ >= sub2.fullname_)
		return true;

	return false;
}

bool operator<(const Subscription & sub1, const Subscription & sub2)
{
	if (sub1.fullname_ < sub2.fullname_)
		return true;

	return false;
}

bool operator<=(const Subscription & sub1, const Subscription & sub2)
{
	if (sub1.fullname_ <= sub2.fullname_)
		return true;

	return false;
}

ostream & operator<<(ostream & os, const Subscription & sub)
{
	os << sub.fullname_ << "  "<< sub.age_ << "  " << sub.cellphone_ << 
	"  " << sub.validity_ << '\n';
	return os;
}

istream & operator>>(istream & is, Subscription & sub)
{
	if (is) {
		is >> sub.fullname_ >> sub.age_ >> sub.cellphone_ >> sub.validity_;
	}
	return is;
}
