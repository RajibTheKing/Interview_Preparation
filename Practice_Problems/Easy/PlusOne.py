class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        carry = 1
        for i in range(len(digits)-1, -1, -1):
            print(digits[i])
            now = digits[i] + carry
            if now >= 10:
                now = now % 10
                carry = 1
            else:
                carry = 0
            digits[i] = now

        if carry:
            digits = [1] + digits
        return digits