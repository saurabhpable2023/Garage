#ifndef PART_H
#define PART_H
#include<iostream>
#include<iomanip>
using namespace std;
class part
{
    private:
    string desc;
    double rate;
    public:
    string get_desc();
    double get_rate();
    void input();
    part();
    part(const string &desc,const double &rate);
    void set_desc(const string &desc);
    void set_rate(const double &rate);
    void display();
};

#endif