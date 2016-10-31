#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isPrime(int);
void markMultiples(int);

int *primes;    // Array of prime numbers: -1 not prime; 0 not visited; 1 prime
int n;          // Max number

int main()
{
    int i, j;
    clock_t t_start, t_end;
    double total;

    scanf("%d", &n);

    t_start = clock();

    primes = (int*) calloc (n, sizeof(int));
    primes[0] = 1;
    primes[1] = 1;

    for(i = 2; i*i < n; i++)
    {
        if(primes[i] == 0)
        {
            markMultiples(i);
            primes[i] = isPrime(i);
        }
    }

    t_end = clock();

    total = (double)(t_end - t_start)/CLOCKS_PER_SEC;
/*
    for (i = 2; i < n; i++)
    {
        if(primes[i] == 1 || primes[i] == 0)
            printf("%d ", i);
    }
    printf("\n");
*/
    printf("Finished in %lf\n", total);
}

// Verify if a number is prime
int isPrime(int k)
{
    int i;

    for(i = 2; i < k; i++)
    {
        if(k%i == 0)
            return -1;
    }
    return 1;
}

// Mark all multiples of a non prime number as non prime
void markMultiples(int k)
{
    int i;
    for (i = k*2; i <= n; i+=k)
    {
        primes[i] = -1;
    }
}
