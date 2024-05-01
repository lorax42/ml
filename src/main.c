#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_LEN(arr) (sizeof(arr)/sizeof(arr[0]))

float train[][2] = {
    {0,0},
    {1,2},
    {2,4},
    {3,6},
    {4,8},
};

float randf(){
    return( (float) rand()/ (float) RAND_MAX );
}

float cost(float w, float b){
    float result = 0.0f;
    for(size_t i = 0; i < ARR_LEN(train); i++){
        float x = train[i][0];
        float y = x*w + b;
        float d = y - train[i][1];
        result += d*d;
    }
    result /= ARR_LEN(train);
    return(result);
}

int main(){
    // x1, x2, x3, ..., b
    // w1, w2, w3, ...
    // y = x1*w1 + x2*w2 + x3*w3 + ... + b

    //srand(time(0));
    //srand(69);
    //srand(1);
    srand(42);

    float w = randf()*10.0f;
    float b = randf()*5.0f;

    float eps = 1e-3;
    float rate = 1e-3;

    printf("%f\n", cost(w, b));

    for(size_t i = 0; i < 5000; i++){
        float c = cost(w, b);
        float dw = (cost(w + eps, b) - c)/eps;
        float db = (cost(w, b + eps) - c)/eps;
        w -= rate*dw;
        b -= rate*db;
        printf("c = %f, w = %f, b = %f\n", cost(w, b), w, b);
    }

    printf("-------------------------\n");
    printf("w = %f, b = %f\n", w, b);

    return(0);
}

