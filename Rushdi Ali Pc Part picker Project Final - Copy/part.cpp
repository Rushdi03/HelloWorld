#include "Part.h"

// Constructor to initialize a Part object with name, price, and specifications
Part::Part(string name, double price, vector<pair<string, string>> specs)
    : name(name), price(price), specifications(specs) {}

// Getter function for the part's name
string Part::getName() const {
    return name;
}

// Getter function for the part's price
double Part::getPrice() const {
    return price;
}

// Getter function for the part's specifications
vector<pair<string, string>> Part::getSpecifications() const {
    return specifications;
}

// Function to display the part details
void Part::display() const {
    cout << name << " - $" << fixed << setprecision(2) << price << "\n"; // Show name and price
    for (const auto& spec : specifications) {
        cout << "  " << spec.first << ": " << spec.second << "\n"; // Show each spec
    }
    cout << endl;
}

// Overloading the << operator to print Part objects easily
ostream& operator<<(ostream& os, const Part& part) {
    os << part.name << " - $" << fixed << setprecision(2) << part.price << "\n"; // Print name and price
    for (const auto& spec : part.specifications) {
        os << "  " << spec.first << ": " << spec.second << "\n"; // Print each spec
    }
    cout << endl; // Add an empty line at the end
    return os; // Return the stream
}