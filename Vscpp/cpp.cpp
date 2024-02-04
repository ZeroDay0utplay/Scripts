#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef set<int> si;


#define INF 1e9
#define epsilon 1e-9
#define mod 1e9+7
#define PB push_back
#define mp make_pair
#define FOR(n) for (ll i=0; i<n; i++)



vl subset;
vector<vl> subsets;
vl permutation;
vector<vl> permutations;
vector<string> str_perm;
const ll n = 3; //change it for each permutation
bool chosen[n+1]; 
map<char,int> alphabet = {
        {'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7},
        {'h', 8}, {'i', 9}, {'j', 10}, {'k', 11}, {'l', 12}, {'m', 13},
        {'n', 14}, {'o', 15}, {'p', 16}, {'q', 17}, {'r', 18}, {'s', 19},
        {'t', 20}, {'u', 21}, {'v', 22}, {'w', 23}, {'x', 24}, {'y', 25}, {'z', 26}
    };

void generate_subset(ll from, ll to);
void generate_Permutations();
string bit_representation(ll n);
void str_permutation(string str, int i, int n);



template <typename T>
T binpow(T a, T b, T m=INF) {
    a %= m;
    T res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}


template <typename T>
vector<bool> bfs(vector<vector<T>> adj, T source_vertex){
    T n = adj.size(); // number of nodes

    queue<T> q;
    vector<bool> visited(n);
    vector<T> d(n), p(n);

    q.push(source_vertex);
    visited[source_vertex] = true;
    p[source_vertex] = -1;
    while (!q.empty()) {
        T v = q.front();
        q.pop();
        for (T u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
    return visited;
}

int nbNodes=100;
vector<bool> visited(nbNodes);
vector<vi> adj(nbNodes);
vi topsort;

void dfs(int node){
    visited[node]=true;
    for (int child: adj[node]){
        if (!visited[child]) // avoid cyclic behavior
            dfs(child);
    }
    //topsort.push_back(node); // DAG // Other way Indegree / Outdegree

}









int main(){
    
    //cout << fixed << setprecision(10);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif

    

    return 0;

}






















































void generate_subset(ll from, ll to){
    if (from==to+1){
        subsets.PB(subset);
        return;
    }
    subset.PB(from);
    generate_subset(from+1, to);
    subset.pop_back();
    generate_subset(from+1, to);
}




void generate_Permutations() {
    if (permutation.size() == n) {
        permutations.PB(permutation);
        return;
    } else {
        for (int i = 1; i <= n; i++) {
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            generate_Permutations();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}



string bit_representation(ll n){
    ll highest_exp = log2(n);
    string ans=  "";
    for (int i=highest_exp; i>=0; i--){
        ans += (n&(1<<i)) ? "1" : "0"; 
    }
    return ans;
}


ll set_k_bit_to_one(ll n, ll k){
    return (n | (1<<k));
}

ll set_k_bit_to_zero(ll n, ll k){
    return (n & ~(1<<k));
}

ll invert_k_bit(ll n, ll k){
    return (n ^ (1<<k));
}

bool is_power_of_2(ll n){
    return (n & (n-1)) == 0;
}





void str_permutation(string str, int i, int n)
{
    if (i == n - 1)
    {
        for (auto p: str_perm){
            if (p == str) return;
        }
        str_perm.PB(str);
        return;
    }
 
    for (int j = i; j < n; j++)
    {
        swap(str[i], str[j]);       
 
        str_permutation(str, i + 1, n);
 
        swap(str[i], str[j]);
    }
}
