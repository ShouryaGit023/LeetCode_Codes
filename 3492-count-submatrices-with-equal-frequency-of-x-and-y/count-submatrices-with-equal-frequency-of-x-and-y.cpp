class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& v) {
        int n = v.size();
        int m = v[0].size();

        vector<vector<pair<int,int>>> a(n, vector<pair<int,int>>(m, {0,0}));
        for(int i = 0; i < n; i++){
            int cx = 0, cy = 0;
            for(int j = 0; j < m; j++){
                if(v[i][j] == 'X') cx++;
                else if(v[i][j] == 'Y') cy++;
                a[i][j] = {cx, cy};
            }
        }


        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                a[i][j].first += a[i-1][j].first;
                a[i][j].second += a[i-1][j].second;
            }
        }

        int ans = 0;

        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j].first == a[i][j].second && a[i][j].first >= 1)
                    ans++;
            }
        }

        return ans;
    }
};