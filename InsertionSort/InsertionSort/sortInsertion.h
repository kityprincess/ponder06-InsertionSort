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
   // Start by handling easy cases an empty array
   // or an array with only one item
   if (num <= 1)
      return;

   // Now, we create our sorted structure
   Node<T> * sorted = new Node<T>(array[0]);

   // Next, we loop through the items find where they belong
   // and put them there; we start at 1 because we've already
   // put item 0 in our sorted structure
   for (int j = 1; j < num; ++j)
   {
      if (array[j] < sorted->data)
      {
         insert(array[j], sorted, true);
         continue;
      }

      Node<T> * prev = sorted;
      Node<T> * cur = prev->pNext;

      while (cur && cur->data <= array[j])
      {
         prev = cur;
         cur = prev->pNext;
      }
      
      insert(array[j], prev);
   }

   // And then we copy our data back into the array
   int i = 0;
   for (Node<T> * p = sorted; p; p = p->pNext)
   {
      array[i] = p->data;
      ++i;
   }

   freeData(sorted);
}

#endif // INSERTION_SORT_H

