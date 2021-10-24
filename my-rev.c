/** 
 * Copyright 2021 Isha Padmanaban
 * Name : Isha Padmanaban
 * Email : ipadmanaban@wisc.edu 
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * This function reverses the input string 
 */

char *reverse_string(char *str) {
    if (!str || !*str)
        return str;

    int index1 = strlen(str) - 1, index2 = 0;

    char ch;
    while (index1 > index2) {
        ch = str[index1];
        str[index1] = str[index2];
        str[index2] = ch;
        index1--;
        index2++;
    }
    return str;
}

/** 
 * This program simply reverse each line of
 * a file on a character-by-character basis
 */

int main(int argc, char ** argv) {
    int opt, file_found = 0, length;
    char buffer[128];
    FILE *fp;

    while ((opt  = getopt(argc, argv, "Vhf:")) != -1) {
        switch (opt) {
            case 'V':
                printf("my-rev from CS537 Spring 2021\n");
                exit(0);
            case 'h':
                printf("my-rev reverses each line of a file on a");
                printf(" character-by-character basis\n");
                exit(0);
            case 'f':
                fp = fopen(optarg, "r");
                if (fp == NULL) {
                    printf("my-rev: cannot open file\n");
                    exit(1);
                }
                file_found = 1;
                break;
            case '?':
                printf("my-rev: invalid command line\n");
                exit(1);
        }
    }

    if (file_found == 0) {
        fp = stdin;
    }

    for (; optind < argc; optind++) {
        printf("my-rev: invalid command line\n");
        exit(1);
    }

    /**
     * The below code eliminates new line character
     * calls string reverse function
     */

    while (fgets(buffer, 128, fp) != NULL) {
        length = strlen(buffer);
        if (buffer[length - 1] == '\n') {
            buffer[--length] = '\0';
            printf("%s\n", reverse_string(buffer));
        } else {
            printf("%s", reverse_string(buffer));
        }
    }

    fclose(fp);
    return 0;
}
