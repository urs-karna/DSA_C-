class LRUCache {
public:
    class node {
     public:
        int key;
        int val;
        node *prev;
        node * next;
        node(int key1,int val1) {

            key = key1;
            val=val1;
        }

    };

    node *dumHead = new node(-1,-1);
    node *dumTail = new node(-1,-1);
    int cap;
    unordered_map<int,node*>mp;


    void delete_node(node * temp) {

        node * prevNode= temp->prev;
        node* nextNode= temp->next;
        prevNode-> next=nextNode;
        nextNode->prev= prevNode;
    }

    void add_next_to_head( node * newNode) {
         node * currentNode= dumHead->next;
          newNode->next=currentNode;
          newNode->prev= dumHead;
          dumHead->next= newNode;
          currentNode->prev=newNode;

    }
    LRUCache(int capacity) {
        cap= capacity;
        dumHead->next =dumTail;
        dumTail->prev = dumHead;

        
    }
    
    int get(int key) {
      if(mp.find(key) == mp.end()) return -1;
      else {
        node* newNode= mp[key];
        delete_node(newNode);
        add_next_to_head(newNode);
       return newNode->val;
      }  
    }
    
    void put(int key, int value) {

    if(mp.find(key) != mp.end()) {
        node* newNode= mp[key];
         newNode->val= value;
         delete_node(newNode);
         add_next_to_head(newNode);
         return;

    }

    if(mp.size() == cap) {
         node* newNode= dumTail->prev;
         mp.erase(newNode->key);
         delete_node(newNode);

    } 
   
     node * newNode= new node(key,value);
    mp[key]= newNode;
    add_next_to_head(newNode);
    
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */