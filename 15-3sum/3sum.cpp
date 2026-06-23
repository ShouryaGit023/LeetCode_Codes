class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        int n=v.size();
        sort(v.begin(),v.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if (i > 0 && v[i] == v[i - 1]) continue;
            int req=-v[i];
            int l=i+1;
            int r=n-1;
            while(l<r){
                int cs=v[l]+v[r];
                if(cs>req)r--;
                else if(cs<req)l++;
                else {
                   ans.push_back({v[i], v[l], v[r]});
                    
                    // 3. Skip duplicates for the second and third elements
                    while (l < r && v[l] == v[l + 1]) l++;
                    while (l < r && v[r] == v[r - 1]) r--;
                    
                    l++;
                    r--;
                }
            }
        }
        return ans;
        
    }
};