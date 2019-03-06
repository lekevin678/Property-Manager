#ifndef BUSINESS
#define BUSINESS
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "property.h"

using namespace std;

class Business : public Property {
    private:
        string size;
    public:
        Business();
        Business (const Business & );
        Business & operator= (const Business &);
        ~Business();

        string get_size();
        void set_size(string );
        void zero_this();
        string assign_size();
        int assign_business_prop_value();
        Tenants * create_tenant_arr();
        void set_agree_score(Tenants * tenant_arr);
        int collect_rent();
};

#endif