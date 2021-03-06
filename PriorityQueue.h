/*
PriorityQueue.h
Author: Max Strauss
Submission Date: [Submission date here]
Purpose: A brief paragraph description of the program. What does it do?
Statement of Academic Honesty:
The following code represents my own work. I have neither received nor given inappropriate
assistance. I have not copied or modified code from any source other than the course webpage or
the course textbook. I recognize that any unauthorized assistance or plagiarism will be handled in
accordance with the University of Georgia's Academic Honesty Policy and the policies of this
course. I recognize that my work is based on an assignment created by the Department of
Computer Science at the University of Georgia. Any publishing or posting of source code for this
project is strictly prohibited unless you have written consent from the Department of Computer
Science at the University of Georgia.
*/

#include <iostream>
#include <string>
#include <cstddef>
#include <new>

template <class ItemType> struct QueueNode{
  ItemType info;
  int priority;
  QueueNode<ItemType>* next;
};

//class FullQueue{};

//class EmptyQueue{};

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

template <class ItemType>class PriorityQueue{
 public:
  //Class constructor.  Default.
  PriorityQueue();
  //Parametized class constructor. Takes in the max length of the Queue.
  //  PriorityQueue(int max);
  //Class destructor.
  ~PriorityQueue();
  /*
Places a new item into the queue based on the second value which is the item's priority which is a numerical value.  Lower numbers have higher priority.
   */
  void enqueue(ItemType newItem, int newPriority);
  //Removes the item at the top of the queue.  Calling on empty causes runtime.
  ItemType dequeue(ItemType& item);
  //Returns the item at the top without removing it. Calling on empty causes runtime.
  ItemType peek();
  /*Returns the priority value of the item at the front of the queue without removing it.  Causes runtime on an empty queue.
*/
  int peekPriority();
  //Removes all items from the queue.
  void makeEmpty();
  //Returns current number of elements in the queue.
  int size();
  //Returns true if the queue is empty.
  bool isEmpty();
  //Prints queue items from front to rear.
  void printQueue();
  //Returns true if the queue is full.
  bool isFull();

 private:
  QueueNode<ItemType>* front;
  QueueNode<ItemType>* rear;
  int count;
};
#endif
