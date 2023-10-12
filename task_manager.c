#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getTasks();
int createTask();
int deleteTask(); 


int main() {
    int choice = 0;

    printf("\033[97;42m");
    printf("Choose action\033[0m\n"
    "1. See all tasks\n"
    "2. Create task\n"
    "3. Delete task\n"
    "4. Exit\n> "
    );  

    if(scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
        printf("\033[0;31mWrong input\n\033[0m");
        return 1;
    }  
    
    switch (choice)
    {
    case 1:
        printf("\033[97;42mSee all tasks\033[0m\n");
        getTasks();
        break;
    case 2:
        printf("\033[97;42mCreate a new task\033[0m\n");
        createTask();
        break;
    case 3:
        printf("\033[97;42mDelete task\033[0m\n");
        deleteTask();
        break;
    case 4:
        printf("\033[97;42mExit\033[0m\n");
        return 0;
    default:
        break;
    }

    return 0;
}

int getTasks() {
    FILE *fileRead;
    fileRead = fopen("data", "r");

    if (fileRead == NULL) {
        printf("Error opening file for reading.\n");
        main();
    }

    int id;
    char taskContent[256];
    
    while (fscanf(fileRead, "%d. %[^\n]", &id, taskContent) == 2) {
        printf("%d. %s\n", id, taskContent);
    }

    fclose(fileRead);
    main();
}

int createTask() {
    FILE *fileAppend;
    fileAppend = fopen("data", "a");

    int lastId = 0;
    char task[256];
    char content[4096];

    printf("> ");
    scanf(" %[^\n]s", &task);

    FILE *fileRead;
    fileRead = fopen("data", "r");

    while ((fgets(content, sizeof(content), fileRead) != NULL)) {
        char* token = strtok(content, ".");
        if (token != NULL) {
            int id = atoi(token);
            if (id > lastId) {
                lastId = id;
            }
        }
    }

    fclose(fileRead);
    fprintf(fileAppend, "%d. %s\n", lastId + 1, &task);
    fclose(fileAppend);
    printf("\033[97;44mTask was created\033[0m\n");
    main();
}

int deleteTask() {
    FILE *fileRead;
    fileRead = fopen("data", "r");
    
    FILE *tempFile;
    tempFile = fopen("temp", "w");

    char line[512]; 
    char taskIdstr[256];  
    int id = 0;
    char taskContent[256];

    printf("> ");
    if(scanf(" %[^\n]s", taskIdstr) != 1) {
        printf("\033[0;31mWrong input\n\033[0m");
        return 1;    
    }

    int taskId = atoi(taskIdstr);

    while (fgets(line, sizeof(line), fileRead) != NULL) {
        char *token = strtok(line, ".");

        if (token != NULL) {
            id = atoi(token);
            token = strtok(NULL, "\n");

            if (id != taskId) {
                fprintf(tempFile, "%d. %s\n", id, token);
            }
        }
    }

    fclose(fileRead);
    fclose(tempFile);

    if (remove("data") == 0 && rename("temp", "data") == 0) {
        printf("\033[97;44mTask with id %d has been deleted.\033[0m\n", taskId);
    } else {
        printf("\033[0;31mError deleting the file\n\033[0m");
    }

    main();
}
