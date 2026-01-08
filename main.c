#include <stdio.h>
#include "./headers/todo.h"
#include "./headers/storage.h"
#include "./headers/todo_types.h"

int main() {
    TodoList list = {0};
    add_task(&list, "Create add task function");
    add_task(&list, "Create list tasks function");
    add_task(&list, "Create delete task function");
    delete_task(&list, 1);
    mark_done(&list, 0);
    list_tasks(&list);
    return 0;
}