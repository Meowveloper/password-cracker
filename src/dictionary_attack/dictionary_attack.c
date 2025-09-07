#include "dictionary_attack.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

long long run_dictionary_attack(const char *hash, const char *wordlist_path) {
    printf("dictionary attack initiated!!!\n");

    FILE *wordlist_file = fopen(wordlist_path, "r");

    if (wordlist_file == NULL) {
        printf("ERROR:: could not open file at the path %s\n", wordlist_path);
        return 0;
    }

    printf("Successfully opened file at %s\n", wordlist_path);

    char line[256];
    int found = 0;
    long long attempts = 0;

    while (fgets(line, sizeof(line), wordlist_file)) {
        attempts++;
        line[strcspn(line, "\n")] = '\0';

        if (hash_and_compare(line, hash)) {
            printf("success!, password found\n");
            printf("hash: %s\n", hash);
            printf("password: %s\n", line);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("password not found in the word list\n");
    }

    fclose(wordlist_file);
    return attempts;
}
