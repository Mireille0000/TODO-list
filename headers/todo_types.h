#ifndef TODO_TYPES_H
#define TODO_TYPES_H

#define MAX_TODOS_H 100
#define LEN_TASK 150

typedef struct {
    int id;
    char task[LEN_TASK];
    int done;
} Todo;

typedef struct {
    Todo todos[MAX_TODOS_H];
    int count;
} TodoList;


#endif