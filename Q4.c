#include "ht48.c"
#include <time.h>

int main(void){
    printf("Response to Question 4:\n");
    clock_t start, end;
    double time_used;

    uint8_t message[6] = {9, 8, 7, 6, 5, 4};
    printf("message : %02X%02X%02X%02X%02X%02X\n", message[0], message[1], message[2], message[3], message[4], message[5]);
    uint8_t tag[6] = {0x7D, 0x1D, 0xEF, 0xA0, 0xB8, 0xAD};
    printf("tag : ");
    printhash(tag);
    uint64_t weight = 7;
    printf("Weight : %ld\n", weight);
    uint8_t *key = (uint8_t*)malloc(sizeof(uint8_t)*6);
    //initialisation à 0
    memset(key, 0, sizeof(uint8_t) * 6);
    verifiyInitialisation(key);

    start = clock();
    key_rec(sizeof(message), message, tag, weight, key);
    end = clock();
    time_used = ((double)(end - start))/ CLOCKS_PER_SEC;
    printf("Time used for searching all keys: %f s\n ", time_used);

    printf("result key (if it's a bunch of zeros, there is no key found): ");
    printhash(key);
    free(key);
    return 1;
}