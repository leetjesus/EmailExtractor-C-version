#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *regex_extraction(const char *text, bool hash_type){
    regex_t regex_hash;
    
    regmatch_t match[1];  // To store match position
    
    char *pattern; 

    if (hash_type == 0){
        pattern = "\\b[a-f0-9]{32}\\b"; 
    } else if (hash_type == 1){
        pattern = "\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}\\b";
    }

    if (regcomp(&regex_hash, pattern, REG_EXTENDED) != 0) {
            printf("Regex compilation failed\n");
        }

    if (regexec(&regex_hash, text, 1, match, 0) == 0) {
        int start = match[0].rm_so;
        int end = match[0].rm_eo;
        int length = end - start;
        
        char *regex_result = malloc(length + 1);
        
        if (!regex_result) {
            printf("Memory allocation failed\n");
        }

        strncpy(regex_result, text + start, length);
        regex_result[length] = '\0';  // Null-terminate the string

        printf("%s\n", regex_result);
        return regex_result;
        
    } else {
        // If no email is found return NULL
        return NULL;
    }

    regfree(&regex_hash);
    return 0;
}

int main(int argc, char *argv[]) {
    char *token;
    char delimiters[] = ",";
    
    if (argc <= 0) {
        printf("Usage: %s <datadump_filename>\n", argv[0]);
        return 1;
    } else if (argc > 2){
        printf("To many command-line arguments specified\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");

    // char line_character;
    char line[256];
    
    // Error for not opening file 
    if (file == NULL) {
        perror("Error opening a file.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file) != NULL){
        char *value = regex_extraction(line, 1);
    
        if (value == NULL) {
            ;
        } else {
            // If email is found continue with token
            token = strtok(line, delimiters);
            while (token != NULL){
                regex_extraction(token, 0);
                token = strtok(NULL, delimiters);
            }
        }
    }

    fclose(file);
    return 0;

}
