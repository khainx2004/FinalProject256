#include "admin.h"
#include "singletask.h"
#include "sharetask.h"

Admin::Admin() : User() {}

Admin::Admin(const string& name, const string& password)
    : User(name, "Admin", password) {}

void Admin::displayUserInfo()
{
    cout << "----------User Information----------" << endl;
    cout << "User name: " << this->getName() << endl;
    cout << "Role: " << this->getRole() << endl;
    cout << "------------------------------------" << endl;
}
const std::vector<Staff*>& Admin::getStaffMembers() const {
        return staff;
    }
void Admin::adminMenu(std::vector<User*>& userList)
{
    int option;
    do{
        cout << "-------------Admin Menu-------------" << endl;
        cout << "1. Display User Information" << endl;
        cout << "2. Display Staff List" << endl;
        cout << "3. Add New Staff" << endl;
        cout << "4. Remove Staff" << endl;
        cout << "5. Display Task List" << endl;
        cout << "6. Add New Task" << endl;
        cout << "7. Remove Task" << endl;
        cout << "8. Assign Task to Staff" << endl;
        cout << "9. Log out" << endl;
        cout << "Enter your option: ";
        cin >> option;
        cin.ignore();
        cin.clear();

        switch (option){
            case 1:
                displayUserInfo();
                break;
            case 2:
                displayStaffList();
                break;
            case 3:
                addStaff(userList);
                break;
            case 4:
                removeStaff();
                break;
            case 5:
                displayTaskList();
                break;
            case 6:
                addTask();
                break;
            case 7: 
                removeTask();
                break;
            case 8:
                assignTask();
                break;
            case 9:
                cout << "-----------Logging out...-----------" << endl;
                break;
            default:
                cout << "-----Invalid value. Try again!------" << endl;
                break;
        }
    }
    while (option != 9);
}

void Admin::displayStaffList()
{
    if (staff.empty()){
        cout << "----------No Staff Found------------" << endl;
    }
    else{
        cout << "-------------Staff List-------------" << endl;
        for (int i = 0; i < staff.size(); i++){
            cout << " - ID: " << staff[i]->getID() << "_Name: " << staff[i]->getName() << endl;
        }
        cout << "------------------------------------" << endl;
    }
}

void Admin::addStaff(vector<User*>& userList)
{
    string name, password;
    cout << "----------Adding New Staff----------" << endl;
    cout << "Enter staff name: ";
    getline(cin, name);
    cout << "Enter password for staff: ";
    getline(cin, password);

    Staff* newstaff = new Staff(name,password);
    staff.push_back(newstaff);
    userList.push_back(newstaff);
    cout << "----Add new staff successfully!-----" << endl;
    cout << "------------------------------------" << endl;

}

void Admin::removeStaff()
{
    int id;
    cout << "Enter staff's ID to remove: ";
    cin >> id;

    for (int i = 0; i < staff.size(); i++){
        if (staff[i]->getID() == id){
            staff.erase(staff.begin() + i);
            cout << "-----Remove staff successfully!-----" << endl;
            cout << "------------------------------------" << endl;
        }
    }
}
void Admin::displayTaskList()
{
    if (taskList.empty()){
        cout << "-----------No task found!-----------" << endl;
    }
    else{
        cout << "-------------Task List--------------" << endl;
        for (int i = 0; i < taskList.size(); i++){
            taskList[i]->displayTaskInfo();
        }
    }
}

void Admin::addTask()
{
    string taskName, deadline;
    int typechoice;
    cout << "Enter task name: ";
    getline(cin, taskName);
    cout << "Enter deadline: ";
    getline(cin, deadline);
    cout << "If single task choose <1>\nIf Shared Task choose <2>" <<endl;
    cin >> typechoice;
    if (typechoice == 1) {
        Task* newtask = new SingleTask(taskName,deadline);
        taskList.push_back(newtask);
    }
    else if (typechoice == 2) {
        Task* newtask = new ShareTask(taskName,deadline);
        taskList.push_back(newtask);
    }
    cout << "-----Add new task successfully!-----" << endl;
    cout << "------------------------------------" << endl;
}

void Admin::removeTask()
{
    int taskId;
    cout << "Enter task ID to remove: ";
    cin >> taskId;
    cin.ignore();
    cin.clear();

    for (int i = 0; i < taskList.size(); i++){
        if (taskId == taskList[i]->getTaskId()){
            taskList.erase(taskList.begin() + i);
            cout << "-----Remove task successfully!------" << endl;
            cout << "------------------------------------" << endl;
        }
    }
}

void Admin::assignTask()
{
    int taskid,staffid;
    bool staffFound = false;
    bool taskFound = false;
    cout << "--------Assign Task To Staff--------" << endl;
    cout << "Enter Staff's ID to asign: ";
    cin >> staffid;

    for(const auto& staff: staff) {
        if (staff->getID() == staffid) {
            staffFound = true;
            cout << "Enter Task'ID to assign: ";
            cin >> taskid;
            for (const auto& t: taskList) {
                if (t->getTaskId() == taskid) {
                    taskFound = true;
                    if (canAssign(staff,t) == true) {
                        cout << "-Assign Task To Staff Successfully!-\n";
                        cout << "------------------------------------" << endl;
                    }
                    else {
                        cout << "-This task is already assigned!-" << endl;
                        cout << "------------------------------------" << endl;
                    }
                    break;
                }
            }
            if (!taskFound) {
                cout << "-----------No Task Found-----------\n";
            }
            break;
        }

    }
    if (!staffFound) {
        cout << "-----------No Staff Found-----------\n";
    }
}

bool Admin::canAssign(Staff* staff, Task* task) {
        if (dynamic_cast<SingleTask*>(task)) {
            SingleTask* singletask = static_cast<SingleTask*>(task);
            return singletask->assignStaff(staff);
        }
        else {
            ShareTask* sharetask = static_cast<ShareTask*>(task);
            return sharetask->assignStaff(staff);
        }
}
