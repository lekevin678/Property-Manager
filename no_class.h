#ifndef NO_CLASS
#define NO_CLASS
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "apartment.h"
#include "business.h"
#include "house.h"
#include "property.h"

using namespace std;

struct Player{
    int num_house;
    int num_apartment;
    int num_business;
    House * house_arr;
    Apartment * apartment_arr;
    Business * business_arr;
    int bank_account;
    int turn;
};
/********************************************************************* 
** Function: create functions
** Description: creates array of the three properties
** Parameters: int
** Pre-Conditions: length of array
** Post-Conditions: n/a
*********************************************************************/
House * create_house_arr(int);
Apartment * create_apartment_arr(int);
Business * create_business_arr(int);
/********************************************************************* 
** Function: display
** Description: displays info
** Parameters: player & p
** Pre-Conditions: player object
** Post-Conditions: n/a
*********************************************************************/
void display(Player & p);
/********************************************************************* 
** Function: display
** Description: creates array of the three properties
** Parameters: int
** Pre-Conditions: length of array
** Post-Conditions: n/a
*********************************************************************/
void display_tenants(Player & p);
/********************************************************************* 
** Function: player_setup
** Description: sets up the player struct
** Parameters: Plyaer &
** Pre-Conditions: player object
** Post-Conditions: n/a
*********************************************************************/
void player_setup(Player &);
/********************************************************************* 
** Function: start_game
** Description: game loop
** Parameters: Player &
** Pre-Conditions: player object
** Post-Conditions: n/a
*********************************************************************/
void start_game(Player &);
/********************************************************************* 
** Function: ask_three
** Description: gives the user three properties to buy from
** Parameters: Player &
** Pre-Conditions: player object
** Post-Conditions: n/a
*********************************************************************/
void ask_three(Player &);
/********************************************************************* 
** Function: ask_three
** Description: gives the user three properties to buy from
** Parameters: Player &
** Pre-Conditions: player object
** Post-Conditions: n/a
*********************************************************************/
void ask_tree_one(int * , int* , House *, Apartment *, Business *, Player &);
/********************************************************************* 
** Function: ask_three
** Description: gives the user three properties to buy from
** Parameters: Player &
** Pre-Conditions: player object
** Post-Conditions: n/a
*********************************************************************/
void ask_tree_two(Player & );
/********************************************************************* 
** Function: ask_three
** Description: gives the user three properties to buy from
** Parameters: Player &
** Pre-Conditions: player object
** Post-Conditions: n/a
*********************************************************************/
void a_ask_three_two(Player & p);
/********************************************************************* 
** Function: ask_three
** Description: gives the user three properties to buy from
** Parameters: Player &
** Pre-Conditions: player object
** Post-Conditions: n/a
*********************************************************************/
void b_ask_three_two(Player & p);
/********************************************************************* 
** Function: rent_setup
** Description: ask the user what they want the rent to be
** Parameters: Player &
** Pre-Conditions: player object
** Post-Conditions: n/a
*********************************************************************/
void rent_setup(Player &);
/********************************************************************* 
** Function: kick_tenants
** Description: kicks the tenants that cant pay rent
** Parameters: Player &
** Pre-Conditions: player object
** Post-Conditions: n/a
*********************************************************************/
void kick_tenants(Player &);
/********************************************************************* 
** Function: collect_rent
** Description: collect rent from tenants
** Parameters: Player &
** Pre-Conditions: player object
** Post-Conditions: n/a
*********************************************************************/
void collect_rent(Player &p);
/********************************************************************* 
** Function: mortgage
** Description: collects mortgage
** Parameters: Player &
** Pre-Conditions: player object
** Post-Conditions: n/a
*********************************************************************/
void mortgage(Player & p);
/********************************************************************* 
** Function: property_tax
** Description: collects property tax
** Parameters: Player &
** Pre-Conditions: player object
** Post-Conditions: n/a
*********************************************************************/
void property_tax(Player & p);
/********************************************************************* 
** Function: get_int
** Description: turns string to int
** Parameters: string
** Pre-Conditions: string of numbers
** Post-Conditions: n/a
*********************************************************************/
int get_int (string prompt);
/********************************************************************* 
** Function: is_int
** Description: sees if string is a number
** Parameters: string
** Pre-Conditions: string of numbers
** Post-Conditions: n/a
*********************************************************************/
bool is_int(string num);
/********************************************************************* 
** Function: print_options
** Description:print options to user
** Parameters: Player &
** Pre-Conditions: player object
** Post-Conditions: n/a
*********************************************************************/
void print_options(Player & p);
/********************************************************************* 
** Function: delete_player
** Description: deletes players array
** Parameters: Player &
** Pre-Conditions: player object
** Post-Conditions: n/a
*********************************************************************/
void delete_players(Player &);
/********************************************************************* 
** Function: delete_fun
** Description: deletes arrays
** Parameters: House &, Apartment *, Business *
** Pre-Conditions: arrays
** Post-Conditions: n/a
*********************************************************************/
void delete_fun(House *, Apartment *, Business *);
/********************************************************************* 
** Function: adjust_rent
** Description: adjust rent
** Parameters: Player &
** Pre-Conditions: player object
** Post-Conditions: n/a
*********************************************************************/
void adjust_rent(Player &);
/********************************************************************* 
** Function: adjust_rent
** Description: adjust rent
** Parameters: Player &
** Pre-Conditions: player object
** Post-Conditions: n/a
*********************************************************************/
void adjust_rent_two(Player &);
/********************************************************************* 
** Function: adjust_rent
** Description: adjust rent
** Parameters: Player &
** Pre-Conditions: player object
** Post-Conditions: n/a
*********************************************************************/
void a_adjust_rent_two(Player &);
/********************************************************************* 
** Function: adjust_rent
** Description: adjust rent
** Parameters: Player &
** Pre-Conditions: player object
** Post-Conditions: n/a
*********************************************************************/
void b_adjust_rent_two(Player &);
/********************************************************************* 
** Function: sell_prop
** Description: ask user which property they would like to sell
** Parameters: Player &
** Pre-Conditions: player object
** Post-Conditions: n/a
*********************************************************************/
void sell_prop(Player &);
/********************************************************************* 
** Function: adjust_rent
** Description: adjust rent
** Parameters: Player &
** Pre-Conditions: player object
** Post-Conditions: n/a
*********************************************************************/
void sell_prop_two(Player &);
/********************************************************************* 
** Function: adjust_rent
** Description: adjust rent
** Parameters: Player &
** Pre-Conditions: player object
** Post-Conditions: n/a
*********************************************************************/
void a_sell_prop_two(Player &);
/********************************************************************* 
** Function: adjust_rent
** Description: adjust rent
** Parameters: Player &
** Pre-Conditions: player object
** Post-Conditions: n/a
*********************************************************************/
void b_sell_prop_two(Player &);
/********************************************************************* 
** Function: rand_event
** Description: picks random number and has an event 
** Parameters: Player &
** Pre-Conditions: player object
** Post-Conditions: n/a
*********************************************************************/
void rand_event(Player &);

#endif