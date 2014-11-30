#include <iostream>
#include "summerlight_vec.h"
using namespace std;
int main()
{

    vec v1, v2, v3, temp(3);
    cin >> v1;
    cin >> v2;
    cin >> v3;
    v2 -= v3;
    v1 -= v3;
    cout << "v2 - v3: " << v2;
    cout << "v1 - v3: " << v1;
    temp = v1*v2;
    cout << "cross: " << temp;
    cout << "Area: " << temp.abs() / 2;
    //cin >> v3;*/

    return 0;
}
