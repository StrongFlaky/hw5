#include "BloomFilter.h"
#include "HashFunctions.h"

/**
 * Implement insert() correctly
 */
void BloomFilter::insert(const string & s) {
    for(int i = 0; i < K; i++){
        int index = hash_functions[i](s)%M;
        bits[index] = true;
    }
}

/**
 * Implement find() correctly
 */
bool BloomFilter::find(const string & s) {
    for(int i = 0; i < K; i++){
        int index = hash_functions[i](s)%M;
        if (bits[index] == false){
            return false; 
        }
    }
    return true;
}
