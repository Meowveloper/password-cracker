#include "dictionary_attack.h"
#include "brute_force_attack.h"
#include "utils.h"
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("usage: %s <mode> [options]\n", argv[0]);
        printf("Modes: -d (dictionary), -b (brute-force)\n");
        return 1;
    }



    char *mode = argv[1];
    long long total_attempts = 0;

    clock_t start_time, end_time;
    double cpu_time_used;

    start_time = clock();

    if (is_string_equal(mode, "-d")) {

        if (argc != 4) {
            printf("Usage: %s -d <hash-file> <wordlist-file>\n", argv[0]);
            return 1;
        }
        total_attempts = run_dictionary_attack(argv[2], argv[3]);

    } else if (is_string_equal(mode, "-b")) {

        if(argc != 3) {
            printf("usage: %s -b <hash>", argv[0]);
            return 1;
        }
        
        total_attempts = run_brute_force_attack(argv[2]);
    } else {
        printf("ERROR!!!: unknown mode.\n");
        return 1;
    }

    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    double hashes_per_second = 0;

    if(cpu_time_used > 0) {
        hashes_per_second = total_attempts / cpu_time_used;
    }

    printf("\n----- attack summary -----\n");
    printf("total time: %.2f seconds\n", cpu_time_used);
    printf("total attempts attacks: %lld\n", total_attempts);
    printf("cracking speed: %.2f hashes/second\n", hashes_per_second);
    printf("--------------------------\n");


    return 0;
}
