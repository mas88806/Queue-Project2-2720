/*
  [File name here].cpp Author: [Your name here]
Submission Date: [Submission date here]
Purpose: A brief paragraph description of the program. What does it do?
Statement of Academic Honesty:
The following code represents my own work. I have neither received nor given inappropriate assistance. I have not copied or modified code from any source other than the course webpage or the course textbook. I recognize that any unauthorized assistance or plagiarism will be handled in accordance with the University of Georgia's Academic Honesty Policy and the policies of this course. I recognize that my work is based on an assignment created by the Department of Computer Science at the University of Georgia. Any publishing or posting of source code for this project is strictly prohibited unless you have written consent from the Department of Computer Science at the University of Georgia.
*/


#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

class Customer{

 private:
  string name;
  int arrival;
  int service;
  int departure;
  int wait;

 public:
  Customer();

  Customer(string n, int a, int s);

  string getName();
  void setName(string n);

  int getArrival();
  void setArrival(int a);

  int getService();
  void setService(int s);

  int getWait();
  void setWait(int w);

  int getDeparture();
  void setDeparture(int d);

  Customer& operator=(Customer& c);

};


