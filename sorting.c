#include<time.h>
#define NSIZE 10

void sorting(int, int*, int*);
int main()
{
    srand(time(NULL));


    int i, number[NSIZE], seq[NSIZE];

    // fill the number array
    for (i=0; i<NSIZE; i++) number[i] = rand() % 256;
    // fill the seq array
    for (i=0; i<NSIZE; i++) seq[i] = i;


    printar(number);
    sorting(NSIZE, number, seq);
    printar(number);
    //printar(seq);
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
    int i, j, temp;
    for (i=0; i<=size-2; i++)
    {
        for (j=i+1; j<=size - 1; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
