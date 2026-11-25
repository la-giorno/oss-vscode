#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char word[256];
    char filename[256];
    const char *path;

    if (argc > 2) {
        fprintf(stderr, "Usage: %s <filelist>\n", argv[0]);
        return 1;
    }

    if (argc == 2) {
        path = argv[1];
    } else {
        printf("Enter file name: ");
        // Read the file name from standard input
        if (fgets(filename, sizeof filename, stdin) == NULL) {
            fprintf(stderr, "Failed to read file name\n");
            return 1;
        }
        // Remove the newline character from the input
        filename[strcspn(filename, "\n")] = '\0';
        if (filename[0] == '\0') {
            fprintf(stderr, "File name cannot be empty\n");
            return 1;
        }
        path = filename;
    }

    FILE *filelist = fopen(path, "r");

    if (filelist == NULL) {
        perror(path);
        return 1;
    }
    // Read and print each word from the file
    while (fscanf(filelist, "%255s", word) == 1) {
        printf("%s\n", word);
    }

    fclose(filelist);
    return 0;
}