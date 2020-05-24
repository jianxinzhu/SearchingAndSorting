  
/*  HOW TO PROGRAM C++ 10th Edition
    Authors : PAUL DEITEL, HARVEY DEITEL
*/
#include<array>
#include<ctime>
#include<iostream>
#include<random>
using namespace std;

template <typename T, size_t size>
void displayElement(const array<T, size>& item, size_t low, size_t high)
{
	for (size_t i = 0; i < item.size() && i < low; ++i)
	{
		cout << "   ";
	}
	for (size_t i = low; i < item.size() && i < high; ++i)
	{
		cout << item[i] << " ";
	}
	cout << endl;
}
template<typename T, size_t size>
void merge(array<T, size>& item, size_t left, size_t middle1, size_t middle2, size_t right)
{
	size_t leftIndex{ left };
	size_t rightIndex{ middle2 };
	size_t combinedIndex{ left };
	array<T, size>combined;

	cout << "Merge:    ";
	displayElement(item, left, middle1);
	cout << "          ";
	displayElement(item, middle2, right);
	cout << endl;

	while (leftIndex <= middle1 && rightIndex <= right)
	{
		if (item[leftIndex] <= item[rightIndex])
		{
			combined[combinedIndex++] = item[leftIndex++];
		}
		else
		{
			combined[combinedIndex++] = item[rightIndex++];
		}
	}

	if (leftIndex == middle2)
	{
		while (rightIndex <= right)
		{
			combined[combinedIndex++] = item[rightIndex++];
		}
	}
	else
	{
		while (leftIndex <= middle1)
		{
			combined[combinedIndex++] = item[leftIndex++];
		}
	}

	for (size_t i = left; i <= right; ++i)
	{
		item[i] = combined[i];
	}

	cout << "           ";
	displayElement(item, left, right);
	cout << endl;
}

template <typename T, size_t size>
void mergeSort(array<T, size>& item, size_t low, size_t high)
{
	if ((high - low) >= 1)
	{
		int middle1 = (low + high) / 2;
		int middle2 = (middle1 + 1);

		cout << "Split:  ";
		displayElement(item, low, high);
		cout << "        ";
		displayElement(item, low, middle1);
		cout << "        ";
		displayElement(item, middle2, high);

		mergeSort(item, low, middle1);
		mergeSort(item, middle2, high);

		merge(item, low, middle1, middle2, high);

	}
}

int main()
{
	default_random_engine enginer{ static_cast<unsigned int>(time(nullptr)) };
	uniform_int_distribution<unsigned int> ramdonInt{ 1, 99 };

	const size_t arraySize{ 10 };
	array<int, arraySize> data;

	for (int& item : data)
	{
		item = ramdonInt(enginer);
	}

	cout << "Unsorted array: " << endl;
	displayElement(data, 0, data.size() - 1);
	cout << endl;

	mergeSort(data, 0, data.size() - 1);

	cout << "\nSorted array: \n";
	displayElement(data, 0, data.size() - 1);
}
