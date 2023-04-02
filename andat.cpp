#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

//C:\Users\ivc1-5\source\repos

class andat {
public:
    double data,input;
    bool check(int a){
    	return data==a;
	}
	void set(int a){
		data=a;
	}
    double get(){
    	return data;
	}
    
};

 
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    return 0;
}
