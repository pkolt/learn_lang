#include <stdio.h>
#include <string.h>

const char DATA_FILENAME[] = "data.txt";
const int DATA_ROW_SIZE = 300;
const char DATA_CELL_SEPARATOR[] = ",";
const char DATA_ROW_SEPARATOR[] = "\n";

typedef struct AppData {
    char word[100];
    char translate[100];
    int learn_counter;
} AppData;

typedef enum MainAction {
    ADD_WORD_ACTION = 1,
    EXIT_ACTION = 2
} MainAction;

void save_data(AppData *data) {
    char line[DATA_ROW_SIZE];
    char str_counter[4];
    strcat(line, data->word);
    strcat(line, DATA_CELL_SEPARATOR);
    strcat(line, data->translate);
    strcat(line, DATA_CELL_SEPARATOR);
    sprintf(str_counter, "%d", data->learn_counter);
    strcat(line, str_counter);
    strcat(line, DATA_ROW_SEPARATOR);
    FILE *file = fopen(DATA_FILENAME, "a+");
    fputs(line, file);
    fclose(file);
}

void print_title(char *title) {
    printf("--- %s ---\n", title);
}

void input_data(AppData *data) {
    data->learn_counter = 0;
    print_title("Add word");
    printf("Input word: ");
    scanf("%s", data->word);
    printf("Input translate: ");
    scanf("%s", data->translate);
}

MainAction select_action() {
    MainAction action;
    print_title("Select action:");
    printf("[%i]: Add word\n", ADD_WORD_ACTION);
    printf("[%i]: Exit\n", EXIT_ACTION);
    printf("Enter value: ");
    while (scanf("%d", &action) != 1 || !(action == ADD_WORD_ACTION || action == EXIT_ACTION)) {
        printf("Invalid value, please try again: ");
    }
    return action;
}

int main() {
    AppData data = {};
    switch (select_action()) {
        case ADD_WORD_ACTION:
            input_data(&data);
            save_data(&data);
            break;
        case EXIT_ACTION:
            break;
    }
    return 0;
}
