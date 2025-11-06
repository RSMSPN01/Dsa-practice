#include <iostream>
#include <math.h>
using namespace std;
void roots (int d,int b,int a){
    int x1 = (-b+sqrt(d))/2*a;
    cout<<"First Root : "<<x1<<endl;
    int x2 = (-b-sqrt(d))/2*a;
    cout<<"Second Root : "<<x2<<endl;
}
int main(){
    int a,b,c; // a^2x +bx+c
    cin>>a>>b>>c;
    int d = (b*b)-4*a*c;
    if (d<0)
    {
        cout<<"Imaginary";
    }
    else
    {
        roots(d,b,a);
    }
    
    
    return 0;
}