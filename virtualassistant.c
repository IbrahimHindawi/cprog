#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define get_array_length(array) sizeof(array)/sizeof((array)[0])
typedef struct{
    const char **root;
    const char **children[32];
}string_node;
const char *main_menu_phrases[] = {
    "Daily Routine.",
    "Knowledge Library.",
    "Quit.",
};
const char *daily_routine[] = {
    "Fajr",
    "Stretch",
    "Workout",
    "Tajweed",
    "Breakfast",
    "Work",
    "Return",
    "Study",
};
const char *knowledge_library[] = {
    "Quraan",
    "Arabic",
    "Computer Science",
    "Graphics Programming",
};
void print_intro() {
    printf("\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Virtual Assistant-v0.1\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n");
}
int main (int argc, char *argv[]) {
    string_node node = {0};
    node.root = main_menu_phrases;
    node.children[0] = daily_routine;
    //node.children[1] = knowledge_library;
    printf("root: %s\n", node.root[0]);
    for (int i = 0; i < 8; ++i) { printf("children: %s\n", node.children[0][i]); }
    //printf("children: %s\n", node.children[1]);
    //printf("%s\n", knowledge_library[0]);
    print_intro();
    printf("Options: \n");
    for (int i = 0; i < get_array_length(main_menu_phrases); ++i){
        printf("\t[%d]-%s\n", i, main_menu_phrases[i]);
    }
    int option = 0;
    scanf_s("%d", &option);
    printf("Selection: \n");
    for (int i = 0; i < get_array_length(main_menu_phrases); ++i){
        if (option > get_array_length(main_menu_phrases) || option < 0) {
            printf("\tInvalid Option! Shut down!\n");
            exit(1);
        }
        if (option == i) {
            printf("\t[%d]-%s\n", i, main_menu_phrases[i]);
        }
    }
    uint64_t *n = malloc(128);
    n = malloc(128);
    free(n);
    return 0;
}
