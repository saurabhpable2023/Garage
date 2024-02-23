#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>
using namespace std;
#include<vector>
#include"../include/vehicle.h"

class customer
{
    private:
    string Name;
    string Address;
    string Mobile_Number;
    vector<vehicle> veh_list;

    public:
    customer();
    customer(string Name, string Address,string Mobile_Number );
    void display_vehicle();
    void display();
    string get_address();
    string get_mobile();
    string get_name();
    vector<vehicle>& get_veh_list();
    void input();
    void set_name(const string &Name);
    void set_address(const string &Address);
    void set_mobile_number(const string &Mobile_number);
};
#endif