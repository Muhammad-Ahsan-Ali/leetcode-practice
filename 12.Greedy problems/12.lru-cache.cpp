// Structure for a doubly linked list node
struct node
{
    int key, value; // Stores key-value pair
    node *next;     // Pointer to next node
    node *prev;     // Pointer to previous node

    // Default constructor initializes node with invalid values and null pointers
    node() : key(-1), value(-1), next(nullptr), prev(nullptr) {}

    // Parameterized constructor initializes node with given key and value
    node(int k, int val) : key(k), value(val), next(nullptr), prev(nullptr) {}
};

class LRUCache
{
private:
    int size;            // Maximum capacity of the cache
    node *head;          // Dummy head node of the doubly linked list
    node *tail;          // Dummy tail node of the doubly linked list
    map<int, node *> mp; // Hash map to store key-node pairs for O(1) access
    int curSz;           // Current size of the cache

    // Function to remove a node from the doubly linked list
    void delNode(node *cur)
    {
        node *prev = cur->prev;
        node *next = cur->next;
        prev->next = next; // Update previous node's next pointer
        next->prev = prev; // Update next node's prev pointer
    }

    // Function to insert a node right after the head (most recently used position)
    void insertAfterHead(node *cur)
    {
        node *headNext = head->next;
        head->next = cur;
        cur->prev = head;
        headNext->prev = cur;
        cur->next = headNext;
    }

public:
    // Constructor to initialize LRU cache with given capacity
    LRUCache(int capacity)
    {
        curSz = 0; // Initialize current size to 0
        size = capacity;
        head = new node(); // Create dummy head node
        tail = new node(); // Create dummy tail node
        head->next = tail; // Link head to tail
        tail->prev = head; // Link tail to head
    }

    // Function to get the value associated with a key
    int get(int key)
    {
        if (mp.find(key) == mp.end()) // If key is not found in the cache
        {
            return -1; // Return -1 (not found)
        }
        else
        {
            node *cur = mp[key];  // Get the node associated with the key
            delNode(cur);         // Remove it from its current position
            insertAfterHead(cur); // Move it to the most recently used position
            return cur->value;    // Return the value
        }
    }

    // Function to insert or update a key-value pair in the cache
    void put(int key, int value)
    {
        if (mp.find(key) != mp.end()) // If key already exists in cache
        {
            node *cur = mp[key];
            delNode(cur);         // Remove the existing node
            insertAfterHead(cur); // Move it to the most recently used position
            cur->value = value;   // Update its value
        }
        else
        {
            if (curSz == size) // If cache is full
            {
                node *LRUNode = tail->prev; // Get the least recently used node
                delNode(LRUNode);           // Remove it from the list
                mp.erase(LRUNode->key);     // Remove it from the map
                delete LRUNode;             // Free memory
            }
            else
            {
                curSz++; // Increase current size
            }

            node *cur = new node(key, value); // Create a new node
            mp[key] = cur;                    // Store it in the map
            insertAfterHead(cur);             // Insert at the most recently used position
        }
    }
};
