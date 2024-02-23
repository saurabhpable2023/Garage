#ifndef Maintainance_H
#define Maintainance_H
#include<list>
#include<iostream>
#include"../include/service.h"
#include"../include/part.h"
using namespace std;
class maintainance :public service
{
private:
double labour_charge;
list<part> part_list;
public:
void add_part();
void part_display();
void display();
double get_labour_charges();
list<part> & get_part_list();
void input();
maintainance();
maintainance (const string &desc,double labour_charge);
double price();
void set_labour_charges(double labour );
};
#endif