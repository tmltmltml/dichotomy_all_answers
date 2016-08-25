//all answers of  the function f(x) = 0  which are in the interval [a,b]，dichotomy

#include <iostream>
#include "fun.h"
#include <cmath>
using namespace std;
double *ans = 0;
int index = 0;

bool scan(const double &, const double &, const double&);                       //equal step san
void dicho(double , double , const double&);                                    //dichotomy
void output(double *, int &);                                                     //output the answers
void add(double);                                                               //add one answer

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
		output(ans, index);
	cout << endl;
	delete []ans;
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
			add(t1);
		else if(fabs(fun(t1 + step_width)) < err * 1e-2 )
			add(t1+=step_width);
		else
			;
		t1 += step_width;
	}
	if(!index)
		return 0;
	return 1;
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
	add((a + b) / 2);
}

void add(double answer)
{
	double *temp = new double[index + 1];                                  //we'd better use "index"
	for(int i = 0; i < index; ++i)
		temp[i] = ans[i];
	temp[index++] = answer;
	delete []ans;
	ans = temp;
}

void output(double *ans, int &index)
{
	for(int i = 0; i < index; ++i)
	{
		cout << ans[i] << ' ';
		if((i + 1) % 5 == 0)
			cout << endl;
	}
}