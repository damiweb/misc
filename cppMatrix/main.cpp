#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
   cout << "Program działa" << endl;
   int vecdim = 1;
   cout << "Wpisz wymiar wektora"  << endl;
   cin >> vecdim;
   Vector my(vecdim);
   my.valuesAdd();
   cout << "wektor wygląda następująco" << endl;
   //my.display();
   cout << "Wpisz wymiar wektora"  << endl;
   cin >> vecdim;
   Vector my2(vecdim);
   my2.valuesAdd();
   Vector my3(2);
   my3 = my + my2;
   cout << "Wektor przyisany przeciążonym operatorem" << endl;
   my3.display();
   return 0;
}