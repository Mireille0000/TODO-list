#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "./headers/storage.h"
#include "./headers/todo_types.h"

void save_todo_list(const TodoList *list, const char *file){
    FILE *todo_list;
    todo_list = fopen(file, "w");
    if(!todo_list) {
        return;
    }
    int i = 0;
    for(i; i < list->count; i++) {
        fprintf(todo_list, "%s | %s\n", list->todos[i].task, list->todos[i].done ? "[x]" : "[ ]");
    }
    fclose(todo_list);
}

void load_todo_list(TodoList *list, const char *file) {
    FILE *todo_list;
    todo_list = fopen(file, "r");
    if(todo_list == NULL) {
        printf("File does not exist\n");
        return;
    }

    char todos_storage[MAX_TODOS_H];

    while(fgets(todos_storage, MAX_TODOS_H, todo_list)) {
        char *task = strchr(todos_storage, '|');
        if(list->count >= MAX_TODOS_H) {
            printf("You can add up to 100 todos");
            return;
        }
        if (task == 0) {
            continue;
        }
        int task_len = task - todos_storage;

        if(task_len > 0 && todos_storage[task_len - 1] == ' ') {
            task_len--;
        }

        if(task_len >= LEN_TASK) {
            task_len = LEN_TASK - 1;
        }

        char task_to_load[LEN_TASK];
        strncpy(task_to_load, todos_storage, task_len);
        task_to_load[task_len] = '\0';
        strncpy(list->todos[list->count].task, task_to_load, task_len);
        list->todos[list->count].task[task_len] = '\0';
        
        char *done = task + 1;
        while (*done == ' ') done++;
        if(done[1] == 'x') {
            list->todos[list->count].done = 1;
        } else {
            list->todos[list->count].done = 0;
        }
        
        list->todos[list->count].id = list->count;
        list->count++;
    };
  
    fclose(todo_list);
}