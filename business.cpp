#include "business.h"

using namespace std;

Business::Business() : Property(){
    rent = 0;
    prop_value = assign_business_prop_value();
    mortgage = ( (rand() % 5 ) + 1 ) * 1000;
    mortgage_duration = assign_mortgage_duration();
    prop_tax = 0.015;
    num_tenants = (rand() % 5) + 1;
    total_tenants = num_tenants;
    location = assign_location();
    sold = false;
    size = assign_size();
    tenant_arr = create_tenant_arr();
}

Business::Business(const Business & copy){
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
    this-> size = copy.size;
    if (total_tenants > 1){
        for (int i = 0; i < total_tenants; i++){
            tenant_arr[i] = copy.tenant_arr[i];
        }
    }
}

Business & Business::operator= (const Business & copy){
    this-> rent = copy.rent;
    this-> prop_value = copy.prop_value;
    this-> mortgage = copy.mortgage;
    this-> mortgage_left = copy.mortgage_left;
    this-> mortgage_duration = copy.mortgage_duration;
    this-> prop_tax = copy.prop_tax;
    this-> num_tenants = copy.num_tenants;
    this-> total_tenants = copy.total_tenants;
    this-> location = copy.location;
    this-> size = copy.size;
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


string Business::get_size(){return this-> size;}
void Business::set_size(string s){this-> size = s;}

void Business::set_agree_score(Tenants * tenant_arr){
    int agree = 0;
        for (int j = 0; j < this-> num_tenants; j++){
            agree = 0;
            agree = (rand() % 5) + 1;
            tenant_arr[j].agree_score = agree;
        }
    int budget = 0;
        for (int j = 0; j < this-> num_tenants; j++){
            budget = 0;
            budget = (rand() % 8000) + 2000;
            tenant_arr[j].monthly_budget = budget;
        }
        for (int j = 0; j < this-> num_tenants; j++){
            tenant_arr[j].here = true;
        }
}

string Business::assign_size(){
    int r = rand() % 3;
    string loc = "";
    if (r==0){
        loc = "Small";
    }
    if (r==1){
        loc = "Medium";
    }
    if (r==2){
        loc = "Large";
    }
    return loc;
}

Tenants * Business::create_tenant_arr(){
    Tenants * arr;
    arr = new struct Tenants [this-> num_tenants];
    set_agree_score(arr);
    return arr;
}

int Business::assign_business_prop_value(){
    int r = 0;
        do{
            r = 0;
            r = ( ( rand() % 401 ) * 10000 );
        } while (r > 600000 || r < 400000);
    return r;
}

void Business::zero_this(){
    this-> rent = 0;
    this-> prop_value = 0;
    this-> mortgage = 0;
    this-> mortgage_left = 0;
    this-> mortgage_duration = 0;
    this-> prop_tax = 0.015;
    this-> num_tenants = 0;
    this-> location = "";
    this-> sold = false;
    //this-> tenant_arr = NULL;
    this-> size = "";
}
int Business::collect_rent(){
    cout << "Business collect_rent" << endl;
    string temp = "";
    int total = 0;
    if(this-> sold == true){
        cout << "rent: " << rent << endl;
        cout << "num_tenants: " << num_tenants << endl;
        for (int i = 0; i < total_tenants; i ++){
            if (tenant_arr[i].here == true){
                if((tenant_rent_check(i) == true) ){
                    this-> prop_value = this-> prop_value * 1.01;  
                    total += this->rent;
                }
            }
            else{
                continue;
            }
        }
        cout << "TOTAL: " << total << endl;
    }
    cout << "press ENTER to continue" << endl;
    getline(cin,temp);
    return total;
}

Business::~Business(){

}
