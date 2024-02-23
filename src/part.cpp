#include "../include/part.h"

    string part::get_desc()
    {
        return desc;
    }
    double part:: get_rate()
    {
        return rate;
    }
    void part::input()
    {
        cout<<"Enter part Description"<<endl;
        getchar();
        getline(cin,desc);
        cout<<"Enter Rate"<<endl;
       cin>>rate;
        
    }
    part::part()
    {
  
    };
    part::part(const string &desc,const double &rate)
    {
        this->desc=desc;
        this->rate=rate;
    }
    void part:: set_desc(const string &desc)
    {
        this->desc=desc;
    }
    void part::set_rate(const double &rate)
    {
        this->rate=rate;
    }
    
    void part::display()
    {
        cout<<"\t\t    ";
        cout<<left<<setw(40)<<desc;
        cout<<rate<<endl;
    
    }

