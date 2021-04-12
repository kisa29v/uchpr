#include "plant.h"

//#include <discpp.h>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;
using std::vector;
void
plant_init(Plant plant);

static void
gettime(struct tm* result);

double
initdat(void);

double
plant_measure(int kanal, Plant plant);

void
plant_control(int kanal, double upr, Plant plant);

int
main()
{
    // Инициализация ОУ.
    Plant plant;
    plant_init(plant);
    int L1, L2, L3, N, i;
    double Xn1, Xn2, Xn3, B1, B2, B3, X1, X2, X3, value;
    bool flag;
    flag = 0;
    cin >> L1,L2, L3, N, Xn1, Xn2, Xn3, B1, B2, B3;
    for (i=0; i<N; i++)
    {
        X1 = plant_measure(L1, plant);
        X2 = plant_measure(L2, plant);
        X3 = plant_measure(L3, plant);
        if ((- B1 < (X1-Xn1)) and ((X1-Xn1) < B1))    //control
        {
            flag = 1;
        }
        cout << X1;
        if (flag == 0)
        {
            cout << "Нарушение неравенства в канале L1, неравенство 1";
        }
        flag = 0;
        if (((-B2) < (X2-Xn2)) and ((X2-Xn2) < B2))
        {
        flag = 1;
        }
    cout << X2;
         if (flag == 0)
    {
        cout << "Нарушение неравенства в канале L2, неравенство 2";
    }
    flag = 0;
           if (((-B3) < (X3-Xn3)) and ((X3-Xn3) < B3))
    {
        flag = 1;
    }
    cout << X3;
         if (flag == 0)
    {
        cout << "Нарушение неравенства в канале L3, неравенство 3";
    }
}
}
