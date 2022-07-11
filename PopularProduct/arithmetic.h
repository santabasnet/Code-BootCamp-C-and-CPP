/* ************************************************* */
/* This file is a part of popular. */
/* Created by santa on 2022-03-27. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */

#ifndef POPULAR_ARITHMETIC_H
#define POPULAR_ARITHMETIC_H

/**
 * Define max items.
 */
const int MAX_SIZE = 100;

/**
 * Boolean Literals.
 */
const int TRUE = 1;
const int FALSE = 0;

/**
 * Definition of Product Data.
 */
typedef struct {
    long id;
} Product;

/**
 * Definition of sales data.
 */
typedef struct {
    Product *productItems;
    long count;
} Sales;

/**
 * Define the product frequencies.
 */
typedef struct {
    Product product;
    long frequency;
} ProductFrequency;

/**
 * Product Statistics.
 */
struct ProductStats {
    ProductFrequency *productFrequency;
    long entryCount;
};

/**
 * Finds the max occurrence of the product.
 */
ProductFrequency *maxOccurrence(ProductStats *);

ProductStats *accumulateProductFrequency(Sales *);

int isAlreadyCounted(ProductStats *, Product);

#endif //POPULAR_ARITHMETIC_H
