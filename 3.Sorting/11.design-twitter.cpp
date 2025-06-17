class Twitter
{
private:
    int time;
    unordered_map<int, vector<pair<int, int>>> posts;
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter()
    {
        time = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        posts[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        priority_queue<pair<int, int>> pq;

        for (auto i : posts[userId])
            pq.push(i);

        for (auto i : following[userId])
            for (auto j : posts[i])
                pq.push(j);

        vector<int> feed;
        int cnt = 10;
        while (!pq.empty() && cnt)
        {
            feed.push_back(pq.top().second);
            pq.pop();
            cnt--;
        }

        return feed;
    }

    void follow(int followerId, int followeeId)
    {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        following[followerId].erase(followeeId);
    }
};

// optimized