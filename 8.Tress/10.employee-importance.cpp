/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution
{
public:
    int getImportance(vector<Employee *> employees, int id)
    {
        unordered_map<int, Employee *> mp;

        for (auto emp : employees)
        {
            mp[emp->id] = emp;
        }

        queue<Employee *> q;

        q.push(mp[id]);

        int ans = 0;
        while (!q.empty())
        {
            Employee *cur = q.front();
            q.pop();

            ans += cur->importance;

            for (auto sub : cur->subordinates)
                q.push(mp[sub]);
        }

        return ans;
    }
};