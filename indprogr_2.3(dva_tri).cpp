#include <iostream>
#include <cmath>

using namespace std;
/*
class eq2 {
    private:
        double a, b, c;
        double D;

    public:
        eq2 (double a1, double b1, double c1) {
            a = a1; b = b1; c = c1;
            D = b*b - 4*a*c;
        }
        void set (double a1, double b1, double c1) {
            a = a1; b = b1; c = c1;
            D = b*b - 4*a*c;
        }
        double find_X () {
            if (D<0) {
                cout << "корней нет" << endl;
                return 0;
            }
            else {
                if (D==0) {
                    cout << "корень один: " << endl;
                    double x = (-b - sqrt(D))/(2*a);
                    cout << x << endl;
                    return x;
                }
                else {
                    cout << "корень 2 мах: " << endl;
                    double x1 = (-b - sqrt(D))/(2*a);
                    double x2 = (-b + sqrt(D))/(2*a);
                    if (x1>x2) {
                        cout << x1  << endl;
                        return x1;
                    }
                    else {
                        cout << x2 << endl;
                        return x2;
                    }
                }
            }
        }
        double find_Y (double x1) {
            return a*x1*x1+b*x1+c;
        }
};
*/
class rational {
private:
    int a, b;

public:
    void Rational(int a1, int b1) {
        if (b1 == 0) {
            cout << "znam ==0";
        }
        else {
            for (int i = 2; i <= a1 / 2 + 1; i++) {
                if (a1 % i == 0 and b1 % i == 0) {
                    a1 = a1 / i;
                    b1 = b1 / i;
                }
            }
            if (a1 >= b1) {
                a1 = a1 % b1;
            }
        }
        a = a1;
        b = b1;
    }
    void set(int a1, int b1) {
        if (b1 == 0) {
            cout << "znam ==0";
        }
        else {
            if (a1 % b1 == 0) {
                a1 = a1 / b1;
            }
            if (a1 > b1) {
                a1 = a1 % b1;
            }
        }
        a = a1;
        b = b1;
    }
    int get_a() {
        return a;
    }
    int get_b() {
          return b;
        }
    
    void show() {
        cout << a << "/" << b<<endl;
    }
    rational operator+(rational dva) {
        int a1, b1, a2, b2, a3, b3;
        rational ans;
        a1 = this->a;
        b1 = this->b;
        a2 = dva.get_a();
        b2 = dva.get_b();
        b3 = b1 * b2;
        a3 = a1 * b2 + a2 * b1;
        //cout<<a3<<" "<<b3<<endl;
        ans.Rational(a3, b3);
        return ans;
    }
    rational operator++() {
        int a1, b1;
        rational ans;
        a1 = this->a;
        b1 = this->b;
       // cout<<a1<<" "<<b1;
        ans.Rational(a1+1, b1);
        return ans;
    }
   /* ational operator++(rational dva) {
        int a1, b1;
        rational ans;
        a1 = dva.get_a();
        b1 = dva.get_b();
        ans.Rational(a1 + 1, b1);
        return ans;
    }*/
    bool operator==(rational dva) {
        int a1, b1, a2, b2;
        a1 = this->a;
        b1 = this->b;
        a2 = dva.get_a();
        b2 = dva.get_b();
        return (a1 == a2 and b1 == b2);
    }
    bool operator>(rational dva) {
        int a1, b1, a2, b2;
        a1 = this->a;
        b1 = this->b;
        a2 = dva.get_a();
        b2 = dva.get_b();
        bool bob = a1 * b2 > a2 * b1;
        return bob;
    }
    rational operator=(rational dva) {
        int a2, b2;
            rational ans;
            a2 = dva.get_a();
            b2 = dva.get_b();
           // cout<<a2<<" "<<b2<<endl;
            ans.Rational(a2, b2);
            this->a=a2;
            this->b=b2;
            return *this;
    }

    friend rational operator-(rational odin,rational dva);
};
rational operator-(rational odin, rational dva) {
    int a1, b1, a2, b2, a3, b3;
    rational ans;
    a1 = odin.get_a();
    b1 = odin.get_b();
    a2 = dva.get_a();
    b2 = dva.get_b();
    b3 = b1 * b2;
    a3 = a1 * b2 - a2 * b1;
    ans.Rational(a3, b3);
    return ans;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    /* double a, b, c;
     cin >> a >> b >> c;
     eq2 exmpl(a, b, c);
     exmpl.find_X();
     cout << exmpl.find_Y(6);*/
     
     int a,b,v;
     cin>>a;
     a=a-1;
     rational *mas2 = new rational[a];
     for (int i=0;i<=a;i++){
         cin>>b>>v;
         cout<<endl;
         mas2[i].Rational(b,v);
     }

     for (int i=0;i<=a;i++){
     mas2[i].show();
     cout<<endl;
     }

     delete[] mas2;
     
    int n, x, y;
    cin >> n;
    n = n - 1;
    rational ans,inc,test;
    rational* mas = new rational[n];
    for (int i = 0; i <= n; i++) {
        cin >> x >> y;
        cout << endl;
        mas[i].Rational(x, y);
    }
    ans = mas[0] + mas[1];
    ans.show();
    ans = mas[0] - mas[1];
    ans.show();
    inc = ++mas[0];
    inc.show();
  	bool srav=( mas[0] == mas[1]);
   cout << srav<<endl;
   bool srav2=( mas[0] > mas[1]);
   cout << srav2<<endl;
   test = mas[1];
   test.show();
    return 0;
}
