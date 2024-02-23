#include"../include/service_station.h"

list<customer> &service_station::  get_customer_list()
{
    return customerlist;
}
list<bill> &service_station::  get_bill_list()
{
    return bill_list;
}
service_station:: service_station (string name)
{
    this->name=name;
}
string service_station:: get_station_name()
{
    return name;
}