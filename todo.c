#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "./headers/todo_types.h"
#include "./headers/todo.h"

void add_task(TodoList *list, const char *task) {
    if (list->count >= MAX_TODOS_H) {
        printf("Cannot add more tasks: \n you can add up to 100 tasks :)");
    }
    
    Todo *t = &list->todos[list->count]; // get memory slot
    t->id = list->count; // add id
    strncpy(t->task, task, LEN_TASK-1); // copy the new todo
    t->task[LEN_TASK-1] = '\0'; // to avoid null-terminated string
    t->done = false; // is the todo done

    list->count++;
}

void list_tasks(TodoList *list) {
    int i = 0;
    for(i; i < list->count; i++) {
        printf("Id: %d\nTask: %s\nDone: %s\n\n",list->todos[i].id, list->todos[i].task, list->todos[i].done ? "[x]" : "[ ]");
    }
}

void update_task(TodoList *list, int id, const char *updated_text) {
    if (id < 0 || id >= list->count) {
        return;
    } //

    Todo *t = &list->todos[id];
    int len_new_text = strlen(updated_text);
    char new_text[LEN_TASK] = {};

    if (len_new_text >= LEN_TASK) {
        len_new_text = LEN_TASK - 1;
    }

    strcpy(new_text, updated_text);

    for (int i = 0; i < len_new_text; i++) {
        t->task[i] = new_text[i];
    }
    t->task[len_new_text] = '\0';
}

void delete_task(TodoList *list, int id){
    if (list->count == 0) {
        return;
    }

    if (id > list->count-1) {
        return;
    }

    int i = 0;
    for (i; i < list->count - 1; i++) {
       if(i >= id) {
            list->todos[i] = list->todos[i + 1];
        } 
        list->todos[i].id = i;
    }

    list->count--;
}

void mark_done(TodoList *list, int id) {
    if (list->count == 0) {
        return;
    }

    if (id > list->count-1) {
        return;
    }

    Todo *t = &list->todos[id];
    t->done = true;
}