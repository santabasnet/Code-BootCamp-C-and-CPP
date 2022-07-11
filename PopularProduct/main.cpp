/**
 * Popular Product Demo, i.e. most frequent items from the list.
 */
#include <malloc.h>
#include "arithmetic.h"
#include "console_utils.h"

/**
 * Program entry point.
 * @return 0 with successful execution.
 */
int main() {

    /**
     * Demo Data.
     */
    Product items[10] = {{1},
                         {6},
                         {1},
                         {2},
                         {1},
                         {6},
                         {9},
                         {9},
                         {2},
                         {1},
    };

    Sales *sales = (Sales *) malloc(sizeof(Product) * 10);
    sales->productItems = items;
    sales->count = 10;

    /**
     * Accumulate product statistics.
     */
    ProductStats *productStats = accumulateProductFrequency(sales);
    printf("\nTotal Stats: %ld", productStats->entryCount);

    /**
     * Highest frequent product.
     */
    ProductFrequency *product = maxOccurrence(productStats);

    /**
     * Display highest frequent product.
     */
    displayProduct(product);
    return 0;
}
