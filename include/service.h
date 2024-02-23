#ifndef SERVICE_H
#define SERVICE_H
#include<iostream>
#include<iomanip>
using namespace std;
class service
{
private:
    string desc;
public:
service();
service(string desc);
virtual void display();
string get_disc();
virtual void input ();
virtual double price()=0;
void set_desc(const string &desc);
};
#endif