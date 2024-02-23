#include"../include/maintainance.h"

void maintainance::add_part()
{
    int choice;
    do
    {
        part p1;
        p1.input();
        part_list.push_back(p1);
        cout<<"Enter 0 for Exit "<<endl;
        cout<<"if you want to add more parts enter any number "<<endl;   
        cin>>choice;
    } while (choice!=0);
}

void maintainance:: part_display()
{
    //  for(list<customer>::iterator it = servicestation.get_customer_list().begin();it!=servicestation.get_customer_list().end();it++)
    // {
    //     it->display();
    // }
   for(list<part>:: iterator it= part_list.begin();it!=part_list.end();it++)
   {
        it->display();
   }
}
void maintainance::display()
{
    service::display();
    cout<<labour_charge<<endl;
    for(list<part>:: iterator it= part_list.begin();it!=part_list.end();it++)
   {
        it->display();
   }
}
double maintainance::get_labour_charges()
{
    return labour_charge;
}
list<part> & maintainance::get_part_list()
{
    return part_list;
}
void maintainance::input()
{
    service::input();
    cout<<"Enter labour charges for maintainance"<<endl;
    cin>>labour_charge;
}
maintainance::maintainance()
{
    
}

maintainance::maintainance (const string &desc,double labour_charge)
{
    service::set_desc(desc);
    this->labour_charge=labour_charge;
}
double maintainance:: price()
{
    int cost=0;
    for(list<part>:: iterator it= part_list.begin();it!=part_list.end();it++)
   {
        cost=it->get_rate()+cost;
   }

    return labour_charge+cost;
}
void maintainance::set_labour_charges(double labour_charge )
{
    this->labour_charge=labour_charge;
}