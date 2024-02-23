#ifndef VEHICLE_H
#define VEHICLE_H
#include<iostream>
using namespace std;
class vehicle
{
    private:
    string company;
    string model;
    string veh_number;
    //string mobile_number;

    public:
    string get_company();
    string get_model();
    string get_veh_number();
    //string get_mobile_number();
    void input();
    void set_company(const string &company);
    void set_model(const string &model);
    void set_number(const string &veh_number);
    void set_mobile_number(const string &mobile_number);
    vehicle();
    vehicle(const string &company,const string &model,const string &veh_number);
    void display();
};

#endif