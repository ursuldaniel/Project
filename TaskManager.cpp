#include <iostream>
#include <vector>
#include <algorithm>

class Task {
public:
    virtual std::string get_task_name() const = 0;
    virtual std::string get_task_description() const = 0;
    virtual std::string get_task_priority() const = 0;
    virtual std::string get_task_status() const = 0;
    virtual void display_task() const = 0;
};

class TaskHigh : public Task {
private:
    std::string name;
    std::string description;
    std::string priority = "High";
    bool status = false;
public:
    TaskHigh() {}

    TaskHigh(std::string n, std::string d) {
        name = n;
        description = d;
    }

    std::string get_task_name() const override {
        return name;
    }

    std::string get_task_description() const override {
        return description;
    }

    std::string get_task_priority() const override {
        return priority;
    }

    std::string get_task_status() const override {
        return (status ? "Completed" : "Uncompleted");
    }

    void display_task() const override {
        std::cout << "Name: " << name << '\n';
        std::cout << "Description: " << description << '\n';
        std::cout << "Priority: " << priority << '\n';
        std::cout << "Status: " << get_task_status() << "\n\n";
    }

    bool operator == (const Task*& other) {
        return name == other->get_task_name();
    }
};

class TaskMiddle : public Task {
private:
    std::string name;
    std::string description;
    std::string priority = "Middle";
    bool status = false;
public:
    TaskMiddle() {}

    TaskMiddle(std::string n, std::string d) {
        name = n;
        description = d;
    }

    std::string get_task_name() const override {
        return name;
    }

    std::string get_task_description() const override {
        return description;
    }

    std::string get_task_priority() const override {
        return priority;
    }

    std::string get_task_status() const override {
        return (status ? "Completed" : "Uncompleted");
    }

    void display_task() const override {
        std::cout << "Name: " << name << '\n';
        std::cout << "Description: " << description << '\n';
        std::cout << "Priority: " << priority << '\n';
        std::cout << "Status: " << get_task_status() << "\n\n";
    }

    bool operator == (const Task*& other) {
        return name == other->get_task_name();
    }
};

class TaskLow : public Task {
private:
    std::string name;
    std::string description;
    std::string priority = "Low";
    bool status = false;
public:
    TaskLow() {}

    TaskLow(std::string n, std::string d) {
        name = n;
        description = d;
    }

    std::string get_task_name() const override {
        return name;
    }

    std::string get_task_description() const override {
        return description;
    }

    std::string get_task_priority() const override {
        return priority;
    }

    std::string get_task_status() const override {
        return (status ? "Completed" : "Uncompleted");
    }

    void display_task() const override {
        std::cout << "Name: " << name << '\n';
        std::cout << "Description: " << description << '\n';
        std::cout << "Priority: " << priority << '\n';
        std::cout << "Status: " << get_task_status() << "\n\n";
    }

    bool operator == (const Task*& other) {
        return name == other->get_task_name();
    }
};

class TaskManager {
private:
    std::vector<TaskHigh*> tasks_high;
    std::vector<TaskMiddle*> tasks_middle;
    std::vector<TaskLow*> tasks_low;
    std::vector<Task*> tasks;
public:
    TaskManager() {}

    void add_task_high(TaskHigh* task) {
        tasks_high.push_back(task);
        tasks.push_back(task);
    }

    void add_task_middle(TaskMiddle* task) {
        tasks_middle.push_back(task);
        tasks.push_back(task);
    }

    void add_task_low(TaskLow* task) {
        tasks_low.push_back(task);
        tasks.push_back(task);
    }

    void complete_task(Task* task) {
        auto it = std::find(tasks.begin(), tasks.end(), task);
        tasks.erase(it);
    }

    void display_tasks_high() {
        std::cout << "High-Priority Tasks: \n";
        for (int i = 0; i < tasks_high.size(); i++) {
            std::cout << "#" << i + 1 << '\n';
            tasks_high[i]->display_task();
        }
    }

    void display_tasks_middle() {
        std::cout << "Middle-Priority Tasks: \n";
        for (int i = 0; i < tasks_middle.size(); i++) {
            std::cout << "#" << i + 1 << '\n';
            tasks_middle[i]->display_task();
        }
    }

    void display_tasks_low() {
        std::cout << "Low-Priority Tasks: \n";
        for (int i = 0; i < tasks_low.size(); i++) {
            std::cout << "#" << i + 1 << '\n';
            tasks_low[i]->display_task();
        }
    }

    void unsorted_display() {
        for (int i = 0; i < tasks.size(); i++) {
            std::cout << "#" << i + 1 << '\n';
            tasks[i]->display_task();
        }
    }

    void sorted_display() {
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
        std::cout << "Select: \n";
        std::cout << "1 - High-Priority Task\n";
        std::cout << "2 - Middle-Priority Task\n";
        std::cout << "3 - Low-Priority Task\n\n";
    }

    void complete_info() const {
        std::cout << "----------------------\n";
        std::cout << "     COMPLETING MENU    \n";
        std::cout << "----------------------\n";
        std::cout << "To complete task enter title: ";
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

    void create_task_high() {
        std::string t;
        std::string d;

        std::cout << "Enter title: ";
        std::cin >> t;

        std::cout << "Enter description: ";
        std::cin >> d;

        TaskHigh* task_high = new TaskHigh(t, d);
        add_task_high(task_high);
    }

    void create_task_middle() {
        std::string t;
        std::string d;

        std::cout << "Enter title: ";
        std::cin >> t;

        std::cout << "Enter description: ";
        std::cin >> d;

        TaskMiddle* task_middle = new TaskMiddle(t, d);
        add_task_middle(task_middle);
    }

    void create_task_low() {
        std::string t;
        std::string d;

        std::cout << "Enter title: ";
        std::cin >> t;

        std::cout << "Enter description: ";
        std::cin >> d;

        TaskLow* task_low = new TaskLow(t, d);
        add_task_low(task_low);
    }
public:
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
        std::cout << "3 - View\n\n";
    }

    void exit_case() {
        std::cout << "See you later!";
        exit(0);
    }

    void create_case() {
        create_info();

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            create_task_high();
        }

        if (choice == 2) {
            create_task_middle();
        }

        if (choice == 3) {
            create_task_low();
        }
    }

    void complete_case() {
        complete_info();

        std::string title;
        std::cin >> title;

        Task* task = new TaskHigh(title, "");
        complete_task(task);
    }

    void view_case() {
        view_info();

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            display_tasks_high();
        }

        if (choice == 2) {
            display_tasks_middle();
        }

        if (choice == 3) {
            display_tasks_low();
        }

        if (choice == 4) {
            unsorted_display();
        }

        if (choice == 5) {
            sorted_display();
        }
    }
};

int main() {
    UserInterface UI;
    UI.greeting();
    UI.general_info();
    
    while (true) {
        int choice;
        std::cout << "Your Choice: ";
        std::cin >> choice;

        if (choice == 0){
            UI.exit_case();
        }
        
        if (choice == 1) {
            system("cls");
            UI.create_case();
            system("cls");
            UI.general_info();
        }

        if (choice == 2) {
            // system("cls");
            // UI.complete_case();
            // system("cls");
            // UI.general_info();
        }

        if (choice == 3) {
            system("cls");
            UI.view_case();
            UI.general_info();
        }
    }
}
