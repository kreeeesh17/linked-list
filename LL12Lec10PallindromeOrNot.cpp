/**************************************
07/07
Author - kreeeesh_17
Created : 13:41:31
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

struct Node{
    ll data;
    Node* next;
    Node(ll data1, Node* next1){
        data=data1;
        next=next1;
    }
    Node(ll data1){
        data=data1;
        next=nullptr;
    }
};
// O(N)

Node* convertarrtoll(vector<ll>&a){
    if(a.empty()) return NULL;
    Node* head=new Node(a[0]);
    Node* mover=head;
    for(ll i=1;i<a.size();i++){
        Node* temp=new Node(a[i]);
        mover->next=temp ;
        mover=temp;
    }
    return head;
}

// O(N)

void printll(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

// O(N)

Node* reverseall(Node* head){
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

// O(N)

bool isPallindrome(Node* head){
    // Tortoise and hare algo
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* newhead=reverseall(slow->next);
    Node* first=head;
    Node* second=newhead;
    while(second!=NULL){
        if(first->data!=second->data){
            reverseall(newhead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverseall(newhead);
    return true;
}

void solve(){
    vint a={5,4,3,3,4,5};
    Node* head=convertarrtoll(a);
    printll(head);
    head=reverseall(head);
    printll(head);
    if(isPallindrome(head)){
        cout<<"Pallindrome"<<endl;
    }
    else{
        cout<<"No Pallindrome"<<endl;
    }
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