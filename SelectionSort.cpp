/*  HOW TO PROGRAM C++ 10th Edition
    Authors : PAUL DEITEL, HARVEY DEITEL
*/
#include<array>
#include<iomanip>
#include<iostream>
using namespace std;


template <typename T, size_t size>
void selectionSort(array<T, size>& item)
{
	for (size_t i{ 0 }; i < item.size() - 1; ++i)
	{
		size_t indexOfsmallest = i;
		for (size_t index{ i + 1 }; index < item.size(); ++index)
		{
			if (item[index] < item[indexOfsmallest])
			{
				indexOfsmallest = index;
			}

			T hold = item[i];
			item[i] = item[indexOfsmallest];
			item[indexOfsmallest] = hold;
		}
	}
}

int main()
{
	const size_t arraySize = 10;
	array<int, arraySize> data{ 10,34,50,60,90,100,22,73,12, 33};

	cout << "Unsort Array: \n";
	for (int i = 0; i < arraySize; i++)
	{
		cout << data[i] << setw(4);
	}

	selectionSort(data);
	cout << "\nAfter selection Sorting: \n";
	for (int i = 0; i < arraySize; i++)
	{
		cout << data[i] << setw(4);
	}
}
