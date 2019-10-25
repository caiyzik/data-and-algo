class TwoSum {
public:
    vector<int> brute_force(vector<int>& nums, int target) {
        vector<int> v;
        for (int i = 0; i < nums.size(); ++i){
            for(int j = 0;j < nums.size()-1; ++j){
                if(nums[i]+nums[j] and i != j){
                    v.push_back(i);
                    v.push_back(j);
                    return v;
                }
            }
        }
        v.push_back(-1);
        return v;
    }

};