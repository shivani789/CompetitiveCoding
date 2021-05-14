class Solution {
public:
    vector<int> distinctNumInEachSubarray(vector<int>& arr,int k){
           vector<int> ans;
        map<int, int> m;
     for (int i = 0; i <= arr.size() - k; i++) {
        int sum = 0;
        for (int j = i; j < k + i; j++)
            m[arr[j]]++;
         ans.push_back(m.size());
         m.clear();
    }
        return ans;
    }
};
