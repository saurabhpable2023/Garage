#ifndef SERVICE_REQUEST_H
#define SERVICE_REQUEST_H
#include<list>
#include<iostream>
#include"../include/service.h"
#include"../include/part.h"
using namespace std;
class service_request
{
private:
string cust_name;
string mobile_number;
list<service*> serv_list;
string veh_number;
public:
    string get_cust_name();
    string get_mobile_number();
    list<service*> &get_serv_list();
    string get_veh_number();
    service_request();
    service_request(string cust_name,string mobile_number,string veh_number);
    void set_cust_name(const string &cust_name);
    void set_mobile_number(const string &mobile_number);
    void set_veh_number(const string &veh_number);
};
#endif