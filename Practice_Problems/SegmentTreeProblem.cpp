#define MAX_LEN 100000+7

class Solution {
public:
    int segTree[MAX_LEN];
    long long cumSum[MAX_LEN];
    
    void buildSegmentTree(vector<int>& strength, int left, int right, int pos){
        if(left == right){
            //cout<<"Now: pos = "<<pos<<endl;
            segTree[pos] = strength[left];
            return;
        }
        
        int mid = (left + right) / 2;
        
        buildSegmentTree(strength, left, mid, pos*2 + 1);
        
        buildSegmentTree(strength, mid+1, right, pos*2 + 2);
        
        segTree[pos] = min(segTree[pos*2 + 1], segTree[pos*2 + 2]);
    }
    
    int queryMin(int left, int right, int qLeft, int qRight, int pos){
        if(qLeft <= left &&  right <= qRight){
            //total Overlap
            return segTree[pos];
        }
        
        if(qRight < left || right < qLeft){
            //no Overlap
            return INT_MAX;
        }
        
        //case for Partial Overlap
        int mid = (left + right) / 2;
        return min(queryMin(left, mid, qLeft, qRight, pos*2+1), queryMin(mid+1, right, qLeft, qRight, pos*2+2));
    }
    
    int totalStrength(vector<int>& strength) {
        int modValue = 1000000000 + 7;
        int len = strength.size();
        
        for(int i=0; i<len; i++){
            segTree[i] = INT_MAX;
        }
        buildSegmentTree(strength, 0, len-1, 0);
        
        long long cumulativeSum = 0;
        for(int i=0; i<len; i++){
            cumulativeSum+=strength[i];
            cumSum[i+1] = cumulativeSum;
        }
        cumSum[0] = 0;
        
        int totalSum = 0;
        
        for(int i=0; i<len; i++){
            for(int j=i; j<len; j++){
                //cout<<"i, j = "<<i<<", "<<j<<endl;
                long long currentSum = (cumSum[j+1] - cumSum[i]) % modValue;
                int minValue = queryMin(0, len-1, i, j, 0);
                totalSum+=currentSum * minValue;
                totalSum%=modValue;
            }
        }
        
        return totalSum;
        
        
    }
};