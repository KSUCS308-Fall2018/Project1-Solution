//
//  core.h
//  Project 1 
//
//  Created by Ashley Coleman on 7/5/18.
//  Copyright © 2018 Ashley Coleman. All rights reserved.
//

#ifndef core_h
#define core_h

char encrypt_character(char source, int key);
void encrypt_string(char * message, int key, int step);
char decrypt_character(char source, int key);
void decrypt_string(char * message, int key, int step);
int core_main(int argc, const char * argv[]);

#endif /* core_h */
