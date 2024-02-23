#ifndef SERVICE_STATION_H
#define SERVICE_STATION_H
#include<iostream>
#include"../include/bill.h"
#include"../include/customer.h"
#include<list>
using namespace std;
class service_station
{
private:
list<bill> bill_list;
string name;
list<customer> customerlist;
public:
service_station (string name);
list<customer>& get_customer_list();
list<bill> & get_bill_list();
string get_station_name();
};
#endif