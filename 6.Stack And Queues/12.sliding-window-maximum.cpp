class Dequeue
{
private:
    int front;
    int rear;
    vector<int> queue_Array;

public:
    Dequeue() : front(0), rear(0) {}

    bool isempty()
    {
        return front == rear;
    }

    void push_back(int value)
    {
        if (rear == queue_Array.size())
            queue_Array.push_back(value);
        else
            queue_Array[rear] = value;
        rear++;
    }

    int pop_front()
    {
        if (isempty())
        {
            throw underflow_error("Queue is empty");
        }
        return queue_Array[front++];
    }

    int pop_rear()
    {
        if (isempty())
        {
            throw underflow_error("Queue is empty");
        }
        return queue_Array[--rear];
    }

    int front()
    {
        if (isempty())
        {
            throw underflow_error("Queue is empty");
        }
        return queue_Array[front];
    }

    int rear()
    {
        if (isempty())
        {
            throw underflow_error("Queue is empty");
        }
        return queue_Array[rear - 1];
    }
};

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        Dequeue q;
        int size = nums.size();
        vector<int> output;

        for (int i = 0; i < size; i++)
        {
            if (!q.isempty() && q.front() == i - k)
            {
                q.pop_front();
            }

            while (!q.isempty() && nums[i] > nums[q.rear()])
            {
                q.pop_rear();
            }

            q.push_back(i);

            if (i >= k - 1)
            {
                output.push_back(nums[q.front()]);
            }
        }

        return output;
    }
};
