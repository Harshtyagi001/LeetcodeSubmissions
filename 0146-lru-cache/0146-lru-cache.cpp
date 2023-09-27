
class LRUCache {
public:

class DLList{
public:
  int key;
  int val;
  DLList* next;
  DLList* prev;
  DLList(int key,int val){
      this->key=key;
      this->val=val;
  }
};
    int cap;
    unordered_map<int,DLList*>mp;
    DLList* head=new DLList(-1,-1);
    DLList* tail=new DLList(-1,-1);
    
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void insertNode(DLList*node){
        DLList* nextNode=head->next;
        node->next=nextNode;
        node->prev=head;
        nextNode->prev=node;
        head->next=node;
    }
    
    void deleteNode(DLList*node){
        DLList* preNode=node->prev;
        DLList* nextNode=node->next;
        preNode->next=nextNode;
        nextNode->prev=preNode;
    }

    int get(int key) {
        if(mp.find(key)!=mp.end()){
          DLList* node=mp[key];
            mp.erase(key);  
          int val=node->val;
          deleteNode(node);  // delete from the prev pos
          insertNode(node);  // make it most recently used by inserting after head
          mp[key]=head->next; // inplace update in map
          return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
         DLList* existNode=mp[key]; // find where it exits
         mp.erase(key);
         deleteNode(existNode);  // delete existing node
        }
       else if(mp.size()==cap){
            mp.erase(tail->prev->key); // LRU key map se delete krdo
            deleteNode(tail->prev);  // LRU node bhi linked list se delete krdo
        }
        insertNode(new DLList(key,value));   // make it most recent used
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */