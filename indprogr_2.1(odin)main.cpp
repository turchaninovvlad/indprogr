#include <iostream>
#include <cmath>
#include <stdio.h>
#include <indprogr_2.1(odin).h>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");
      Triangle mas[3];
      double a, b, c;
      for (int i = 0; i < 3; i++) {
          cout << "a b c " << i + 1 << " вводить через пробел " << endl;
          cin >> a >> b >> c;
          mas[i].set(a, b, c);
          if (!(mas[i].exst_tr())) {
              mas[i].show();
              cout << "не существует" << endl;
              i--;
          }
      }
      for (int i = 0; i < 3; i++) {
          mas[i].show();
          cout << "периметр" << mas[i].perimetr() << endl;
          cout << "площадь " << mas[i].square() << endl;
      }
     
  
    return 0;
}
