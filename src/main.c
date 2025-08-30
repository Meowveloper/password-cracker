#include <stdio.h>
#include <string.h>
#include "dictionary_attack.h"

int is_string_equal(char *str1, char *str2);

int main (int argc, char *argv[]) {

    if(argc < 2) {

        printf("Usage: %s <mode> [options]\n", argv[0]);
        printf("Modes: -d (dictionary), -b (brute-force)\n");
        return 1;

    }

    char *mode = argv[1];

    if(is_string_equal(mode, "-d")) {
        if(argc !=4) {
            printf("Usage: %s -d <hash-file> <wordlist-file>\n", argv[0]);
            return 1;
        }
        run_dictionary_attack(argv[2], argv[3]);

    } else if(is_string_equal(mode, "-b")) {
        printf("selected mode: BRUTE-FORCE ATTACK\n");
    } else {
        printf("ERROR!!!: unknown mode.\n");
        return 1;
    }

    return 0;
}

int is_string_equal(char *str1, char *str2) {
    return strcmp(str1, str2) == 0;
}

