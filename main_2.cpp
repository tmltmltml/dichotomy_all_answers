//all answers of  the function f(x) = 0  which are in the interval [a,b]，dichotomy

#include <iostream>
#include "fun.h"
#include <cmath>
#include  <vector>
using namespace std;

bool scan(const double &, const double &, const double&);                       //equal step san
void dicho(double , double , const double&);                                    //dichotomy

vector<double> vd;

int main()
{
	double a, b;
	cout << "input a, b(a < b)" << endl;
	cin >> a >> b;
	cout <<"input degree of accuracy(scientific notation):" << endl;
	double err;
	cin >> scientific >> err;

	if(!scan(a, b, err))
		cout << "no answer(s)!" << endl;
	else
		for(const auto &i : vd)
			cout << i << ' ';
	cout << endl;
	return 0;
}

bool scan(const double &a, const double &b,const double &err)
{
	double step_width = (b - a) / (1e2);                                     
	double t1 = a;                                                           //set left and right end points
	while((t1 + step_width) <= b)
	{
		if((fun(t1) * fun(t1 + step_width)) < 0 && fun(t1) * fun(t1 + step_width) < -err * 1e-2)                               //there is one answer in the interval
			dicho(t1, t1 + step_width, err);
		else if(fabs(fun(t1)) < err * 1e-2) 
			vd.push_back(t1);
		else if(fabs(fun(t1 + step_width)) < err * 1e-2)
			vd.push_back(t1+=step_width);
		else
			;
		t1 += step_width;
	}
	return !vd.empty();
}

void dicho(double a, double b, const double &err)
{
	while((b - a) > err)
	{
		double c = (a + b) / 2;
		if(fabs(fun(c)) < err)
			break;
		else
			if(fun(a) * fun(c) < 0)
				b = c;
			else
				a = c;
	}
	vd.push_back((a + b) / 2);
}
