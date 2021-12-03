#include<bits/stdc++.h>
using namespace std;

void solve(string a, string b){
    if(a.size()>b.size())
        swap(a,b);
    string s = "";
    int carry = 0, dif = b.size()-a.size(), sum = 0;
    for(int i = a.size()-1; i >= 0; i--){
        sum = (b[i+dif]-'0') - (a[i]-'0') - carry;
        if(sum<0){
            carry = 1;
            sum += 10;
        } else{
            carry = 0;
        }
        s.push_back(sum+'0');
    }
    for(int i = dif-1; i >= 0; i--){
        sum = (b[i]-'0') - carry;
        if(i == 0 && sum==0)
            continue;
        else{
            if(sum<0){
                carry = 1;
                sum += 10;
            } else{
                carry = 0;
            }
            s.push_back(sum+'0');
        }
            
    }
    reverse(s.begin(),s.end());
    cout << s << endl;
}

int main(){
    string a,b;
    cin >> a >> b;
    solve(a,b);
    return 0;
}
