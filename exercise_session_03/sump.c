#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "gt.h"

typedef struct {
    float x;
    float y;
    float z;
    float r2;
} coord;

int main(int argc, char *argv[]) {
    const int N = 1024*1024*256;
    coord *data;
    int i;
    double sum;
    double gtStart, gtElapsed;
    gtStart = getTime();
    
    data = malloc(N * sizeof(coord));
    assert(data);
    
    sum = 0.0;
#pragma omp parallel for reduction(+ : sum)
    for(i=0; i<N; ++i) {
        data[i].x = i & 31;
        data[i].y = i & 63;
        data[i].z = i & 15;
        data[i].r2 = data[i].x*data[i].x + data[i].y*data[i].y + data[i].z*data[i].z;
        sum += sqrt(data[i].r2);
    }
    printf("sum=%f\n", sum);
    gtElapsed = getTime() - gtStart;
    printf("with gt function computed in %.4g seconds\n", gtElapsed);
    return 0;
}
