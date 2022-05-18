 #include<iostream>;
 using namespace std;
 class BinaryNumTrie{
        public :
        class  binNode{
            public :
            vector<pair<int, binNode*>> child;
            binNode(){
                child.push_back(make_pair(-1,nullptr));
                child.push_back(make_pair(-1,nullptr));
            }
        };
        binNode* root;
        BinaryNumTrie(){root = new binNode();}
        void insert(int num){
                insert(root,num,31);
        }
        int searchClosest(int num){
            // num = num xor INT_MAX;
            searchClosest(root,num,31);
            return num;
        }
        void searchClosest(binNode *node, int &num, int bit){ 
            if(bit<0){return;}
            int bitVal = (num>>bit) & 1 ;
            if(node->child[bitVal].first == bitVal){
                searchClosest(node->child[bitVal].second,num,bit-1);
            }else{
                num = num xor (1<<bit);
                searchClosest(node->child[!bitVal].second,num,bit-1);
            }
        }
        void insert(binNode *node, int num, int bit){
            if(bit<0){return;}
            int bitVal = (num>>bit) & 1 ;
            if(node->child[bitVal].first == -1){
                node->child[bitVal].first = bitVal;
                node->child[bitVal].second = new binNode();
                insert(node->child[bitVal].second,num,bit-1);
            }else{
                insert(node->child[bitVal].second,num,bit-1);
            }
        }
};

int maxAND (int arr[], int N)
    {
        BinaryNumTrie bt;
        unsigned int maxAnd;
        int a,b,temp;
        
        for(int i=0; i<N; i++){
            bt.insert(arr[i],i);
        }
        maxAnd = 0;
        for(int i=0; i<N; i++){
            temp = bt.searchClosest(arr[i]);
            cout<<arr[i]<<" "<<temp<<" "<<(arr[i]&temp)<<endl;
            if(temp & arr[i]> maxAnd){
                maxAnd = temp & arr[i];
            }
        }
        return maxAnd;
    }