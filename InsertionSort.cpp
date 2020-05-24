/*  HOW TO PROGRAM C++ 10th Edition
    Authors : PAUL DEITEL, HARVEY DEITEL
*/

#include<array>
#include<iomanip>
#include<iostream>
using namespace std;

template <typename T, size_t size>
void insertionSort(array<T, size>& item)
{
	for (size_t next = 1; next < item.size(); ++next)
	{
		T insert = item[next];
		size_t moveIndex = next;

		while ((moveIndex > 0) && (item[moveIndex - 1] > insert))
		{
			item[moveIndex] = item[moveIndex - 1];
			--moveIndex;
		}

		item[moveIndex] = insert;
	}
}

int main()
{
	const size_t arraysize = 10;
	array<int, arraysize> line = { 3,4,1,2,8,7,9,10,5,6 };

	cout << "Unsort array: \n";
	for (int i = 0; i < line.size(); i++)
	{
		cout << line[i];
		cout << endl;
	}

	insertionSort(line);

	cout << "\nSort array: \n";

	for (int i = 0; i < line.size(); i++)
	{
		cout << line[i];
		cout << endl;
	}
}
