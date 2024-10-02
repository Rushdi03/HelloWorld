#ifndef ACC_H
#define ACC_H

#include "Part.h"

class Accessory : public Part {
public:
    Accessory(string name, double price, vector<pair<string, string>> specs);

    void display() const;
};

#endif // ACCESSORY_H
