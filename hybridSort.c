#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Algoritmo Insertion*/
void InsertionSort(int *A, int len)
{
    int i, j, key;
    for (j = 1; j < len; j++)
    {
        key = A[j];
        i = j - 1;
        while ((i >= 0) && (A[i] > key))
        {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}

/* Algoritmo Adapted Insertion Sort per hybrid*/
void AdaptedInsertionSort(int *A, int base, int len)
{
    int i, j, key;
    for (j = base; j <= len; j++) //=?, base = 1
    {
        key = A[j];
        i = j - 1;
        while ((i >= base) && (A[i] > key))
        {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}

/* Algoritmo Merge */
void Merge(int *A, int p, int q, int r)
{
    int n1, n2, i, j, k;
    n1 = q - p + 1;
    n2 = r - q;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = A[p + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = A[q + j + 1];
    }
    i = 0;
    j = 0;
    for (k = p; k < r + 1; k++)
    {
        if (i < n1)
        {
            if (j < n2)
            {
                if (L[i] <= R[j])
                {
                    A[k] = L[i];
                    i++;
                }
                else
                {
                    A[k] = R[j];
                    j++;
                }
            }
            else
            {
                A[k] = L[i];
                i++;
            }
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

/* Algoritmo Merge Sort */
void MergeSort(int *A, int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
}

/* Hybrid Sort */
void HybridSort(int *A, int p, int r)
{
    int k = 165;
    int q;
    if (r - p + 1 > k)
    {
        q = (p + r) / 2;
        HybridSort(A, p, q);
        HybridSort(A, q + 1, r);
        Merge(A, p, q, r);
    }
    else
    {
        AdaptedInsertionSort(A, p, r);
    }
}

/* Singolo Esperimento */
float singoloEsperimento(int length, int maxInstances, char *alg)
{
    float timeTot = 0, timeStart, timeEnd, timeElapsed;
    int A[length];
    for (int i = 0; i < maxInstances; i++)
    {
        for (int j = 0; j < length; j++) // Generatore Array di numeri Casuali:
        {                                // tramite il metodo rand()%N, genera un numero tra 0 e N-1
            A[j] = 1 + rand() % 1000000; // e metto il numero generato nell'array
        }

        if (strcmp(alg, "InsertionSort") == 0)
        {

            timeStart = clock();
            InsertionSort(A, length);
            timeEnd = clock();
        }

        if (strcmp(alg, "MergeSort") == 0)
        {
            timeStart = clock();
            MergeSort(A, 0, length - 1);
            timeEnd = clock();
        }

        if (strcmp(alg, "HybridSort") == 0)
        {
            timeStart = clock();
            HybridSort(A, 0, length - 1);
            timeEnd = clock();
        }
        timeElapsed = timeEnd - timeStart;
        timeTot = timeTot + timeElapsed;
    }
    return timeTot / maxInstances;
}

/* Esperimento */
void esperimento(int minLen, int maxLen, int SEED)
{
    int maxInstances = 50;
    int STEP = 10;
    float timeIS, timeMS, timeHS;

    for (int length = minLen; length < maxLen; length = length + STEP)
    {
        srand(SEED);
        timeIS = singoloEsperimento(length, maxInstances, "InsertionSort");
        srand(SEED);
        timeMS = singoloEsperimento(length, maxInstances, "MergeSort");
        srand(SEED);
        timeHS = singoloEsperimento(length, maxInstances, "HybridSort");
        //printf("dim %d\t Tempo IN: %.2f \tTempo MS: %.2f \tTempo HS: %.2f\n", length, timeIS, timeMS, timeHS);
        //printf("%.2f\t%.2f\t%.2f\n", timeIS, timeMS, timeHS);
        printf("%.2f\n", timeHS);
        SEED += 1;
    }
}

/* Main */
int main(int argc, char *argv[])
{
    int minLength = 5;
    int maxLength = 1000;
    esperimento(minLength, maxLength, 15); // esperimento() mi da n.Tempi per tentativo
                                           // dove n = (maxLength - minLength) / Step

    return 0;
}
