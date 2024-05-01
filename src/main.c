#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_LEN(arr) (sizeof(arr)/sizeof(arr[0]))

float train[][2]={
    {0,0},
    {1,2},
    {2,4},
    {3,6},
    {4,8},
};

float randf(){
    return( (float) rand()/ (float) RAND_MAX);
}

float cost(float w){
    float result=0.0f;
    for(size_t i=0;i<ARR_LEN(train);i++){
        float x=train[i][0];
        float y=x*w;
        float d=y-train[i][1];
        result += d*d;
    }
    result/=ARR_LEN(train);
    return(result);
}

int main(){
    // y=x*w

    //srand(time(0));
    //srand(69);
    srand(42);

    float w=randf()*10.0f;

    float eps=1e-3;
    float rate=1e-3;

    printf("%f\n",cost(w));

    for(size_t i=0;i<500;i++){
        float dcost=(cost(w+eps)-cost(w))/eps;
        w-=rate*dcost;
        printf("cost=%f, w=%f\n",cost(w),w);
    }

    printf("-------------------------\n");
    printf("%f\n",w);

    return(0);
}

