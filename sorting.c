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

// print the array
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

void sorting(int size, int* array, int* seqq)
{
    int i, j, temp1, temp2;
    for (i=0; i<=size-2; i++)
    {
        for (j=i+1; j<=size - 1; j++)
        {
            if (array[i] > array[j])
            {
                // swap the order for array and seq
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
