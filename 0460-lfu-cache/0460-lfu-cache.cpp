class Node{
public:
int key;
int val;
int cnt;
Node*next;
Node*prev;
Node(int key,int val){
  this->key=key;
  this->val=val;
  cnt=1;
}
};

class List{
public:
  Node* head;
  Node* tail;
  int size;

  List(){
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        size=0;
  }

  void insertNode(Node*node){
      Node*nextNode=head->next;
      node->next=nextNode;
      node->prev=head;
      head->next=node;
      nextNode->prev=node;
      size++;
  }

  void deleteNode(Node*node){
    Node*nextt=node->next;
    Node*prevv=node->prev;
    prevv->next=nextt;
    nextt->prev=prevv;
    size--;
  }
};

class LFUCache {
public:
  unordered_map<int,Node*>mp;
  unordered_map<int,List*>freq;

  int cap;
  int minFreq;
  int crr_sz;
    LFUCache(int capacity) {    
        cap=capacity;
        minFreq=0;
        crr_sz=0;
    }
    
    void updateFreqList(Node*node){
        mp.erase(node->key);
        freq[node->cnt]->deleteNode(node);
        if(node->cnt==minFreq and freq[node->cnt]->size==0) minFreq++;

        List* nextHigherFreqList=new List();
        if(freq.find(node->cnt+1)!=freq.end()){
            nextHigherFreqList=freq[node->cnt+1];
        }
        node->cnt+=1;
        nextHigherFreqList->insertNode(node);
        freq[node->cnt]=nextHigherFreqList;
        mp[node->key]=node;
    }

    int get(int key) {
        if(mp.find(key)!=mp.end()){
          Node*node=mp[key];
          int val=node->val;
          updateFreqList(node);
          return val;
        }
     return -1;
    }
    
    void put(int key, int value) {
        if(cap==0)return;
        if(mp.find(key)!=mp.end()){
            Node*node=mp[key];
            node->val=value;
            updateFreqList(node);
        }
        else{
            if(crr_sz==cap){
                List* list=freq[minFreq];
                mp.erase(list->tail->prev->key);
                list->deleteNode(list->tail->prev);
                crr_sz--;
            }
            crr_sz++;
            minFreq=1;
            List*listfreq=new List();
            if(freq.find(minFreq)!=freq.end()){
                listfreq=freq[minFreq];
            }
            Node*node=new Node(key,value);
            listfreq->insertNode(node);
            mp[node->key]=node;
            freq[minFreq]=listfreq;
            }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */