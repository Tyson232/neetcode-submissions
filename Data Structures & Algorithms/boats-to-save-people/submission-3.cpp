class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        vector<bool> vis(n,false);
        int count = 0;
        int boats = 0;
        int i = 0;
        while(count < n){
            vis[i] = true;
            if(people[i] == limit){
                boats++;
                count++;
            }
            else{
                int maxw = people[i];
                int maxIndex = -1;
                for(int j = i+1; j < n; j++){
                    if(vis[j] == false && i != j && people[i] + people[j] <= limit ){
                        int maxn = people[i] + people[j];
                        if(maxn > maxw){
                            maxw = maxn;
                            maxIndex = j;
                        }
                    }
                }
                if(maxIndex == -1){
                    boats++;
                    count++;
                }
                else{
                vis[maxIndex]=true;
                boats++;
                count += 2;
                }
            }
            while(vis[i]){
                i++;
            }
        }
        return boats;
    }
};