// website : https://www.bogotobogo.com/Algorithms/bucketsort.php 
#include<iostream>
#include<iomanip>
using namespace std;

const int arraySize = 10;
const int bucket = 10;
const int interval = 10;

struct Node
{
	int data;
	struct Node* next;
};

void BucketSort(int arr[]);
struct Node* InsertionSort(struct Node* list);
void print(int arr[]);
void printBucket(struct Node* list);
int getBucketIndex(int value);


void BucketSort(int arr[])
{
	int i, j;
	struct Node** buckets;

	buckets = (struct Node**)malloc(sizeof(struct Node*) * bucket);

	for (i = 0; i < arraySize; ++i)
	{
		buckets[i] = NULL;
	}

	for (i = 0; i < arraySize; ++i)
	{
		struct Node* current;
		int pos = getBucketIndex(arr[i]);
		current = (struct Node*) malloc(sizeof(struct Node));
		current->data = arr[i];
		current->next = buckets[pos];
		buckets[pos] = current;
	}

	for (i = 0; i < bucket; i++)
	{
		cout << "Bucket[" << i << "] : ";
		printBucket(buckets[i]);
		cout << endl;
	}

	for (i = 0; i < bucket; ++i)
	{
		buckets[i] = InsertionSort(buckets[i]);
	}

	cout << "------------------------------" << endl;
	cout << "Buckets after sorted" << endl;
	for (i = 0; i < bucket; ++i)
	{
		cout << "Bucket[" << i << "] : ";
		printBucket(buckets[i]);
		cout << endl;
	}

	for (j = 0, i = 0; i < bucket; ++i)
	{
		struct Node* node;
		node = buckets[i];
		while (node)
		{
			arr[j++] = node->data;
			node = node->next;
		}
	}

	for (i = 0; i < bucket; ++i)
	{
		struct Node* node;
		node = buckets[i];
		while (node)
		{
			struct Node* temp;
			temp = node;
			node = node->next;
			delete temp;
		}
	}
}
struct Node* InsertionSort(struct Node* list)
{
	struct Node* k, * nodeList;
	if (list == 0 || list->next == 0)
	{
		return list;
	}
	nodeList = list;
	k = list->next;
	nodeList->next = 0;

	while (k != 0)
	{
		struct Node* ptr;
		if (nodeList->data > k->data)
		{
			struct Node* temp;
			temp = k;
			k = k->next;
			temp->next = nodeList;
			nodeList = temp;
			continue;
		}
		for (ptr = nodeList; ptr->next != 0; ptr = ptr->next)
		{
			if (ptr->next->data > k->data)
				break;
		}
		if (ptr->next != 0)
		{
			struct Node* temp;
			temp = k;
			k = k->next;
			temp->next = ptr->next;
			ptr->next = temp;
			continue;
		}
		else
		{
			ptr->next = k;
			k = k->next;
			ptr->next->next = 0;
			continue;
		}
	}
	return nodeList;
}

int getBucketIndex(int value)
{
	return value / interval;
}
void print(int arr[])
{
	int i;
	for (i = 0; i < arraySize; ++i)
	{
		cout << setw(3) << arr[i];
	}
	cout << endl;
}
void printBucket(struct Node* list)
{
	struct Node* current = list;
	while (current)
	{
		cout << setw(3) << current->data;
		current = current->next;
	}
}

int main()
{
	int array[arraySize];
	int number;
	for (int i = 0; i < arraySize; i++)
	{
		cout << "Enter number in Array: ";
		cin >> number;
		array[i] = number;
	}
	cout << "Unsorted Array: \n";
	print(array);
	cout << "------------------------------" << endl;

	BucketSort(array);
	cout << "\nAfter Sorting: \n";
	print(array);
	return 0;
}
