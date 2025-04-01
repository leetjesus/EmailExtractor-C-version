#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

// Get the user input using argv 
// Auto-generate dataset file

int main(int argc, char *argv[]) {
    regex_t regex;
    regmatch_t match[1];
    // regmatch_t match;

    if (argc <= 0) {
        printf("Usage: %s <datadump_filename>\n", argv[0]);
        return 1;
    } else if (argc > 2){
        printf("To many command-line arguments specified\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");

    // char buffer_character;
    char *buffer_character = (char*)malloc(256 * sizeof(char)); 
    char buffer[256];

    // The pattern we're going to use
    const char *pattern = "\\b[a-f0-9]{32}\\b"; 

    // Compile the regex that we're going to use.
    if (regcomp(&regex, pattern, REG_EXTENDED) != 0) {
        printf("Regex compilation failed\n"); 
        return 1;
    }

    // Error for not opening file 
    if (file == NULL) {
        perror("Error opening a file.\n");
        exit(EXIT_FAILURE);
    }

    // This will not get the entire line
    while (fgets(buffer, sizeof(buffer), file) != NULL){
        if (regexec(&regex, buffer, 1, match, 0 ) == 0) {
            for (int i = match[0].rm_so; i < match[0].rm_eo; i++) {
                char final_hash = + buffer[i];
                printf("%c", final_hash);
            }
        } else {
            printf("\n");
            printf("Match not found!\n");
        }
    };

    fclose(file);
    return 0;

}
