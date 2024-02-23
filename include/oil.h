#ifndef OIL_H
#define OIL_H
#include<iostream>
#include"../include/service.h"
using namespace std;
class oil :public service
{
private:
double cost;

public:
oil ();
oil (const string & desc,double cost);
void display();
double get_oil_cost ();
void input();
double price();
void set_oil_cost(double cost);
};

#endif