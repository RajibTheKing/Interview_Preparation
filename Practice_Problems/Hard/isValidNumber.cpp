class Solution {
public:
    bool isNumber(string s) {
        string regStr = "[-,+]?(([\\d]+[.])|([\\d]+)|([\\d]+[.][\\d]+)|([.][\\d]+))([e|E][-,+]?[\\d]+)?";
        regex re(regStr);
        bool result = std::regex_match(s, re);
        return result;
    }
};