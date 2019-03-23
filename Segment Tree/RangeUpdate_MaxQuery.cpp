//Lazy propagation for range update for max query

#include <bits/stdc++.h>
#define MAX 2000001
#define left (2*i+1)
#define right (2*i+2)
#define mid ((l+r)>>1)
using namespace std;

int seg[MAX],lazy[MAX];

int clear_lazy(int i){
    lazy[left] = lazy[right] = lazy[i];
    seg[i] = lazy[i];
    lazy[i] = 0;
    return 0;
}

int update(int i,int l,int r,int x,int y,int v){
    if (lazy[i]) clear_lazy(i);
    if (l>r || y<l || x>r) return 0;
    if (l>=x && r<=y){
        seg[i] = v;
        lazy[left] = lazy[right] = v;
        return 0;
    }
    update(left,l,mid,x,y,v);
    update(right,mid+1,r,x,y,v);
    seg[i] = max(seg[left],seg[right]);
    return 0;
}

int query(int i,int l,int r,int x,int y){
    if (lazy[i]) clear_lazy(i);
    if (l>r || y<l || x>r) return 0;
    if (l>=x && r<=y) return seg[i];
    return max(query(left,l,mid,x,y),query(right,mid+1,r,x,y));
}

update(1,1,n,l,r,val);
int qp = query(1,1,n,r,r);
