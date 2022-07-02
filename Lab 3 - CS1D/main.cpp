/******************************************************************************
 * NAME   : Aaris & Jake
 * CLASS  : CS1D
 * DATE   : 01-25-17
 * LAB #3 : Prefix Averages
 ******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <vector>

using namespace std;

void prefixAverages1 (vector<int>& vec1, vector<int>& vec2, const int SIZE);
void prefixAverages2 (vector<int>& vec1, vector<int>& vec2, const int SIZE);
void InitializeVector(vector<int> &a, int SIZE);

int main()
{

	const int SIZE = 5;
	vector<int> a;
	vector<int> b;
	clock_t t;



	t = clock();
	InitializeVector(a,SIZE);
	cout << endl << endl;

	prefixAverages1 (a,b,SIZE);
	prefixAverages1 (a,b,SIZE);

	t = clock()-t;

	printf("(%f)", ((float)t)/CLOCKS_PER_SEC);

	return 0;
}

//
void prefixAverages1 (vector<int>& vec1,vector<int>& vec2, const int SIZE)
{
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
        {
            sum += vec1[i];
            vec2.push_back(sum/(i+1));
            cout << vec2[i]<< " ";
        }
}

//
void InitializeVector(vector<int> &a, int SIZE)
{
	srand(time(NULL));
	for(int i =0; i < SIZE; i++)
	{

		a.push_back(rand()%99+1);
		cout << a[i] << " ";
	}
}

//
void prefixAverages2 (vector<int>& vec1,vector<int>& vec2,const int SIZE)
{
        for (int i = 0; i < SIZE; i++)
        {
            double sum = 0;
            for (int j = 0; j <= i; j++) {
                sum += vec1[j];
            }
            vec2.push_back(sum/(i+1));
        }
}

