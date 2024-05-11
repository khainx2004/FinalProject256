#include "Admin.h"
#include "SingleTask.h"
#include "ShareTask.h"
Admin::Admin()
    :User() {

    }
Admin::Admin(const std::string& name)  
    : User(name) {

    }

const std::vector<Staff*>& Admin::getStaffMembers() const {
        return staff;
    }
void Admin::displayMenu() {
        int choice;
        while(choice != 0) {
            std::cout << "============*ADMIN MENU*============" << std::endl;
            std::cout << "1. Manage Staff\n2. Manage Tasks\n0. Exit\nEnter choice: ";
            std::cin >> choice;
            switch (choice) {
                case 1:
                    manageStaff();
                    break;
                case 2: 
                    manageTasks();
                    break;
                case 0:
                    std::cout << "Exiting..\n";
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
        }
}

void Admin::manageStaff() {
    int choice;

    bool in_manastaffmenu = true;
    while(in_manastaffmenu) {
        std::cout << "===========*STAFF MANAGEMENT*===========" << std::endl;
        std::cout << "1. Add Staff\n2. Remove Staff\n3. Update Staff\n4. Display Staff Members\n0. Back\nEnter choice: ";
        std::cin >> choice;
        if(choice == 1){
            std::string new_staffname;
            std::cout << "\nAdd Staff: \nPlease Enter Name: ";
            std::cin.ignore();
            getline(std::cin,new_staffname);
            Staff* newstaff = new Staff(new_staffname);
            addStaff(newstaff);
            std::cout << "Added Staff successfully.\n";
        }
        else if (choice == 2) {
            removeStaff();
        }
        else if (choice == 3) {
            updateStaff();
        }
        else if (choice == 4) {
            viewStaff();
        }
        else if (choice == 0) {
            std::cout << "Going back...\n";
            in_manastaffmenu = false;
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
    
}
void Admin::addStaff(Staff* newstaff) {
    staff.push_back(newstaff);
}
void Admin::removeStaff() {
    std::cout << "\nEnter Staff's ID you want to remove: ";
    int removeid;
    std::cin >> removeid;
    bool staffRemoved = false;
    for (auto it = staff.begin(); it != staff.end(); ++it) {
        Staff* s = *it;
        if (s->getID() == removeid) {
            staff.erase(it);
            std::cout << "Staff member removed successfully.\n";
            staffRemoved = true;
            break;
        }
    }
    if (!staffRemoved) {
        std::cout << "Staff member with ID:" << removeid << " not found." << std::endl;
    }
}

void Admin::updateStaff() {
    int idupdate;
    std::cout << "\nEnter Staff's ID you want to update: ";
    std::cin >> idupdate;
    bool staffFound = false;
    for (Staff* s: staff) {
        if (s->getID() == idupdate) {
            std::string newName;
            std::cout << "Enter new name: ";
            std::cin.ignore();
            getline(std::cin, newName);
            s->setname(newName);
            std::cout << "Staff member updated succesfully." << std::endl;
            staffFound = true;
        }
    }
    if (!staffFound) {
        std::cout << "Staff not found." << std::endl;
    }
    

}

void Admin::viewStaff() {
    if (staff.empty()) {
        std::cout << "\nNo staff member to display." << std::endl;
    }
    else {
        std::cout << "\n";
        for (const auto& s: staff) {
            std::cout << "Staff: " << s->getname() << " [ID: " << s->getID() << "]" << std::endl;  
        }
    }
}
void Admin::manageTasks() {
    int choice;
    bool inmanaTask = true;
    while(inmanaTask){
        std::cout << "===========*TASK MANAGEMENT*===========" << std::endl;
        std::cout << "1. Add Task\n2. Assign Task\n3. View Task\n0. Back\nEnter choice: ";
        std::cin >> choice;
        if(choice == 1){
            std::string new_taskname;
            std::string task_des;
            int typechoice;
            std::cout << "\nAdd Task: \nPlease Enter Task's Name: ";
            std::cin >> new_taskname;
            std::cin.ignore();
            std::cout << "Description of Task: ";
            getline(std::cin,task_des);
            std::cout << "If single task choose <1>\nIf Shared Task choose <2>" << std::endl;
            std::cin >> typechoice;
            if (typechoice == 1) {
                Task* newtask = new SingleTask(new_taskname,task_des);
                addTask(newtask);
            }
            else if (typechoice == 2) {
                Task* newtask = new ShareTask(new_taskname,task_des);
                addTask(newtask);
            }
            std::cout << "Add task successfully.\n";
        }
        else if (choice == 2) {
            bool staffFound = false;
            bool taskFound = false;

            int staffid;
            int taskid;

            std::cout << "\nAssign Task to Staff Member: \n";
            std::cout << "Enter Staff's ID you want to assign to: ";
            std::cin >> staffid;
        
            for (const auto& s: staff) {
                if (s->getID() == staffid){
                    staffFound = true;
                    std::cout << "Enter Task's ID you want to assign: ";
                    std::cin >> taskid;

                    for (const auto& t: tasks) {
                        if (t->getID() == taskid){
                            taskFound = true;
                            if(assignTask(s,t) == true) {
                                std::cout << "Assigned successfully.\n";
                                }
                            else {
                                std::cout << "Assigned unsuccessful.\n";
                            }
                            
                            break;
                        }
                    }

                    if (!taskFound) {
                        std::cout << "Task not found.\n";
                    }

                    break;
                }
            }
            if (!staffFound) {
                std::cout << "Staff not found.\n";
            }
        }
        else if (choice == 3) {
            viewTasks();
        }
        else if (choice == 0) {
            std::cout << "Going back...\n";
            inmanaTask = false;
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
    
}



void Admin::addTask(Task* newtask) {
    tasks.push_back(newtask);
}



void Admin::viewTasks() {
    if (tasks.empty()) {
        std::cout << "No tasks available." << std::endl;
    }
    else {
        std::cout << "Tasks: \n";
        for (size_t i = 0; i < tasks.size(); i++) {
            std::cout << "Task " << i + 1 << ": \n";
            tasks[i]->displayDetails();
            std::cout << "\n";
        }
    }
}

bool Admin::assignTask(Staff* staff, Task* task) {
    if (dynamic_cast<SingleTask*>(task)) {
        SingleTask* singleTask = static_cast<SingleTask*>(task);
        return singleTask->assignStaff(staff);
    }
    else {
        ShareTask* shareTask = static_cast<ShareTask*>(task);
        return shareTask->assignStaff(staff);

    }
}

