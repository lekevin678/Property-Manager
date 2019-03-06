#include "house.h"

using namespace std;

House::House() : Property(){
    rent = 0;
    prop_value = assign_house_prop_value();
    mortgage = ( (rand() % 5 ) + 1 ) * 1000;
    mortgage_duration = assign_mortgage_duration();
    prop_tax = 0.015;
    num_tenants = 1;
    total_tenants = 1;
    location = assign_location();
    sold = false;
    tenant_arr = create_tenant_arr();
}
House::House(const House & copy){
    this-> rent = copy.rent;
    this-> prop_value = copy.prop_value;
    this-> mortgage = copy.mortgage;
    this-> mortgage_left = copy.mortgage_left;
    this-> mortgage_duration = copy.mortgage_duration;
    this-> prop_tax = copy.prop_tax;
    this-> num_tenants = copy.num_tenants;
    this-> total_tenants = copy.total_tenants;
    this-> location = copy.location;
    this-> sold = copy.sold;
    if (total_tenants > 1){
        for (int i = 0; i < total_tenants; i++){
            tenant_arr[i] = copy.tenant_arr[i];
        }
    }
}
House & House::operator= (const House & copy){
    this-> rent = copy.rent;
    this-> prop_value = copy.prop_value;
    this-> mortgage = copy.mortgage;
    this-> mortgage_left = copy.mortgage_left;
    this-> mortgage_duration = copy.mortgage_duration;
    this-> prop_tax = copy.prop_tax;
    this-> num_tenants = copy.num_tenants;
    this-> total_tenants = copy.total_tenants;
    this-> location = copy.location;
    this-> sold = copy.sold;
    if(tenant_arr != NULL){
        delete [] tenant_arr;
    }
    if (this->total_tenants >= 1){
        this->tenant_arr = new Tenants[this->total_tenants];
        for (int i = 0; i < total_tenants; i++){
            this-> tenant_arr[i] = copy.tenant_arr[i];
        }
    }
    return *this;
}

int House::assign_house_prop_value(){
    int r = 0;
        do{
            r = 0;
            r = ( ( rand() % 101 ) * 10000 );
        } while (r > 600000 || r < 100000);
    return r;
}

House::~House(){
}


using namespace std;