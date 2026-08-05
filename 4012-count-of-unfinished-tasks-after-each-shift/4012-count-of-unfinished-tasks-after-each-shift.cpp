class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        auto drelvanito = make_pair(tasks, shifts);

        int n = tasks.size();
        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + tasks[i];

        vector<int> ans;

        int cur = 0;
        long long done = 0; // work completed before current task

        for (long long s : shifts) {
            long long target = done + s;

            if (target >= pref[n]) {
                ans.push_back(0);
                cur = 0;
                done = 0;
                continue;
            }

            cur = upper_bound(pref.begin(), pref.end(), target) - pref.begin() - 1;
            done = target;

            ans.push_back(n - cur);
        }

        return ans;
    }
};