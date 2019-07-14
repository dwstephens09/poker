/* File: SortingList.cpp
 * Course: CS216-00x
 * Project: Lab12 (as the second part of project 3)
 * Purpose: the implementation of member functions for the SortingList class.
 *          it stores a sequence of Building objects to perform sorting operation
 *          it will be modified to a template class
 *
 */
#ifndef SORTINGLIST_CPP
#define SORTINGLIST_CPP


#include <iostream>
#include <algorithm>  //std::swap (c++98)  it is defined in <utility> in c++11
#include "SortingList.h"

// inserts the newitem to the end of the current vector   
template<class T> void SortingList<T>::insert(T newitem)
{
    items.push_back(newitem);
}

// return how many items in the list
template<class T> int SortingList<T>::size()
{
    return items.size();
}

// operator overloading for "[]"
// provide the direct access by index number
template<class T> T& SortingList<T>::operator[](int index)
{
    if (index >= size() || index < 0)
        cout << "Warning:: invalid index number!!!" << endl;
    return items[index];
}

// sort all items in ascending order 
// the items are compared using operator "<"
// using sort() from standard library
template<class T> void SortingList<T>::sort()
{
    std::sort(items.begin(), items.end());
}

// provide different sorting algorithms 
// based on comparison defined by the function passing in as parameter

// apply selection sorting algorithm
template<class T> void SortingList<T>::selection_sort(int (*compare)(const T& b1, const T& b2))
{
    size_t min_index = 0;
    for(size_t i = 0; i < items.size()-1 ; i++) 
    {
        min_index = i;
        for(size_t j = i+1; j < items.size(); j++) 
        {
            // find the index of the minimum from the current sequence 	
            if((*compare)(items[min_index],items[j]) < 0)
            {
                min_index = j;
            }
        }
        // if min_index != i, swap these two
        if (min_index != i) 
            swap(items[i], items[min_index]);
    }
}

// apply bubble sorting algorithm
template<class T> void SortingList<T>::bubble_sort(int (*compare)(const T& b1, const T& b2))
{
    for(size_t i = 1; i < items.size(); i++) 
    {
        for(size_t j = 0; j < items.size() - 1; j++) 
        {
            if((*compare)(items[j],items[j+1]) < 0) 
                swap(items[j], items[j+1]);
        }
    }
}

// apply merge sorting algorithm
template<class T> void SortingList<T>::merge_sort(int (*compare)(const T& b1, const T& b2))
{
    merge_sortHelper(0, items.size() - 1, (*compare));
}

// apply shuffle algorithm
template<class T> void SortingList<T>::shuffle()
{
    for(size_t i = items.size()-1; i > 1; i--)
    {
        // j = random integer with 0 <= j <= i
        //swap(A[j], A[i])
        size_t j = rand() % (i+1);
        swap(items[i], items[j]);		
    } 
}

// display all the items
template<class T> void SortingList<T>::print()
{
    for(size_t i = 0; i < items.size(); i++){
        cout << items[i] << endl;
    }
    cout<<endl;
}

// helper functions
template<class T> void SortingList<T>::merge(int first, int mid, int last, int (*compare)(const T& b1, const T& b2))
{
    vector<T> temp(items.size());
    int first1 = first;
    int last1 = mid;   // endpoints of first subvector
    int first2 = mid + 1;
    int last2 = last;  // endpoints of second subvector
    int index = first1; //next index open in temp 

    // copy smaller term from each subvector into temp until
    // one of the subvector is exhaused
    while (first1 <= last1 && first2 <= last2)
    {
        if ((*compare)(items[first1],items[first2]) > 0)
        {
            temp[index] = items[first1];
            first1++;
        }
        else
        {
            temp[index] = items[first2];
            first2++;
        }
        index++;
    }
    // copy remaining items from first subvector, if any 
    while (first1 <= last1)
    {
        temp[index] = items[first1];
        first1++;
        index++;
    }
    // copy remaining items from second subvector, if any
    while (first2 <= last2)
    {
        temp[index] = items[first2];
        first2++;
        index++;
    }
    // copy merged data into original vector
    for (int i = first; i <= last; i++)
        items[i] = temp[i];
}

template<class T> void SortingList<T>::merge_sortHelper(int min, int max, int (*compare)(const T& b1, const T& b2))
{
    if (min < max)
    {
        int mid = (min + max) / 2;
        merge_sortHelper(min, mid, (*compare));
        merge_sortHelper(mid + 1, max, (*compare));
        merge(min, mid, max, (*compare));
    }
}

#endif
