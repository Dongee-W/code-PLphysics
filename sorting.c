#include<time.h>
#define NSIZE 10

void sorting(int, int*, int*);
int main()
{
    srand(time(NULL));
    int i, number[NSIZE], numberx[NSIZE], seq[NSIZE];

    // fill the number array and copy to numberx
    for (i=0; i<NSIZE; i++)
    {
        number[i] = rand() % 256;
        numberx[i] = number[i];
    }
    // initialize the seq array
    for (i=0; i<NSIZE; i++) seq[i] = i;

    // Display array
    printf("original number array: ");
    printar(number);
    sorting(NSIZE, numberx, seq);
    printf("Sorted number array: [");
    for (i=0; i<NSIZE; i++)
    {
        printf("%d", number[seq[i]]);
        if (i != NSIZE - 1) printf(", ");
    }
    printf("]");
}

// array printer
void printar(int* a)
{
    int i;
    printf("[");
    for (i=0; i < NSIZE; i++)
    {
        printf("%d", a[i]);
        if (i == NSIZE - 1) break;
        printf(", ");
    }
    printf("]\n");
}

// sorting function
void sorting(int size, int* array, int* seqq)
{
    int i, j, temp1, temp2;
    for (i=0; i<=size-2; i++) // step through the array
    {
        for (j=i+1; j<=size - 1; j++)
        {
            if (array[i] > array[j]) // check if the lower index element > greater one
            {
                // swap the order of the element in array and seq
                temp1 = array[i];
                temp2 = seqq[i];
                array[i] = array[j];
                seqq[i] = seqq[j];
                array[j] = temp1;
                seqq[j] = temp2;
            }
        }
    }
}
