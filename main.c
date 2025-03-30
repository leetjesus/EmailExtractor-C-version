#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
    if (argc <= 2) {
        printf("Usage: %s <datadump_filename>\n", argv[0]);
        return 1;
    } else if (argc > 3){
        printf("To many command-line arguments specified\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");

    char buffer_character;
    
    if (file == NULL) {
        perror("Error opening a file.\n");
        exit(EXIT_FAILURE);
    }

    // Reading the file
    while ((buffer_character = fgetc(file)) != EOF) {
        // so tech buffer_character represents a line 
        printf("%c", buffer_character);
    }

    fclose(file);
    return 0;
}
