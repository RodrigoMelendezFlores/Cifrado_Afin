#include <iostream>
using namespace std;

int EuclidesExtendido(int a, int b, int &x, int &y) {
    if(b == 0) {
       x = 1;
       y = 0;
       return a;
    }
    int x1, y1;
    int euclides = EuclidesExtendido(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return euclides;
}

void inverso(int a, int n)
{
    int x, y;
    int eucli = EuclidesExtendido(a, n, x, y);
    if (eucli == 1){
      if(0<=x<=n-1){
        int resultado = (x % n + n) % n;
        cout << "inverso es:  " << resultado;
      }
       else cout << "no esta en el rango de Zn";  
    }
    else cout << "no existe";  
}

int main()
{
   int a, n, aux;
  cout<<"insertar primer numero: ";
    cin>>a;
  cout<<"insertar segundo numero: ";
    cin>>n;
  if(n<0){cout<<"no cumple lo de n enteros positivos";}  
  if ((a<0)&& (n<0)) {cout<< "Ingrese numeros positivos";}
  else inverso(a,n);
    
   return 0;
}
