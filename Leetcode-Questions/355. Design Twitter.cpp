class Twitter {
    int timeCounter;

    // SC = O(N)
    unordered_map<int, vector<pair<int, int>>> tweets;

    // SC = O(U * U)
    unordered_map<int, unordered_set<int>> following;
public:
    // TC = O(1)
    Twitter() {
        timeCounter = 0;
    }

    // TC = O(1)
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeCounter++, tweetId});
    }

    // TC = O(K)
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (auto &t : tweets[userId]) {
            pq.push(t);

            if (pq.size() > 10)
                pq.pop();
        }

        for (auto &id : following[userId]) {
            for (auto &t : tweets[id]) {
                pq.push(t);

                if (pq.size() > 10)
                    pq.pop();
            }
        }

        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

    // TC = O(1)
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    // TC = O(1)
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
