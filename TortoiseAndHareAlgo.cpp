/**************************************
07/07
Author - kreeeesh_17
Created : 13:43:39
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
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++){for(int j=0;j<col;j++) cout<<mat[i][j]<<" ";cout<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T> ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T> ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T> ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T> ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cout << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}  
ll mod=1e9+7;
ll power(ll a, ll b){if(b==0) return 1;if(b%2) return a*power(a,b-1)%mod;else{ll x= power(a,b/2);return (x*x)%mod;}}
ll inverse(ll x){return power(x,mod-2);}  
ll dx[ ] = { 1 , 0 , -1 , 0 } ;
ll dy[ ] = { 0 , 1 , 0 , -1 } ;
/********************************************************************************************************************************************************************************************/

// Definition of linked list node
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

// Finds and returns the middle node of the list (second middle if even length)
Node* findMiddle(Node* head) {
    if (head == nullptr) return nullptr;
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Detects cycle and returns the entry point of the cycle, or nullptr if no cycle
Node* detectCycleStart(Node* head) {
    if (!head) return nullptr;
    Node* slow = head;
    Node* fast = head;
    // Phase 1: detect cycle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (!fast || !fast->next) {
        return nullptr;  // no cycle
    }
    // Phase 2: find entry
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

void solve(){
    // Example usage (uncomment to test):
    // Node* n5 = new Node(5);
    // Node* n4 = new Node(4, n5);
    // Node* n3 = new Node(3, n4);
    // Node* n2 = new Node(2, n3);
    // Node* n1 = new Node(1, n2);
    // // create a cycle: 5->3
    // n5->next = n3;
    // Node* mid = findMiddle(n1);
    // pr(mid->data);            // prints middle element
    // Node* entry = detectCycleStart(n1);
    // pr(entry ? entry->data : -1);  // prints cycle entry or -1
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}
