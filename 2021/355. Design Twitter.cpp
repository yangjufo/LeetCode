
class Twitter {
public:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, set<pair<int, int>>> tweets;
    int index;    
    /** Initialize your data structure here. */
    Twitter() {
        index = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {        
        tweets[userId].insert({index, tweetId});
        index++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> feed;                        
        for (auto iter = tweets[userId].rbegin(); iter != tweets[userId].rend() && feed.size() < 10; iter++) {
            feed.push(*iter);            
        }            
        for (int f : following[userId]) {
            for (auto iter = tweets[f].rbegin(); iter != tweets[f].rend() && (feed.size() < 10 || iter->first > feed.top().first); iter++) {
                feed.push(*iter);
                if (feed.size() > 10) {
                    feed.pop();
                }
            }
        }
        vector<int> res;
        while (!feed.empty()) {
            res.push_back(feed.top().second);
            feed.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
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