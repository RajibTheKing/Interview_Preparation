class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        return self.solve(0, x, x)

    def solve(self, left, right, x):
        if(left > right):
            return -1

        mid = (int)((left + right) / 2)

        ans = -1
        if (mid * mid) > x:
            ans = max(ans, self.solve(left, mid-1, x))
        else:
            ans = mid
            ans = max(ans, self.solve(mid+1, right, x))

        return ans
