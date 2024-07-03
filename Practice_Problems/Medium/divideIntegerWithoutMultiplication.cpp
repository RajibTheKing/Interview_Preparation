class Solution {
public:
    int divide(int dividend, int divisor) {
        int negFlag = (dividend < 0 ^ divisor < 0) ? 1 : 0;

        long long d = labs(dividend);
        long long r = labs(divisor);
        double ans;

        if (d < r)
        {
            // it's obvious, skip additional calculation
            return 0;
        }

        if (r == 1)
        {
            ans = d;
        }
        else
        {
            // adding 0.000000001 to compensate for the precision errors
            ans = exp(log(d) - log(r)) + 0.000000001; 
        }

        ans = negFlag ? -ans : ans;

        if(ans >= INT_MAX) return INT_MAX;
        if(ans <= INT_MIN) return INT_MIN;

        return ans;
    }
};

// d / r = x
// We need to calculate x?
// log10(d/r) = log10(x)
// log10(d) - log10(r) = log10(x)
// x = pow(10, (log10(d) - log10(r)) )
