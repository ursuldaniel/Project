# Абстрактный класс Task
Публичные методы:
- `virtual std::string get_task_title() const` — метод, возвращающий название задачи.

- `virtual std::string get_task_description() const` — метод, возвращающий описание задачи.

- `virtual std::string get_task_priority() const` — метод, возвращающий приоритет задачи.

- `virtual std::string get_task_status() const` — метод, возвращающий статус задачи.

- `virtual void display_task() const` — метод, отображающий информацию о задаче.

- `virtual void complete_task()` — метод, отмечающий задачу выполненной.

# Класс TaskHigh (наследник абстрактного класса Task)
Приватные поля:
- `std::string task_title` — поле для хранения названия задачи.

- `std::string task_description` — поле для хранения описания задачи.

- `std::string task_priority` — поле для хранения приоритета задачи.

- `std::string task_status` — поле для хранения статуса задачи.

Публичные методы:
- `TaskHigh() {}` — дефолтный конструктор.

- `TaskHigh(const std::string& t, const std::string& d)` — конструктор с двумя параметрами.

- `std::string get_task_title() const override`.

- `std::string get_task_description() const override`.

- `std::string get_task_priority() const override`.

- `std::string get_task_status() const override`.

- `void display_task() const override`.

- `void complete_task() override`.

Характеристики методов описаны в абстрактном классе Task.

# Класс TaskMid (наследник абстрактного класса Task)
Приватные поля:
- `std::string task_title` — поле для хранения названия задачи.

- `std::string task_description` — поле для хранения описания задачи.

- `std::string task_priority` — поле для хранения приоритета задачи.

- `std::string task_status` — поле для хранения статуса задачи.

Публичные методы:
- `TaskMid() {}` — дефолтный конструктор.

- `TaskMid(const std::string& t, const std::string& d) ` — конструктор с двумя параметрами.

- `std::string get_task_title() const override`.

- `std::string get_task_description() const override`.

- `std::string get_task_priority() const override`.

- `std::string get_task_status() const override`.

- `void display_task() const override`.

- `void complete_task() override`.

Характеристики методов описаны в абстрактном классе Task.

# Класс TaskLow (наследник абстрактного класса Task)
Приватные поля:
- `std::string task_title` — поле для хранения названия задачи.

- `std::string task_description` — поле для хранения описания задачи.

- `std::string task_priority` — поле для хранения приоритета задачи.

- `std::string task_status` — поле для хранения статуса задачи.

Публичные методы:
- `TaskLow() {}` — дефолтный конструктор.

- `TaskLow(const std::string& t, const std::string& d)` — конструктор с двумя параметрами.

- `std::string get_task_title() const override`.

- `std::string get_task_description() const override`.

- `std::string get_task_priority() const override`.

- `std::string get_task_status() const override`.

- `void display_task() const override`.

- `void complete_task() override`.

Характеристики методов описаны в абстрактном классе Task. 

# Класс TaskManager
Приватные поля и методы:
- `std::vector<TaskHigh*> tasks_high` — контейнер для хранения задач высокого приоритета.

- `std::vector<TaskMiddle*> tasks_middle` — контейнер для хранения задач среднего приоритета.

- `std::vector<TaskLow*> tasks_low` — контейнер для хранения задач низкого приоритета.

- `std::vector<Task*> tasks` — контейнер для хранения задач.

- `bool task_high_exists(const std::string& title) const` — метод, для проверки наличия задачи в контейнере задач высокого приоритета. 

- `bool task_middle_exists(const std::string& title) const` — метод, для проверки наличия задачи в контейнере задач среднего приоритета.

- `bool task_low_exists(const std::string& title) const` — метод, для проверки наличия задачи в контейнере задач низкого приоритета.

Публичные методы:

- `void add_task_high(TaskHigh* task)` — метод, осуществляющий добавление задачи высокого приоритета.

- `void add_task_middle(TaskMiddle* task)` — метод, осуществляющий добавление задачи среднего приоритета.

- `void add_task_low(TaskLow* task)` — метод, осуществляющий добавление задачи низкого приоритета.

- `void complete_task_high(const std::string& title)` — метод, выполняющий задачу высокого приоритета.

- `void complete_task_middle(const std::string& title)` — метод, выполняющий задачу среднего приоритета.

- `void complete_task_low(const std::string& title)` — метод, выполняющий задачу низкого приоритета.

- `void delete_task_high(const std::string& title)` — метод, удаляющий задачу высокого приоритета.

- `void delete_task_middle(const std::string& title)` — метод, удаляющий задачу среднего приоритета.

- `void delete_task_low(const std::string& title)` — метод, удаляющий задачу низкого приоритета.

- `void display_tasks_high()` — метод, отображающий задачи высокого приоритета.

- `void display_tasks_middle()` —   метод, отображающий задачи среднего приоритета.

- `void display_tasks_low()` —  метод, отображающий задачи низкого приоритета.

- `void unsorted_display()` — метод, отображающий неотсортированные задачи.

- `void sorted_display()` — метод, отображающий задачи в отсортированном порядке.

# Класс UserInterface (наследник класса TaskManager)
Приватные методы:
- `void create_info() const` — метод, представляющий информацию о создании задачи

- `void complete_info1() const` — метод, предоставляющий информацию о выполнении задачи.

- `void complete_info2() const` — метод, предоставляющий информацию о выполнении задачи.

- `void delete_info1() const` — метод, предоставляющий информацию об удалении задачи.

- `void delete_info2() const` — метод, предоставляющий информацию об удалении задачи.

- `void view_info() const` — метод, предоставляющий информацию о просмотре задач.

- `void create_task_high()` — метод, создающий новый объект класса TaskHigh*.

- `void create_task_middle()` — метод, создающий новый объект класса TaskMid*.

- `void create_task_low()` — метод, создающий новый объект класса TaskLow*.

Публичные методы:

- `UserInterface() {}` — дефолтный конструктор.

- `void greeting() const` — метод, приветствующий пользователя.

- `void general_info()` const — метод, отображающий основную информацию.

- `void exit_case()` — метод, прерывающий работу программу.

- `void create_case()` — метод, создающий задачу.

- `void complete_case()` — метод, выполняющий задачу.

- `void delete_case()` — метод, удаляющий задачу.

- `void view_case()` — метод, отображающий задачи.
