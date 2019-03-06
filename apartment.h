#ifndef APARTMENT
#define APARTMENT
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include "property.h"

using namespace std;

class Apartment : public Property {
    private:

    public:
        Apartment();
        Apartment (const Apartment & );
        Apartment & operator= (const Apartment &);
        ~Apartment();

        int assign_apartment_prop_value();
};

#endif