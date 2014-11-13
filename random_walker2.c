#include <stdio.h>
#include <stdlib.h>

int main(int nu, char **argv)
{
    int i, istep;
    int a, b ,c, isample, nstep, sf, ncell, nd, N;
    double x, y;
    double *sum;
    N = atoi(argv[1]);
    nstep = atoi(argv[2]);
    sf = atoi(argv[3]);

    sum = calloc(nstep/sf + 1, sizeof(double));

    srand(time(NULL));

    for (isample = 0; isample < N; isample++)
    {
        x = 0.0, y = 0.0;
        for (istep = 0; istep <= nstep; istep++)
        {
            nd = rand() % 40;
            switch (nd)
            {
                case 0:
                    x++;
                    break;
                case 1:
                    y++;
                    break;
                case 2:
                    x--;
                    break;
                case 3:
                    y--;
                    break;
            }
            if (nd>=0 && nd<=10) x++; // right
            else if (nd>=11 && nd<=19) x--; //left
            else if (nd>=20 && nd<=29) y++;
            else if (nd>=30 && nd<=39) y--;

            if (istep%sf==0)
            {
                ncell = istep / sf;
                sum[ncell] += x*x + y*y;
            }
        }
    }
    FILE *fp;
    fp = fopen("result.txt", "w");
    for (i = 0; i<21; i++)
    {
        sum[i] = sum[i] / N;
        fprintf( fp," %2d    %lf\n", i, sum[i]);
    }
    fclose(fp);
    return 0;
}
