#ifndef HOUSE
#define HOUSE
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "property.h"

using namespace std;

class House : public Property {
    private:

    public:
        House();
        House (const House & );
        House & operator= (const House &);
        ~House();

        int assign_house_prop_value();
        void set_citizen();

};


#endif