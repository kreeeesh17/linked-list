/**************************************
06/07
Author - kreeeesh_17
Created : 13:07:48
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

// add two numbers

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

// O(max(n1,n2))

Node* add2numbers(Node* num1, Node* num2){
    Node* dummy=new Node(-1);
    Node* curr=dummy;
    Node* temp1=num1;
    Node* temp2=num2;
    ll carry=0;
    while(temp1!=NULL || temp2!=NULL){
        ll sum=carry;
        if(temp1) sum+=temp1->data;
        if(temp2) sum+=temp2->data;
        Node* newnode=new Node(sum%10);
        carry=sum/10;
        curr->next=newnode;
        curr=curr->next;
        if(temp1) temp1=temp1->next;
        if(temp2) temp2=temp2->next;
    }
    if(carry){
        Node* newnode=new Node(carry);
        curr->next=newnode;
    }
    return dummy->next;
}


void solve(){
    vint a={2,4,6};
    vint b={3,8,7};
    vint c={3,5};
    vint d={4,5,9,9};
    Node* head1=convertarrtoll(a);
    Node* head2=convertarrtoll(b);
    Node* head3=convertarrtoll(c);
    Node* head4=convertarrtoll(d);
    printll(add2numbers(head1,head2));
    printll(add2numbers(head3,head4));

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