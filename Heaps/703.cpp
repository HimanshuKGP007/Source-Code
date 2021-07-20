#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define order_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
order_set s;


int ind;
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        s.clear();
        ind=k;
        for(int i=0;i<nums.size();i++)s.ins(nums[i]);
    }
    
    int add(int val) {
        s.ins(val);
        int sizes=s.size();
        int ans=*s.find_by_order(sizes-ind);
        return ans;
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

// Anshuman Solution:-

class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int size;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(int a:nums){
            pq.push(a);
            if(pq.size()>k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>size)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
