#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt","r", stdin)
    //读文件
    freopen("input.txt","r",stdout)
    //写文件
    
    
    printf("%.9f\n",x)
    //输出的是九位小数

    typedef long long ll;
    //把long long数据类型定义为ll

    #define f first;
    //把first函数定义为f

    vector<int> v = {4,2,23,3,24,4,5};
    sort(v.begin(),v.end())
    //begin和end没有参数

    //vector不可以任意两个索引之间排序，但是list可以

    //string也可以sort
    string s = "monkey";
    sort(s.begin(), s.end())
    

    for(int x: v){
        cout<<x<<"\n";
    }
    //把vector v里的每一个元素都打印出来
    cout<<"1";
    
    
    for(vector<int>::iterator it = name.begin(); it !=name.end(); ++it){
        cout<< *it;
    }
    //替代加强for循环
    
    string a = "ILOVEUSACO";
    int pos = a.find("USACO");
    //如果找不到返回npos
    if(a.find("USACO")!= string ::nops){
        cout<<"found";
    }

    reverse(a.begin(), a.end());

    string s = "123"
    int number = stoi(s);

    int number = 123;
    string s = to_string(number);

    a.erase(2,1);
    a.insert(2,"XX");
    
    a.substr(i);
    //只有一个input 代表是从i到最后






int N, M;
cin >> N >> M;

vector<vector<int>> grid(N, vector<int>(M));

for (int row = 0; row < N; row++) {
    for (int col = 0; col < M; col++) {
        cin >> grid[row][col];
    }
}
//2D array模版









#include <bits/stdc++.h>
using namespace std;

//input;
string s;
cin >> s;

string s;
getline(cin, s);

int n = s.size();
int n = s.length();


//example:
U S A C O
0 1 2 3 4

cout << s[0];   // U
cout << s[2];   // A
cout << s[s.size() - 1]; //o


//change:
string s = "USACO";

s[0] = 'X';
cout << s;


//print:
for (int i = 0; i < s.size(); i++) {
    cout << s[i] << endl;
}

for (char ch : s) {
    cout << ch << endl;
}


//count char:

int count = 0;
for (char ch : s) {
    if (ch == 'A') {
        count++;
    }
}
cout << count;


//compare
string a = "ABC";
string b = "ABC";

if (a == b) {
    cout << "Same";
}


//"ABC" < "ABD"



a += "ABC";   // append at end

// a = “ABCABC”;

substring function:
a.substr(2, 3);


//find string in a string
string s = "ILOVEUSACO";
int position = s.find("USXCO");
//返回首字母的索引

if (s.find("USACO") != string::npos) {
    cout << "Found";
}




// Reverse

// s = “ABCBA”

string reversed = s;

reverse(reversed.begin(), reversed.end());

if (s == reversed) {
    cout << "Palindrome";
} else {
    cout << "Not palindrome";
}


//转换
string s = "123";

int number = stoi(s);


int number = 123;

string s = to_string(number);


//插入删除
string s = "ABCDE";

s.erase(2, 1);

cout << s;  

s.insert(2, "XX");




//例：

string s = “AAABBBBBCCD”;
cin >> s;

int current = 1;
int answer = 1;

for (int i = 1; i < s.size(); i++) {
    if (s[i] == s[i - 1]) {
        current++;
    } else {
        current = 1;
    }

    answer = max(answer, current);
}

cout << answer;




//2d array：
int grid[100][100];
grid[0][0] = 5;

1 2 3 
4 5 6
7 8 9 


//模版：用vector
int N, M;
cin >> N >> M;

vector<vector<int>> grid(N, vector<int>(M));

for (int row = 0; row < N; row++) {
    for (int col = 0; col < M; col++) {
        cin >> grid[row][col];
    }
}


int N, M;
cin >> N >> M;

vector<string> grid(N);

for (int row = 0; row < N; row++) {
    cin >> grid[row];
}


for (int row = 0; row < N; row++) {
    for (int col = 0; col < M; col++) {
        cout << grid[row][col];
    }

    cout << endl;
}

int a =0;
cout << a;

//复制：
vector<string> copyGrid = grid;

//转制：把表格竖过来
vector<vector<int>> result(M, vector<int>(N));

for (int row = 0; row < N; row++) {
    for (int col = 0; col < M; col++) {
        result[col][row] = grid[row][col];
    }
}
struct Person {
int height;
int weight;
};

bool cmp (Person a, Person b) {
return a.height < b.height;
}
   

return 0;



}