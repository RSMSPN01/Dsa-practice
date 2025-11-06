#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    cout<<"No. of digits are : "<<floor(log10(n)+1)<<endl;
    return 0;
}