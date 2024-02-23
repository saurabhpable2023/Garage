#include"../include/oil.h"

oil::oil ()
{

}
oil::oil (const string & desc,double cost)
{
    //service::get_disc()=desc;
    service::set_desc(desc);
    this->cost=cost;
}
void oil::display()
{
      cout<<"\t\t    ";
      cout<<left<<setw(40)<<get_disc();
        cout<<cost<<endl;
}
double oil::get_oil_cost ()
{
        return cost;
}
void oil::input()
{
    service::input();
    cout<<"Enter the cost of oil"<<endl;
    cin>>cost;
}
double oil::price()
{
        return cost;
}
void oil::set_oil_cost(double cost)
{
    this->cost=cost;
}