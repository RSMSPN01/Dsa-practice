#include <iostream>
using namespace std;

int checkPalindrome(int n){
    int final = 0;
    while (n!=0)
    {
        int r = n%10;
        n/=10;
        final = r + final*10;
    }
    return final;
}

int main(){
    int n;
    cin>>n;
    int x = checkPalindrome(n);
    if (x==n)
    {
        cout<<"Number is Palindrome";
    }else
    {
        cout<<"Not Palindrome";
    }
    
    
    return 0;
}