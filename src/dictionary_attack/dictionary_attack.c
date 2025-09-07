#include "dictionary_attack.h"
#include "utils.h"
#include <stdio.h>
#include <string.h>

long long run_dictionary_attack(const char *hash, const char *wordlist_path) {
    const int PROGRESS_INTERVAL = 10;
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

        if(attempts % PROGRESS_INTERVAL == 0) {
            printf("\rtrying word: [%s]", line);
            fflush(stdout);
        }

        if (hash_and_compare(line, hash)) {
            found = 1;
            break;
        }
    }

    fclose(wordlist_file);

    if (!found) {
        printf("\npassword not found in the word list\n");
    } else {
        printf("\nsuccess!, password found\n");
        printf("hash: %s\n", hash);
        printf("password: %s\n", line);
    }

    return attempts;
}
