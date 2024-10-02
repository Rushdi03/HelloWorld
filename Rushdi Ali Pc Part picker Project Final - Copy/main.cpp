#include <iostream>
#include <vector>
#include <string>
#include "Part.h"
#include "Comp.h"
#include "Acc.h"

using namespace std;

// This function shows the list of parts and asks the user to pick one
void displayParts(const vector<Part>& parts) {
    for (size_t i = 0; i < parts.size(); ++i) {
        cout << i + 1 << ". " << parts[i]; // Shows each part with a number
    }
    cout << "Input the Part # to add: \n"; // Asks user to pick a part
}

// This is the same as above but for accessories instead of parts
void displayParts(const vector<Accessory>& parts) {
    for (size_t i = 0; i < parts.size(); ++i) {
        cout << i + 1 << ". ";
        parts[i].display(); // Shows each accessory with a number
    }
    cout << "Input the Part # to add: \n"; // Asks user to pick an accessory
}

int main() {
    // These are the parts available for the user to choose from
    vector<Part> cpuParts{
        Part("Intel Core i9", 550.00, {{"Clock Speed", "3.6GHz"}, {"Cores", "8"}}),
        Part("AMD Ryzen 9", 500.00, {{"Clock Speed", "3.8GHz"}, {"Cores", "12"}}),
        Part("Intel Core i7", 350.00, {{"Clock Speed", "3.8GHz"}, {"Cores", "6"}})
    };

    vector<Part> ramParts{
        Part("Corsair Vengeance", 160.00, {{"Size", "16GB"}, {"Speed", "3200MHz"}}),
        Part("G.SKILL Trident", 210.00, {{"Size", "32GB"}, {"Speed", "3600MHz"}}),
        Part("HyperX Fury", 130.00, {{"Size", "16GB"}, {"Speed", "2666MHz"}})
    };

    vector<Part> mthrBrdParts{
        Part("ASUS ROG", 320.00, {{"Chipset", "Z390"}, {"Form Factor", "ATX"}}),
        Part("MSI B450", 120.00, {{"Chipset", "B450"}, {"Form Factor", "ATX"}}),
        Part("Gigabyte A520", 90.00, {{"Chipset", "A520"}, {"Form Factor", "Micro ATX"}})
    };

    vector<Part> strgParts{
        Part("Samsung 980 Pro", 180.00, {{"Capacity", "1TB"}, {"Form Factor", "M.2-2280"}}),
        Part("Kingston NV2", 70.00, {{"Capacity", "1TB"}, {"Form Factor", "M.2-2280"}}),
        Part("Western Digital Blue", 90.00, {{"Capacity", "500GB"}, {"Form Factor", "2.5-inch SSD"}})
    };

    vector<Part> caseParts{
        Part("NZXT H510", 80.00, {{"Type", "Mid Tower"}, {"Color", "Black"}}),
        Part("Corsair 4000D", 90.00, {{"Type", "Mid Tower"}, {"Color", "White"}}),
        Part("Phanteks Eclipse", 75.00, {{"Type", "Mid Tower"}, {"Color", "Gray"}})
    };

    vector<Part> psuParts{
        Part("Corsair RM750x", 140.00, {{"Wattage", "750W"}, {"Efficiency", "80+ Gold"}}),
        Part("EVGA 600 W1", 45.00, {{"Wattage", "600W"}, {"Efficiency", "80+ White"}}),
        Part("Seasonic S12III", 65.00, {{"Wattage", "650W"}, {"Efficiency", "80+ Bronze"}})
    };

    vector<Part> gpuParts{
        Part("NVIDIA RTX 3080", 750.00, {{"Memory", "10GB GDDR6X"}, {"Cores", "8704"}}),
        Part("AMD RX 6800", 600.00, {{"Memory", "16GB GDDR6"}, {"Cores", "3840"}}),
        Part("NVIDIA RTX 3070", 500.00, {{"Memory", "8GB GDDR6"}, {"Cores", "5888"}})
    };

    vector<Accessory> accParts{
        Accessory("Monitor", 350.00, {{"Resolution", "2560x1440"}, {"Size", "27 inches"}}),
        Accessory("Keyboard", 70.00, {{"Type", "Mechanical"}, {"Backlight", "RGB"}}),
        Accessory("Mouse", 40.00, {{"Type", "Wireless"}, {"DPI", "16000"}})
    };

    Computer comp; // This is the computer we're building
    int choice;
    while (true) { // Loop to keep the menu going until the user exits
        cout << "\n--------------------------------------";
        cout << "\n************  M E N U  **************\n"
            << "--------------------------------------\n"
            << "1. View current build\n"
            << "2. Remove a part\n"
            << "3. Clear build\n"
            << "4. Add CPU\n"
            << "5. Add RAM\n"
            << "6. Add Motherboard\n"
            << "7. Add Storage\n"
            << "8. Add Case\n"
            << "9. Add Power Supply\n"
            << "10. Add Graphics Card\n"
            << "11. Add Accessory\n"
            << "12. Exit\n\n"
            << "Input Choice. ";
        cin >> choice;

        // Check if the user input is valid
        if (cin.fail() || choice < 1 || choice > 12) {
            cin.clear(); // Clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any leftover input
            cout << "Invalid input. Please enter a number between 1 and 12.\n";
            continue; // Start the loop again
        }

        try {
            if (choice == 1) {
                comp.viewBuild(); // Show the current build
            }
            else if (choice == 2) {
                int partIndex;
                comp.printBuild(); // Show the parts so the user can pick which to remove
                cout << "\nInput the Part # to remove: ";
                cin >> partIndex;
                if (cin.fail() || partIndex < 1 || partIndex > comp.getCurrentBuild().size()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid part number.\n";
                    continue; // Start the loop again
                }
                comp.removePart(partIndex - 1); // Remove the selected part
            }
            else if (choice == 3) {
                comp.clearBuild(); // Remove all parts from the build
                cout << "Build cleared.\n";
            }
            else if (choice >= 4 && choice <= 11) { // Handling the case when the user wants to add a part
                int chosenPart;
                switch (choice) {
                case 4: displayParts(cpuParts); break; // Show CPU options
                case 5: displayParts(ramParts); break; // Show RAM options
                case 6: displayParts(mthrBrdParts); break; // Show motherboard options
                case 7: displayParts(strgParts); break; // Show storage options
                case 8: displayParts(caseParts); break; // Show case options
                case 9: displayParts(psuParts); break; // Show PSU options
                case 10: displayParts(gpuParts); break; // Show GPU options
                case 11: displayParts(accParts); break; // Show accessory options
                }
                cin >> chosenPart;
                if (cin.fail() || chosenPart < 1 || chosenPart > cpuParts.size()) { // Check if the user input is valid
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid part number.\n\n";
                    continue; // Start the loop again
                }

                // Add the selected part to the computer build
                switch (choice) {
                case 4: comp.addPart(cpuParts[chosenPart - 1], "CPU"); break;
                case 5: comp.addPart(ramParts[chosenPart - 1], "RAM"); break;
                case 6: comp.addPart(mthrBrdParts[chosenPart - 1], "Motherboard"); break;
                case 7: comp.addPart(strgParts[chosenPart - 1], "Hard Drive"); break;
                case 8: comp.addPart(caseParts[chosenPart - 1], "Case"); break;
                case 9: comp.addPart(psuParts[chosenPart - 1], "Power Supply"); break;
                case 10: comp.addPart(gpuParts[chosenPart - 1], "Graphics Card"); break;
                case 11: comp.addPart(accParts[chosenPart - 1], "Accessory"); break;
                }

            }
            else if (choice == 12) { // Exit the program
                cout << "\nExiting...\n";
                break; // End the loop and exit
            }
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl; // Display any errors that occur
        }
    }

    return 0;
}