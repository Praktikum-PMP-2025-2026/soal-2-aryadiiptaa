#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct meteorit {
    char nama[30];
    int massa;
    int kemurnian;
};

static int compare_meteorit(const void *a, const void *b) {
    const struct meteorit *x = a;
    const struct meteorit *y = b;

    if (x->kemurnian != y->kemurnian) {
        return y->kemurnian - x->kemurnian;
    }
    if (x->massa != y->massa) {
        return x->massa - y->massa;
    }
    return strcmp(x->nama, y->nama);
}

int main(void) {
    int N;
    if (scanf("%d", &N) != 1 || N <= 0) {
        return 0;
    }

    struct meteorit *M = malloc(sizeof(*M) * N);
    if (M == NULL) {
        return 1;
    }

    for (int i = 0; i < N; i++) {
        if (scanf("%29s %d %d", M[i].nama, &M[i].massa, &M[i].kemurnian) != 3) {
            free(M);
            return 0;
        }
    }

    qsort(M, N, sizeof(*M), compare_meteorit);

    int limit = (N < 3) ? N : 3;
    for (int i = 0; i < limit; i++) {
        printf("%s %d %d\n", M[i].nama, M[i].massa, M[i].kemurnian);
    }

    free(M);
    return 0;
}
