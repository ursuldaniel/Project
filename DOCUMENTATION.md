# Класс Task

Приватные поля:
- `std::string task_title` — поле для хранения названия задачи.

- `std::string task_description` — поле для хранения описания задачи.

- `std::string task_priority` — поле для хранения приоритета задачи.

- `bool task_status` — поле для хранения статуса задачи.

Публичные методы:
- `Task()` — дефолтный конструктор.

- `Task(const std::string& t, const std::string d, const std::string& p)` — конструктор с двумя параметрами.

- `std::string get_task_title() const` — метод, возвращающий название задачи.

- `std::string get_task_description() const` — метод, возвращающий описание задачи.

- `std::string get_task_priority() const` — метод, возвращающий приоритет задачи.

- `std::string get_task_status() const` — метод, возвращающий статус задачи. 

- `void get_task_completed()` — метод, меняющий статус задачи на "Completed".

- `void display_task() const` — метод, отображающий информацию о задаче.

# Класс TaskManager

Приватные методы и поля:
- `std::vector<Task> tasks` — контейнер для хранения задач.

- `bool task_exists(const std::string& title) const` —

- `bool task_high_exists() const` — метод, проверяющий существование хотя бы одной задачи установленного приоритета.

- `bool task_middle_exists() const` — метод, проверяющий существование хотя бы одной задачи установленного приоритета.

- `bool task_low_exists() const` — метод, проверяющий существование хотя бы одной задачи установленного приоритета.

Публичные методы:
- `TaskManager()` — дефолтный конструктор.

- `void add_task(const Task& task)` — метод, добавляющий задачу.

- `void complete_task(const std::string& title)` — метод, выполняющий задачу.

- `void delete_task(const std::string& title)` — метод, удаляющий задачу.

- `void display_tasks_high() const` — метод, отображающий задачи высокого приоритета.

- `void display_tasks_middle() const` — метод, отображающий задачи среднего приоритета.

- `void display_tasks_low() const` — метод, отображающий задачим низкого приоритета.

- `void unsorted_display() const` — метод, отображающий неотсортированные задачи.

- `void sorted_display() const` — метод, отображающий задачи в отсортированном порядке.

# Класс UserInterface (наследний класса TaskManager)

Приватные методы:
- `void create_info() const` — метод, представляющий информацию о создании задачи. 

- `void complete_info() const` — метод, предоставляющий информацию о выполнении задачи.

- `void delete_info() const` — метод, предоставляющий информацию о выполнении задачи.

- `void view_info() const` — метод, предоставляющий информацию о просмотре задач.

- `void create_task()` — метод, создающий новый объект класса Task.

Публичные методы:
- `UserInterface()` — дефолтный конструктор.

- `void greeting() const` — метод, приветствующий пользователя.

- `void general_info() const` — метод, отображающий основную информацию.

- `void exit_case() const` — метод, прерывающий работу программу.

- `void create_case()` — метод, создающий задачу.

- `void complete_case()` — метод, выполняющий задачу.

- `void delete_case()` — метод, удаляющий задачу.

- `void view_case()` — метод, отображающий задачи.`
