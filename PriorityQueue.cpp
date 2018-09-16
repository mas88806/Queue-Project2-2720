/*
PriorityQueue.cpp
Author: Max Strauss
Submission Date: 3/10/17
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




#include "PriorityQueue.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template<class ItemType> PriorityQueue<ItemType>::PriorityQueue(){
  front = NULL;
  rear = NULL;
  count = 0;
}

template<class ItemType> PriorityQueue<ItemType>::~PriorityQueue(){
  makeEmpty();
}

template<class ItemType> void PriorityQueue<ItemType>::enqueue(ItemType newItem, int newPriority){
  //  if(isFull())
  //throw FullQueue();
  QueueNode<ItemType>* current;
  QueueNode<ItemType>* item = new QueueNode<ItemType>;
  item->priority = newPriority;
  item->info = newItem;
  if(front == NULL || peekPriority() > newPriority){
    item->next = front;
    front = item;
  }
  else{
    current = front;
    while(current->next != NULL && current->next->priority < newPriority){
      current = current->next;
    }
    item->next = current->next;
    current->next = item;
  }
  count++;
}

template<class ItemType> ItemType PriorityQueue<ItemType>::dequeue(ItemType& item){
  //if(isEmpty())
  //throw EmptyQueue();
  QueueNode<ItemType>* tempPtr;
  tempPtr = front;
  item = front->info;
  front = front->next;
  if(front==NULL)
    rear = NULL;
  count--;
  return tempPtr->info;
}

template<class ItemType> ItemType PriorityQueue<ItemType>::peek(){
  return front->info;
}

template<class ItemType> int PriorityQueue<ItemType>::peekPriority(){
  return front->priority;
}

template<class ItemType> void PriorityQueue<ItemType>::makeEmpty(){
  QueueNode<ItemType>* tempPtr;
  while (front != NULL){
    tempPtr = front;
    front = front->next;
    delete tempPtr;
    count--;
  }
  front = rear = NULL;
  count = 0;
  cout << "Queue: " << endl;
}

template<class ItemType> int PriorityQueue<ItemType>::size(){
  return count;
}

template<class ItemType> bool PriorityQueue<ItemType>::isEmpty(){
  return(front == NULL);
}

template<class ItemType> void PriorityQueue<ItemType>::printQueue(){
  if(isEmpty()){
  }
  QueueNode<ItemType>* temp;
  temp = front;
  while(temp->next!=NULL){
    cout << temp->info << " " ;
    temp = temp->next;
  }
  cout << temp->info << endl;
}

template<class ItemType> bool PriorityQueue<ItemType>::isFull(){
  QueueNode<ItemType>* ptr;
  ptr = new QueueNode<ItemType>;
  if(ptr==NULL)
    return true;
  else{
    delete ptr;
    return false;
  }
}
