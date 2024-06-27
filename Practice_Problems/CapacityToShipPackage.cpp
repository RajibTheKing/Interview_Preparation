class Solution {
public:
    int minimumWeights;
    int shipWithinDays(vector<int>& weights, int days) {
        int totalWeight = 500 * 50000;
        minimumWeights = totalWeight;
        solve(1, totalWeight, weights, days);
        return minimumWeights;
    }

    bool isPossible(int weight, vector<int>& weights, int days)
    {
        int selectedWeight = weight;
        for(int i=0; i<weights.size(); i++)
        {
            if(selectedWeight == weight)
            {
                days--;
                if(days < 0) return false;
            }

            if(selectedWeight < weights[i])
            {
                selectedWeight = weight;
                i--;
                continue;
            }

            selectedWeight-=weights[i];
        }
        if(days < 0)
            return false;
        return true;
    }

    void solve(int left, int right, vector<int>& weights, int days)
    {
        if(left > right) return;

        int mid = ( left + right ) / 2;
        //cout << left << ", " << right << ", " << mid << endl;
        if(isPossible(mid, weights, days))
        {
            //cout << "Possible for: " << mid << endl;
            minimumWeights = min(minimumWeights, mid);
            solve(left, mid-1, weights, days);
        }
        else
        {
            solve(mid+1, right, weights, days);
        }
    }
};