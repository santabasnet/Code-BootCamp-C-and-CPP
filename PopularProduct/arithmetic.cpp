/* ************************************************* */
/* This file is a part of popular. */
/* Created by santa on 2022-03-27. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */

#include <malloc.h>
#include "arithmetic.h"

/**
 * Checks if the sales product is already present or not,
 * if so, it returns the positive index, otherwise it
 * returns -1.
 */
int isAlreadyCounted(ProductStats *productStats, Product product) {
    int found = -1;
    for (int index = 0; index < productStats->entryCount; index++) {
        if (productStats->productFrequency->product.id == product.id) {
            found = index;
            break;
        }
    }
    return found;
}

/**
 * Calculates the product frequency table.
 */
ProductStats *accumulateProductFrequency(Sales *sales) {
    ProductStats *productStats = (ProductStats *) malloc(sizeof(ProductStats));
    productStats->productFrequency = (ProductFrequency *) malloc(sizeof(ProductFrequency) * MAX_SIZE);
    productStats->entryCount = 0;
    for (int index = 0; index < sales->count; index++) {
        int isFound = isAlreadyCounted(productStats, sales->productItems[index]);
        if (isFound >= 0) {
            productStats->productFrequency[isFound].frequency++;
        } else {
            (productStats->productFrequency + productStats->entryCount)->product = sales->productItems[index];
            (productStats->productFrequency + productStats->entryCount++)->frequency = 1L;
        }
    }
    return productStats;
}

/**
 * Calculates the most frequent item from the sales data.
 * @param sales
 * @return productItem
 */
ProductFrequency *maxOccurrence(ProductStats *productStats) {
    int max = 0;
    ProductFrequency *productFrequency = NULL;
    for (int index = 0; index < productStats->entryCount; index++) {
        if (productStats->productFrequency[index].frequency > max) {
            productFrequency = productStats->productFrequency;
        }
    }
    return productFrequency;
}

