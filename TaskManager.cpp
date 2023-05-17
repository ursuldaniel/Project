#include <iostream>
#include <vector>
#include <string>

class Task {
private:
    std::string task_title;
    std::string task_description;
    std::string task_priority;
    bool task_status = false;
public:
    Task() {}

    Task(const std::string& t, const std::string d, const std::string& p) {
        task_title = t;
        task_description = d;
        task_priority = p;
    }

    std::string get_task_title() const {
        return task_title;
    }

    std::string get_task_description() const {
        return task_description;
    }

    std::string get_task_priority() const {
        return task_priority;
    }

    std::string get_task_status() const {
        return (task_status ? "Completed" : "Uncompleted");
    }

    void get_task_completed() {
        task_status = true; 
    }

    void display_task() const {
        std::cout << "Title: " << task_title << '\n';
        std::cout << "Description: " << task_description << '\n';
        std::cout << "Priority: " << task_priority << '\n';
        std::cout << "Status: " << get_task_status() << "\n\n"; 
    }
};

class TaskManager {
private:
    std::vector<Task> tasks;

    bool task_exists(const std::string& title) const {
        for (int i = 0; i < tasks.size(); i++) {
            if (title == tasks[i].get_task_title()) {
                return true;
            }
        }
        return true;
    }

    bool task_high_exists() const {
        for (int i = 0; i < tasks.size(); i++) {
            if (tasks[i].get_task_priority() == "High") {
                return true;
            }
        }
        return false;
    }

    bool task_middle_exists() const {
        for (int i = 0; i < tasks.size(); i++) {
            if (tasks[i].get_task_priority() == "Middle") {
                return true;
            }
        }
        return false;
    }

    bool task_low_exists() const {
        for (int i = 0; i < tasks.size(); i++) {
            if (tasks[i].get_task_priority() == "Low") {
                return true;
            }
        }
        return false;
    }
public:
    TaskManager() {}

    void add_task(const Task& task) { //
        tasks.push_back(task);
    }

    void complete_task(const std::string& title) {
        if (!task_exists(title)) {
            std::cout << "There Is No Such Task\n";
            return;
        }

        for (int i = 0; i < tasks.size(); i++) {
            if (title == tasks[i].get_task_title()) {
                tasks[i].get_task_completed();
                break;
            }
        }

        std::cout << "There Is No Such Task\n\n";
    }

    void delete_task(const std::string& title) {
        if (!task_exists(title)) {
            std::cout << "There Is No Such Task\n";
        }

        for (auto it = tasks.begin(); it != tasks.end(); it++) {
            if (title == it->get_task_title()) {
                tasks.erase(it);
                break;
            }
        }

        std::cout << "There Is No Such Task\n\n";
    }

    void display_tasks_high() const {
        if (!task_high_exists()) {
            std::cout << "There Are No High-Priority Tasks\n";
            return;
        }

        std::cout << "High-Priority Tasks: \n";
        for (int i = 0; i < tasks.size(); i++) {
            if (tasks[i].get_task_priority() == "High") {
                std::cout << "#" << i + 1 << '\n';
                tasks[i].display_task();
            }
        }
    }

    void display_tasks_middle() const {
        if (!task_middle_exists()) {
            std::cout << "There Are No Middle-Priority Tasks\n";
            return;
        }

        std::cout << "Middle-Priority Tasks: \n";
        for (int i = 0; i < tasks.size(); i++) {
            if (tasks[i].get_task_priority() == "Middle") {
                std::cout << "#" << i + 1 << '\n';
                tasks[i].display_task();
            }
        }
    }

    void display_tasks_low() const {
        if (!task_low_exists()) {
            std::cout << "There Are No Low-Priority Tasks\n";
            return;
        }

        std::cout << "Low-Priority Tasks: \n";
        for (int i = 0; i < tasks.size(); i++) {
            if (tasks[i].get_task_priority() == "Low") {
                std::cout << "#" << i + 1 << '\n';
                tasks[i].display_task();
            }
        }
    }

    void unsorted_display() const {
        if (tasks.size() == 0) {
            std::cout << "There Are No Tasks\n";
            return;
        }

        for (int i = 0; i < tasks.size(); i++) {
            std::cout << "#" << i + 1 << '\n';
            tasks[i].display_task();
        }
    }

    void sorted_display() const {
        if (tasks.size() == 0) {
            std::cout << "There Are No Tasks\n";
            return;
        }

        display_tasks_high();
        display_tasks_middle();
        display_tasks_low();
    }
};

class UserInterface : public TaskManager {
private:
    void create_info() const {
        std::cout << "----------------------\n";
        std::cout << "     CREATING MENU    \n";
        std::cout << "----------------------\n";
    }

    void complete_info() const {
        std::cout << "----------------------\n";
        std::cout << "    COMPLETING MENU   \n";
        std::cout << "----------------------\n";
        std::cout << "Enter Tasks' Title: ";
    }

    void delete_info() const {
        std::cout << "----------------------\n";
        std::cout << "     DELETING MENU    \n";
        std::cout << "----------------------\n";
        std::cout << "Enter Tasks' Title: ";
    }

    void view_info() const {
        std::cout << "----------------------\n";
        std::cout << "     VIEWING MENU    \n";
        std::cout << "----------------------\n";
        std::cout << "Select: \n";
        std::cout << "1 - View High-Priority Tasks\n";
        std::cout << "2 - View Middle-Priority Tasks\n";
        std::cout << "3 - View Low-Priority Tasks\n";
        std::cout << "4 - View Unsorted Tasks\n";
        std::cout << "5 - View Sorted Tasks\n\n";
    }

    void create_task() {
        std::string t;
        std::string d;
        std::string p;

        std::cout << "Enter title: ";
        std::cin >> t;

        std::cout << "Enter description: ";
        std::cin >> d;

        std::cout << "Enter priority: ";
        std::cin >> p;

        Task task(t, d, p);
        add_task(task);
    }
public:
    UserInterface() {}

    void greeting() const {
        std::cout << "WELCOME TO TASKMANAGER\n\n";
    }

    void general_info() const {
        std::cout << "----------------------\n";
        std::cout << "         MENU         \n";
        std::cout << "----------------------\n";
        std::cout << "0 - Exit\n";
        std::cout << "1 - Create\n";
        std::cout << "2 - Complete\n";
        std::cout << "3 - Delete\n";
        std::cout << "4 - View\n";
        std::cout << "5 - Clear Console\n\n";
    }

    void exit_case() const {
        std::cout << "See you later!";
        exit(0);
    }

    void create_case() {
        create_info();
        create_task();
    }

    void complete_case() {
        complete_info();

        std::string title;
        std::cin >> title;

        complete_task(title);
    }

    void delete_case() {
        delete_info();
        
        std::string title;
        std::cin >> title;

        delete_task(title);
    }

    void view_case() {
        view_info();

        std::string choice;
        std::cin >> choice;

        if (choice == "1") {
            display_tasks_high();
        }

        if (choice == "2") {
            display_tasks_middle();
        }

        if (choice == "3") {
            display_tasks_low();
        }

        if (choice == "4") {
            unsorted_display();
        }

        if (choice == "5") {
            sorted_display();
        }
    }
};

int main() {
    UserInterface UI;
    UI.greeting();
    UI.general_info();

    while (true) {
        std::string choice;
        std::cout << "Your Choice: ";
        std::cin >> choice;

        if (choice == "0") {
            UI.exit_case();
        }

        if (choice == "1") {
            system("cls");
            UI.create_case();
            UI.general_info();
        }

        if (choice == "2") {
            system("cls");
            UI.complete_case();
            UI.general_info();
        }

        if (choice == "3") {
            system("cls");
            UI.delete_case();
            UI.general_info();
        }

        if (choice == "4") {
            system("cls");
            UI.view_case();
            UI.general_info();
        }

        if (choice == "5") {
            system("cls");
            UI.general_info();
        }
    }
}
