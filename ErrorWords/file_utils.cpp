/* ************************************************* */
/* This file is a part of ErrorWords. */
/* Created by santa on 2022-03-27. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */

#include <stdio.h>
#include <malloc.h>
#include "file_utils.h"

/**
 * Perform the read operation of the text content.
 * @param fileName
 * @return textContent
 */
char *readFromFile(char *fileName) {
    FILE *file = fopen(fileName, "r");
    char *textContent = (char *) malloc(sizeof (char) * MAX_SIZE);
    int ch = fgetc(file);
    int count = 0;
    while(ch != EOF){
        textContent[count++] = (char)ch;
        ch = fgetc(file);
    }
    textContent[count] = '\0';
    fclose(file);
    return textContent;
}
