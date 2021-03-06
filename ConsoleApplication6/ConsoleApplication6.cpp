#include <iostream>
#include <string>

#include<omp.h>
using namespace std;
int main()
{
	int y = 0;
	do
	{
		string str; string s; string s1, s2, s3, s4; int k3 = 0; int k4 = 0; y = 0;
		double ao, bo, co;
		ao = omp_get_wtime();
		int l; int n; int l1; int p; int t1; int t2; int j;
		int i; int t; int c = 0, c1 = 0; int k = 0; int k1 = 0; int k2 = 0;
		cout << "\nEnter the genome sequence:\t";
		cin >> str;
		l = str.length();
		cout << "\nEnter the sequence to be found\n";
		cin >> s;
		l1 = s.length();
		cout << "\nLength of " << str << " is " << l << endl;
		s1 = str.substr(0, 4);
		int tid; int ind;

		if (l % 4 != 0)
			p = l + (l % 4);
		t = p / 4;
		t1 = t;
		s1 = str.substr(0, t1); //cout << t1 << s1<<" "<<endl;
		t2 = t1 + t;
		s2 = str.substr(t1, t); //cout << t1 <<" "<<s2<<t2<< endl;
		t1 = t2;
		t2 = t1 + t;
		s3 = str.substr(t1, t); //cout << t1 << s3<<" "<<t2<<endl;
		//t2 = t1 + t;
		t1 = t2;
		s4 = str.substr(t1, l); //cout << t1 << s4 << " " << endl;
		cout << "The partitions are :" << endl;
		cout << "1." << s1 << endl;
		cout << "2." << s2 << endl;
		cout << "3." << s3 << endl;
		cout << "4." << s4 << endl;
		//cout << s1 << " " << s2 << " " << s3 << " " << s4 << endl;
		omp_set_num_threads(4);
		tid = omp_get_thread_num();
		int max = omp_get_max_threads();
		cout << "Maximum number of threads used are " << max << endl;
#pragma omp parallel
		{
			//cout << "Tid is " << tid << endl;
			if (tid == 0)
			{
				//cout << "hello" << endl;
				int l2; string sub; int x;

				l2 = s1.length();
				ind = s1.find(s);
				if (ind != -1)
				{
					cout << "Sequence has been detected at position " << ind << " of the first partition " << endl;
					k2 = 1;
				}

			}

			if (tid == 0)
			{
				//cout << "hello" << endl;
				int l2; string sub; int x;

				l2 = s2.length();
				ind = s2.find(s);
				//cout << "S is: " << s << " " << "Sub is: " << s2 << " "<< endl;
				if (ind != -1)
				{
					cout << "Sequence has been detected at position " << ind << " of the second partition " << endl;
					k2 = 1;
				}
			}

			if (tid == 0)
			{
				//cout << "hello" << endl;
				int l2; string sub; int x;

				l2 = s3.length();
				ind = s4.find(s);
				if (ind != -1)
				{
					cout << "Sequence has been detected at position " << ind << " of the third partition " << endl;
					k2 = 1;
				}
			}

			if (tid == 0)
			{
				//cout << "hello" << endl;
				int l2; string sub; int x;

				l2 = s4.length();
				ind = s4.find(s);
				if (ind != -1)
				{
					cout << "Sequence has been detected at position " << ind << " of the fourth partition " << endl;
					k2 = 1;
				}
			}

		}
		if (k2 == 1)
			cout << "Sequence successfully detected " << endl;
		else
			cout << "The given DNA doesn't exist in the given sequence" << endl;
		if (k2 != 1)
		{
			if (l % 2 != 0)
				p = l + (l % 2);
			t = p / 2;
			s1 = str.substr(0, t);
			s2 = str.substr(t, l);
			cout << "On merging:" << endl;
			cout << "1." << s1 << endl;
			cout << "2." << s2 << endl;
#pragma omp parallel
			{
				if (tid == 0)
				{
					//cout << "hello" << endl;
					int l2; string sub; int x;

					l2 = s1.length();
					ind = s1.find(s);
					if (ind != -1)
					{
						cout << "Sequence has been detected at position " << ind << " of the first partition " << endl;
						k3 = 1;
					}

				}

				if (tid == 0)
				{
					//cout << "hello" << endl;
					int l2; string sub; int x;

					l2 = s2.length();
					ind = s2.find(s);
					//cout << "S is: " << s << " " << "Sub is: " << s2 << " "<< endl;
					if (ind != -1)
					{
						cout << "Sequence has been detected at position " << ind << " of the second partition " << endl;
						k3 = 1;
					}
				}
			}
			if (k3 == 1)
				cout << "Sequence successfully detected on merging" << endl;
			else
				cout << "The given DNA doesn't exist in the given sequence on merging" << endl;
		}
		if (k3 != 1 && k2!=1)
		{
			ind = s2.find(s);
			//cout << "S is: " << s << " " << "Sub is: " << s2 << " "<< endl;
			if (ind != -1)
			{
				cout << "Sequence has been detected at position " << ind << " after final merge operation " << endl;

			}
			else
				cout << "The given DNA strand doesnt exist anywhere in the sequence" << endl;
		}
		bo = omp_get_wtime();
		co = bo - ao;
		cout << "Time taken to carry out the operation is " << co << endl;
		cout << "Enter 1 to search again" << endl;
		cin >> y;
	}while (y = 1);
	return 0;
}
