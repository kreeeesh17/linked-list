/**************************************
05/07
Author - kreeeesh_17
Created : 19:16:43
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
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;  
}

// O(1)

Node* insertathead(Node* head, ll val){
    Node* temp=new Node(val,head);
    return temp;
}

//O(N)

Node* insertatend(Node* head, ll val){
    if(head==NULL){
        return new Node(val);
    }
    Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newnode=new Node(val);
    temp->next=newnode;
    return head;

}

//O(k)

Node* insertatk(Node* head, ll k, ll val){
    if(head==NULL){
        if(k==1){
            return new Node(val);
        }
        else{
            return NULL;
        }
    }
    if(k==1){
        Node* temp=new Node(val,head);
        return temp;
    }
    ll count=0;
    Node* temp=head;
    while(temp!=NULL){
        count++;
        if(count==k-1){
            Node* newnode=new Node(val,temp->next);
            temp->next=newnode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

// O(N)

Node* insertbeforeel(Node* head, ll el, ll val){
    if(head==NULL){
        return NULL;
    }
    if(head->data==val){
        Node* temp=new Node(val,head);
        return temp;
    }
    Node* temp=head;
    while(temp!=NULL){
        if(temp->next->data==el){
            Node* newnode=new Node(val,temp->next);
            temp->next=newnode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

void solve(){
    vector<ll>a={1,2,5,8,7,9,1,12,5,7,10,1,13};    
    Node* head= convertarrtoll(a);
    printll(head);    
    head=insertathead(head,15);
    printll(head);
    head=insertatend(head,27);
    printll(head);
    head=insertatk(head,3,11);
    printll(head);
    vint b={};
    Node* head2=convertarrtoll(b);
    head2=insertatk(head2,1,1);
    printll(head2);
    head=insertbeforeel(head,12,69);
    printll(head);
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