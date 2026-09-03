class Solution {
public:
    static bool mycmp(pair<int, pair<int, int>> &p1, pair<int, pair<int, int>> &p2){
        return p1.second.first < p2.second.first;
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();
        vector<pair<int, pair<int, int>>> p(n);
        for(int i = 0 ; i < trips.size(); i++){
            p[i].first = trips[i][0];
            p[i].second.first = trips[i][1];
            p[i].second.second = trips[i][2];
        }
        sort(p.begin(), p.end(), mycmp);
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>>pq;
        if(p[0].first <= capacity){
        pq.push({p[0].second.second, p[0].first});
        capacity -= p[0].first;
        }
        else return 0;
        for(int i = 1 ; i < n; i++){
            while(!pq.empty() && p[i].second.first >= pq.top().first){
                capacity += pq.top().second;
                pq.pop();
            }
            if(p[i].first <= capacity){
                    capacity -= p[i].first;
                    pq.push({p[i].second.second, p[i].first});
            }
            else return 0;
        }
        return 1;
    }
};