class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        set<int> a,b;
        vector<int> c;
        for(int i=0;i<n;i++){
            a.insert(A[i]);
            b.insert(B[i]);
            set<int> intersectResult;
            set_intersection(a.begin(), a.end(),
                          b.begin(), b.end(),
                          inserter(intersectResult, intersectResult.begin()));
            c.push_back(intersectResult.size());
        }
        return c;
    }

};