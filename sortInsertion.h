/***********************************************************************
 * Header:
 *    INSERTION SORT
 * Summary:
 *    This will contain just the prototype for insertionSortTest(). You may
 *    want to put other class definitions here as well.
 * Author
 *    <your names here>
 ************************************************************************/

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "node.h"

/***********************************************
 * INSERTION SORT
 * Sort the items in the array
 **********************************************/
template <class T>
void sortInsertion(T array[], int num)
{   
  int i;
  int j;
  int minIndex;
  T tmp;  
    
      for (i = 0; i < num - 1; i++) 
      {
            minIndex = i;
            for (j = i + 1; j < num; j++)
                  if (array[j] < array[minIndex])
                        minIndex = j;
            if (minIndex != i) 
            {
                  tmp = array[i];
                  array[i] = array[minIndex];
                  array[minIndex] = tmp;
            }
      }
}

#endif // INSERTION_SORT_H

