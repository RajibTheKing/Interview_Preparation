class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        map<int, bool> mp;
        for (const auto& x : nums1)
            mp[x] = true;

        for (const auto& x : nums2)
        {
            if (mp.find(x) != mp.end())
            {
                s.insert(x);
            }
        }

        vector<int> ans(s.begin(), s.end());

        return ans;
    }
};