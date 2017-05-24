#ifndef NODE_H
#define NODE_H

#include <cassert>

template <class T>
class Node
{
public:
   Node() : pNext(NULL)
   {

   }

   Node(T in_value) : pNext(NULL)
   {
      data = in_value;
   };

   Node * pNext;
   T data;
};

template <class T>
void freeData(Node<T> * in_node)
{
   assert(NULL != in_node);
   if (NULL == in_node)
      return;

   Node<T> * cur = in_node;
   Node<T> * next;

   while (cur)
   {
      next = cur->pNext;
      delete cur;
      cur = next;
   }

   return;
}

template <class T>
Node<T> * copy(Node<T> * in_source)
{
   assert(NULL != in_source);
   if (NULL == in_source)
      return NULL;

   Node<T> * pHead = new Node<T>(in_source->data);
   Node<T> * tmp = pHead;

   for (Node<T> * p = in_source->pNext; p; p = p->pNext)
   {
      // although we could call insert to do this, doing it here should be cheaper
      tmp->pNext = new Node<T>(p->data);
      tmp = tmp->pNext;
   }

   assert(NULL != pHead);
   return pHead;
}

template <class T>
Node<T> * insert(T in_value, Node<T> * & in_priorNode, bool in_atHead = false)
{
   if (NULL == in_priorNode)
   {
      in_priorNode = new Node<T>(in_value);
      return in_priorNode;
   }

   Node<T> * newNode = new Node<T>(in_value);

   if (!in_atHead)
   {     
      newNode->pNext = in_priorNode->pNext;
      in_priorNode->pNext = newNode;
   }
   else
   {
      newNode->pNext = in_priorNode;
      in_priorNode = newNode;
   }

   assert(NULL != newNode);
   assert(in_atHead || in_priorNode->pNext == newNode);
   assert(!in_atHead || newNode == in_priorNode);

   return newNode;
}

template <class T>
Node<T> * find(Node<T> * in_head, const T & in_valueToFind)
{
   return NULL;
}
#endif // !NODE_H
