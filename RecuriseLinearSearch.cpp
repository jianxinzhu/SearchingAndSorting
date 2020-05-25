 /*    name: jianxin zhu
     date : may/24/2020
*/
#include<iostream>
#include<array>
#include<random>
using namespace std;

template <typename T, size_t size>
int recuriseLinearSearch(array<T, size>& item, T& key, size_t i)
{
	if (item[i] == key)
	{
		if (i == 0)
		{
			return 1;
		}
		else
		{
			return i+1;
		}
	}
	else if (i == item.size())
	{
		return -1;
	}

	return recuriseLinearSearch(item, key, ++i);
}
template<typename T, size_t size>
void printArray(array<T, size>& item)
{
	for (auto& i : item)
	{
		cout << i << " ";
	}
	cout << endl;
}

int main()
{
	const int arraySize = 30;
	array<int, arraySize>data;

	int key;

	for (auto& i : data)
	{
		i = rand() % 50 + 1;
	}

	cout << "Array contain : \n";
	printArray(data);

	cout << "Enter the Key Value: ";
	cin >> key;


	int element = recuriseLinearSearch(data, key, 0);
	if (element != -1)
	{
		cout << "\nThe Key " << key << " is found in " << element << endl;
	}
	else
	{
		cout << "\nThe Key " << key << " do not found" << endl;
	}
}
