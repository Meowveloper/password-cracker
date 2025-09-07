#include <stdio.h>
#include <string.h>
#include "brute_force_attack.h"
#include "utils.h"


static int brute_force_attack_recursive(const char *target_hash, const char *char_set, char *prefix, int current_length, int max_length, long long *attempts) {
	const int PROGRESS_INTERVAL = 1000;

	// base case: if have a complete password candidate;
	if(current_length == max_length) {
		// hanh and compare it to the target hash;
		prefix[current_length] = '\0';
		(*attempts)++;

		if(*attempts % PROGRESS_INTERVAL == 0) {
			printf("\rcurrent attempt: [%s]", prefix);
			fflush(stdout);
		}

		return hash_and_compare(prefix, target_hash);
	}

	// recursive step:
	// loop through each character in the character set;
	for(int i = 0; i < strlen(char_set); i ++) {

		// append the next character to the prefix;
		prefix[current_length] = char_set[i];

		// make the recursive call for the next level;
		if(brute_force_attack_recursive(target_hash, char_set, prefix, current_length + 1, max_length, attempts)) {

		// if the recursive call found the password, stop and return 1;
		return 1;
		}
	}

	return 0;
}

long long run_brute_force_attack(const char *target_hash) {
    printf("starting brute_force_attack....\n");

    const char *char_set = "abcdefghijklmnopqrstuvwxyz";
    const int max_length = 8;

    char candidate[max_length + 1];

    int found = 0;
    
    long long attempts = 0;

    for (int len = 1; len <= max_length; len++) {
        printf("\nchecking passwords of length %d...\n", len);


        if(brute_force_attack_recursive(target_hash, char_set, candidate, 0, len, &attempts)) {
            found = 1;
            break;
        }
    }


    if(!found) {
        printf("\npassword not found within the speific constraints...\n");
    } else {
        printf("\npassword found\n");
        printf("password: %s\n", candidate);
        printf("hash: %s\n", target_hash);
    }

    return attempts;
}
