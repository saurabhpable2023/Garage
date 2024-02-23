#include "../include/customer.h"
    customer::customer()
    {
        
    }
    customer::customer(string Name, string Address,string Mobile_Number )
    {

        this->Name=Name;
        this->Address=Address;
        this->Mobile_Number=Mobile_Number;
    }

    void customer:: display()
    {
    cout<<"*************************"<<endl;
     cout<<"Name:"<<Name<<endl;
     cout<<"Address:"<<Address<<endl;
     cout<<"Mobile number:"<<Mobile_Number<<endl;

    }
    
    void customer:: display_vehicle()
    {
        for(int i=0; i<veh_list.size();i++)
        {
            //if(b->get_mobile==mobile)
            cout<<"*****************"<<endl;
            veh_list[i].display();
        } 
        
    }
    string customer::get_address()
    {
        return Address;
    }
    string customer::get_mobile()
    {
        return Mobile_Number;
    }
    string customer:: get_name()
    {
        return Name;
    }
    vector<vehicle>& customer:: get_veh_list()
    {
        return veh_list;
    }
    void customer::input()
    {
        cout<<"Enter your name"<<endl;
        cin>>Name;
        cout<<"Enter your Address"<<endl;
        cin>>Address;
        cout<<"Enter your Mobile Number"<<endl;
        cin>>Mobile_Number;
    }
    void customer:: set_name(const string &Name)
    {
        this->Name=Name;
    }
     void customer::set_address(const string &Address)
    {
        this->Address=Address;
    }
     void customer::set_mobile_number(const string &Mobile_number)
    {
        this->Mobile_Number=Mobile_Number;
    }

