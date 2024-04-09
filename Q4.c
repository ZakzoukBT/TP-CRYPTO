#include "ht48.c"

int main(void){
    printf("Response to Question 4:\n");

    uint8_t message[6] = {9, 8, 7, 6, 5, 4};
    printf("1\n");
    uint8_t tag[6] = {0x7D, 0x1D, 0xEF, 0xA0, 0xB8, 0xAD};
    printf("2\n");
    uint64_t nb_true_bits = 7;
    printf("3\n");
    uint8_t key[6] = {0};
    printf("4\n");

    key_rec(sizeof(message), message, tag, nb_true_bits, key);


}