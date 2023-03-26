#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

//C:\Users\ivc1-5\source\repos
const double pi = 3.14159265;

// класс конуса.
class Cone {
    double x, y, z;        // трёхмерные координаты 
    double radius;         // радиус
    double height;         // высота
public:
    // конструктор по умолчанию
    Cone() { x = y = z = radius = height = 0; }
    // конструктор с центром в начале координат
    Cone(double r, double h) {
        x = y = z = 0.0;
        radius = r;
        height = h;
    }
    // конструктор для Cone
    Cone(double a, double b, double c, double r, double h) {
        x = a;
        y = b;
        z = c;
        radius = r;
        height = h;
    }

    // доступ
    void setCoordinate(double a, double b, double c) { x = a; y = b; z = c; }
    void setRadius(double r) { radius = r; }
    void setHeight(double h) { height = h; }
    double getRadius() { return radius; }
    double getHeight() { return height; }

    // рлощадь поверхности
    double area() {
        double l = sqrt(height * height + radius * radius);
        return pi * radius * (radius + l);
    }
    // объём
    double volume() {
        return pi * radius * radius * height / 3;
    }

    // перезагрузка ввода
    friend ostream& operator<<(ostream& stream, Cone obj);
};

// вывод
ostream& operator<<(ostream& stream, Cone obj) {
    stream << "(" << obj.x << "; ";
    stream << obj.y << "; ";
    stream << obj.z << ") ";
    stream << "r=" << obj.radius << " ";
    stream << "h=" << obj.height << "\n";
    return stream;
}


class halfCone : public Cone {
    double x, y, z;        // трёхмерные координаты 
    double radius;         // радиус
    double halfheight;		//высота разреза считоя от основания ot osnovaniya
    double height;         // высота
public:
    // конструктор по умолчанию
    halfCone() { x = y = z = radius = height= halfheight = 0; }
    // конструктор усечённого
    halfCone(double a, double b, double c, double r, double h, double h1) {
        x = a;
        y = b;
        z = c;
        halfheight = h1;
        radius = r;
        height = h;
    }
    // доступ
    void setCoordinate(double a, double b, double c) { x = a; y = b; z = c; }
    void setRadius(double r) { radius = r; }
    void setHeight(double h) { height = h; }
    double getRadius() { return radius; }
    double getHeight() { return height; }

    // лощадь поверхности
    double area() {
        Cone a(x, y, z, radius, height);
        double scone = a.area();
        double rmin = ((height - halfheight) * radius) / height;
        double minheight = height - halfheight;
        double lmin = sqrt(minheight * minheight + rmin * rmin);//малая длинна стороны конуса
        double spmin = pi * rmin * lmin;//малая площадь поверхности
            double somin = pi * rmin * rmin;//малая площадь основания
        return (scone - spmin + somin);
    }
    // объём
    double volume() {
        double minheight = height - halfheight;
        double rmin = ((height - halfheight) * radius) / height;
        Cone a(x, y, z, radius, height), b(x, y, z, rmin, minheight);
        double v1, v2;
        v1 = a.volume();
        v2 = b.volume();
       // cout << v1 << "  " << v2;
        return v1 - v2;
    }

    // перезагрузка ввода
    friend ostream& operator<<(ostream& stream, halfCone obj);
    istream& operator>> (istream& stream)
    {
        stream >> x;
        stream >>y;
        stream >> z;
        stream >> radius;
        stream >> halfheight;
        stream >> height;
        ;
        return stream;
    }

};
ostream& operator<<(ostream& stream, halfCone obj) {
    stream << "(" << obj.x << "; ";
    stream << obj.y << "; ";
    stream << obj.z << ") ";
    stream << "r=" << obj.radius << " ";
    stream << "hh=" << obj.halfheight << " ";
    stream << "h=" << obj.height << "\n";
    return stream;;
}






int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    Cone c1(3, 7);              // конус с центром  в начале координат радиусом  3 и высотой 7
    Cone c2(1, 2, 3, 5, 10);    // произвольный конус

    cout << "конус 1: " << c1;
    cout << "площадь роверхности: " << c1.area() << "\n";
    cout << "объём: " << c1.volume() << "\n";

    cout << "конус 2: " << c2;
    cout << "площадь роверхности: " << c2.area() << "\n";
    cout << "объём: " << c2.volume() << "\n";
    halfCone c3(1, 2, 3, 5, 10,5);
    cout << "конус 3: " << c3;
    cout << "площадь роверхности: " << c3.area() << "\n";
    cout << "объём: " << c3.volume() << "\n";

    halfCone c4(1, 2, 3, 2, 10, 2);
    cout << "конус 4: " << c4;
    cout << "площадь роверхности: " << c4.area() << "\n";
    cout << "объём: " << c4.volume() << "\n";

    Cone c5(1, 2, 3, 5, 10);
    halfCone c5_1(1, 2, 3, 5, 10, 2);
    halfCone c5_2(1, 2, 3, 5, 10, 4);
    halfCone c5_3(1, 2, 3, 5, 10, 8);
    cout << "конус 5_1: " << c5_1;
    cout << "площадь роверхности: " << c5_1.area() << "\n";
    cout << "объём: " << c5_1.volume() << "\n";
    cout << "конус 5_2: " << c5_2;
    cout << "площадь роверхности: " << c5_2.area() << "\n";
    cout << "объём: " << c5_2.volume() << "\n";
    cout << "конус 5_3: " << c5_3;
    cout << "площадь роверхности: " << c5_3.area() << "\n";
    cout << "объём: " << c5_3.volume() << "\n";
    return 0;
}