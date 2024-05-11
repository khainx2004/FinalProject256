#include "User.h"
#include "Admin.h"
#include "Staff.h"
#include "Task.h"
#include "SingleTask.h"
#include "ShareTask.h"

#include "User.cpp"
#include "Admin.cpp"
#include "Staff.cpp"
#include "Task.cpp"
#include "SingleTask.cpp"
#include "ShareTask.cpp"

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
    Admin admin;
    Staff staff1("Xuan Khai"),staff2("Vu");

    admin.addStaff(&staff1);
    admin.addStaff(&staff2);

    SingleTask task1("ST001", "Prepare report");
    ShareTask task2("ST002", "Update website");

    admin.addTask(&task1);
    admin.addTask(&task2);

    Staff* foundStaff = nullptr;
    int choice;
    do {
        std::cout << "============*MAIN MENU*============" << std::endl;
        std::cout << "1. Admin Menu\n2. Staff Menu\n0. Exit\nEnter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                admin.displayMenu();
                break;
            case 2:
                std::cout << "Enter staff's ID: ";
                int staffID;
                std::cin >> staffID;

                
                // const std::vector<Staff*>& staffMembers = admin.getStaffMembers();
                for (Staff* staff: admin.getStaffMembers()) {
                    if (staff->getID() == staffID) {
                        foundStaff = staff;
                        break;
                    }
                }
                if (foundStaff) {
                    foundStaff->displayMenu();
                }
                else {
                        std::cout << "Staff not found.\n";
                    }
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }while (choice != 0);

    return 0;
}
