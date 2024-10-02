#include "Acc.h"

Accessory::Accessory(string name, double price, vector<pair<string, string>> specs)
    : Part(name, price, specs) {}

void Accessory::display() const {
    cout << getName() << " - $" << fixed << setprecision(2) << getPrice() << " (Accessory)\n";
    for (const auto& spec : getSpecifications()) {
        cout << "  " << spec.first << ": " << spec.second << "\n";
    }
}
