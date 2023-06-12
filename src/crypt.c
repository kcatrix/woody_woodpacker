#include "woody.h"

char * generateKey(char *key) {
    size_t i;
    for (i = 0; i < KEY_SIZE; i++) {
        int randomType = rand() % 2;
        if (randomType == 0) {
            key[i] = '0' + rand() % 10;
        } else {
            key[i] = 'A' + rand() % 26; 
        }
    }
    key[KEY_SIZE] = '\0';
	return key;
}