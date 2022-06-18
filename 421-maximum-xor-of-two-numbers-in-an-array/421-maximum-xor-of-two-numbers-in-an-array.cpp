class Solution {
    struct Node{
        Node* links[2];
        bool containskey(int bit)
        {
            return (links[bit]!=NULL);
        }
        Node* get(int bit)
        {
            return links[bit];
        }
        void put(int bit,Node* node)
        {
            links[bit]=node;
        }
    };
    class Trie {
        public:
        Node* root;
        Trie()
        {
            root=new Node();
        }
        void insert(int num)
        {   Node* node=root;
            for(int i=31;i>=0;i--)
            {
                int bit=((num>>i)&1);
                if(!node->containskey(bit))
                {  Node* temp=new Node();
                   node->put(bit,temp);
                }
                    node=node->get(bit);
                
            }
        }
        int getmax(int num)
        {
            int ans=0;
            Node* node=root;
            for(int i=31;i>=0;i--)
            {
                int bit=((num>>i)&1);
                
                if(node->containskey(1-bit))
                {
                    ans=ans|(1<<i);
                    node=node->get(1-bit);
                }
                else
                {
                    node=node->get(bit);
                }
            }
            return ans;
        }
    };
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            trie.insert(nums[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int x=trie.getmax(nums[i]);
            ans=max(ans,x);
        }
        return ans;
    }
};