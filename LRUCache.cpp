/**************************************
08/07
Author - kreeeesh_17
Created : 22:15:14
**************************************/
 
#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(ll i=0;i<n;i++)
#define ll long long int
#define inf 1000000000
#define endl '\n'
#define g(i,m,n) for(ll i=m;i<n;i++)
#define vint vector<ll>
#define ia(a,n) vint a(n);f(i,n)cin >>a[i];
#define asc(a) (a).begin(),(a).end()
#define desc(a) (a).rbegin(),(a).rend()
#define print(a) for(auto x :(a))cout << x<< ' ';cout<<endl;
#define pb(x) push_back(x);
#define pii pair<ll,ll>
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cout<<mat[i][j]<<" ";cout<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS)
template <class S, class T> ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T> ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T> ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T> ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cout << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]\n";}
ll mod=1e9+7;
ll power(ll a, ll b){if(b==0) return 1;if(b%2) return a*power(a,b-1)%mod;else{ll x= power(a,b/2);return (x*x)%mod;}}
ll inverse(ll x){return power(x,mod-2);}
ll dx[ ] = { 1 , 0 , -1 , 0 } ;
ll dy[ ] = { 0 , 1 , 0 , -1 } ;
/********************************************************************************************************************************************************************************************/

class LRUCache {
public:
    class Node{
        public:
            int key,val;
            Node* prev;
            Node* next;
            Node(int k, int v){
                key=k;
                val=v;
                prev=NULL;
                next=NULL;
            }    
    };
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    unordered_map<int,Node*>mp;
    int limit;

    // O(1)

    void deletenode(Node* oldnode){
        Node* oldnext=oldnode->next;
        Node* oldprev=oldnode->prev;
        oldprev->next=oldnext;
        oldnext->prev=oldprev;
    }

    // O(1)

    void addnode(Node* newnode){
        Node* oldnext=head->next;
        oldnext->prev=newnode;
        head->next=newnode;
        newnode->next=oldnext;
        newnode->prev=head;
    }

    LRUCache(int capacity) {
        limit=capacity;
        head->next=tail;
        tail->prev=head;  
    }
    
    // O(1)

    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        int ans=mp[key]->val;
        Node* temp=mp[key];
        mp.erase(key);
        deletenode(temp);
        addnode(temp);
        mp[key]=temp;
        return ans;
    }
    
    // O(1)

    void put(int key, int val) {
        if(mp.find(key)!=mp.end()){
            Node* oldnode=mp[key];
            deletenode(oldnode);
            mp.erase(key);
        }
        if(mp.size()==limit){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        Node* newnode=new Node(key,val);
        addnode(newnode);
        mp[key]=newnode;
    }
};

void solve(){

}

int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}