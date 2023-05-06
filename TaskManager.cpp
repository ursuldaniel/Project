#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    virtual std::string get_task_title() const = 0;
    virtual std::string get_task_description() const = 0;
    virtual std::string get_task_priority() const = 0;
    virtual std::string get_task_status() const = 0;
    virtual void display_task() const = 0;
    virtual void complete_task() = 0;
};

class TaskHigh : public Task {
private:
    std::string task_title;
    std::string task_description;
    std::string task_priority = "High";
    bool task_status = false;
public:
    TaskHigh() {}

    TaskHigh(const std::string& t, const std::string& d) {
        task_title = t;
        task_description = d;
    }

    std::string get_task_title() const override {
        return task_title;
    }

    std::string get_task_description() const override {
        return task_description;
    }

    std::string get_task_priority() const override {
        return task_priority;
    }

    std::string get_task_status() const override {
        return (task_status ? "Completed" : "Uncompleted");
    }

    void display_task() const override {
        std::cout << "Title: " << task_title << '\n';
        std::cout << "Description: " << task_description << '\n';
        std::cout << "Priority: " << task_priority << '\n';
        std::cout << "Status: " << get_task_status() << "\n\n";
    }

    void complete_task() override {
        task_status = true;
    }
};

class TaskMiddle : public Task {
private:
    std::string task_title;
    std::string task_description;
    std::string task_priority = "Middle";
    bool task_status = false;
public:
    TaskMiddle() {}

    TaskMiddle(const std::string& t, const std::string& d) {
        task_title = t;
        task_description = d;
    }

    std::string get_task_title() const override {
        return task_title;
    }

    std::string get_task_description() const override {
        return task_description;
    }

    std::string get_task_priority() const override {
        return task_priority;
    }

    std::string get_task_status() const override {
        return (task_status ? "Completed" : "Uncompleted");
    }

    void display_task() const override {
        std::cout << "Title: " << task_title << '\n';
        std::cout << "Description: " << task_description << '\n';
        std::cout << "Priority: " << task_priority << '\n';
        std::cout << "Status: " << get_task_status() << "\n\n";
    }

    void complete_task() override {
        task_status = true;
    }
};

class TaskLow : public Task {
private:
    std::string task_title;
    std::string task_description;
    std::string task_priority = "Middle";
    bool task_status = false;
public:
    TaskLow() {}

    TaskLow(const std::string& t, const std::string& d) {
        task_title = t;
        task_description = d;
    }

    std::string get_task_title() const override {
        return task_title;
    }

    std::string get_task_description() const override {
        return task_description;
    }

    std::string get_task_priority() const override {
        return task_priority;
    }

    std::string get_task_status() const override {
        return (task_status ? "Completed" : "Uncompleted");
    }

    void display_task() const override {
        std::cout << "Title: " << task_title << '\n';
        std::cout << "Description: " << task_description << '\n';
        std::cout << "Priority: " << task_priority << '\n';
        std::cout << "Status: " << get_task_status() << "\n\n";
    }

    void complete_task() override {
        task_status = true;
    }
};

class TaskManager {
private:
    std::vector<TaskHigh*> tasks_high;
    std::vector<TaskMiddle*> tasks_middle;
    std::vector<TaskLow*> tasks_low;
    std::vector<Task*> tasks;

    bool task_high_exists(const std::string& title) const {
        for (int i = 0; i < tasks_high.size(); i++) {
            if (title == tasks_high[i]->get_task_title()) {
                return true;
            }
        }
        return false;
    }

    bool task_middle_exists(const std::string& title) const {
        for (int i = 0; i < tasks_middle.size(); i++) {
            if (title == tasks_middle[i]->get_task_title()) {
                return true;
            }
        }
        return false;
    }

    bool task_low_exists(const std::string& title) const {
        for (int i = 0; i < tasks_middle.size(); i++) {
            if (title == tasks_low[i]->get_task_title()) {
                return true;
            }
        }
        return false;
    }
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

    void complete_task_high(const std::string& title) {
        if (!task_high_exists(title)) {
            std::cout << "There Are No Such High-Priority Task\n";
            return;
        }

        for (int i = 0; i < tasks.size(); i++) {
            if (title == tasks[i]->get_task_title()) {
                tasks[i]->complete_task();
                break;
            }
        }

        for (int i = 0; i < tasks_high.size(); i++) {
            if (title == tasks_high[i]->get_task_title()) {
                tasks_high[i]->complete_task();
                break;
            }
        }
    }

    void complete_task_middle(const std::string& title) {
        if (!task_middle_exists(title)) {
            std::cout << "There Are No Such Middle-Priority Task\n";
            return;
        }

        for (int i = 0; i < tasks.size(); i++) {
            if (title == tasks[i]->get_task_title()) {
                tasks[i]->complete_task();
                break;
            }
        }

        for (int i = 0; i < tasks_middle.size(); i++) {
            if (title == tasks_middle[i]->get_task_title()) {
                tasks_middle[i]->complete_task();
                break;
            }
        }
    }

    void complete_task_low(const std::string& title) {
        if (!task_low_exists(title)) {
            std::cout << "There Are No Such Low-Priority Task\n";
            return;
        }

        for (int i = 0; i < tasks.size(); i++) {
            if (title == tasks[i]->get_task_title()) {
                tasks[i]->complete_task();
                break;
            }
        }

        for (int i = 0; i < tasks_low.size(); i++) {
            if (title == tasks_low[i]->get_task_title()) {
                tasks_low[i]->complete_task();
                break;
            }
        }
    }

    void delete_task_high(const std::string& title) {
        if (!task_high_exists(title)) {
            std::cout << "There Are No Such High-Priority Task\n";
            return;
        }

        for (auto it = tasks.begin(); it != tasks.end(); it++) {
            if (title == (*it)->get_task_title()) {
                tasks.erase(it);
                break;
            }
        }

        for (auto it = tasks_high.begin(); it != tasks_high.end(); it++) {
            if (title == (*it)->get_task_title()) {
                tasks_high.erase(it);
                break;
            }
        }
    }

    void delete_task_middle(const std::string& title) {
        if (!task_middle_exists(title)) {
            std::cout << "There Are No Such Middle-Priority Task\n";
            return;
        }

        for (auto it = tasks.begin(); it != tasks.end(); it++) {
            if (title == (*it)->get_task_title()) {
                tasks.erase(it);
                break;
            }
        }

        for (auto it = tasks_middle.begin(); it != tasks_middle.end(); it++) {
            if (title == (*it)->get_task_title()) {
                tasks_middle.erase(it);
                break;
            }
        }
    }

    void delete_task_low(const std::string& title) {
        if (!task_low_exists(title)) {
            std::cout << "There Are No Such Low-Priority Task\n";
            return;
        }

        for (auto it = tasks.begin(); it != tasks.end(); it++) {
            if (title == (*it)->get_task_title()) {
                tasks.erase(it);
                break;
            }
        }

        for (auto it = tasks_low.begin(); it != tasks_low.end(); it++) {
            if (title == (*it)->get_task_title()) {
                tasks_low.erase(it);
                break;
            }
        }
    }

    void display_tasks_high() {
        if (tasks_high.size() == 0) {
            std::cout << "There Are No High-Priority Tasks\n";
            return;
        }

        std::cout << "High-Priority Tasks: \n";
        for (int i = 0; i < tasks_high.size(); i++) {
            std::cout << "#" << i + 1 << '\n';
            tasks_high[i]->display_task();
        }
    }

    void display_tasks_middle() {
        if (tasks_middle.size() == 0) {
            std::cout << "There Are No Middle-Priority Tasks\n";
            return;
        }

        std::cout << "Middle-Priority Tasks: \n";
        for (int i = 0; i < tasks_middle.size(); i++) {
            std::cout << "#" << i + 1 << '\n';
            tasks_middle[i]->display_task();
        }
    }

    void display_tasks_low() {
        if (tasks_low.size() == 0) {
            std::cout << "There Are No Low-Priority Tasks\n";
            return;
        }

        std::cout << "Low-Priority Tasks: \n";
        for (int i = 0; i < tasks_low.size(); i++) {
            std::cout << "#" << i + 1 << '\n';
            tasks_low[i]->display_task();
        }
    }

    void unsorted_display() {
        if (tasks.size() == 0) {
            std::cout << "There Are No Tasks\n";
            return;
        }

        for (int i = 0; i < tasks.size(); i++) {
            std::cout << "#" << i + 1 << '\n';
            tasks[i]->display_task();
        }
    }

    void sorted_display() {
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
        std::cout << "Select: \n";
        std::cout << "1 - High-Priority Task\n";
        std::cout << "2 - Middle-Priority Task\n";
        std::cout << "3 - Low-Priority Task\n\n";
    }

    void complete_info1() const {
        std::cout << "----------------------\n";
        std::cout << "    COMPLETING MENU   \n";
        std::cout << "----------------------\n";
        std::cout << "Select: \n";
        std::cout << "1 - Complete High-Priority Task\n";
        std::cout << "2 - Complete Middle-Priority Task\n";
        std::cout << "3 - Complete Low-Priority Task\n\n";
    }

    void complete_info2() const {
        std::cout << "Enter Tasks' Title: ";
    }

    void delete_info1() const {
        std::cout << "----------------------\n";
        std::cout << "     DELETING MENU    \n";
        std::cout << "----------------------\n";
        std::cout << "Select: \n";
        std::cout << "1 - Delete High-Priority Task\n";
        std::cout << "2 - Delete Middle-Priority Task\n";
        std::cout << "3 - Delete Low-Priority Task\n\n";
    }

    void delete_info2() const {
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

    void exit_case() {
        std::cout << "See you later!";
        exit(0);
    }

    void create_case() {
        create_info();

        std::string choice;
        std::cin >> choice;

        if (choice == "1") {
            create_task_high();
        }

        if (choice == "2") {
            create_task_middle();
        }

        if (choice == "3") {
            create_task_low();
        }
    }

    void complete_case() {
        complete_info1();

        std::string choice;
        std::cin >> choice;

        if (choice == "1") {
            complete_info2();

            std::string title;
            std::cin >> title;

            complete_task_high(title);
        }

        if (choice == "2") {
            complete_info2();

            std::string title;
            std::cin >> title;

            complete_task_middle(title);
        }

        if (choice == "3") {
            complete_info2();

            std::string title;
            std::cin >> title;

            complete_task_low(title);
        }
    }

    void delete_case() {
        delete_info1();

        std::string choice;
        std::cin >> choice;

        if (choice == "1") {
            delete_info2();

            std::string title;
            std::cin >> title;

            delete_task_high(title);
        }

        if (choice == "2") {
            delete_info2();

            std::string title;
            std::cin >> title;

            delete_task_middle(title);
        }

        if (choice == "3") {
            delete_info2();

            std::string title;
            std::cin >> title;

            delete_task_low(title);
        }
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

        if (choice == "0"){
            UI.exit_case();
        }
        
        if (choice == "1") {
            system("cls");
            UI.create_case();
            // system("cls");
            UI.general_info();
        }

        if (choice == "2") {
            system("cls");
            UI.complete_case();
            // system("cls");
            UI.general_info();
        }

        if (choice == "3") {
            system("cls");
            UI.delete_case();
            // system("cls");
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
