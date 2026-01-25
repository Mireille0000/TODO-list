#include <stdio.h>
#include <string.h>
#include "./headers/todo.h"
#include "./headers/storage.h"
#include "./headers/todo_types.h"

int main() {
    TodoList list = {0};
    int selected_option;
    int id;
    char todo[LEN_TASK];
    char updated_text[LEN_TASK];
    load_todo_list(&list, "todo.txt");

    while(1) {
        printf("Menu:\n");
        printf("List tods: 1\n");
        printf("Add task: 2\n");
        printf("Update task: 3\n");
        printf("Mark as done: 4\n");
        printf("Delete: 5\n");
        printf("Save todos: 0\n");
        printf("Enter your option: ");
        scanf("%d", &selected_option);
        getchar();

        switch (selected_option) {
        case 1:
            printf("List\n");
            list_tasks(&list);
            break;
        case 2:
            printf("Add\n");
            fgets(todo, LEN_TASK, stdin);
            todo[strcspn(todo, "\n")] = '\0';
            add_task(&list, todo);
            break;
        case 3:
            printf("Update\n");
            printf("Enter task ID to update: \n");
            scanf("%d", &id);
            getchar();

            printf("Enter new text: \n");
            fgets(updated_text, LEN_TASK, stdin);
            updated_text[strcspn(updated_text, "\n")] = '\0';
            update_task(&list, id, updated_text);
            break;
        case 4:
            printf("Done\n");
            printf("Enter task ID to mark as done: \n");
            scanf("%d", &id);
            getchar();

            mark_done(&list, id);
            break;
        case 5:
            printf("Delete\n");
            printf("Enter task ID to delete: \n");
            scanf("%d", &id);
            getchar();

            delete_task(&list, id);
            break;
        case 0:
            printf("Save and close\n");
            save_todo_list(&list, "todo.txt");
            return 0;
        default:
            printf("There is no such an option\n");
            break;
        }
    }
    return 0;
}