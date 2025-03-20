#include <iostream>
#include <vector>

using namespace std;
class Stack
{
private:
    vector<int> array;

public:
    void push(int val)
    {
        array.push_back(val);
    }

    int pop()
    {
        int value = array.back();
        array.pop_back();
        return value;
    }

    int top()
    {
        return array.back();
    }

    bool empty()
    {
        return array.empty();
    }
};

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        Stack s;
        for (int i = 0; i < asteroids.size(); i++)
        {
            bool destroyed = false;

            // Continue handling collision until either the stack is empty or there's no collision
            while (!s.empty() && s.top() > 0 && asteroids[i] < 0)
            {
                int topAsteroid = s.top();

                // If the top asteroid in the stack is larger
                if (topAsteroid > abs(asteroids[i]))
                {
                    destroyed = true; // Current asteroid is destroyed
                    break;
                }
                // If both asteroids have the same magnitude, both are destroyed
                else if (topAsteroid == abs(asteroids[i]))
                {
                    s.pop(); // Pop the top asteroid as they destroy each other
                    destroyed = true;
                    break;
                }
                // If the current asteroid is larger, pop the top and continue
                else
                {
                    s.pop();
                }
            }

            // If the current asteroid isn't destroyed, push it into the stack
            if (!destroyed)
            {
                s.push(asteroids[i]);
            }
        }

        // Collect the remaining asteroids in the stack to output
        vector<int> output;
        while (!s.empty())  
        {
            output.insert(output.begin(), s.pop());
        }

        return output;
    }
};

int main()
{

    return 0;
}