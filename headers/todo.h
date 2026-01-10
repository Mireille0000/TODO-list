#ifndef TODO_H
#define TODO_H

#include "todo_types.h"

void add_task(TodoList *list, const char *task);
void list_tasks(TodoList *list);
void update_task(TodoList *list, int id, const char *updated_text);
void delete_task(TodoList *list, int id);
void mark_done(TodoList *list, int id);

#endif