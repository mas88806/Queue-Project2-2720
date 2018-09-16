/*
  [File name here].cpp Author: [Your name here]
Submission Date: [Submission date here]
Purpose: A brief paragraph description of the program. What does it do?
Statement of Academic Honesty:
The following code represents my own work. I have neither received nor given inappropriate assistance. I have not copied or modified code from any source other than the course webpage or the course textbook. I recognize that any unauthorized assistance or plagiarism will be handled in accordance with the University of Georgia's Academic Honesty Policy and the policies of this course. I recognize that my work is based on an assignment created by the Department of Computer Science at the University of Georgia. Any publishing or posting of source code for this project is strictly prohibited unless you have written consent from the Department of Computer Science at the University of Georgia.
*/


#include "Customer.h"
#include <ostream>
#include <iostream>

Customer::Customer(){
  name = "";
  arrival = 0;
  service = 0;
  departure = 0;
  wait = 0;
}

Customer::Customer(string n, int a, int s){
  name = n;
  arrival = a;
  service = s;
  departure = 0;
  wait = 0;
}

string Customer::getName(){
  return name;
}

int Customer::getArrival(){
  return arrival;
}

int Customer::getService(){
  return service;
}

int Customer::getWait(){
  return wait;
}

int Customer::getDeparture(){
  return departure;
}

void Customer::setName(string n){
  name = n;
}

void Customer::setArrival(int a){
  arrival = a;
}

void Customer::setService(int s){
  service = s;
}

void Customer::setWait(int w){
  wait = w;
}

void Customer::setDeparture(int d){
  departure = d;
}

Customer& Customer::operator =(Customer& c){
  setName(c.getName());
  setArrival(c.getArrival());
  setService(c.getService());
  setDeparture(c.getDeparture());
  setWait(c.getWait());
  return c;
}

