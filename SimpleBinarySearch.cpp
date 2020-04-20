/*  HOW TO PROGRAM C++ 10th Edition
    Authors : PAUL DEITEL, HARVEY DEITEL
*/


#include<algorithm>
#include<array>
#include<ctime>
#include<iostream>
#include<random>
using namespace std;


template<typename T, size_t size>
void displayElements(const array<T, size>& item, size_t low, size_t high)
{
	for (size_t i = 0; i < item.size()&& i< low; ++i)
	{
		cout << "   ";
	}
	for (size_t i = low; i < item.size() && i <= high; ++i)
	{
		cout << item[i] << " ";
	}
	cout << endl;
}

template<typename T, size_t size>
int binarySearch(const array<T, size>& item, const T& key)
{
	int low{ 0 };
	int high{ (static_cast<int>(item.size()) - 1) };
	int middle{ ((low + high + 1) / 2) };
	int location = -1;

	do
	{
		displayElements(item, low, high);

		for (int i = 0; i < middle; ++i)
		{
			cout << "   ";
		}
		cout << " * " << endl;

		if (key == item[middle])
		{
			location = middle;
		}
		else if (key < item[middle])
		{
			high = middle - 1;
		}
		else
		{
			low = middle + 1;
		}

		middle = (low + high + 1) / 2;

	} while ((low <= high) && (location == -1));

	return location;
}

int main()
{
	default_random_engine engine{ static_cast<unsigned int>(time(nullptr)) };
	uniform_int_distribution<unsigned int> randomInt{ 10, 99 };

	const size_t arraySize = 15;
	array<int, arraySize> arrayToSearch;

	for (auto& item : arrayToSearch)
	{
		item = randomInt(engine);
	}

	sort(arrayToSearch.begin(), arrayToSearch.end());
	displayElements(arrayToSearch, 0, arrayToSearch.size() - 1);

	cout << "\nPlease enter an integer value: ";
	int searchKey;
	cin >> searchKey;
	cout << endl;

	while (searchKey != -1)
	{
		int position = binarySearch(arrayToSearch, searchKey);

		if (position == -1)
		{
			cout << "The integer " << searchKey << " was not found.\n";
		}
		else
		{
			cout << "The integer " << searchKey << " was found in position " << position << endl;
		}

		cout << "\nPlease enter an integer value: ";
		cin >> searchKey;
		cout << endl;
	}
}
