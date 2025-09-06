#include "dictionary_attack.h"
#include <openssl/md5.h>
#include <stdio.h>
#include <string.h>

void run_dictionary_attack(const char *hash, const char *wordlist_path) {
  printf("dictionary attack initiated!!!\n");

  FILE *wordlist_file = fopen(wordlist_path, "r");

  if (wordlist_file == NULL) {
    printf("ERROR:: could not open file at the path %s\n", wordlist_path);
    return;
  }

  printf("Successfully opened file at %s\n", wordlist_path);

  char line[256];
  unsigned char md5_result[MD5_DIGEST_LENGTH];
  char hex_hash[33];

  while (fgets(line, sizeof(line), wordlist_file)) {
    line[strcspn(line, "\n")] = '\0';
    MD5((const unsigned char *)line, strlen(line), md5_result);

    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
      sprintf(hex_hash + (i * 2), "%02x", md5_result[i]);
    }
    printf("%s\n", hex_hash);
  }

  printf("\n");

  fclose(wordlist_file);
}
