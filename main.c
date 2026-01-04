#include <stdio.h>
#include "./headers/todo.h"
#include "./headers/storage.h"
#include "./headers/todo_types.h"

int main() {
    TodoList list = {0};
    add_task(&list, "Create add task function");
    add_task(&list, "Create list tasks function");
    update_task(&list, 1, "Create update_task fn");
    printf("TODO application \n");
    list_tasks(&list);
    return 0;
}