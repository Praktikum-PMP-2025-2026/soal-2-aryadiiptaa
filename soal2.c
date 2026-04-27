#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct meteorit
{
    char nama [30];
    int massa;
    int kemurnian;
};

int main(){
    int N,a;
    int temp, temp2;
    char temp3[50];
    scanf("%d", &N);
    struct meteorit M[N+1];

    for(int i=0; i<N; i++){
        scanf("%s", &M[i].nama);
        scanf("%d", &M[i].massa);
        scanf("%d", &M[i].kemurnian);
        if(i>=3){
            a=3;
        }
        else{
            a=i+1;
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N-i; j++){
            if(M[j].kemurnian < M[j+1].kemurnian) {
                temp = M[j].kemurnian;
                temp2 = M[j].massa;
                strcpy(temp3, M[j].nama); 
                M[j].kemurnian = M[j+1].kemurnian;
                M[j].massa = M[j+1].massa;
                strcpy(M[j].nama, M[j+1].nama);
                M[j+1].kemurnian = temp;
                M[j+1].massa = temp2;
                strcpy(M[j+1].nama, temp3);
            }
        }
    }

    for(int i=0; i<N; i++){
        if(M[i].kemurnian == M[i+1].kemurnian){
            if(M[i+1].massa < M[i].massa){
                temp = M[i].kemurnian;
                temp2 = M[i].massa;
                strcpy(temp3, M[i].nama); 
                M[i].kemurnian = M[i+1].kemurnian;
                M[i].massa = M[i+1].massa;
                strcpy(M[i].nama, M[i+1].nama);
                M[i+1].kemurnian = temp;
                M[i+1].massa = temp2;
                strcpy(M[i+1].nama, temp3); 
            }
        }
    }

    for(int i=0; i<N; i++){
        int res;
        if(M[i].kemurnian == M[i+1].kemurnian && M[i].massa == M[i+1].massa){
            res = strcmp(M[i].nama, M[i+1].nama);
            if(res>0){
                temp = M[i].kemurnian;
                temp2 = M[i].massa;
                strcpy(temp3, M[i].nama); 
                M[i].kemurnian = M[i+1].kemurnian;
                M[i].massa = M[i+1].massa;
                strcpy(M[i].nama, M[i+1].nama);
                M[i+1].kemurnian = temp;
                M[i+1].massa = temp2;
                strcpy(M[i+1].nama, temp3); 
            }
        }
    }

    for(int i=0; i<a; i++){
        printf("%s ", M[i].nama);
        printf("%d ", M[i].massa);
        printf("%d", M[i].kemurnian);
        printf("\n");
    }
    
}
