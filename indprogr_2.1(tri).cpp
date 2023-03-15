#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

class Triangle {
private:
    double a, b, c;

public:
    bool exst_tr() {
        return ((a + b > c) && (b + c > a) && (a + c > b));
    }
    void set(double a1, double b1, double c1) {
        a = a1;
        b = b1;
        c = c1;
    }
    void show() {
        cout << "1 сторона: " << a << endl;
        cout << "2 сторона: " << b << endl;
        cout << "3 сторона: " << c << endl;
    }
    double perimetr() {
        double p = a + b + c;
        return p;
    }
    double square() {
        double p = (a + b + c) / 2;
        double s = sqrt(p * (p - a) * (p - b) * (p - c));
        return s;
    }
};

class circle {
private:
    float radius, x_center, y_center;

public:

    void set_circle(float r, float x, float y) {
        radius = r;
        x_center = x;
        y_center = y;
    }
    void Circle(float r, float x, float y) {
        radius = r;
        x_center = x;
        y_center = y;
    }
    float  square() {

        float s = M_PI * radius * radius;
        return s;
    }
    bool triangle_around(float a, float b, float c) {
        float p = (a + b + c) / 2;
        return (radius == (a * b * c) / (4 * sqrt(p * (p - a) * (p - b) * (p - c))));
    }
    bool triangle_in(float a, float b, float c) {
        float p = (a + b + c) / 2;
        return (radius == sqrt((p - a) * (p - b) * (p - c)) / p);
    }
    bool check_circle(float r, float x_cntr, float y_cntr) {
        float len = sqrt(((x_center - x_cntr) * (x_center - x_cntr)) + ((y_center - y_cntr) * (y_center - y_cntr)));
        return (radius + r <= len);
    }

};

class figure {
private:
    float x1, x2, x3, x4;
    float y1, y2, y3, y4;
    float S;
    float P;
public:


    void Figure(float x_1, float x_2, float x_3, float x_4, float y_1, float y_2, float y_3, float y_4) {
        x1 = x_1;
        x2 = x_2;
        x3 = x_3;
        x4 = x_4;
        y1 = y_1;
        y2 = y_2;
        y3 = y_3;
        y4 = y_4;
        S = (abs((x1 - x2) * (y1 - y2) + (x2 - x3) * (y2 - y3) + (x3 - x4) * (y3 - y4) + (x4 - x1) * (y4 - y1)) / 2);
        P = (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) + sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2)) + sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2)) + sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2)));
    }
    void show() {
        cout << "x1  " << x1 << endl;
        cout << "x2  " << x2 << endl;
        cout << "x3  " << x3 << endl;
        cout << "x4  " << x4 << endl;
        cout << "y1  " << y1 << endl;
        cout << "y2  " << y2 << endl;
        cout << "y3  " << y3 << endl;
        cout << "y4  " << y4 << endl;
        cout << "S  " << S << endl;
        cout << "P  " << P << endl;
    }
    bool is_prug() {
        return((sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) == sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2))) and (sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2)) == (sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2)))));
    }
    bool is_square() {
        return(((sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) == sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2))) and (sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2)) == sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2))) and (sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2)) == sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2))) and (sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2)) == (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2))))) and sqrt(pow(x2 - x4, 2) + pow(y2 - y4, 2)) == sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2)));
    }
    bool is_romb() {
        return((sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) == sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2))) and (sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2)) == sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2))) and (sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2)) == sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2))) and (sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2)) == (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)))));
    }
    bool is_in_circle() {
        float ax, ay, bx, by, cx, cy, dx, dy, a, b, c, d, a_b, c_d, cos1, cos2;
        ax = x2 - x1;
        bx = x3 - x2;
        cx = x4 - x3;
        dx = x1 - x4;
        ay = y2 - y1;
        by = y3 - y2;
        cy = y4 - y3;
        dy = y1 - y4;
        a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
        c = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
        d = sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2));
        a_b = ax * bx + ay * by;
        c_d = cx * dx + cy * dy;
        cos1 = a_b / (a * b);
        cos2 = c_d / (c * d);
        return(acos(cos1) + acos(cos2) == 3.1415);
    }
    bool is_out_circle() {
        float a, b, c, d;
        a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
        c = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
        d = sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2));
        return(a + c == b + d);
    }
};




int main()
{
    setlocale(LC_ALL, "Russian");
  /*    Triangle mas[3];
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
     */
  /*  circle mas1[3];
    double a, b, c;
    for (int i = 0; i < 3; i++) {
        cout << "a b c " << i + 1 << " вводить через пробел " << endl;
        cin >> a >> b >> c;
        mas1[i].set_circle(a, b, c);
    }
    for (int i = 0; i < 3; i++) {
       // mas1[i].show();
        cout << "описанный " << mas1[i].triangle_around(3, 4, 5) << endl;
        cout << "вписанный " << mas1[i].triangle_in(3, 4, 5) << endl;
        cout << "площадь " << mas1[i].square() << endl;
        cout << "другая окружгость " << mas1[i].check_circle(0, 0, 2) << endl;
    }*/
  figure mas2[3];
    double a, b, c, d,w,x,y,z;
    for (int i = 0; i < 3; i++) {
        cout << "a b c d w x y z " << i + 1 << " вводить через пробел " << endl;
        cin >> a >> b >> c>>d>>w>>x>>y>>z;
        mas2[i].Figure(a, b, c,d,w,x,y,z);
    }
    for (int i = 0; i < 3; i++) {
       	mas2[i].show();
        cout << "прямоугольник " << mas2[i].is_prug() << endl;
        cout << "квадрат  " << mas2[i].is_square() << endl;
        cout << "ромб " << mas2[i].is_romb() << endl;
        cout << "вписанный " << mas2[i].is_in_circle() << endl;
        cout << "описанный " << mas2[i].is_out_circle() << endl<<endl;
    }

    return 0;
}
