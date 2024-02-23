    #include"../include/service_request.h"

    string service_request:: get_cust_name()
    {
        return cust_name;
    }
    string service_request::get_mobile_number()
    {
        return mobile_number;
    }
   list<service*> &service_request::get_serv_list()
    {
        return serv_list;
    }
    string service_request::get_veh_number()
    {
        return veh_number;
    }
    service_request::service_request()
    {

    }
    service_request::service_request(string cust_name,string mobile_number,string veh_number)
    {
        this->cust_name=cust_name;
        this->mobile_number=mobile_number;
        this->veh_number=veh_number;

    }
    void service_request:: set_cust_name(const string &cust_name)
    {
           this->cust_name=cust_name; 
    }
    void service_request:: set_mobile_number(const string &mobile_number)
    {
                    this->cust_name=cust_name;
    }
    void service_request::set_veh_number(const string &veh_number)
    {
     this->veh_number=veh_number;
    }