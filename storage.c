#include <stdio.h>
#include "./headers/storage.h"
#include "./headers/todo_types.h"

void save_todo_list(const TodoList *list, const char *file){
    FILE *todo_list;
    todo_list = fopen(file, "w");
    printf("HEY");
    if(!todo_list) {
        return;
    }
    int i = 0;
    printf("%d\n", list->count);
    for(i; i < list->count; i++) {
        printf("%d\n", list->todos[i].done);
        fprintf(todo_list, "%s | %s\n", list->todos[i].task, list->todos[i].done ? "[x]" : "[ ]");
    }
    fclose(todo_list);
}

void load_todo_list(TodoList *list, const char *file) {
    // To implement
}