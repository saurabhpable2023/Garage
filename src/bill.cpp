#include"../include/bill.h"
bill::bill(service_request *req)
{
    this->req=req;
}
double bill::computeamount()
{
    double cost;
    for (service *service: req->get_serv_list())
    {
       // service->display();
        cost=service->price()+cost;
    }
    return cost;
}
double bill::computetax()
{
    double toat_amount=computeamount();

    return (toat_amount*18)/100;

}
double bill::computetotalbill()
{
    amount=computeamount()+computetax();
    return amount;
}

void bill::display()
{
    cout<<"\t\t**********************************************************************"<<endl;
    cout<<"\t\t\t\t ....SUNBEAM GARAGE HINJEWADI.... "<<endl;
    cout<<"\t\t**********************************************************************"<<endl;
    cout<<"\t\t    Customer Name:- "<<req->get_cust_name()<<"\t Customer Mobile NO:-"<<req->get_mobile_number()<<endl;
    cout<<"\t\t    Vehicle Number :-"<<req->get_veh_number()<<endl;                                                                 
    cout<<"\t\t    DESCRIPTION\t\t\tCharges/part price"<<endl;
        for (service *service: req->get_serv_list())
    {
        service->display();
    }    
    cout<<"\t\t**********************************************************************"<<endl;
    cout<<"\t\t\t\t          TOTAL AMOUNT :"<<computeamount()<<endl;
    cout<<"\t\t\t\t              GST TAX  :"<<computetax()<<endl;
    cout<<"\t\t\t           TOTAL BILL WITH GST :"<<computetotalbill()<<endl;
    cout<<"\t\t\t                   paid amount :"<<paid_amount<<endl;
}
double bill:: get_amount()
{
    return amount;
}

void bill::set_paid_amount(double amount)
{
    paid_amount=amount;
}

double bill:: get_paid_amount()
{
    return paid_amount;
}