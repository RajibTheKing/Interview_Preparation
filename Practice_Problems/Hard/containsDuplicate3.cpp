class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<int> track;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > indexDiff)
            {
                track.erase(nums[i - indexDiff - 1]);
            }

            auto it = track.lower_bound(nums[i] - valueDiff);

            if (it != track.end() && *it <= (nums[i] + valueDiff))
            {
                // found a solution
                return true;
            }

            track.insert(nums[i]);
        }

        return false;

    }
};