#ifndef BILL_H
#define BILL_H
#include<iostream>
#include<iomanip>
#include"../include/service_request.h"
using namespace std;
class bill
{
private:
double amount;
double paid_amount=0;
service_request *req;
public:
bill(service_request *req);
double computeamount();
double computetax();
double computetotalbill();
double get_amount();
void display();
void set_paid_amount(double amount);
double get_paid_amount();
};
#endif