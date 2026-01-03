#include <stdio.h>
#include "./headers/todo.h"
#include "./headers/storage.h"
#include "./headers/todo_types.h"

int main() {
    TodoList list = {};
    add_task(&list, "Create add task function");
    printf("TODO application \n");
    printf("%p \n", &list);
    printf("%s \nDone: %s \n", list.todos[0].task, list.todos[0].done ? "[x]" : "[ ]");
    return 0;
}