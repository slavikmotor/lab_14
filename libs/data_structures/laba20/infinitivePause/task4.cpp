#include <stdio.h>
#include <stdlib.h>
void fourthTaskAlgorithm(domain array[], size_t size){
    size_t closeIndexes[size];
    size_t countClose = 0;
    domain results[200];
    size_t sizeResult = 0;

    for (size_t ind = 0; ind < size; ind++){
        results[sizeResult++] = array[ind];
    }

    while(countClose != size){
        for (size_t ind = 0; ind < size; ind++){
            if (!searchNumFromArray(closeIndexes, countClose, ind)){
                char *dotPtr = strchr(array[ind].name, '.');

                if (dotPtr != NULL){
                    handlerDotPrtNotNull(array, ind, dotPtr,
                                         results, &sizeResult);
                } else{
                    closeIndexes[countClose++] = ind;
                }
            }
        }
    }

    outputResultDomains(results, sizeResult);
}

bool searchNumFromArray(const size_t array[], size_t length, size_t num){
    for (size_t ind = 0; ind < length; ind++){
        if (num == array[ind]){
            return true;
        }
    }

    return false;
}

oid handlerDotPrtNotNull(domain *array, size_t ind, char *dotPtr,
                         domain results[], size_t *sizeResult){
    strcpy(array[ind].name, dotPtr + 1);
    size_t pos = searchDomainInResults(results, *sizeResult,
                                       array[ind].name);
    if (pos == *sizeResult){
        results[*sizeResult] = array[ind];
        *sizeResult += 1;
    } else{
        results[pos].visits += array[ind].visits;
    }
}

void outputResultDomains(domain *results, size_t size){
    for (size_t ind = 0; ind < size; ind++){
        printf("%ld %s\n", results[ind].visits, results[ind].name);
    }
}