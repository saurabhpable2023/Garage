#include"../include/service.h"
service::service()
{

}
 service::service(string desc)
{
   this->desc=desc; 
}

void service::display()
{
    cout<<"\t\t    ";
    cout<<left<<setw(40)<<desc;
}
string service:: get_disc()
{
    return desc;
}

void service:: input ()
{
    cout<<"Enter Description for service"<<endl;
    getchar();
    getline(cin,desc);
    //cin>>desc;
}
// double service::price()
// {
//         return price;
// }
void service:: set_desc(const string &desc)
{
    this->desc=desc;
}