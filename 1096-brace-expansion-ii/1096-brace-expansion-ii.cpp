class Solution {
    string s;
    int i = 0;

private:
    set<string> parseExpression() {
        set<string> result = parseTerm();
        while (i < s.size() && s[i] == ',') {
            i++;
            set<string> next = parseTerm();
            result.insert(next.begin(), next.end());
        }
        return result;
    }

    set<string> parseTerm() {
        set<string> result = {""};
        while (i < s.size() && s[i] != ',' && s[i] != '}') {
            set<string> cur = parseFactor();
            set<string> next;
            for (const string& a : result) {
                for (const string& b : cur) {
                    next.insert(a + b);
                }
            }
            result = move(next);
        }
        return result;
    }

    set<string> parseFactor() {
        if (s[i] == '{') {
            i++;
            set<string> result = parseExpression();
            i++;
            return result;
        }
        return {string(1, s[i++])};
    }

public:
    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;
        set<string> result = parseExpression();
        return {result.begin(), result.end()};
    }
};