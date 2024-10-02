#ifndef PART_H
#define PART_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class Part {
private:
    string name;
    double price;
    vector<pair<string, string>> specifications;

public:
    Part(string name, double price, vector<pair<string, string>> specs);
    string category;
    string getName() const;
    double getPrice() const;
    vector<pair<string, string>> getSpecifications() const;

    void display() const;
    friend ostream& operator<<(ostream& os, const Part& part);
};

#endif // PART_H
