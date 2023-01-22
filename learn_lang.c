#include <stdio.h>
#include <string.h>

const char DICTIONARY_FILENAME[] = "dictionary.txt";
const int DICTIONARY_ROW_SIZE = 300;
const char DICTIONARY_DATA_SEPARATOR[] = ",";
const char DICTIONARY_ROW_SEPARATOR[] = "\n";

struct DictionaryItem {
    char text[100];
    char text_translate[100];
    int learn_counter;
};

enum MAIN_MENU {
    MAIN_MENU_ADD_WORD = 1,
    MAIN_MENU_EXIT = 2
};

void add_word_to_dictionary(struct DictionaryItem item) {
    char line[DICTIONARY_ROW_SIZE];
    char str_counter[4];
    strcat(line, item.text);
    strcat(line, DICTIONARY_DATA_SEPARATOR);
    strcat(line, item.text_translate);
    strcat(line, DICTIONARY_DATA_SEPARATOR);
    sprintf(str_counter, "%d", item.learn_counter);
    strcat(line, str_counter);
    strcat(line, DICTIONARY_ROW_SEPARATOR);
    FILE *file = fopen(DICTIONARY_FILENAME, "a+");
    fputs(line, file);
    fclose(file);
}

int show_main_menu() {
    int choice;
    printf("Select action:\n");
    printf("[%i]: Add word\n", MAIN_MENU_ADD_WORD);
    printf("[%i]: Exit\n", MAIN_MENU_EXIT);
    printf("Enter value: ");
    while (scanf("%d", &choice) != 1 || !(choice == MAIN_MENU_ADD_WORD || choice == MAIN_MENU_EXIT)) {
        printf("Invalid value, please try again: ");
    }
    return choice;
}

void show_add_word() {
    struct DictionaryItem item;
    item.learn_counter = 0;
    printf("Input text: ");
    scanf("%s", item.text);
    printf("Input text translate: ");
    scanf("%s", item.text_translate);
    add_word_to_dictionary(item);
}

int main() {
    switch (show_main_menu()) {
        case MAIN_MENU_ADD_WORD:
            show_add_word();
            break;
    }
    return 0;
}
