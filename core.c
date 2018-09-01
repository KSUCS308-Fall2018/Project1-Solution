//
//  core.c
//  Project 1 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "core.h"

#define CHARACTER_COUNT (LAST_CHARACTER - FIRST_CHARACTER + 1) 
#define FIRST_CHARACTER 'A'
#define LAST_CHARACTER 'Z'

#define TRUE 1;
#define FALSE 0;

int is_number_convertable(const char * string) {
    int len = strlen(string);
    const char * s = string;
    
    for (int i = 0; i < len; i++) {
        if (!isdigit(*s)) {
            return FALSE;
        }
        s++;
    }
    
    return TRUE;
}

char encrypt_character(char source, int key) {
    if (source == ' ') {
        return ' ';
    }

    if (key < 0) { // Negative keys not supported
        return source;
    }

    int real_key = key % CHARACTER_COUNT;

    char result = source + real_key;

    if (result > LAST_CHARACTER) {
        result = FIRST_CHARACTER + (result - LAST_CHARACTER) - 1;
    }

    return result;
}

void encrypt_string(char * message, int key, int step) {
    int char_count = strlen(message); 
    int current_key = key;
    
    for (int i = 0; i < char_count; i++) {
        message[i] = encrypt_character(message[i], current_key); 
        current_key += step;
    }
}

char decrypt_character(char source, int key) {
    if (source == ' ') {
        return ' ';
    }

    if (key < 0) { // Negative keys not supported
        return source;
    }

    int real_key = key % CHARACTER_COUNT;

    char result = source - real_key;

    if (result < FIRST_CHARACTER) {
        result = LAST_CHARACTER - (FIRST_CHARACTER - result) + 1;
    }

    return result;
}

void decrypt_string(char * message, int key, int step) {
    int char_count = strlen(message); 
    int current_key = key;
    
    for (int i = 0; i < char_count; i++) {
        message[i] = decrypt_character(message[i], current_key); 
        current_key += step;
    }
}

void print_usage() {
    printf("Usage:\n");
    printf("\t./main encrypt message key key_offset\n");
    printf("\t./main decrypt message key key_offset\n");
}

int core_main(int argc, const char * argv[]) {
    if (argc < 5) {
        printf("Missing arguements\n");
        print_usage();
        return 1;
    }

    int should_encrypt = FALSE;

    if (strcmp(argv[1], "encrypt") == 0) {
        should_encrypt = TRUE;
    } else if (strcmp(argv[1], "decrypt") == 0) {
        should_encrypt = FALSE;
    } else {
        printf("Unknown command: %s\n", argv[1]);
        print_usage();
        return 2;
    }

    if (strlen(argv[2]) > 100) {
        printf("Max message length is 100 characters\n");
        print_usage();
        return 3;
    }
    
    if (!is_number_convertable(argv[3])) {
        printf("Key must be an integer\n");
        print_usage();
        return 4;
    }
    
    if (!is_number_convertable(argv[4])) {
        printf("Key offset must be an integer\n");
        print_usage();
        return 5;
    }

    int key = atoi(argv[3]);
    int key_offset = atoi(argv[4]);

    char input[101];
    strncpy(input, argv[2], 100);
    input[100] = '\0';

    if (should_encrypt) {
        encrypt_string(input, key, key_offset);
        printf("%s\n", input);
    } else {
        decrypt_string(input, key, key_offset);
        printf("%s\n", input);
    }

    return 0;
}
