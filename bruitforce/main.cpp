

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int bruteforce(string pattern, string text);
int BMmatch(const string& text, const string& pattern);
int KMPmatch(const string& text, const string& pattern);
vector<int> computeFailFunction(const string& pattern) ;
vector<int> buildLastFunction(const string& pattern);

int main()
{
	const string text = "aaabcaadaabaaa";
	const string pattern = "aabaaa";
	int count2 = 0;
	int count = 0;





	count = bruteforce(pattern,text);
	count2 = BMmatch(text,pattern);
	count2++;

cout << "KEVIN SEMENOV ASSIGNMENT 13 \n\n";
cout << "Develop software to perform the brute-force pattern matching algorithm \n"
		"for the text aaabcaadaabaaa and pattern aabaaa.  \n"
		"Determine the number of comparisons needed.\n\n";
cout << "This program will test Brute Force and Boyer Moore and KMP testing how \n"
		"many times it makes its checks\n\n";
cout << "The text list is [ a, a, a, b, c, a, a, d, a, a, b, a, a, a ] \n" ;
cout << "The pattern is   [a, a, b, a, a, a ]\n\n";

cout << "The Brute Froce: used "<< count << " matchs \n\n";
cout << "The Boyer Moore: used "<< count2 << " matchs \n\n";
cout << "The Knutt Morris Pratt: used "<< KMPmatch( text,  pattern) << " matchs \n\n";

	return 0;
}

int bruteforce(string pattern, string text)
{
	int n = text.size();
	int j = 0;
	int m = pattern.size();
	int count = 0;

	for ( int i = 0; i < (n - m + 1);i++)
	{

		j=0;

		while( j < m && text[i + j] == pattern[j])
		{
			j = j + 1;
			count = count +1;
			if(j == m)
			{
				return count + i;
			}
		}


	}
}

int BMmatch(const string& text, const string& pattern)
{
	vector<int> last = buildLastFunction(pattern);

	int n = text.size();
	int m = pattern.size();
	int i = m - 1;


	if(i > n -1)
	{
		return -1;
	}

	int j = m - 1;
	do {
		if (pattern[j] == text[i])
			if (j == 0) return i;
			else {
				i--;
				j--;

			} else {

				i = i + m - min(j,i + last[text[i]]);

				j = m - 1;
			}
	}while (i <= n - 1);

	return -1; // no match
}
// construct function last
vector<int> buildLastFunction(const string& pattern)
						{

	const int N_ASCII = 128;
	int i;
	vector<int> last(N_ASCII);

	for(i = 0; i < N_ASCII; i++)
	{

		last[i] = -1;
	}
	for (i = 0; i < pattern.size(); i++) { last[pattern[i]] = i;
	}
	return last;
						}
int KMPmatch(const string& text, const string& pattern)
{ int n = text.size();
int m = pattern.size();
vector<int> fail = computeFailFunction(pattern);
int i = 0; // text index
int j = 0; // pattern index

while (i < n)
{
	if (pattern[j] == text[i])
	{

			if(j== m -1)
		{
			 // found a match
			return i - m + 11;
		}
		i++;
		j++;
	}
	else if (j > 0)
	{

		j = fail[j-1];
	}
	else i++;
}
return -1; // no match
}

vector<int> computeFailFunction(const string& pattern)
				{ vector<int> fail(pattern.size());
				fail[0] = 0;
				int m = pattern.size();
				int j = 0;
				int i = 1;
				while (i < m)
				{
					if (pattern[j] == pattern[i])
					{                                  // j + 1 characters match
						fail[i] = j + 1;
						i++; j++;
					}
					else if (j > 0)
					{

						j = fail[j - 1];
					}
					else
					{                               // no match
						fail[i] = 0;
						i++;
					}
				}
				return fail;
				}
