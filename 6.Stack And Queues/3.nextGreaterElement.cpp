// Stack class implementation
class Stack
{
private:
    vector<int> array; // Stores stack elements
    int size = -1;     // Tracks the top index of the stack

public:
    Stack() : size(-1) {} // Constructor initializes size to -1

    void push(int val) // Pushes an element onto the stack
    {
        size++;
        array.push_back(val);
    }

    int pop() // Removes and returns the top element of the stack
    {
        int value = array[size]; // Store the top element
        array.pop_back();        // Remove the top element
        size--;                  // Decrement the size
        return value;            // Return the popped value
    }

    int top() // Returns the top element of the stack without removing it
    {
        return array[size];
    }

    bool empty() // Checks if the stack is empty
    {
        return size == -1;
    }
};

// Function to find the next greater element for each element in nums1 based on nums2
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    Stack s;            // Custom stack to store elements
    map<int, int> map;  // Stores the next greater element for each number in nums2
    vector<int> output; // Stores the final result

    // Iterate through nums2 in reverse order
    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        // Remove elements from the stack that are smaller than or equal to nums2[i]
        while (!s.empty() && s.top() <= nums2[i])
        {
            s.pop();
        }

        // If stack is empty, no greater element exists; otherwise, store the top element
        if (s.empty())
        {
            map[nums2[i]] = -1; // No next greater element
        }
        else
        {
            map[nums2[i]] = s.top(); // Next greater element
        }

        // Push the current element onto the stack
        s.push(nums2[i]);
    }

    // Iterate through nums1 to find the next greater elements
    for (int i = 0; i < nums1.size() - 1; i++)
    {
        output.push_back(map[nums1[i]]);
    }

    return output;
}
