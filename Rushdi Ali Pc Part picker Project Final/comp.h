#ifndef COMP_H
#define COMP_H

#include <vector>
#include <string>
#include "Part.h"
#include <algorithm> // for using find and other algorithms
using namespace std;

class Computer {
private:
    vector<Part> currentBuild; // parts in the build
    vector<string> categories; // part types like CPU, RAM
    vector<int> limits; // max allowed for each type
    vector<string> requiredCategories; // must-have parts

public:
    Computer(); // constructor

    vector<Part> getCurrentBuild() const {
        return currentBuild;
    }

    void addPart(Part& part, const string& category); // add a part to the build
    void removePart(int index); // remove a part from the build
    void viewBuild() const; // show the build
    void clearBuild(); // clear all parts
    void printBuild() const; // print all parts
    void displayCategories() const; // show categories

    void printBuild() { // show what's in the build
        cout << "\nCurrent Build:\n";
        for (const auto& part : currentBuild) {
            cout << part << endl;
        }
    }

private:
    int getCategoryIndex(const string& category) const; // find index of a category
    int countPartsInCategory(const string& category) const; // count parts in a category
    void removeOldestPartInCategory(const string& category); // remove oldest part in a category
    bool isRequiredPart(const string& category) const; // check if category is needed
};

#endif // COMP_H