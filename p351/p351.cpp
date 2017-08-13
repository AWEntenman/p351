// p351.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
unsigned long n_tot = 0;
unsigned long n_max = 0;
unsigned long n = 0;
unsigned long L = 0;


void aa(
	unsigned long a1,
	unsigned long b1,
	unsigned long a2,
	unsigned long b2)
{
	unsigned long a3 = 0;
	unsigned long b3 = 0;
	unsigned long y1 = 0;
	unsigned long n1 = 0;
	++n_tot;
	if (n_tot > n_max) n_max = n_tot;
	a3 = a1 + a2;
	b3 = b1 + b2;
	y1 = b2 + b3;
	y1 = y1*b3;
	if (y1 <= L)
	{
		n1 = L / y1;
		n = n + n1;
		aa(a1,b1,a3,b3);
		aa(a3, b3, a2, b2);
	}
	--n_tot;
	return;
}


int main()
{
	//const unsigned long s_begin = 1ULL;
	//const unsigned long s_stop = 1000000000000ULL;
	bool ok = true;
	char ch[50];
	clock_t t;
	double timeSec;

	for (; ; )
	{
/*		do {
			ok = true;
			cout << "Enter L\n->";
			cin >> L;
			if ((L < s_begin) || (L > s_stop))
			{
				ok = false;
				L = 0;
				cout << "Error, please enter an L " << s_begin << " and " << s_stop << endl;
			}
		} while (!ok);
*/		cout << "Enter L\n->";
		cin >> L;

//		ok = true;

		cout << "Calculation has begun.\n\n";

		n = 0;
		//start timing
		t = clock();
		aa(0, 1, 1, 1);
		//stop timing
		t = clock() - t;//log current time
		timeSec = double(t) / CLOCKS_PER_SEC;
		//cout << "****** COMPUTATION READY *******\n";
		//cout << "computer time = " << timeSec << " seconds" << endl;
		cout << "F(L) = " << n << ", " << n_max << endl;
		n_max = 0; n = 0;
		//cout << "Enter 'c' to continue, any other to continue ->";
		//cin >> ch;
		//cout << endl;
		//if (ch[0] != 'c')
		//return 0;
	}
	return 0;
}

