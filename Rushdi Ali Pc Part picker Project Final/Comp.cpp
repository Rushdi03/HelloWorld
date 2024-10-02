#include "Comp.h"
#include <iostream>
#include <limits>

// Constructor: sets up the categories, limits, and required parts
Computer::Computer()
    : categories{ "CPU", "RAM", "Motherboard", "Hard Drive", "Case", "Power Supply", "Graphics Card", "Accessory" },
    limits{ 1, 4, 1, 4, 1, 1, 2, 10 },
    requiredCategories{ "CPU", "RAM", "Motherboard", "Hard Drive", "Case", "Power Supply" } {}

// Add a part to the build, remove oldest if over the limit
void Computer::addPart(Part& part, const string& category) {
    int categoryIndex = getCategoryIndex(category);
    int count = countPartsInCategory(category);

    if (count >= limits[categoryIndex]) {
        removeOldestPartInCategory(category);
    }
    part.category = category;
    currentBuild.push_back(part);
    cout << category;
}

// Remove a part from the build by index
void Computer::removePart(int index) {
    if (index >= 0 && index < currentBuild.size()) {
        currentBuild.erase(currentBuild.begin() + index);
    }
}

// Clear all parts from the build
void Computer::clearBuild() {
    currentBuild.clear();
}

// Show the current build and total price
void Computer::viewBuild() const {
    double totalPrice = 0.0;
    cout << "\nRequired Parts:\n\n";
    for (const auto& part : currentBuild) {
        if (isRequiredPart(part.category)) {
            cout << part;
            totalPrice += part.getPrice();
        }
    }
    cout << "\nOptional Parts:\n\n";
    for (const auto& part : currentBuild) {
        if (!isRequiredPart(part.category)) {
            cout << part;
            totalPrice += part.getPrice();
        }
    }

    cout << "\n\nTotal Price: $" << fixed << setprecision(2) << totalPrice << "\n\n";
}

// Show all categories
void Computer::displayCategories() const {
    cout << "Part Categories:\n";
    for (size_t i = 0; i < categories.size(); ++i) {
        cout << i + 1 << ". " << categories[i] << "\n";
    }
    cout << "Enter a category # to add a part: ";
}

// Get the index of a category
int Computer::getCategoryIndex(const string& category) const {
    for (size_t i = 0; i < categories.size(); ++i) {
        if (categories[i] == category) {
            return i;
        }
    }
    return -1;
}

// Count how many parts are in a category
int Computer::countPartsInCategory(const string& category) const {
    int count = 0;
    for (const auto& part : currentBuild) {
        if (part.getName().find(category) != string::npos) {
            ++count;
        }
    }
    return count;
}

// Remove the oldest part in a category
void Computer::removeOldestPartInCategory(const string& category) {
    for (auto it = currentBuild.begin(); it != currentBuild.end(); ++it) {
        if (it->getName().find(category) != string::npos) {
            currentBuild.erase(it);
            return;
        }
    }
}

// Check if a category is required
bool Computer::isRequiredPart(const string& category) const {
    return find(requiredCategories.begin(), requiredCategories.end(), category) != requiredCategories.end();
}