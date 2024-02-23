#ifndef MENU_H
#define MENU_H
#include<fstream>
#include<sstream>
#include<list>
#include<iostream>
using namespace std;
#include"../include/customer.h"
#include"../include/service_station.h"
#include"../include/service_request.h"
#include"../include/maintainance.h"
#include"../include/oil.h"


string choosevehiclenumber();
void load_customer();
void sub_menu2(service_request *ptr);
string sub_menu1();
void sub_menu();
void load_vehicles();
void menu();

enum e_menu
{
    Exit,
    New_customer, 
    New_service_request,
    Todays_bussiness,
    Total_bussiness
};

enum e_sub_menu
{
    Go_back,Existing_customer,Display_vehicle,Input_output_vehicle,Process_request,PrepareNdisplay_bill,Get_payment
};

enum e_submenu1
{
    Gooo_back,Choose_vehicle,Input_vehicle
};
enum e_sub_submenu2
{
Goo_back,Maintainance,Reparing,Oil_change
};

#endif