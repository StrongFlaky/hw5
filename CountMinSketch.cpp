#include <limits>
#include "CountMinSketch.h"
#include "HashFunctions.h"

/**
 * Implement increment() correctly
 */
void CountMinSketch::increment(const string & s) {
    for(int i = 0; i < K; i++){
        int index = hash_functions[i](s)%M;
        count[i][index] += 1;
    }
}

/**
 * Implement find() correctly
 */
unsigned int CountMinSketch::find(const string & s) {
    int check = std::numeric_limits<int>::max();
    for(int i = 0; i < K; i++){
        int index = hash_functions[i](s)%M;
        int current = count[i][index];
        if (current < check){
            check = current;
        }
    }
    return check; 
}
