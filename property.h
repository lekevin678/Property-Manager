#ifndef PROPERTY
#define PROPERTY
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

struct Tenants{
    int monthly_budget;
    int agree_score;
    bool citizen;
    bool here;
};

class Property{
    protected:
        int rent;
        int prop_value;
        int mortgage;
        int mortgage_left;
        int mortgage_duration;
        int num_tenants;
        int total_tenants;
        float prop_tax;
        string location;
        bool sold;
        Tenants * tenant_arr;

    public:
        Property();
        Property(const Property & );
        Property & operator= (const Property &);
        friend bool operator> (const Property & , const Property & );
        friend bool operator< (const Property & , const Property & );

        virtual ~Property();
/********************************************************************* 
** Function: get functions
** Description: gets private
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
        int get_rent();
        int get_prop_value();
        int get_mortgage();
        int get_mortgage_left();
        int get_mortgage_duration();
        float get_prop_tax();
        int get_num_tenants();
        int get_total_tenants();
        string get_location();
        bool get_sold();
        Tenants * get_tenant_arr();
/********************************************************************* 
** Function: set_functions
** Description: sets privates
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
        void set_rent(int );
        void set_prop_value(int);
        void set_mortgage(int);
        void set_mortgage_left(int);
        void set_mortgage_duration(int);
        void set_prop_tax(float);
        void set_num_tenants(int);
        void set_total_tenants(int);
        void set_location(string);
        void set_sold(bool);
/********************************************************************* 
** Function: assign_mortagege_duration
** Description: finds the duration of mortgage payment
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
        int assign_mortgage_duration();
/********************************************************************* 
** Function: assign_location
** Description: assigns a location
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
        string assign_location();
/********************************************************************* 
** Function: set_agree_score
** Description: sets the agree score for each tenant
** Parameters: Tenats *
** Pre-Conditions: array of tenants
** Post-Conditions: n/a
*********************************************************************/
        void set_agree_score(Tenants * arr);
/********************************************************************* 
** Function: create_tenant_arr
** Description: creates an array of tenants
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
        Tenants * create_tenant_arr();
/********************************************************************* 
** Function: zero_this
** Description: zero's everything
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
        void zero_this();
/********************************************************************* 
** Function: display_info
** Description: displays info about property
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
        void display_info();
/********************************************************************* 
** Function: tenant_rent_check
** Description: checks to see if tenant pays rent
** Parameters: int
** Pre-Conditions: rent ammount
** Post-Conditions: n/a
*********************************************************************/
        bool tenant_rent_check(int);
/********************************************************************* 
** Function: tenant_kicker
** Description: kicks out tenants who cant pay rent
** Parameters: n/a
** Pre-Conditions:n/a
** Post-Conditions: n/a
*********************************************************************/
        void tenant_kicker();
/********************************************************************* 
** Function: property_tax_ammount
** Description: finds the property tax ammount
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
        int property_tax_ammount();
/********************************************************************* 
** Function: adjust_rent_two
** Description: adjust rent
** Parameters: Player &
** Pre-Conditions: player object
** Post-Conditions: n/a
*********************************************************************/
        void adjust_rent_two();
/********************************************************************* 
** Function: sell_value
** Description: finds how much property will sell for
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
        int sell_value();
/********************************************************************* 
** Function: is_int
** Description: int or not
** Parameters: string
** Pre-Conditions: num
** Post-Conditions: n/a
*********************************************************************/
        bool is_int(string);
/********************************************************************* 
** Function: get_int
** Description: turns to int
** Parameters: string
** Pre-Conditions: num
** Post-Conditions: bool
*********************************************************************/
        int get_int(string);
/********************************************************************* 
** Function: random_event
** Description: random event occurs
** Parameters: int
** Pre-Conditions: int num of random event
** Post-Conditions: int
*********************************************************************/
        void random_event(int);
/********************************************************************* 
** Function: collect_rent
** Description: collects rent from each tenant
** Parameters: n/a
** Pre-Conditions: n/a
** Post-Conditions: n/a
*********************************************************************/
        virtual int collect_rent();
};



#endif