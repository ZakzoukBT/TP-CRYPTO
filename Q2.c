#include "ht48.c"

int main(void){
    printf("Response to Question 2:\n");

    uint8_t keys[6] = {0, 1, 2, 3, 4, 5};
    uint8_t message[6] = {9, 8, 7, 6, 5, 4};
    uint8_t keys_two[6] = {0xE4, 0x16, 0x9F, 0x12, 0xD3, 0xBA};
    uint8_t h[6];

    printf("message : %d%d%d%d%d%d\n", message[0], message[1], message[2], message[3], message[4], message[5]);
    printf("key_one : %02X%02X%02X%02X%02X%02X\n", keys[0], keys[1], keys[2], keys[3], keys[4], keys[5]);
    printf("key_two : %02X%02X%02X%02X%02X%02X\n", keys_two[0], keys_two[1], keys_two[2], keys_two[3], keys_two[4], keys_two[5]);
    printf("Encryption of message with key_one : ");
    smht48(keys,sizeof(message), message,h);
    printhash(h);
    printf("Encryption of message with key_two : ");
    smht48(keys_two,sizeof(message),message,h);
    printhash(h);

    return 0;
}