#include <iostream>

using namespace std;

class TemperatureScales
{
public:
	double convert(int f1, int b1, int f2, int b2, int t);
};

double TemperatureScales::convert(int f1, int b1, int f2, int b2, int t)
{
	double a, b;

	a = ( (double)(f2 - b2) ) / (f1 - b1);
	b = ( (double)(f1*b2 - f2*b1) ) / (f1 - b1);
	return (double)(a * t + b);
}

int main()
{

	return 0;
}