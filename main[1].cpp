// main.cpp
// Corner Grocer: menu interface only
#include <iostream>
#include <string>
#include "ItemTracker.h"

int main() {
    ItemTracker tracker;

    /* 1) Load data file & make backup copy */
    if (!tracker.LoadFile("CS210_Project_Three_Input_File.txt"))
        return 1;                                     // bail if missing

    tracker.WriteBackup("frequency.dat");             // silent fail OK

    /* 2) Simple four-choice menu loop */
    int choice = 0;
    while (choice != 4) {
        std::cout << "\nCorner Grocer: Main Menu\n"
            "1  Look up item frequency\n"
            "2  Print item list with counts\n"
            "3  Print histogram\n"
            "4  Exit\n"
            "Enter choice > ";
        if (!(std::cin >> choice)) {                  // non-numeric guard
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input – please enter 1-4.\n";
            continue;
        }
        std::cin.ignore();                            // eat leftover '\n'

        switch (choice) {
        case 1: {                                     // ---- option 1 ----
            std::string item;
            std::cout << "Enter item to look for > ";
            std::getline(std::cin, item);
            std::cout << item << " was sold "
                << tracker.GetCount(item) << " time(s).\n";
            break;
        }
        case 2:                                       // ---- option 2 ----
            std::cout << "\nItem Counts\n-----------\n";
            tracker.PrintAll();
            break;
        case 3:                                       // ---- option 3 ----
            std::cout << "\nSales Histogram\n---------------\n";
            tracker.PrintHistogram();
            break;
        case 4:                                       // ---- option 4 ----
            std::cout << "Good-bye!\n";
            break;
        default:
            std::cout << "Please choose 1-4.\n";
        }
    }
    return 0;
}
