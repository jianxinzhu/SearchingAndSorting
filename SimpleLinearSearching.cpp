/*  C++ HOW TO PROGRAM 10th Edition
    Authors: PAUL DEITEL, HARVEY DEITEL
*/

#include<iostream>
#include<array>

using namespace std;

template<typename T, size_t size>
int linearSearch(const array<T, size>& item, const T& key)
{
     for (size_t i=0; i<= item.size(); ++i)
       {
            if(key == item[i])
              {
                 return i;
              }
       }
       return -1;
 }
 
 int main()
 {
     const size_t arraySize = 100;
     int flag,key;
     array<int, arraySize>array1;
     
     
     for (int i = 0; i < 100; ++i)
         {
             array1[i] = i*2;
         }
   cout<<"Enter the key value: ";
   cin>>key;
   flag = linearSearch(array1, key);
   if (flag == -1)
   {
      cout<<"The key value does not found..."<<endl;
   }
   else
   {
      cout<<"The key value is in "<<flag<<endl;
   }
 }
   
