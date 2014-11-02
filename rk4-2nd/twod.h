#ifndef _ytlu_twod_head_
#define _ytlu_twod_head_
 // ytlu_twod_head_
struct ttt {  double x, y;};
typedef struct ttt twod;

twod twodplus(twod v1, twod v2)
{
    twod v3;
    v3.x = v1.x + v2.x;
    v3.y = v1.y + v2.y;
    return v3;
}

twod twodxd(twod v, double r)
{
    twod w;
    w.x = v.x * r;
    w.y = v.y * r;
    return w;
}
twod twodminus(twod v1, twod v2)
{
    twod v3;
    v3.x = v1.x - v2.x;
    v3.y = v1.y - v2.y;
    return v3;
}
double twoddot(twod v1, twod v2)
{
    return v1.x*v2.x + v1.y*v2.y;
}
#endif

