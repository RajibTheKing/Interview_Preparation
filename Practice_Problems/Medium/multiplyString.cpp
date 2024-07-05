class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() == 1 && num1[0] == '0')
            return "0";
        
        if (num2.size() == 1 && num2[0] == '0')
            return "0";
        
        if (num1.size() < num2.size())
        {
            swap(num1, num2);
        }

        string multAns = "";
        for (int j = num2.size() - 1; j >= 0; j--)
        {
            string now = multiplyByOneDigit(num1, num2[j]);
            for (int k = j+1; k < num2.size(); k++)
                now += '0';
            multAns = addTwoString(multAns, now);
        }

        return multAns;
    }

    string multiplyByOneDigit(string& s, char c)
    {
        string ret = "";
        int carry  = 0;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            int d1 = s[i] - '0';
            int d2 = c - '0';
            int now = d1 * d2 + carry;
            if (now >= 10)
            {
                carry = now / 10;
                now %= 10;
            }
            else
            {
                carry = 0;
            }
            ret = to_string(now) + ret;
        }
        if (carry > 0)
        {
            ret = to_string(carry) + ret;
        }

        return ret;
    }

    string addTwoString(string num1, string num2)
    {
        if (num1.size() < num2.size())
        {
            swap(num1, num2);
        }
        string ans = "";
        int carry = 0;
        for(int j = num2.size() - 1, i = num1.size() - 1; j >= 0; j--, i--)
        {
            int sum = calculate(num2[j], num1[i], carry);
            ans = to_string(sum) + ans;
        }

        int dif = num1.size() - num2.size();
        for(int i = dif - 1; i >= 0; i--)
        {
            int sum = calculate(num1[i], '0', carry);
            ans = to_string(sum) + ans;
        }

        if (carry > 0)
        {
            ans = to_string(carry) + ans;
        }
        return ans;
    }

    int calculate(char c1, char c2, int& carry)
    {
        int d1 = c1 - '0';
        int d2 = c2 - '0';

        int sum = d1 + d2 + carry;

        if(sum >= 10)
        {
            carry = 1;
            sum %= 10;
        }
        else
        {
            carry = 0;
        }
        return sum;
    }
};
