/* ************************************************* */
/* This file is a part of AutoSuggestion. */
/* Created by santa on 2022-03-28. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */

#ifndef AUTOSUGGESTION_VECTOR_UTILS_H
#define AUTOSUGGESTION_VECTOR_UTILS_H

/**
 * Vector Definition.
 */
typedef struct {
    double *coefficients;
    long entryCount;
} Vector;

/**
 * Calculates the magnitude of a vector.
 */
double magnitude(Vector *);

/**
 * Calculates the dot product of two vectors.
 */
double dotProduct(Vector *, Vector *);


/**
 * Calculate the cosine value between two vectors.
 */
double costTheta(Vector *, Vector *);


#endif //AUTOSUGGESTION_VECTOR_UTILS_H
