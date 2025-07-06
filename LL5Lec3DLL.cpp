/**************************************
06/07
Author - kreeeesh_17
Created : 01:28:04
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


// doubly link list is used in browser to navigate front and back 


struct Node{
    ll data;
    Node* next;
    Node* back;
    Node(ll data1, Node* next1, Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    Node(ll data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};

// O(N)

Node* convertarrtoll(vector<ll>&a){
    if(a.empty()) return NULL;
    Node* head=new Node(a[0]);
    Node* prev= head;
    for(int i=1;i<a.size();i++){
        Node* temp=new Node(a[i],nullptr,prev);
        prev->next=temp;  
        prev=temp;
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

// O(1)

Node* deletehead(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    delete prev;
    return head;
}

// O(N)

Node* deletetail(Node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* prev=tail->back;
    prev->next=nullptr;
    tail->back=nullptr;
    delete tail;
    return head;
}

// O(K)
Node* deleteatk(Node* head, ll k){
    Node* temp=head;
    ll count=0;
    while(temp!=NULL){
        count++;
        if(count==k){
            break;
        }   
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* next=temp->next;
    if(prev==NULL && next==NULL){
        delete temp;
        return NULL;
    }
    else if(prev==NULL){
        head=deletehead(head);
        return head;
    }
    else if(next==NULL){
        head=deletetail(head);
        return head;
    }
    else{
        prev->next=next;
        next->back=prev;
        temp->next=nullptr;
        temp->back=nullptr;
        delete temp;
        return head;
    }
}

// O(N)

void deletenode(Node* temp){  // temp cannot be head

    Node* prev=temp->back;
    Node* front=temp->next;
    if(front==NULL){
        prev->next=nullptr;
        front->back=nullptr;
        delete temp;
        return;
    }
    prev->next=front;
    front->back=prev;
    temp->next=nullptr;
    temp->back=nullptr;
    delete temp;
    return;
}

//O(1)

Node* insertbeforehead(Node* head, ll val){
    Node* newhead=new Node(val,head,nullptr);
    head->back=newhead;
    return newhead;
}

// O(N)

Node* insertbeforetail(Node* head, ll val){
    Node* tail = head;
    if(tail->next==NULL){
        return insertbeforehead(head,val);
    }
    while(tail->next->next!=NULL){
        tail=tail->next;
    }
    Node* newnode=new Node(val,tail->next,tail);
    tail->next->back=newnode;
    tail->next=newnode;
    return head;
}

// O(n)

Node* insertbeforek(Node* head, ll val, ll k){
    Node* temp=head;
    ll count=0;
    while(temp!=NULL){
        count++;
        if(count==k) break;
        temp=temp->next;
    }
    if(temp->back==NULL){
        head=insertbeforehead(head,val);
        return head;
    }
    else if(temp->next==NULL){
        head=insertbeforetail(head,val);
        return head;
    }
    else{
        Node* prev=temp->back;
        Node* newnode=new Node(val,temp,prev);
        prev->next=newnode;
        temp->back=newnode;
        return head;
    }
}

// O(1)

void insertbeforenode(Node* node, ll val){
    Node* prev=node->back;
    Node* newnode=new Node(val,node,prev);
    prev->next=newnode;
    node->back=newnode;
    return;
}

void solve(){
    vector<ll>a={1,2,5,8,7,9,1,12,5,7,10,1,13};    
    Node* head=convertarrtoll(a);
    printll(head);
    head=deletehead(head);
    printll(head);
    head=deletetail(head);
    printll(head);
    head=deleteatk(head,1);
    printll(head);
    head=deleteatk(head,10);
    printll(head);
    head=deleteatk(head,5);
    printll(head);
    deletenode(head->next->next);
    printll(head);
    head=insertbeforehead(head,91);
    printll(head);
    head=insertbeforetail(head,92);
    printll(head);
    vint b={2};
    Node* head2=convertarrtoll(b);
    head2=insertbeforetail(head2,17);
    printll(head2);
    head=insertbeforek(head,51,1);
    printll(head);
    head=insertbeforek(head,52,10);
    printll(head);
    head=insertbeforek(head,53,5);
    printll(head);
    insertbeforenode(head->next->next->next,57);
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