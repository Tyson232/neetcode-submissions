class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0, right = people.size() - 1;
        int boats = 0;

        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++;  // lightest person fits with heaviest
            }
            right--;     // heaviest always takes a boat
            boats++;
        }

        return boats;
    }
};