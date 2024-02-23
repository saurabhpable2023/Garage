#include"../include/vehicle.h"
using namespace std;

    string vehicle:: get_company()
    {
        return company;
    }
    string vehicle:: get_model()
    {
        return model;
    }
    string vehicle:: get_veh_number()
    {
        return veh_number;
    }
    //string vehicle:: get_mobile_number()
    //{
      //  return veh_number;
    //}
    void vehicle:: input()
    {
        cout<<"Enter company name"<<endl;
        cin>>company;
        cout<<"Enter model name"<<endl;
        getchar();
        getline(cin,model);
        //cin>>model;
        cout<<"Enter vehicle number"<<endl;
        cin>>veh_number;
        // cout<<"Enter mobile  number"<<endl;
        // cin>>mobile_number;
    }
    void vehicle::set_company(const string &company)
    {
        this->company=company;
    }
    void vehicle::set_model(const string &model)
    {
        this->model=model;
    }
    void vehicle:: set_number(const string &veh_number)
    {
        this->veh_number=veh_number;
    }
    // void vehicle::set_mobile_number(const string &mobile_number)
    // {
    //     this->mobile_number=mobile_number;
    // }
    vehicle::vehicle()
    {

    }
    vehicle::vehicle(const string &company,const string &model,const string &veh_number)
    {
        //this->mobile_number=mobile_number;
        this->company=company;
        this->model=model;
        this->veh_number=veh_number;

    }

    void vehicle::display()
    {
        cout<<"company:"<<company<<endl;
        cout<<"model:"<<model<<endl;
        cout<<"Number:"<<veh_number<<endl;
    }


