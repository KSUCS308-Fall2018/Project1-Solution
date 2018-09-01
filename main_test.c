//
//  main_test.c
//  Project 1 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#include "min_unit.h"
#include "core.h"

static char * test_encrypt_character() {
    mu_begin_case("encrypt_character");
    
    mu_assert_c("encrypt_character('A', 1) should return 'B'", 'B', encrypt_character('A', 1)); 
    mu_assert_c("encrypt_character('Z', 1) should return 'A'", 'A', encrypt_character('Z', 1)); 
    mu_assert_c("encrypt_character('G', 5) should return 'L'", 'L', encrypt_character('G', 5)); 
    mu_assert_c("encrypt_character('Y', 12) should return 'K'", 'K', encrypt_character('Y', 12)); 
    mu_assert_c("encrypt_character('A', 26) should return 'A'", 'A', encrypt_character('A', 26)); 
    mu_assert_c("encrypt_character('A', 52) should return 'A'", 'A', encrypt_character('A', 52)); 
    mu_assert_c("encrypt_character('Z', 52) should return 'Z'", 'Z', encrypt_character('Z', 52)); 
    mu_assert_c("encrypt_character('U', 79) should return 'V'", 'V', encrypt_character('U', 79)); 
    mu_assert_c("encrypt_character('M', 43) should return 'D'", 'D', encrypt_character('M', 43)); 
    mu_assert_c("encrypt_character('E', 0) should return 'E'", 'E', encrypt_character('E', 0)); 
    mu_assert_c("encrypt_character('Z', -5) should return 'Z'", 'Z', encrypt_character('Z', -5)); 

    mu_end_case("encrypt_character");
    return 0;
}

static char * test_encrypt_string() {
    mu_begin_case("encrypt_string");    

    char i1[] = "HELLO"; 
    encrypt_string(i1, 1, 1);
    mu_assert_s("encrypt_string(\"HELLO\", 1, 1) should return 'IGOPT'", "IGOPT", i1);


    char i2[] = "HELLO WORLD"; 
    encrypt_string(i2, 2, 5);
    mu_assert_s("encrypt_string(\"HELLO WORLD\", 2, 5) should return 'JLXCK CZHGD'", "JLXCK CZHGD", i2);

    char i3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    encrypt_string(i3, 1, 0);
    mu_assert_s("encrypt_string(\"ABCDEFGHIJKLMNOPQRSTUVWXYZ\", 1, 0) should return 'BCDEFGHIJKLMNOPQRSTUVWXYZA'", "BCDEFGHIJKLMNOPQRSTUVWXYZA", i3);

    char i4[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    encrypt_string(i4, 1, 1);
    mu_assert_s("encrypt_string(\"ABCDEFGHIJKLMNOPQRSTUVWXYZ\", 1, 1) should return 'BDFHJLNPRTVXZBDFHJLNPRTVXZ'", "BDFHJLNPRTVXZBDFHJLNPRTVXZ", i4);

    char i5[] = "A SERIES OF WORDS"; 
    encrypt_string(i5, 7, 31);
    mu_assert_s("encrypt_string(\"A SERIES OF WORDS\", 7, 31) should return 'H JASOPI OK LIQHB'", "H JASOPI OK LIQHB", i5);

    mu_end_case("encrypt_string");
    return 0;
}

static char * test_decrypt_character() {
    mu_begin_case("decrypt_character");
    
    mu_assert_c("decrypt_character('B', 1) should return 'A'", 'A', decrypt_character('B', 1)); 
    mu_assert_c("decrypt_character('A', 1) should return 'Z'", 'Z', decrypt_character('A', 1)); 
    mu_assert_c("decrypt_character('L', 5) should return 'G'", 'G', decrypt_character('L', 5)); 
    mu_assert_c("decrypt_character('K', 12) should return 'Y'", 'Y', decrypt_character('K', 12)); 
    mu_assert_c("decrypt_character('A', 26) should return 'A'", 'A', decrypt_character('A', 26)); 
    mu_assert_c("decrypt_character('A', 52) should return 'A'", 'A', decrypt_character('A', 52)); 
    mu_assert_c("decrypt_character('Z', 52) should return 'Z'", 'Z', decrypt_character('Z', 52)); 
    mu_assert_c("decrypt_character('V', 79) should return 'U'", 'U', decrypt_character('V', 79)); 
    mu_assert_c("decrypt_character('D', 43) should return 'M'", 'M', decrypt_character('D', 43)); 
    mu_assert_c("decrypt_character('E', 0) should return 'E'", 'E', decrypt_character('E', 0)); 
    mu_assert_c("decrypt_character('Z', -5) should return 'Z'", 'Z', decrypt_character('Z', -5)); 

    mu_end_case("decrypt_character");
    return 0;
}

static char * test_decrypt_string() {
    mu_begin_case("decrypt_string");    

    char i1[] = "IGOPT"; 
    decrypt_string(i1, 1, 1);
    mu_assert_s("decrypt_string(\"IGOPT\", 1, 1) should return 'HELLO'", "HELLO", i1);

    char i2[] = "JLXCK CZHGD"; 
    decrypt_string(i2, 2, 5);
    mu_assert_s("decrypt_string(\"JLXCK CZHGD\", 2, 5) should return 'HELLO WORLD'", "HELLO WORLD", i2);

    char i3[] = "BCDEFGHIJKLMNOPQRSTUVWXYZA"; 
    decrypt_string(i3, 1, 0);
    mu_assert_s("decrypt_string(\"BCDEFGHIJKLMNOPQRSTUVWXYZA\", 1, 0) should return 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", i3);

    char i4[] = "BDFHJLNPRTVXZBDFHJLNPRTVXZ"; 
    decrypt_string(i4, 1, 1);
    mu_assert_s("decrypt_string(\"BDFHJLNPRTVXZBDFHJLNPRTVXZ\", 1, 1) should return 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", i4);

    char i5[] = "H JASOPI OK LIQHB"; 
    decrypt_string(i5, 7, 31);
    mu_assert_s("decrypt_string(\"H JASOPI OK LIQHB\", 7, 31) should return 'A SERIES OF WORDS'", "A SERIES OF WORDS", i5);

    mu_end_case("decrypt_string");
    return 0;
}

static char * all_tests() {
    test_encrypt_character();
    test_encrypt_string();
    test_decrypt_character();
    test_decrypt_string();
    return 0;
}

#ifdef TEST
int main(int argc, char **argv) {
    mu_run(all_tests);
    
    return 0;
}
#endif

