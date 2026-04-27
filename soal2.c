#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct meteorit {
    char nama[30];
    int massa;
    int kemurnian;
};

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;
    
    struct meteorit M[N];

    for(int i=0; i<N; i++){
        scanf("%s", M[i].nama);
        scanf("%d", &M[i].massa);
        scanf("%d", &M[i].kemurnian);
    }

    
    for(int i=0; i<N; i++){
        for(int j=0; j<N-i; j++){
            if(M[j].kemurnian < M[j+1].kemurnian) {
                struct meteorit temp = M[j];
                M[j] = M[j+1];
                M[j+1] = temp;
            }
        }
    }

    for(int i=0; i<N; i++){
        if(M[i].kemurnian == M[i+1].kemurnian){
            if(M[i+1].massa < M[i].massa){
                struct meteorit temp = M[i];
                M[i] = M[i+1];
                M[i+1] = temp; 
            }
        }
    }

    for(int i=0; i<N; i++){
        int res;
        if(M[i].kemurnian == M[i+1].kemurnian && M[i].massa == M[i+1].massa){
            res = strcmp(M[i].nama, M[i+1].nama);
            if(res>0){
                struct meteorit temp = M[i];
                M[i] = M[i+1];
                M[i+1] = temp;
            }
        }
    }

    int limit = (N < 3) ? N : 3;
    for(int i=0; i<limit; i++){
        printf("%s %d %d\n", M[i].nama, M[i].massa, M[i].kemurnian);
    }
    
    return 0;
}
