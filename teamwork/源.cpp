#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 50

struct File {
    char name[MAX_FILENAME_LENGTH];
};

struct File files[MAX_FILES];
int file_count = 0;

void add_file(char* name) {
    if (file_count < MAX_FILES) {
        strcpy_s(files[file_count].name, name);
        file_count++;
        printf("File '%s' added successfully.\n", name);
    }
    else {
        printf("Cannot add more files. Limit reached.\n");
    }
}

void delete_file(char* name) {
    int i, found = 0;
    for (i = 0; i < file_count; i++) {
        if (strcmp(files[i].name, name) == 0) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (int j = i; j < file_count - 1; j++) {
            strcpy_s(files[j].name, files[j + 1].name);
        }
        file_count--;
        printf("File '%s' deleted successfully.\n", name);
    }
    else {
        printf("File '%s' not found.\n", name);
    }
}

void list_files() {
    if (file_count > 0) {
        printf("List of files:\n");
        for (int i = 0; i < file_count; i++) {
            printf("%d. %s\n", i + 1, files[i].name);
        }
    }
    else {
        printf("No files found.\n");
    }
}

int main() {
    int choice;
    char filename[MAX_FILENAME_LENGTH];

    do {
        printf("\nFile Management System Menu:\n");
        printf("1. Add a file\n");
        printf("2. Delete a file\n");
        printf("3. List files\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter file name: ");
            scanf_s("%s", filename,sizeof(filename));
            add_file(filename);
            break;
        case 2:
            printf("Enter file name to delete: ");
            scanf_s("%s", filename,sizeof(filename));
            delete_file(filename);
            break;
        case 3:
            list_files();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}