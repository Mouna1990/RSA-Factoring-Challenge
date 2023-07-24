#include <stdio.h>
#include <stdlib.h>

/* Function to factorize a number and print the result*/
void factorize(int num) {
    int p, q;
    for (p = 2; p <= num / 2; p++) {
        if (num % p == 0) {
            q = num / p;
            printf("%d=%d*%d\n", num, p, q);
            return;
        }
    }
    printf("%d is prime\n", num);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }

    int num;
    while (fscanf(file, "%d", &num) != EOF) {
        factorize(num);
    }

    fclose(file);
    return 0;
}
