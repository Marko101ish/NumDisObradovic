#include <list> 
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

class Polinom 
{
	double _koef, _exp;
	

public:
	Polinom(double koef=0, double exp=0)
	{
		_koef=koef;
		_exp=exp;
	}
	double GetKoef()
	{
		return _koef;
	}
	double GetExp()
	{
		return _exp;
	}
	void SetKoef(double koef)
	{
		_koef=koef;
	}
	void SetExp(double exp)
	{
		_exp=exp;
	}
	double Calc(double);
};

double Calc(list<Polinom>, double);
list<Polinom> ToPoly(string);
string deleteBlanks(string);
void ispisPoly(list<Polinom>);