/*
Chef is playing with a string s that contains digits, arithmetic operators, and parentheses. He wants to find out the maximum nesting depth of parentheses in the string.
A nesting depth is the maximum number of parentheses that are open at the same time. Chef wants you to help him calculate this.

*/

int maxNestingDepth(const string &s) {
    int count =0, ans = 0;
    for(char c: s) {
        if (c == '(') {
            ans = max(ans, ++count);
        }else if(c == ')'){
            --count;
        }
    }
    return ans;
}