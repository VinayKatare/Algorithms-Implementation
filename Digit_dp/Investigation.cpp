//https://vjudge.net/problem/LightOJ-1068

/// How many numbers x are there in the range a to b, where the digit d occurs exactly k times in x?

#include <bits/stdc++.h>
using namespace std;

vector<int> num;
int a, b, d, k;
int DP[12][90][90][2];
/// DP[pos][val][sum][f] = Number of valid numbers <= b from this state
/// p = current position from left side (zero based)
/// val= value so far
/// sum = sum of digits we have placed the digit d so far
/// f = the number we are building has already become smaller than b? [0 = no, 1 = yes]

int call(int pos,int val, int sum, int f){

    if(pos == num.size()){
        if(val==0 && sum==0){
        	return 1;
        } 
        return 0;
    }

    if(DP[pos][val][sum][f] != -1){
    	return DP[pos][val][sum][f];
    } 
    int res = 0;

    int LMT;

    if(f == 0){
        LMT = num[pos];
    } else {
        LMT = 9;
    }

    for(int dgt = 0; dgt<=LMT; dgt++){
        int nf = f;
        if(f == 0 && dgt < LMT) nf = 1;
        res += call(pos+1, (val*10+dgt) % k, (sum+dgt) % k, nf);
    }
    return DP[pos][val][sum][f] = res;
}

int solve(int b){
    num.clear();
    while(b>0){
        num.push_back(b%10);
        b/=10;
    }
    reverse(num.begin(), num.end());

    memset(DP, -1, sizeof(DP));
    int res = call(0, 0, 0, 0);
    return res;
}

int main () {
	int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> a >> b >> k;
        int ans;
        if (k > 83)
            ans = 0;
        else ans = solve(b) - solve(a - 1);
        cout << "Case " << i << ": " << ans << endl;
    }

    return 0;
}
