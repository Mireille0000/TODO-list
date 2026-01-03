#ifndef STORAGE_H
#define STORAGE_H

#include "todo_types.h"

void save_todo_list(const TodoList *list, const char *file);
void load_todo_list(TodoList *list, const char *file);

#endif