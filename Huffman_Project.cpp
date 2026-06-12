#include<bits/stdc++.h>
using namespace std;
static const long long MOD = 1e9 + 7;
class Nodefreq{
    public:
    char val;
    Nodefreq* left;
    Nodefreq* right;
    int freq;
    int id; // unique creation order for tie-breaking
    Nodefreq(char c , int f , int i) : val(c) , freq(f) , left(nullptr) ,right(nullptr) , id(i) {}
    Nodefreq() : val('*') , left(nullptr) , right(nullptr) , id(-1) {};
};
class Node{
    public:
    char ch;
    
    Node* left;
    Node* right;

    Node(char c) {
        ch = c;
        left = right = nullptr;
    }
    Node() : ch('\0' ) , left(nullptr) , right(nullptr){}
};
class Compare{
    public:
    bool operator()(Nodefreq* a, Nodefreq* b) const{
        if(a->freq == b->freq){
            return a->id > b->id;
        }
        return a->freq > b->freq;
    }
};
class huffman{
    private:
    Nodefreq* root;
    map<char,int> freq;
    Nodefreq* extractMin(queue<Nodefreq*>& q1, queue<Nodefreq*>& q2) {
    if (q1.empty()) {
        Nodefreq* t = q2.front(); q2.pop();
        return t;
    }
    if (q2.empty()) {
        Nodefreq* t = q1.front(); q1.pop();
        return t;
    }

    Nodefreq* a = q1.front();
    Nodefreq* b = q2.front();

    if (a->freq < b->freq ||
       (a->freq == b->freq && a->id < b->id)) {
        q1.pop();
        return a;
    } else {
        q2.pop();
        return b;
    }
}
long long choose2(long long x) {
    return (x * (x - 1) / 2) % MOD;
}
long long modexp(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
    public:
    huffman(){
        root = nullptr;
    }
    
    void insert(string arr){
        for(int i =0 ; i< arr.size() ; i++){
            freq[arr[i]]++;
        }
        for(auto &p : freq){
            cout<<(p.first)<<" "<<p.second<<endl;
        }
    }
    string newick(Nodefreq* node){
        if(!node) return "";
        if(!node->left && !node->right){
            return string(1 ,node->val);
        }
        string lefts = newick(node->left);
        string rights =newick(node->right);
        return "(" + lefts + "," +rights +")"; 
    }
   
    void buildhuffman(vector<pair<char,int>> &f){
        priority_queue <Nodefreq* , vector<Nodefreq*> , Compare> minheap;
        int id =0;
        sort(f.begin() , f.end());
        for (auto& p : f){
            minheap.push(new Nodefreq(p.first, p.second , id++));
        }
        while ((minheap.size() > 1)){
          Nodefreq* left = minheap.top() ;minheap.pop();
          Nodefreq* right = minheap.top() ;minheap.pop();

          if (left->freq == right->freq && left->id > right->id){
                swap(left, right);
          }

          Nodefreq* parent = new Nodefreq('\0', (left->freq + right->freq) , id++);
          parent->left = left;
          parent->right = right;
          minheap.push(parent);  
        }
        root =minheap.top();
        string s = newick(root);
        cout<<s<<endl;
    }
    void buildbinary(vector<pair<char ,string>> &f){
        Nodefreq* root1 = new Nodefreq();
        for(int i =0 ;i< f.size() ; i++){
            string s = f[i].second;
            Nodefreq* curr = root1;
            for(int  j =0 ; j< s.size() ; j++){
                if(s[j] == '1'){
                    if(!curr->right){
                            curr->right = new Nodefreq();
                           
                    }
                     curr =curr->right;
                }
                else{
                    if(!curr->left){
                            curr->left = new Nodefreq();
                        }
                        curr =curr->left;
                }
            }
            curr->val = f[i].first;
        }
        string p = newick(root1);
        cout<<p<<endl;
    }
    Node* buildnewick(const string&s , int & i){
        if(i>= s.size()) return nullptr;
        if(isalpha(s[i])){
            Node* node = new Node(s[i]);
            i++;
            return node;
        }
        if(s[i] == '(') {
                i++ ;
            Node* left = buildnewick(s , i);
            if (i < s.size() && s[i] == ',') i++ ;
            Node* right = buildnewick(s,i);
            if(i < s.size() && s[i] == ')') i++ ;
            Node* node = new Node();
            node->left =left;
            node->right =right;
            return node;
        }
        i++ ;
        return nullptr;

    }
    void decode(Node* root , const string & bits){
        string result = "";
        Node* curr = root ;
        for(char b : bits){
            if(b=='0' && curr->left){
                curr = curr->left;

            }
            else if (b=='1' && curr->right){
                curr = curr->right;
            }
            else if( !curr->left && !curr->right ){
                result += curr->ch;
                curr =root ;
            }
        }
        cout<<result<<endl;
    }
    void GenerateTreeEnhanced(queue<Nodefreq*> &q1,queue<Nodefreq*> &q2 , int currid){
        int curID = currid;
        while (q1.size() + q2.size() > 1) {
        Nodefreq* x = extractMin(q1, q2);
        Nodefreq* y = extractMin(q1, q2);

        Nodefreq* parent = new Nodefreq('*', x->freq + y->freq, curID++);
        parent->left = x;
        parent->right = y;

        q2.push(parent);
    }

         root = q1.empty() ? q2.front() : q1.front();
         cout<<newick(root)<<endl;
    }
    void Treecount(unordered_map<long long,long long> &cnt ,int n){
        priority_queue<long long, vector<long long>, greater<long long>> pq;
       
        for (auto &p : cnt)
        pq.push(p.first);

    long long ans = 1;

    while (pq.size() > 1) {
        long long f = pq.top(); pq.pop();

        if (cnt[f] >= 2) {
            ans = (ans * choose2(cnt[f])) % MOD;

            cnt[f] -= 2;
            long long nf = 2 * f;

            if (cnt[nf] == 0) pq.push(nf);
            cnt[nf]++;

            if (cnt[f] > 0) pq.push(f);
        } else {
            long long g = pq.top(); pq.pop();

            ans = (ans * cnt[f]) % MOD;
            ans = (ans * cnt[g]) % MOD;

            cnt[f]--;
            cnt[g]--;

            long long nf = f + g;
            if (cnt[nf] == 0) pq.push(nf);
            cnt[nf]++;

            if (cnt[g] > 0) pq.push(g);
        }
    }

    // Count left-right swaps at internal nodes
    ans = (ans * modexp(2, n - 1)) % MOD;

    cout << ans << "\n";
    }
};

int main(){
    string s;
    huffman HF;
    while(cin>>s){
        if(s == "BuildFrequencyTable"){
            string inp;
            cin>>inp;
            HF.insert(inp);
        }
        else if(s == "BuildTreeFromFrequencyTable"){
            vector<pair<char,int>> f;
            int n ;
            cin>>n;
            for(int i =0 ;i < n ;i++){
                char u;
                int v;
                cin>>u>>v;
                f.push_back({u,v});
            }
            HF.buildhuffman(f);
        }
        else if(s =="DeriveHuffmanTree"){
            vector<pair<char ,string>> f;
            int n;
            cin>>n;
            for(int i =0 ;i <n ;i++){
                char u ;
                string w;
                cin>>u >>w;
                f.push_back({u,w});
            }
            HF.buildbinary(f);
        }
        else if(s == "DecodeMessage"){
            string p;
            cin>>p;
            string bits ;
            cin>>bits;
            int i =0;
            Node* root = HF.buildnewick(p , i);
            HF.decode(root , bits);
        }
        else if(s=="GenerateTreeEnhanced"){
            int n;
            cin>>n;
            queue<Nodefreq*> q1,q2;
            int cid =0;
            for(int i =0 ;i<n ;i++){
                char c;
                int f;
                cin>>c>>f;
                q1.push(new Nodefreq(c,f,cid++));
            }
            HF.GenerateTreeEnhanced(q1 , q2 , cid);
        }
        else if(s == "CountHuffmanTrees"){
            int n;
            cin>>n;
            unordered_map<long long, long long> cnt;
            for (int i = 0; i < n; i++) {
                char c;
                long long f;
                cin >> c >> f;
                cnt[f]++;
            }
            HF.Treecount(cnt , n) ;        
        }
        else{
            break;
        }
    }
}