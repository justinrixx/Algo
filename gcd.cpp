#include <iostream>
#include <cstdlib>

using namespace std;

/* Euclidean GCD */
int euclideanGCD(int a, int b);

/* LCM */
int LCM(int a, int b);

int main(int argc, char ** argv)
{
	if (argc != 3)
	{
		cout << "Usage: " << argv[0] << " arg1 arg2" << endl;
		return 1;
	}

	cout << "GCD: " << euclideanGCD(atoi(argv[1]), atoi(argv[2])) << endl
		 << "LCM: " << LCM(atoi(argv[1]), atoi(argv[2])) << endl;

	return 0;
}

/* Calculate the GCD using Euclid's algorithm */
int euclideanGCD(int a, int b)
{
	while (b != 0)
	{
		int t = b;
		b = a % b;
		a = t;
	}

	return a;
}

int LCM(int a, int b)
{
	return (a * b) / euclideanGCD(a, b);
}
