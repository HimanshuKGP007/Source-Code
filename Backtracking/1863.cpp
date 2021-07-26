class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<=pow(2,n)-1;i++)
        {
            int temp=0;
            for(int j=0;j<n;j++)
            {
                if((i&(1<<j)))
                {
                    temp=temp^nums[j];
                }
            }
            sum+=temp;
        }
        return sum;
    }
};
