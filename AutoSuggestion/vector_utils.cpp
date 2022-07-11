/* ************************************************* */
/* This file is a part of AutoSuggestion. */
/* Created by santa on 2022-03-28. */
/* Everest Engineering College. */
/* Sanepa - 2, Lalitpur. */
/* https://www.eemc.com.np */
/* ************************************************* */
#include <cmath>
#include "vector_utils.h"

/**
 * Calculates the magnitude of a vector.
 */
double magnitude(Vector *vector) {
    double sum = 0.0;
    for (int index = 0; index < vector->entryCount; index++)
        sum += vector->coefficients[index] * vector->coefficients[index];
    return sqrt(sum);
}

/**
 * Calculates the dot product of two vectors.
 */
double dotProduct(Vector *uVector, Vector *wVector) {
    double sum = 0.0;
    for (int index = 0; index < uVector->entryCount || wVector->entryCount; index++) {
        sum += uVector->coefficients[index] * wVector->coefficients[index];
    }
    return sum;
}

/**
 * Calculate the cosine value between two vectors.
 */
double costTheta(Vector *uVector, Vector *wVector) {
    return dotProduct(uVector, wVector) / (magnitude(uVector) * magnitude(wVector));
}

