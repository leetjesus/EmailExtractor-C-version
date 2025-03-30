#include <stdio.h>
#include <stdlib.h>

// Get the user input using argv 
// Auto-generate dataset file

// Give the file name here
int main(int argc, char *argv[]) {

	// Datadump file
    FILE *file = fopen("intimshop.ru.sql", "r");

    char buffer_character;
    
    if (file == NULL) {
        perror("Error opening a file.");
        exit(EXIT_FAILURE);
    }

    while ((buffer_character = fgetc(file)) != EOF) {
        // so tech buffer_character represents a line 
        printf("%c\n", buffer_character);
    }

    fclose(file);
    return 0;



}
