#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>
const int N=51;
int dp[N][N];
bool check[N][N];
int n,m;
int X[4]={0,1,0,-1};
int Y[4]={-1,0,1,0};

bool isValid(int x,int y)
{
    if(x>=0 && y>=0 && x<n && y<m)return true;
    else return false;
}

void dijkstra(vector<vector<int>>& grid)
{
    set<pair<int,pii>>s; //Distance,(i,j)
    dp[0][0]=grid[0][0];
    check[0][0]=true;
    s.ins(mp(dp[0][0],mp(0,0)));
    
    while(s.size()>0)
    {
        auto itr=s.begin();
        int d=itr->fi;
        int x=itr->se.fi;
        int y=itr->se.se;
        dp[x][y]=d;
        check[x][y]=true;
        s.erase(itr);
        
        for(int i=0;i<4;i++)
        {
            int newX=x+X[i];
            int newY=y+Y[i];
            if(isValid(newX,newY) && check[newX][newY]==false)
            {
                check[newX][newY]=true;
                dp[newX][newY]=max(grid[newX][newY],dp[x][y]);
                s.ins(mp(dp[newX][newY],mp(newX,newY)));
            }
        }
    }
    
}

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                check[i][j]=false;
                dp[i][j]=INT_MAX;
            }
        }
        dijkstra(grid);
        return dp[n-1][m-1];
    }
};


//////////////// 2nd Solution with Priority Queue //////////////

class Compare{
public:
    bool operator()(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
        return a.first>=b.first;    
    }
};

class Solution {
public:
    
    bool isSafe(int i, int j, vector<vector<int>>& grid){
        if(i>=0&&j>=0&&i<grid.size()&&j<grid[0].size())return true;
        else return false;
    }
    
    
    
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid.size(), false)) ;
        int n = grid.size();
        int x[4] = {-1,0,0,1};
        int y[4] = {0,-1,1,0};
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, Compare> pq;
        pq.push({grid[0][0],{0,0}});
                                 
        while(true){
            pair<int,pair<int,int>> curr = pq.top();
            pq.pop();
            cout<<curr.first<<" ";
            while(!pq.empty()&&pq.top().first == curr.first)pq.pop();
            
            int i = curr.second.first;
            int j = curr.second.second;
            vis[i][j] = true;
            if(curr.second.first == n-1&& curr.second.second==n-1)break;
            for(int c = 0; c<4;c++){
                if(isSafe(i+x[c], j+y[c], grid)&&!vis[i+x[c]][j+y[c]]){
                    pq.push({grid[i+x[c]][j+y[c]],{i+x[c], j+y[c]}});
                }
            }
        }
        int maxi=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n;j++){
                if(vis[i][j])maxi = max(maxi, grid[i][j]);
            }
        }
        return maxi;
    }
};
