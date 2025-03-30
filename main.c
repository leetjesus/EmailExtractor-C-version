#include <stdio.h>
#include <stdlib.h>

// Get the user input using argv 
// Auto-generate dataset file

// Give the file name here
int main(int argc, char *argv[]) {

    FILE *file = fopen("intimshop.ru.sql", "r");

    int file_count = NULL;


    if (file == NULL) {
        perror("Error opening a file.");
        exit(EXIT_FAILURE);
    }

    printf("File is now opened..\n");
    

    // Only get a section of the file
    char buffer[100];

    while(fgets(buffer, sizeof(buffer), file) != NULL){
        printf("Read: %s", buffer); // Print each line
    }

    fclose(file);
    return 0;



}
