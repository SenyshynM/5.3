#include <iostream>
#include <cmath>
using namespace std;
double y(const double x);
int main()
{
	double fp, fk, z;
	int n;
	cout << "fp = "; cin >> fp;
	cout << "fk = "; cin >> fk;
	cout << "n = "; cin >> n;
	double dg = (fk - fp) / n;
	double f = fp;
	while (f <= fk)
	{
		z = y(f / 2) + pow(y(f + 1), 2) + y(2 * f);
		cout << f << " " << z << endl;
		f += dg;
	}
	return 0;
}

double y(const double x)
{
	if (abs(x) >= 1)
		return (exp(x) / (1 + exp(x) + sin(x)));
	else
	{
		double S = 0;
		int j = 0;
		double a = -1;
		S = a;
		do
		{
			j++;
			double R = pow(-1, j) * pow(x, 2) / 4 * j * j * pow(-1, j - 1) - 2 * j * pow(-1, j - 1);
			a *= R;
			S += a;
		} while (j < 8);
		return S;
	}
}

// pow(-1, j)* pow(x, 2) / 4 * j * j * pow(-1, j - 1) - 2 * j * pow(-1, j - 1);