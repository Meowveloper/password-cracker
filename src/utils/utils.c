#include "utils.h"
#include <openssl/md5.h>
#include <string.h>
#include <stdio.h>

int is_string_equal(const char *str1, const char *str2) {
    return strcmp(str1, str2) == 0;
}

int hash_and_compare(const char *candidate_password, const char *target_hash) {
    unsigned char md5_result[MD5_DIGEST_LENGTH];
    char hex_hash[(MD5_DIGEST_LENGTH * 2) + 1];

    MD5((const unsigned char *)candidate_password, strlen(candidate_password), md5_result);

    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        sprintf(hex_hash + (i * 2), "%02x", md5_result[i]);
    }

    hex_hash[MD5_DIGEST_LENGTH * 2] = '\0';

    if(is_string_equal(hex_hash, target_hash)) return 1; 
    else return 0;
}
