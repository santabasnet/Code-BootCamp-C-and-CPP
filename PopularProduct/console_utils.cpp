/* ************************************************* */
/* This file is a part of popular. */
/* Created by santa on 2022-03-27. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */

#include <stdio.h>
#include "arithmetic.h"

/**
 * Displays product information to the console.
 */
void displayProduct(ProductFrequency *productFrequency) {
    fprintf(stdout, "\n********************************");
    fprintf(stdout, "\nProduct Information: ");
    fprintf(stdout, "\n\tID              : %ld", productFrequency->product.id);
    fprintf(stdout, "\n\tFrequency Count : %ld", productFrequency->frequency);
    fprintf(stdout, "\n********************************");
}

