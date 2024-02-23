#include"../include/menu.h"
service_station servicestation("SUNBEAM SERVICE STATION");
//cout<<servicestation.get_station_name()<<endl;


string choosevehiclenumber(customer *custptr)
{
    string vehicle_number;
    cout<<"Enter vehicle number to choose vehicle"<<endl;
    cin>>vehicle_number;

  for (int i=0; i<custptr->get_veh_list().size();i++)
    {
        if(vehicle_number==custptr->get_veh_list()[i].get_veh_number())
        {
            return vehicle_number;
        }
    }
    return "";

};
void load_vehicles(customer *custptr)
{
    //cout<<servicestation.get_station_name()<<endl;
    ifstream fin("../data/vehicle.txt");
    string data;
    while (getline(fin, data))
    {
        string mobile_number, company_Name,model,veh_number;
        stringstream line(data);
        getline(line, mobile_number, ',');
        if(mobile_number==custptr->get_mobile())
        {
        getline(line, company_Name, ',');
        getline(line, model, ',');
        getline(line, veh_number, ',');
        custptr->get_veh_list().push_back(vehicle( company_Name,model,veh_number));
        }
    }
    fin.close();
}
void load_customer()
{
    
    cout<<servicestation.get_station_name()<<endl;
    ifstream fin("../data/customer.txt");
    string data;
    while (getline(fin, data))
    {
        string Name,Address,Mobile_Number;
        stringstream line(data);
        getline(line, Name, ',');
        getline(line, Address, ',');
        getline(line, Mobile_Number, ',');
        servicestation.get_customer_list().push_back(customer(Name, Address,Mobile_Number));
    }
    fin.close();
}


void sub_menu2(service_request *service_request_ptr)
{
    service *service_ptr=NULL;
    int choice;
    do
    {
    cout<<"Enter o for Go back"<<endl;
    cout<<"Enter 1 for maintainance"<<endl;
    cout<<"Enter 2 for reparing"<<endl;
    cout<<"Enter 3 for oil change"<<endl;
    cin>>choice;
    switch (e_sub_submenu2(choice))
    {
    case Go_back:
        cout<<"you are backed !"<<endl;
        service_ptr=NULL;
        break;
    case Maintainance:
       { 
            service_ptr= new maintainance;//UPCASTING 
       }
        break;
    case Reparing:
        {
            service_ptr= new maintainance;
            maintainance *dptr=(maintainance*)service_ptr;//DOWNCASTING
            dptr->add_part();
           // dptr->part_display();
        }    
        break;
    case Oil_change:
        {
            service_ptr= new oil;
        }
        break;    
    default:
    cout<<"Enter valid number as per menu"<<endl;
        break;

    }
      if(service_ptr!=NULL)
        {
             service_ptr->input();
            //sptr->display();
            service_request_ptr->get_serv_list().push_back(service_ptr);

        }
        
    } while (choice!=0);
    }

string sub_menu1( customer *custptr)
{
    vehicle v;
    int choice;
    do
    {
    cout<<"Enter o for Go back"<<endl;
    cout<<"Enter 1 for choose vehicle"<<endl;
    cout<<"Enter 2 for input your vehicle"<<endl;
    cin>>choice;
    switch (e_submenu1(choice))

    {
    case Go_back:
        cout<<"you are backed !"<<endl;
        break;
    case Choose_vehicle:
            custptr->display_vehicle();
            return choosevehiclenumber(custptr);
    case Input_vehicle:
       { cout<<"Enter your vehicle"<<endl;
        //cin>>b->get_name()<<endl;
        v.input();
        custptr->get_veh_list().push_back(v);
        ofstream fout("../data/vehicle.txt",ios::app);
        fout<<custptr->get_mobile()<<","<<v.get_company()<<","<<v.get_model()<<","<<v.get_veh_number()<<endl;
        fout.close();
        return v.get_veh_number();
        }
    default:
    cout<<"Enter valid number as per menu"<<endl;
        break;
    }
    } while (choice!=0);
    
}
void sub_menu()
{
        customer *custptr=NULL;
        string vehiclenumber="";
        service_request *servicereq_ptr=NULL;
        bill *bill_ptr;
    //customer c;
int choice;
    do
    {
    cout<<"Enter o for Go back"<<endl;
    cout<<"Enter 1 for existing customer"<<endl;
    cout<<"Enter 2 for Display vehicle"<<endl;
    cout<<"Enter 3 for Input/choose vehicle"<<endl;
    cout<<"Enter 4 for process request"<<endl;
    cout<<"Enter 5 for prepare and display bill"<<endl;
    cout<<"Enter 6 for get payment"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    switch (e_sub_menu(choice))
    {
    case Go_back:
    cout<<"You are backed"<<endl;
    if(custptr!=NULL)
    {delete custptr;
    custptr=NULL;}
    if(servicereq_ptr!=NULL)
   { 
    for(service *s :servicereq_ptr->get_serv_list())
           delete  s;
    delete servicereq_ptr;
    servicereq_ptr=NULL;
    }
        return;

    case Existing_customer:
    {
        string mobile_number;
        cout<<"enter your mobile number"<<endl;
        cin>>mobile_number;
       // for(list<customer> iterator i = customer.begin();)
        bool found = false;
        //b->display();
        for(list<customer>::iterator it = servicestation.get_customer_list().begin();it!=servicestation.get_customer_list().end();it++)
    {
        if( mobile_number==it->get_mobile())
        {
            custptr= &*it;
            found=true;
        }
    }
    if(found){
            cout<<"Customer found.....!!!!!"<<endl;
            cout<<"You are existing customer"<<endl;
            custptr->display();
            load_vehicles(custptr);
    } 
    else
    cout<<"customer not found ||||||"<<endl;
        break;
    }
    case Display_vehicle:
    if(custptr==NULL)
    {
    cout<<"First select existing customer"<<endl;
    }
    else
    {
    cout<<"vehicle list:"<<endl;
    custptr->display_vehicle();
    }
        break;
    case Input_output_vehicle:
    if(custptr!=NULL)
    {
    cout<<"Input/choose vehicle"<<endl;
    
    vehiclenumber=sub_menu1(custptr);

    }
    else
    cout<<"First select existing customer"<<endl;
    
        break; 
     case Process_request:
     {
        if(vehiclenumber!="")
        {   
            servicereq_ptr=new service_request(custptr->get_name(),custptr->get_mobile(),vehiclenumber);
            sub_menu2(servicereq_ptr);
        }
        else
        cout<<"select vehicle first "<<endl;
        
     }
        break;   
     case PrepareNdisplay_bill:
     if(servicereq_ptr!=NULL)
    {//cout<<"YOUR BILL WILL BE:"<<endl;
        //bill b(servicereq_ptr);
        bill_ptr= new bill(servicereq_ptr);
       bill_ptr->display();
    // servicestation.get_bill_list().push_back(b);
    // for(list<bill>:: iterator it= servicestation.get_bill_list().begin();it!=servicestation.get_bill_list().end();it++)
    // {
    //     it->display();
    // }
    // for(bill bill:servicestation.get_bill_list())
    // {
    //         bill.display();
    // }
    }
    else
    cout<<"select process request first"<<endl;
        break;   
     case Get_payment:
    cout<<"GET PAYMENT"<<endl;
        if(bill_ptr!=NULL)
        {   
            double amount;
            cout<<"Total bill :"<<bill_ptr->get_amount()<<endl;
            cout<<"Enter the amount paid by customer"<<endl;
            cin>>amount;
            bill_ptr->set_paid_amount(amount);
            bill_ptr->display();
            servicestation.get_bill_list().push_back(*bill_ptr);
        // ofstream fout("../data/customer.txt",ios::app);
        // fout<<c.get_name()<<","<<c.get_address()<<","<<c.get_mobile()<<endl;
        // fout.close();
            ofstream fout ("../data/bill.txt",ios::app);
            fout<<bill_ptr->get_amount()<<","<<bill_ptr->get_paid_amount()<<","<<vehiclenumber<<","<<custptr->get_name()<<endl;
            fout.close();
            delete bill_ptr;
            bill_ptr=NULL;
            choice =0;
        }

        break;   
    default:
    cout<<"Enter valid number as per menu"<<endl;
        break;
    }
    }while (choice!=0);    
}

void menu()
{
    int choice;
    do
    {
    cout<<"Enter o for exit"<<endl;
    cout<<"Enter 1 for new customer"<<endl;
    cout<<"Enter 2 for new service request"<<endl;
    cout<<"Enter 3 for Todays Business"<<endl;
    cout<<"Enter 4 for Total Business"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
    switch (e_menu(choice))
    {
    case Exit:
    cout<<"Thank you for using our app......"<<endl;

    // for(list<customer>::iterator it = servicestation.get_customer_list().begin();it!=servicestation.get_customer_list().end();it++)
    // {
    //     it->display();
    // }
        break;
    case New_customer:
    {
    cout<<"You are new customer"<<endl;
    customer c;
    c.input();
    servicestation.get_customer_list().push_back(c);
    ofstream fout("../data/customer.txt",ios::app);
    fout<<c.get_name()<<","<<c.get_address()<<","<<c.get_mobile()<<endl;
    fout.close();
       }   break;
    case New_service_request:
    cout<<"New serice requsting"<<endl;
        sub_menu();
        break;
    case Todays_bussiness:
        {
            double Total_amount=0;
            double paid_amount=0;
            for ( bill bill :servicestation.get_bill_list())
            {
                Total_amount=bill.get_amount()+Total_amount;
                paid_amount=bill.get_paid_amount()+paid_amount;

            }
            cout<<"\t****************************************************"<<endl;
            cout<<"\t Today Total Bill Amount :"<<Total_amount<<endl;
            cout<<"\t Today Total Paid Amount :"<<paid_amount<<endl;
        }
        break;   
    case Total_bussiness:
        {
            cout<<"Total bill:"<<endl;
            double Total_amount ,paid_amount;

            ifstream fin("../data/bill.txt");
            string data;
            while (getline(fin,data))
            {
                string Totalamount ,paidamount;
                stringstream line(data);
                getline(line,Totalamount,',');
                getline(line,paidamount,',');
                Total_amount=stod(Totalamount)+Total_amount;
                paid_amount=stod(paidamount)+paid_amount;
            }
            fin.close();
            cout<<"\t****************************************************"<<endl;
            cout<<"\t All time Total Bill Amount :"<<Total_amount<<endl;
            cout<<"\t All time Total Paid Amount :"<<paid_amount<<endl;     
        }            
        break;          
    default:
    cout<<"Enter valid number as per menu"<<endl;
        break;
    }
    }while (choice!=0);   
}