/*     name: jianxin zhu
       date: may/24/2020
*/

#include<random>
#include<iostream>
#include<ctime>
#include<array>

using namespace std;


template <typename T, size_t size>
void bubbleSort(array<T, size>& item)
{
	for (int i = 0; i < size; i++)
	{
		int swap = 0;
		for (int j = 0; j < size - i- 1; j++)
		{
			if (item[j] > item[j+1])
			{
				int temp = item[j];
				item[j] = item[j+1];
				item[j+1] = temp;
				swap++;
			}
		}
		if (swap == 0)
			break;
	}
}
template <typename T, size_t size>
void printArray(array<T, size>& item)
{
	for (int i = 0; i < size; i++)
	{
		cout << item[i] << " ";
	}
	cout << endl;
}

int main()
{
	const size_t arraySize = 10;
	default_random_engine engine{ static_cast<unsigned int>(time(nullptr)) };
	uniform_int_distribution<unsigned int> ramdonInt{ 1,99 };

	array<int, arraySize> data;

	for (auto& i : data)
	{
		i = ramdonInt(engine);
	}

	cout << "Unsorted Array: \n";
	printArray(data);

	bubbleSort(data);
	cout << "\nAfter Sorting: \n";
	printArray(data);
}
