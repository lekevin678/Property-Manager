#include "property.h"

using namespace std;

Property::Property(){
    this-> rent = 0;
    this-> prop_value = 0;
    this-> mortgage = 0;
    this-> mortgage_left = 0;
    this-> mortgage_duration = 0;
    this-> prop_tax = 0.015;
    this-> num_tenants = 0;
    this-> total_tenants = 0;
    this-> location = "";
    this-> sold = false;
    this-> tenant_arr = NULL;
}
Property::Property(const Property & copy){
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

bool operator> (const Property & one, const Property & two){
    if(one.prop_value > two.prop_value){
        return true;
    }
    else{
        return false;
    }
}

bool operator< (const Property & one, const Property & two){
    if (one.prop_value < two.prop_value){
        return true;
    }
    else{
        return false;
    }
}

Property & Property::operator= (const Property & copy){
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
    if (total_tenants > 1){
        for (int i = 0; i < total_tenants; i++){
            this-> tenant_arr[i] = copy.tenant_arr[i];
        }
    }
    return *this;
}

int Property::get_rent(){return this-> rent;}
int Property::get_prop_value(){return this-> prop_value;}
int Property::get_mortgage(){return this-> mortgage;}
int Property::get_mortgage_left(){return this-> mortgage_left;}
int Property::get_mortgage_duration(){return this-> mortgage_duration;}
float Property::get_prop_tax(){return this-> prop_tax;}
int Property::get_num_tenants(){return this-> num_tenants;}
int Property::get_total_tenants(){return this-> total_tenants;}
string Property::get_location(){return this-> location;}
bool Property::get_sold(){return this-> sold;}
Tenants * Property::get_tenant_arr(){return this-> tenant_arr;}

void Property::set_rent(int num){this-> rent = num;}
void Property::set_prop_value(int num){ this-> prop_value = num;}
void Property::set_mortgage(int num){this-> mortgage = num;}
void Property::set_mortgage_left(int num){this-> mortgage_left = num;}
void Property::set_mortgage_duration(int num){this-> mortgage_duration = num;}
void Property::set_prop_tax(float num){this-> prop_tax = num;}
void Property::set_num_tenants(int num){this-> num_tenants = num;}
void Property::set_total_tenants(int num){this-> total_tenants = num;}
void Property::set_location(string num){this-> location = num;}
void Property::set_sold(bool num){this-> sold = num;}


Tenants * Property::create_tenant_arr(){
    Tenants * arr;
    if(num_tenants > 0){
        arr = new struct Tenants [this-> num_tenants];
        set_agree_score(arr);
    }
    return arr;
}

int Property::assign_mortgage_duration(){
    int mortgage_duration = 0;
    mortgage_duration = prop_value/mortgage;

    return mortgage_duration;
}
string Property::assign_location(){
    int r =0;
    for (int i = 0; i < 3; i++ ){
        r = 0;
        location = "";
        r = rand() % 5;
        if (r == 0){
            location = "SE";
        }
        if (r == 1){
            location = "NE";
        }
        if (r == 2){
            location = "Midwest";
        }
        if (r == 3){
            location = "SW";
        }
        if (r == 4){
            location = "NW";
        }
    }
    return location;
}
void Property::set_agree_score(Tenants * tenant_arr){
    int agree = 0;
        for (int j = 0; j < this-> total_tenants; j++){
            agree = 0;
            agree = (rand() % 5) + 1;
            tenant_arr[j].agree_score = agree;
        }
    int budget = 0;
        for (int j = 0; j < this-> total_tenants; j++){
            budget = 0;
            budget = (rand() % 4500) + 500;
            tenant_arr[j].monthly_budget = budget;
        }
        for (int j = 0; j < this-> total_tenants; j++){
            tenant_arr[j].here = true;
        }
}

void Property::zero_this(){
    this-> rent = 0;
    this-> prop_value = 0;
    this-> mortgage = 0;
    this-> mortgage_left = 0;
    this-> mortgage_duration = 0;
    this-> prop_tax = 0.015;
    this-> num_tenants = 0;
    this-> total_tenants = 0;
    this-> location = "";
    this-> sold = false;
    // this-> tenant_arr = NULL;
}

void Property::tenant_kicker(){
    string temp = "";
    int total = 0;
    for (int i =0 ; i< this-> total_tenants; i++){
        if (tenant_arr[i].here == true){
            if( (this-> rent > tenant_arr[i].monthly_budget) && (tenant_arr[i].agree_score <= 2) ){
                cout << "You have a tenant who refuses to pay rent but will continue to stay." <<endl;
                cout << "If you would like them to pay rent, lower the rent." << endl;
                cout << "press ENTER to continue" << endl;
                getline(cin,temp);
                continue;
            }
            if ((this-> rent > tenant_arr[i].monthly_budget)){
                cout << "A tenant got kicked out because they couldn't pay rent" << endl;
                cout << "press ENTER to continue" << endl;
                getline(cin,temp);
                tenant_arr[i].here = false;
                total ++;
                continue;
            }
        }
        else{
            continue;
        }
    }
    this-> num_tenants -= total;
}
bool Property::tenant_rent_check(int i){
    string temp = "";
        if(tenant_arr[i].here == true){
            if( (this-> rent > tenant_arr[i].monthly_budget) && (tenant_arr[i].agree_score <= 2) ){
                return false;
            }
            if ((this-> rent > tenant_arr[i].monthly_budget)){
                return false;
            }
        }
        if(tenant_arr[i].here == false){
            return false;
        }
    return true;
}

int Property::collect_rent(){
    string temp = "";
    int total = 0;
    if(this-> sold == true){
        cout << "rent: " << rent << endl;
        cout << "num_tenants: " << num_tenants << endl;
        for (int i = 0; i < total_tenants; i ++){
            if (tenant_arr[i].here == true){
                if((tenant_rent_check(i) == true) ){  
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

void Property::display_info(){
        cout <<"-----------------------------------------" << endl;
        cout << "Prop Value: " << this->prop_value << endl;
        cout << "Mortgage: " << this->mortgage << endl;
        cout << "Mortgage duration: " << this-> mortgage_duration << endl;
        cout << "Location: " << this-> location << endl;
        cout << "Num Tenants: " << this-> num_tenants<< endl;
        cout << "Rent: " << this-> rent << endl;
        cout <<"-----------------------------------------" << endl;
        cout << endl;
}

int Property::property_tax_ammount(){
    int total = 0;
    total = (this-> prop_value) * (this-> prop_tax);
    return total;
}

int Property::sell_value(){
    string price = "";
    int r = rand() % 3 + 1;
    int ten = 0;
    do{
        cout << "What would you like the selling price to be?" << endl;
        getline(cin, price);
    } while (is_int(price) == false);
    ten = get_int(price) * 0.9;
    if (r == 3){
        cout << "You will get your selling price." << endl;
        cout << price << " will be transfered to your account and this property will be sold" << endl;
        return get_int(price);
    }
    if (r == 2){
        cout << "You will get the property value." << endl;
        cout << this-> prop_value << " will be transfered to your account and this property will be sold" << endl;
        return this-> prop_value;
    }
    if (r == 1){
        cout << "You will get 10% less of your selling price." << endl;
        cout << ten << " will be transfered to your account and this property will be sold" << endl;
        return ten;
    }
}


int Property::get_int (string prompt) {
    int new_int = 0;
    for (int a = 0; a < prompt.length(); a++) {
        if (prompt[a] == 48) {
            continue;
        }
        else {
            new_int += (prompt[a] - 48) * pow(10, (prompt.length() - 1 - a));
        }
    }
    return new_int;
}
bool Property::is_int(string num) {
    for (int a = 0; a < num.length(); a++) {
        if (num[a] >= 48 && num[a] <= 57) {
        }
        else {
            return false;
        }
    }
    return true;
}

void Property::random_event(int num){
    int r =0;
    if (num == 0 && this-> sold == true){
        if (this-> location == "SE"){
            this-> prop_value *= .5; 
        }
    }
    if (num == 1 && this-> sold == true){
        if (this-> location == "Midwest"){
            this-> prop_value *= .7; 
        }
    }
    if (num == 2 && this-> sold == true){
        if (this-> location == "NW"){
            this-> prop_value *= .9; 
        }
    }
    if (num == 3 && this-> sold == true){
        if (location == "SW"){
            this-> prop_value *= .75; 
        }
    }
    if (num == 4 && this-> sold == true){
            this-> prop_value *= .70; 
    }
    if (num == 5 && this-> sold == true){
        r = rand() % 5;
        if (r == 0){
            if (this-> location == "SE"){
                cout << "The New York Times wrote about the SE . The property value of all your properties in the SE will increase by 20%" << endl;
                this-> prop_value *= 1.2; 
            }
        }
        if (r == 1){
            if (this-> location == "NE"){
                cout << "A big business just came to the NE . The property value of all your properties in the NE will increase by 20%" << endl;
                this-> prop_value *= 1.2; 
            }
        }
        if (r == 2){
            if (this-> location == "Midwest"){
                cout << "The New York Times wrote about the Midwest . The property value of all your properties in the Midwest will increase by 20%" << endl;
                this-> prop_value *= 1.2; 
            }
        }
        if (r == 3){
            if (this-> location == "SW"){
                cout << "The New York Times wrote about the SW . The property value of all your properties in the SW will increase by 20%" << endl;
                this-> prop_value *= 1.2; 
            }
        }
        if (r == 4){
            if (this-> location == "NW"){
                cout << "The New York Times wrote about the NW . The property value of all your properties in the NW will increase by 20%" << endl;
                this-> prop_value *= 1.2; 
            }
        }
    }
}


Property::~Property(){
    delete [] tenant_arr;
}


