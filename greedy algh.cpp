#include<bits/stdc++.h>
using namespace std;

struct S{
    char name;
    int start_time;
    int end_time;
};

bool cmp (S s1, S s2) {
        return s1.end_time < s2.end_time;
}

int main(){
   vector <S> aaa = {
    {'A', 1, 3}, {'B', 2, 5}, {'C', 3, 9}, {'D', 6, 8}
    };
    int totalamount = 1;

    sort(aaa.begin(), aaa.end(), cmp);
    vector <S> activity;
    activity.push_back(aaa[0]);
    int lastend = aaa[0].end_time;

    for(int i = 0; i < aaa.size()-1; i++){
        if (lastend > aaa[i+1].start_time){
            continue;
        }
        else{
            lastend = aaa[i+1].end_time;
            activity.push_back(aaa[i+1]);
            totalamount++;
        }
    }
    cout<<totalamount<<endl;

    return 0;
}