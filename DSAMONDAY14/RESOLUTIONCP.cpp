/*
Chef made a New Year's resolution, but the year is almost over. Chef wants to know how many days he still has left to complete it.
You are given an integer n- the number of days that have already passed in the current year. You must determine how many days are remaining in the year for Chef to continue working on the resolution.
Important Notes
. The year is not a leap year.
. Therefore, the total number of days in the year is 365.

*/

class Solution {
public:
    int daysLeft(int n) {
        return 365 - n;
    }
};