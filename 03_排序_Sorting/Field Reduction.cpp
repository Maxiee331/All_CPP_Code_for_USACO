#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, x, y, differencex = 0, differencey = 0;
    cin>>N;
    vector<int> xpos;
    vector<int> ypos;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        xpos.push_back(x);
        ypos.push_back(y);
    }
    sort(xpos.begin(), xpos.end());
    sort(ypos.begin(), ypos.end());

    if((xpos[1]-xpos[0])>=(xpos[N-1]-xpos[N-2])){
        differencex = xpos[N-1]-xpos[1];
    }
    else{
        differencex = xpos[N-2]-xpos[0];
    }
    if((ypos[1]-ypos[0])>=(ypos[N-1]-ypos[N-2])){
        differencey = ypos[N-1]-ypos[1];
    }
    else{
        differencey = ypos[N-2]-ypos[0];
    }

    cout<<differencex*differencey<<endl;
    return 0;
}