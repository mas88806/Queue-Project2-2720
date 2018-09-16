/*
  [File name here].cpp Author: [Your name here]
Submission Date: [Submission date here]
Purpose: A brief paragraph description of the program. What does it do?
Statement of Academic Honesty:
The following code represents my own work. I have neither received nor given inappropriate assistance. I have not copied or modified code from any source other than the course webpage or the course textbook. I recognize that any unauthorized assistance or plagiarism will be handled in accordance with the University of Georgia's Academic Honesty Policy and the policies of this course. I recognize that my work is based on an assignment created by the Department of Computer Science at the University of Georgia. Any publishing or posting of source code for this project is strictly prohibited unless you have written consent from the Department of Computer Science at the University of Georgia.
*/



#include "Customer.cpp"
#include "PriorityQueue.cpp"
#include "QueType.cpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

ostream& operator<<(ostream& out, Customer c){
  out <<  c.getName() << " " << c.getWait() << " wait " <<"  service " << c.getDeparture() << endl;
  return out;
}


int main(){

  ifstream infile;
  int numTellers;
  string trash;
  string name;
  int arrival;
  int service;
  QueType<Customer> input;
  QueType<Customer> waitLine;
  PriorityQueue<Customer> output;
  int teller;
  int lowestTeller = 0;
  infile.open("input.txt");
  if(!infile)
    {
      cout << "error opening input file" << endl;
      return 1;
    }
  infile >> trash >> numTellers;
  int * tellers = new int[numTellers];
  while(infile >> name){
    infile >> trash >> arrival >> trash >> service;
    Customer* cur = new Customer(name, arrival, service);
    input.Enqueue(*cur);
  }
  while(!input.IsEmpty()){
    Customer* cur1 = new Customer();
    input.Dequeue(*cur1);
    for(int i = 0; i < numTellers; i++){
     if(tellers[i] < lowestTeller){
	lowestTeller = tellers[i];
	teller = i;
      }

    }//for
    if(lowestTeller <= cur1->getArrival()){
      cur1->setDeparture(cur1->getArrival() + cur1->getService());
      // cout << cur1->getDeparture() << endl;
      output.enqueue(*cur1, cur1->getArrival()+cur1->getService());
      lowestTeller = tellers[teller] = (cur1->getArrival() + cur1->getService());
    }
    else{
      cur1->setWait(lowestTeller - cur1->getArrival());
      cur1->setDeparture(cur1->getArrival() + cur1->getService() + cur1->getWait());
      output.enqueue(*cur1, cur1->getDeparture());
      lowestTeller = tellers[teller] = (cur1->getDeparture());
      }
    // output.enqueue(*cur1, cur1->getArrival() + cur1->getService());
    // output.printQueue();
  }//while
  output.printQueue(); 
  return EXIT_SUCCESS;
}
