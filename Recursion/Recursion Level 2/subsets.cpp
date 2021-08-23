void solve(int n, vector<vector> &ans, int i, vector &A, vector s)
{
    if (i == n - 1)
    {
        s.push_back(A[i]);
        ans.push_back(s);
        return;
    }
    s.push_back(A[i]);
    ans.push_back(s);
    solve(n, ans, i + 1, A, s);
    s.pop_back();
    solve(n, ans, i + 1, A, s);
    return;
}

vector<vector> Solution::subsets(vector &A)
{
    int n = A.size();
    sort(A.begin(), A.end());
    vector s;
    vector<vector> ans;
    ans.push_back(s);
    if (n == 0)
        return ans;
    solve(n, ans, 0, A, s);
    return ans;
}
