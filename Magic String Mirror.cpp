#include <bits/stdc++.h>
using namespace std;

string reverseprint (string a, int len){
    if(len == 0){
        return "";
    }
    return a[len-1] + reverseprint(a,len-1);
}

int main(){
    string x;
    cin >> x;
    int len = x.size();
    cout<<reverseprint(x,len);
    return 0;

}