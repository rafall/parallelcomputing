#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <time.h>

int isPrime(int);
void markMultiples(int);

int *primes;    // Array of prime numbers: -1 not prime; 0 not visited; 1 prime
int n;          // Max number

int main()
{
    int i, j, sqrt_n;
    double total;
    clock_t t_start, t_end; // Variables to count time
    omp_set_num_threads(8);
    scanf("%d", &n);

    t_start = clock();

    primes = (int*) calloc (n, sizeof(int));
    primes[0] = 1;
    primes[1] = 1;

    sqrt_n = (int) sqrt(n);

    // Parallel portion
    #pragma omp for
    for(i = 2; i < sqrt_n; i++)
    {
        if(primes[i] == 0)
        {
            markMultiples(i);
            #pragma omp critical
            primes[i] = isPrime(i);
        }
    }
    t_end = clock();

    // Print all prime numbers
    for (i = 2; i < n; i++)
    {
        if(primes[i] == 1 || primes[i] == 0)
            printf("%d ", i);
    }
    printf("\n");

    total = (double) (t_end - t_start)/CLOCKS_PER_SEC;
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
