#include <stdio.h>

int is_prime(long long int num) {
if (num <= 1) {
return (0);
}
for (long long int i = 2; i * i <= num; i++) {
if (num % i == 0) {
return 0;
}
}
return (1);
}

void factorize_rsa_number(long long int num) {
long long int p, q;
for (p = 2; p * p <= num; p++) {
if (num % p == 0 && is_prime(p)) {
q = num / p;
if (is_prime(q)) {
printf("%lld=%lld*%lld\n", num, p, q);
return;
}
}
}
printf("Unable to factorize %lld into prime factors.\n", num);
}

int main(int argc, char *argv[]) {
if (argc != 2) {
printf("Usage: %s <file>\n", argv[0]);
return (1);
}

FILE *file = fopen(argv[1], "r");
if (file == NULL) {
perror("Error opening file");
return (1);
}

long long int num;
while (fscanf(file, "%lld", &num) != EOF) {
factorize_rsa_number(num);
}

fclose(file);
return (0);
}
