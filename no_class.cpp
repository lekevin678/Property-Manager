#include "no_class.h"

using namespace std;
int get_int (string prompt) {
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
bool is_int(string num) {
    for (int a = 0; a < num.length(); a++) {
        if (num[a] >= 48 && num[a] <= 57) {
        }
        else {
            return false;
        }
    }
    return true;
}

House * create_house_arr(int num){
    House * arr;
    if (num > 0){
        arr = new House [num];
    }
    return arr;
}

Apartment * create_apartment_arr(int num){
    Apartment * arr;
    if (num > 0){
        arr = new Apartment [num];
    }
    return arr;
}

Business * create_business_arr(int num){
    Business * arr;
    if (num > 0)
        arr = new Business [num];
    return arr;
}

void display(Player & p){
    cout << "YOUR PROPERTY" << endl;
    for (int i = 0; i < p.num_house ; i++){
        if (p.house_arr[i].get_sold() == true){
            cout <<"-----------------------------------------" << endl;
            cout << "House " << i+1 << endl;
            p.house_arr[i].display_info();
        }
    }
    for (int i = 0; i < p.num_apartment ; i++){
        if (p.apartment_arr[i].get_sold() == true){
            cout <<"-----------------------------------------" << endl;
            cout << "Apartment " << i+1 << endl;
            p.apartment_arr[i].display_info();
        }
    }
    
    for (int i = 0; i < p.num_business ; i++){
        if (p.business_arr[i].get_sold() == true){
            cout <<"-----------------------------------------" << endl;
            cout << "Business " << i+1 << endl;
            p.business_arr[i].display_info();
        }
    }
}

void display_tenants(Player & p){
    cout << "House" << endl;
    for (int i = 0; i < p.num_house; i++){
        for (int j = 0; j < p.house_arr[i].get_total_tenants(); j ++){
            if (p.apartment_arr[i].get_tenant_arr()[j].here == true){
                cout << "monthly_budget: " << p.house_arr[i].get_tenant_arr()[j].monthly_budget << endl;
                cout << "agree score: " << p.house_arr[i].get_tenant_arr()[j].agree_score << endl;
            }
        }
    }
    
    cout << "apartment" << endl;
    for (int i = 0; i < p.num_apartment; i++){
        cout << "apartment " << i+1 << endl;
        for (int j = 0; j < p.apartment_arr[i].get_total_tenants(); j ++){
            if (p.apartment_arr[i].get_tenant_arr()[j].here == true){
                cout << "tenant " << j+1 << endl;
                cout << "monthly_budget: " << p.apartment_arr[i].get_tenant_arr()[j].monthly_budget << endl;
                cout << "agree score: " << p.apartment_arr[i].get_tenant_arr()[j].agree_score << endl;
                cout << "Here: " << p.apartment_arr[i].get_tenant_arr()[j].here << endl;
            }
        }
    }
    /*
    cout << "Business" << endl;
    for (int i = 0; i < 3; i++){
        cout << "business " << i+1 << endl;
        for (int j = 0; j < business_arr[i].get_num_tenants(); j ++){
            cout << "tenant " << j+1 << endl;
            cout << "monthly_budget: " << business_arr[i].get_tenant_arr()[j].monthly_budget << endl;
            cout << "agree score: " << business_arr[i].get_tenant_arr()[j].agree_score << endl;
            cout << "bool: " << business_arr[i].get_tenant_arr()[j].here << endl;
        }
    } 
    */
}

void kick_tenants(Player &p){
    string temp = "";
    cout << endl;
    cout << "press ENTER to kick out tenants who can't pay rent" << endl;
    getline(cin,temp);
    for (int i = 0; i < p.num_house; i++){
        if(p.house_arr[i].get_sold() == true ){
            p.house_arr[i].tenant_kicker();
        }
    }
    for (int i = 0; i < p.num_apartment; i++){
        if (p.apartment_arr[i].get_sold() == true ){
            p.apartment_arr[i].tenant_kicker();
        }
    }
    for (int i = 0; i < p.num_business; i++){
        if (p.business_arr[i].get_sold() == true ){
            p.business_arr[i].tenant_kicker();
        }
    }
}
void collect_rent(Player &p){
    string temp = "";
    cout << endl;
    cout << "press ENTER to collect rent from tenants" << endl;
    getline(cin,temp);
    int total = 0;
    for (int i = 0; i < p.num_house; i++){
        if (p.house_arr[i].get_sold() == true){
            cout << "House " << i+1 << endl;
            total += p.house_arr[i].collect_rent();
        }
    }
    for (int i = 0; i < p.num_apartment; i++){
        if (p.apartment_arr[i].get_sold() == true){
            cout << "Apartment " << i+1 << endl;
            total += p.apartment_arr[i].collect_rent();
        }
    }
    for (int i = 0; i < p.num_business; i++){
        if (p.business_arr[i].get_sold() == true){
            cout << "Business " << i+1 << endl;
            total += p.business_arr[i].collect_rent();
        }
    }
    p.bank_account += total;
    cout << "Total: " << total << endl;
    cout << "Bank account: " << p.bank_account << endl;
}

void mortgage(Player & p){
    string temp = "";
    cout << endl;
    cout << "press ENTER to pay mortgage" << endl;
    getline(cin,temp);
    int total = 0;
    for(int i = 0; i < p.num_house; i++){
        if (p.house_arr[i].get_sold() == true &&   p.turn < p.house_arr[i].get_mortgage_duration() ){
            total += p.house_arr[i].get_mortgage();
        }
    }
    for(int i = 0; i < p.num_apartment; i++){
        if (p.apartment_arr[i].get_sold() == true && p.turn < p.apartment_arr[i].get_mortgage_duration() ){
            total += p.apartment_arr[i].get_mortgage();
        }
    }
    for(int i = 0; i < p.num_business; i++){
        if (p.business_arr[i].get_sold() == true && p.turn < p.business_arr[i].get_mortgage_duration() ){
            total += p.business_arr[i].get_mortgage();
        }
    }
    cout << "Total Mortgage for all property: " << total << endl;
    p.bank_account -= total;
    cout << "Your current Bank Account balance: " << p.bank_account << endl;
}

void property_tax(Player & p){
    int total = 0;
    string temp = "";
    if (p.turn % 12 == 0){
        cout << "press ENTER to pay property tax" << endl;
        getline(cin,temp);

        for(int i = 0; i < p.num_house; i++){
            if (p.house_arr[i].get_sold() == true){
                total += p.house_arr[i].property_tax_ammount();
            }
        }
        for(int i = 0; i < p.num_apartment; i++){
            if (p.apartment_arr[i].get_sold() == true){
                total += p.apartment_arr[i].property_tax_ammount();
            }
        }
        for(int i = 0; i < p.num_business; i++){
            if (p.business_arr[i].get_sold() == true ){
                total += p.business_arr[i].property_tax_ammount();
            }
        }
    }
    cout << "Your total property tax is: " << total << endl;
    p.bank_account -= total;
    cout << "Bank account: " << p.bank_account << endl;
}
void b_adjust_rent_two(Player & p){
    string input = "";
    string rent = "";
    int temp = 0;
    int r = 0;
    do{
        input = "";
        temp = 0;
        cout << "Which one. Insert the number. Press zero to return to menu." << endl;
        cout << "num: " << p.num_business << endl;
        getline(cin, input);
        temp = get_int(input);
        if (temp == 0){
            return;
        }
    } while(is_int(input) == false || ( temp > (p.num_business) ) || p.business_arr[get_int(input) - 1].get_sold() == false);
    do{
        cout << "What would you like the rent to be?" << endl;
        getline(cin, rent);
    } while( (is_int(rent) == false)  );

    r = get_int(rent);
    p.business_arr[get_int(input) - 1].set_rent(r);
}
void a_adjust_rent_two(Player & p){
    string input = "";
    string rent = "";
    int temp = 0;
    int r = 0;
    do{
        input = "";
        temp = 0;
        cout << "Which one. Insert the number. Press zero to return to menu." << endl;
        cout << "num: " << p.num_apartment << endl;
        getline(cin, input);
        temp = get_int(input);
        if (temp == 0){
            return;
        }
    } while(is_int(input) == false || ( temp > (p.num_apartment) ) || p.apartment_arr[get_int(input) - 1].get_sold() == false);
    do{
        cout << "What would you like the rent to be?" << endl;
        getline(cin, rent);
    } while( (is_int(rent) == false)  );

    r = get_int(rent);
    p.apartment_arr[get_int(input) - 1].set_rent(r);
}

void adjust_rent_two(Player & p){
    string input = "";
    string rent = "";
    int temp = 0;
    int r = 0;
    do{
        input = "";
        temp = 0;
        cout << "Which one. Insert the number. Press zero to return to menu." << endl;
        cout << "num: " << p.num_house << endl;
        getline(cin, input);
        temp = get_int(input);
        if (temp == 0){
            return;
        }
    } while(is_int(input) == false || ( temp > (p.num_house) )|| p.house_arr[get_int(input) - 1].get_sold() == false);
    do{
        cout << "What would you like the rent to be?" << endl;
        getline(cin, rent);
    } while( (is_int(rent) == false)  );

    r = get_int(rent);
    p.house_arr[get_int(input) - 1].set_rent(r);
}

void adjust_rent(Player & p){
    string input = "";
    do{
        input = "";
        cout << "Would you like to adjust a(n)" << endl;
        cout << "   (1) House" << endl;
        cout << "   (2) Apartment" << endl;
        cout << "   (3) Business Complex" << endl;
        getline(cin, input);
    } while (input != "1" &&input != "2" && input != "3");
    if (input == "1"){
            for (int i = 0; i < p.num_house; i++){
                if(p.house_arr[i].get_sold() == true){
                    cout <<"-----------------------------------------" << endl;
                    cout << "House " << i+1 << endl;
                    p.house_arr[i].display_info();
                }
            }
        adjust_rent_two(p);
    }
    if (input == "2"){
        for (int i = 0; i < p.num_apartment; i++){
            if(p.apartment_arr[i].get_sold() == true){
                cout <<"-----------------------------------------" << endl;
                cout << "Apartment " << i+1 << endl;
                p.apartment_arr[i].display_info();
            }
        }
        a_adjust_rent_two(p);
    }
    if (input == "3"){
        for (int i = 0; i < p.num_business; i++){
            if(p.business_arr[i].get_sold() == true){
                cout <<"-----------------------------------------" << endl;
                cout << "Business " << i+1 << endl;
                p.business_arr[i].display_info();
            }
        }
        b_adjust_rent_two(p);
    }
}


void b_sell_prop_two(Player & p){
    string input = "";
    string rent = "";
    int temp = 0;
    bool r = false;
    do{
        input = "";
        temp = 0;
        cout << "Which one. Insert the number. Press zero to return to menu." << endl;
        cout << "num: " << p.num_business << endl;
        getline(cin, input);
        temp = get_int(input);
        if (temp == 0){
            return;
        }
    } while(is_int(input) == false || ( temp > (p.num_business) ) || p.business_arr[get_int(input) - 1].get_sold() == false || p.business_arr[get_int(input) - 1].get_num_tenants() > 0);
    p.bank_account += p.business_arr[get_int(input) - 1].sell_value();
    cout << "Bank account: " << p.bank_account << endl;
    p.business_arr[get_int(input) - 1].set_sold(r);
}
void a_sell_prop_two(Player & p){
    string input = "";
    string rent = "";
    int temp = 0;
    bool r = false;
    do{
        input = "";
        temp = 0;
        cout << "Which one. Insert the number. Press zero to return to menu." << endl;
        cout << "num: " << p.num_apartment << endl;
        getline(cin, input);
        temp = get_int(input);
        if (temp == 0){
            return;
        }
    } while(is_int(input) == false || ( temp > (p.num_apartment) ) || p.apartment_arr[get_int(input) - 1].get_sold() == false || p.apartment_arr[get_int(input) - 1].get_num_tenants() > 0);
    p.bank_account += p.apartment_arr[get_int(input) - 1].sell_value();
    cout << "Bank account: " << p.bank_account << endl;
    p.apartment_arr[get_int(input) - 1].set_sold(r);
}
void sell_prop_two(Player & p){
    string input = "";
    string rent = "";
    int temp = 0;
    bool r = false;
    do{
        input = "";
        temp = 0;
        cout << "Which one. Insert the number. Press zero to return to menu." << endl;
        cout << "num: " << p.num_house << endl;
        getline(cin, input);
        temp = get_int(input);
        if (temp == 0){
            return;
        }
    } while(is_int(input) == false || ( temp > (p.num_house) ) || p.house_arr[get_int(input) - 1].get_sold() == false || p.house_arr[get_int(input) - 1].get_num_tenants() > 0 );
    p.bank_account += p.house_arr[get_int(input) - 1].sell_value();
    cout << "Bank account: " << p.bank_account << endl;
    p.house_arr[get_int(input) - 1].set_sold(r);
}
void sell_prop(Player & p){
    string input = "";
    do{
        input = "";
        cout << "Would you like to sell a(n)" << endl;
        cout << "   (1) House" << endl;
        cout << "   (2) Apartment" << endl;
        cout << "   (3) Business Complex" << endl;
        getline(cin, input);
    } while (input != "1" &&input != "2" && input != "3");
    if (input == "1"){
            for (int i = 0; i < p.num_house; i++){
                if(p.house_arr[i].get_sold() == true){
                    cout <<"-----------------------------------------" << endl;
                    cout << "House " << i+1 << endl;
                    p.house_arr[i].display_info();
                }
            }
            sell_prop_two(p);
    }
    if (input == "2"){
        for (int i = 0; i < p.num_apartment; i++){
            if(p.apartment_arr[i].get_sold() == true){
                cout <<"-----------------------------------------" << endl;
                cout << "Apartment " << i+1 << endl;
                p.apartment_arr[i].display_info();
            }
        }
        a_sell_prop_two(p);
    }
    if (input == "3"){
        for (int i = 0; i < p.num_business; i++){
            if(p.business_arr[i].get_sold() == true){
                cout <<"-----------------------------------------" << endl;
                cout << "Business " << i+1 << endl;
                p.business_arr[i].display_info();
            }
        }
        b_sell_prop_two(p);
    }
}




void print_options(Player & p){
    string input = "";
    do{
        do{
            input = "";
            cout << "Would you like to" << endl;
            cout << "   (1) sell property" << endl;
            cout << "   (2) buy property" << endl;
            cout << "   (3) adjuct rent" << endl;
            cout << "   (4) none " << endl;
            getline(cin, input);
        } while (input != "1" &&input != "2" && input != "3" &&input != "4" );
            if (input == "1"){
                sell_prop(p);
            }
            if (input == "2"){
                ask_three(p);
            }
            if (input == "3"){
                adjust_rent(p);
            }


    } while (input != "4");
}

void ask_three_two(Player & p){
    string input = "";
    int a = 0;
    bool t = true;
    do{
        cout << "What would you like the rent to be?" << endl;
        getline (cin, input);
    } while(is_int(input) == false);
    a = get_int(input);
    p.house_arr[p.num_house].set_sold(t);
    p.house_arr[p.num_house].set_rent(a);
}
void a_ask_three_two(Player & p){
    string input = "";
    int a = 0;
    bool t = true;
    do{
        cout << "What would you like the rent to be?" << endl;
        getline (cin, input);
    } while(is_int(input) == false);
    a = get_int(input);
    p.apartment_arr[p.num_apartment].set_sold(t);
    p.apartment_arr[p.num_apartment].set_rent(a);
}
void b_ask_three_two(Player & p){
    string input = "";
    int a = 0;
    bool t = true;
    do{
        cout << "What would you like the rent to be?" << endl;
        getline (cin, input);
    } while(is_int(input) == false);
    a = get_int(input);
    p.business_arr[p.num_business].set_sold(t);
    p.business_arr[p.num_business].set_rent(a);
}
void ask_three_one(int * prop_arr, int * spec_arr, House * start_house_arr, Apartment * start_apartment_arr, Business * start_business_arr, Player & p ){
    string input;
    do{
        cout << "Which option would you like to buy? 4 if none." << endl;
        getline(cin, input);
    } while (input != "1" && input != "2" && input != "3"&& input != "4");
    if(input == "1"){
        if (prop_arr[0] == 0){ 
            p.house_arr[p.num_house] = start_house_arr[spec_arr[0]]; ask_three_two(p); p.num_house += 1;
        }
        if (prop_arr[0] == 1){ 
            p.apartment_arr[p.num_apartment] = start_apartment_arr[spec_arr[0]]; a_ask_three_two(p); p.num_apartment += 1;
        }
        if (prop_arr[0] == 2){ 
            p.business_arr[p.num_business] = start_business_arr[spec_arr[0]]; b_ask_three_two(p); p.num_business += 1;
        }
    }
    if(input == "2"){
        if (prop_arr[1] == 0){ p.house_arr[p.num_house] = start_house_arr[spec_arr[1]]; ask_three_two(p); p.num_house += 1;
        }
        if (prop_arr[1] == 1){ p.apartment_arr[p.num_apartment] = start_apartment_arr[spec_arr[1]];  a_ask_three_two(p);p.num_apartment += 1;
        }
        if (prop_arr[1] == 2){ p.business_arr[p.num_business] = start_business_arr[spec_arr[1]];  b_ask_three_two(p);p.num_business += 1;
        }
    }
    if(input == "3"){
        if (prop_arr[2] == 0){ p.house_arr[p.num_house] = start_house_arr[spec_arr[2]];  ask_three_two(p);p.num_house += 1;
        }
        if (prop_arr[2] == 1){ p.apartment_arr[p.num_apartment] = start_apartment_arr[spec_arr[2]];  a_ask_three_two(p);p.num_apartment += 1;
        }
        if (prop_arr[2] == 2){ p.business_arr[p.num_business] = start_business_arr[spec_arr[2]];  b_ask_three_two(p);p.num_business += 1;
        }
    }
}
void ask_three(Player & p){
    House * start_house_arr = create_house_arr(3);
    Apartment * start_apartment_arr = create_apartment_arr(3);
    Business * start_business_arr= create_business_arr(3);
    int prop_arr [3];
    int spec_arr [3];
    int prop = 0;
    int spec = 0;
    int z = 0;
    string input = "";
    cout << "Which one(s) would you like to buy?" << endl;
    for (int i = 0; i < 3; i++){
        prop = rand() % 3;
        spec = rand() % 3;
        cout << "Option: " << i+1;
        if (prop == 0){
            cout << "    House "<< endl;
            prop_arr[z] = prop;
            spec_arr[z] = spec;
            start_house_arr[spec].display_info();
            z++;
        }
        if (prop == 1){
            cout << "     Apartment "<< endl;
            prop_arr[z] = prop;
            spec_arr[z] = spec;
            start_apartment_arr[spec].display_info();
            z++;
        }
        if (prop == 2){
            cout << "     Business "<< endl;
            prop_arr[z] = prop;
            spec_arr[z] = spec;
            start_business_arr[spec].display_info();
            z++;
        }
    }
    ask_three_one(prop_arr,spec_arr,start_house_arr,start_apartment_arr, start_business_arr, p);
    delete_fun(start_house_arr,start_apartment_arr, start_business_arr);
}


void player_setup(Player & p){
    p.bank_account = 500000;
    p.num_house = 0;
    p.num_apartment = 0;
    p.num_business = 0;
    p.turn = 1;
    p.house_arr = create_house_arr(100);
    p.apartment_arr = create_apartment_arr(100);
    p.business_arr = create_business_arr(100);
    for (int i = 0; i < 100; i++){      
        p.house_arr[i].zero_this();
    }
    for (int i = 0; i < 100; i++){
        p.apartment_arr[i].zero_this();
    }
    for (int i = 0; i < 100; i++){
        p.business_arr[i].zero_this();
    }
}

void rand_event(Player & p){
    int num = 0;
    num = rand() % 6;
    if (num == 0){
        cout << "A hurricane hit the South East. The property value of your properties in the SE will decrease by 30%" << endl;
    }
    if (num == 1){
        cout << "A tornado hit the Midwest. The property value of your properties in the Midwest will decrease by 30%" << endl;
    }
    if (num == 2){
        cout << "An earthquake hit the North West. The property value of your properties in the NW will decrease by 10%" << endl;
    }
    if (num == 3){
        cout << "A wildfire hit the South West. The property value of your properties in the SW will decrease by 25%" << endl;
    }
    if (num == 4){
        cout << "The stock market crashed. The property value of all your properties will decrease by 30%" << endl;
    }
    if (num == 5){

    }

    for (int i = 0; i < p.num_house; i++){
        if (p.house_arr[i].get_sold() == true){
            p.house_arr[i].random_event(num);
        }
    }
    for (int i = 0; i < p.num_apartment; i++){
        if (p.apartment_arr[i].get_sold() == true){
            p.apartment_arr[i].random_event(num);
        }
    }
    for (int i = 0; i < p.num_business; i++){
        if (p.business_arr[i].get_sold() == true){
            p.business_arr[i].random_event(num);
        }
    }
}

void start_game(Player & p){
    string temp = "";
    cout << "Turn: " << p.turn << endl;
    display(p);
    mortgage(p);
    kick_tenants(p);
    collect_rent(p);
    property_tax(p);
    rand_event(p);
    print_options(p);

    cout << "BANK ACCOUNT @ END OF ROUND: " << p.bank_account << endl;
    cout << endl;
    cout << "press ENTER for next turn" << endl;
    getline(cin,temp);
    p.turn += 1;
}
void delete_players(Player & p){
    delete [] p.house_arr;
    delete [] p.apartment_arr;
    delete [] p.business_arr;
}

void delete_fun(House * house_arr, Apartment * apartment_arr, Business * business_arr){
    delete [] house_arr;
    delete [] apartment_arr;
    delete [] business_arr;
}
