#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "apartment.h"
#include "business.h"
#include "house.h"
#include "no_class.h"
#include "property.h"

using namespace std;



int main(){
    
    bool exit = false;
    Player p;
    string l = "";
    srand(time(NULL));
    player_setup(p);
    cout << "press ENTER to buy your first property" << endl;
    getline(cin, l);
    ask_three(p);
    cout << "press ENTER to start the game" << endl;
    getline(cin, l);
    do{
        start_game(p);
        if (p.bank_account >= 1000000){break;}
        if (p.bank_account <= 0){break;}
    } while (p.bank_account < 1000000);
    
    if (p.bank_account >= 1000000){
        cout << "You reached $1,000,000. YOU WON!!!" << endl;
    }
    if (p.bank_account <= 0){
        cout << "Your bank account is $0. You Lost" << endl;
    }
    
    bool test;
    Apartment a;
    House h;
    test = a > h;
    cout << "house: " << h.get_prop_value() << endl;
    cout << "apartment: " << a.get_prop_value() << endl;
    cout << endl;
    cout << "apartment > house" << endl;
    if (test == true){
        cout << "true" << endl;
    }
    if (test == false){
        cout << "false" << endl;
    }
    test = a < h;
    cout << endl;
    cout << "apartment < house " << endl;
    if (test == true){
        cout << "true" << endl;
    }
    if (test == false){
        cout << "false" << endl;
    }





    //delete_players(p);

    return 0;
}
