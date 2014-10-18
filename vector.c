#include <stdio.h>
#include <math.h>

struct tt {double x, y, z;};
typedef struct tt vec;

vec input_a_vector(void);
vec vectorminus(vec, vec);
vec vectorcross(vec, vec);
double vectorabs(vec);
void printvec(vec);

int main()
{
    vec v1, v2, v3, A, B;
    double area;
    v1 = input_a_vector();
    v2 = input_a_vector();
    v3 = input_a_vector();

    A = vectorminus(v2, v1);
    B= vectorminus(v3, v1);
    area = vectorabs(vectorcross(A, B)) / 2;
    printvec(v1);
    printvec(v2);
    printf("area enclosed=%lf", area);


    return 0;
}

void printvec(vec v)
{
    printf("Vector(%lf, %lf, %lf)\n", v.x, v.y, v.z);
}

vec input_a_vector()
{
    vec v;
    printf("Input the x, y, z of the vector(use space to separate them)\n");
    scanf("%lf%lf%lf", &v.x, &v.y, &v.z);
    return v;
}

double vectorabs(vec v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

vec vectorminus(vec v1, vec v2)
{
    vec v;
    v.x = v1.x - v2.x;
    v.y = v1.y - v2.y;
    v.z = v1.z - v2.z;
    return v;
}

vec vectorcross(vec v1, vec v2)
{
    vec v;
    v.x = v1.y * v2.z - v2.y * v1.z;
    v.y = v2.x * v1.z - v1.x * v2.z;
    v.z = v1.x * v2.y - v2.x * v1.y;
    return v;
}
