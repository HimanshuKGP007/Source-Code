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


// Anshuman Soln

class Solution {
public:
    int ans=0;
    void all_sub(int i,vector<int>& nums,int cur){
        if(i==nums.size()){
            ans+=cur;
        }
        else{
            all_sub(i+1,nums,cur);
            cur=cur^nums[i];
            all_sub(i+1,nums,cur);
        }
    }
    int subsetXORSum(vector<int>& nums) {
        all_sub(0,nums,0);
        return ans;
    }
};
