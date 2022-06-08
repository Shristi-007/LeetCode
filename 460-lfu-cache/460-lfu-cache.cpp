struct Node{
    int key,value,cnt;
    Node *next;
    Node *prev;
    Node(int _key,int _value)
    {
        key=_key;
        value=_value;
        cnt=1;
    }
};
struct List{
    int size;
    Node *head;
    Node *tail;
    List(){
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    
    void addFront(Node *node)
    {
        Node *temp=head->next;
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;
        size++;
    }
    
    void removeNode(Node *node)
    {
        Node *delprev=node->prev;
        Node *nextprev=node->next;
        delprev->next=nextprev;
        nextprev->prev=delprev;
        size--;
    }
};

class LFUCache {
    map<int,Node*>keyNode;
    map<int,List*>freq;
    int capacity,cursize,minfreq;
public:
    LFUCache(int capacity) {
        this->capacity=capacity;
        cursize=0;
        minfreq=0;
        
    }
    
    void update(Node *node)
    {
        keyNode.erase(node->key);
        freq[node->cnt]->removeNode(node);
        if((node->cnt==minfreq)&&(freq[node->cnt]->size==0))
        {
            minfreq++;
        }
        
        List *nextlist=new List();
        if(freq.find(node->cnt+1)!=freq.end())
        {
            nextlist=freq[node->cnt+1];
        }
        node->cnt+=1;
        nextlist->addFront(node);
        freq[node->cnt]=nextlist;
        keyNode[node->key]=node;
    }
    
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end())
        {
            
            Node *node=keyNode[key];
            int ans=node->value;
            update(node);
            return ans;
        }
        else
            return -1;
        
    }
    
    void put(int key, int value) {
        if(capacity==0)
            return;
        if(keyNode.find(key)!=keyNode.end())
        {   Node *node=keyNode[key];
            node->value=value;
            update(node);
        }
        else
        {
            if(cursize==capacity)
            {
                List *list=freq[minfreq];
                keyNode.erase(list->tail->prev->key);
                freq[minfreq]->removeNode(list->tail->prev);
                cursize--;
            }
            cursize++;
            minfreq=1;
            List *newlist=new List();
            if(freq.find(minfreq)!=freq.end())
            {
                newlist=freq[minfreq];
            }
            Node *node=new Node(key,value);
            newlist->addFront(node);
            keyNode[key]=node;
            freq[minfreq]=newlist;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */