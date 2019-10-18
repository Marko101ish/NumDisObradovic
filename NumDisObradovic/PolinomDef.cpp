#include "funkcija.h"

double Polinom::Calc(double x)
{
	double res=0;
	res=_koef*pow(x, _exp);
	return res;
}

double Calc(list<Polinom> polyList, double x)
{
	if(!polyList.empty())
	{
		double result=0;
		Polinom pom;
		list<Polinom>::iterator it = polyList.begin();
		do
		{
			pom=*it;
			result+=pom.Calc(x);
			advance(it,1);
		}
		while(it!=polyList.end());
		return result;
	}
	else
	{
		cout<<"Prazna lista!";
		return 0;
	}
}

list<Polinom> ToPoly(string ulaz)
{
	int po=ulaz.find('x');
	double k,e;
	list<Polinom> polyList;
	if(po>-1)
	{
		while(po>-1)
		{
			po=ulaz.find('x');
			if(po>-1)
				k=stod(ulaz);
			else
			{
				polyList.push_back(Polinom(stod(ulaz),0));
				break;
			}
			ulaz=ulaz.substr(po+1);
			e=stod(ulaz);

			Polinom pom(k,e);
			polyList.push_back(pom);

			if(ulaz[0]=='+' || ulaz[0]=='-')
				ulaz=ulaz.substr(1);
			po=fmin(ulaz.find('-'), ulaz.find('+'));
			if(po>-1)
			{
				ulaz=ulaz.substr(po);
			}
		
		}
	}
	else
	{
		try
		{
			polyList.push_back(Polinom(stod(ulaz)));
		}
		catch(int i)
		{
			cout<<"Neodgovarajuc ulaz!"<<endl;
		}
	}
	return polyList;
}

string deleteBlanks(string ulaz)
{
	string izlaz;
	for(int i=0; i<ulaz.length();i++)
	{
		if(ulaz[i]!=' ')
			izlaz+=ulaz[i];
	}
	return izlaz;
}

void ispisPoly(list<Polinom> polyList)
{
	if(!polyList.empty())
	{
		string ispis;
		list<Polinom>::iterator it = polyList.begin();
		do
		{
		Polinom x=*it;
		double koef, exp;
		koef=x.GetKoef();
		exp=x.GetExp();
		if(koef!=0)
		{
			if(koef>0)
				ispis+="+";
			ispis+=to_string(koef);
			if(exp!=0)
			{
				ispis+="x^";
				if(exp>0)
					ispis+="+";
				ispis+=to_string(exp)+" ";
			}
		}
		advance(it,1);
		}
		while(it!=polyList.end());
		cout<<ispis<<endl;
	}
	else
		cout<<"Prazna lista!"<<endl;
}