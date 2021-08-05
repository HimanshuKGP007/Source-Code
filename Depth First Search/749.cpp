#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>
const int N=51;
bool check[N][N];
int graph[N][N];
int n,m;
int X[4]={0,1,0,-1};
int Y[4]={-1,0,1,0};

bool isValid(int x,int y)
{
    if(x>=0 && y>=0 && x<n && y<m)return true;
    else return false;
}

class Cluster
{
    public:
        set<pii>connectedComp;
        set<pii>uncontaminatedCells;
        int wallsBuilt;
};

void initialize()
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
            check[i][j]=false;
        }
    }
}

void dfs(int x,int y,Cluster *c)
{
    check[x][y]=true;
    c->connectedComp.ins(mp(x,y));
    for(int i=0;i<4;i++)
    {
        int newX=x+X[i];
        int newY=y+Y[i];
        if(isValid(newX,newY) && graph[newX][newY]==1 && check[newX][newY]==false)
            dfs(newX,newY,c);
        else if(isValid(newX,newY) && graph[newX][newY]==0)
        {
            c->uncontaminatedCells.ins(mp(newX,newY));
            c->wallsBuilt++;
        }
    }
}

class Comp
{
    public:
        bool operator()(Cluster *a,Cluster *b)
        {
            if(a->uncontaminatedCells.size() < b->uncontaminatedCells.size())
            {
                return true;
            }
            else return false;
        }
};


class Solution {
public:
    int containVirus(vector<vector<int>>& isInfected) 
    {
        n=isInfected.size();
        m=isInfected[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                graph[i][j]=isInfected[i][j];
            }
        }
        
        int answer=0;
        
        while(true)
        {
            initialize();
            priority_queue<Cluster* ,vector<Cluster*>, Comp>pq;
            
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(check[i][j]==false && graph[i][j]==1)
                    {
                        Cluster *c=new Cluster();
                        c->wallsBuilt=0;
                        c->connectedComp.clear();
                        c->uncontaminatedCells.clear();
                        
                        dfs(i,j,c);
                        pq.push(c);
                    }
                }
            }
            
            
            if(pq.size()==0)break;
            
            
            Cluster *top=pq.top();
            answer+=top->wallsBuilt;
            pq.pop();
            
            for(auto itr=top->connectedComp.begin();itr!=top->connectedComp.end();itr++)
            {
                int x=itr->fi;
                int y=itr->se;
                graph[x][y]=-1;
            }
            
            while(pq.size()>0)
            {
                Cluster *top=pq.top();
                for(auto itr=top->uncontaminatedCells.begin();itr!=top->uncontaminatedCells.end();itr++)
                {
                    int x=itr->fi;
                    int y=itr->se;
                    graph[x][y]=1;
                }
                pq.pop();
            }
            
        }
        
        
        return answer;
    }
};
