#include <stdio.h>
#include <string.h>
#include "dictionary_attack.h"

void run_dictionary_attack(const char *hash, const char *wordlist_path) {
    printf("dictionary attack initiated!!!\n");

    FILE *wordlist_file = fopen(wordlist_path, "r");

    if(wordlist_file == NULL) {
        printf("ERROR:: could not open file at the path %s\n", wordlist_path);
        return;
    }
    printf("Successfully opened file at %s\n", wordlist_path);


    char line[256];

    while (fgets(line, sizeof(line), wordlist_file))
    {
        line[strcspn(line, "\n")] = '\0';
        printf("%s\n", line);
    }
    printf("\n"); 

    fclose(wordlist_file);
}