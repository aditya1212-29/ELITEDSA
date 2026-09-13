class MyCalendar {
public:
    map<int, int>mp;
    MyCalendar() {
        
    }
    bool book(int startTime, int endTime) {
        mp[startTime] += 1;
        mp[endTime] -= 1;
        int cnt = 0;
        for(auto it : mp){
            cnt += it.second;
            if(cnt == 2){
                mp[startTime]--;
                mp[endTime]++;
                if(!mp[startTime]) mp.erase(startTime);
                if(!mp[endTime]) mp.erase(endTime);
                return 0;
            }
        }
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */