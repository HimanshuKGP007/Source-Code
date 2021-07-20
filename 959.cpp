#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert 
#define vii vector<int>
#define pii pair<int,int>
const int N=30*30*4+1;
int parent[N];
int sizes[N];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    sizes[v] = 1;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sizes[a] < sizes[b])
            swap(a, b);
        parent[b] = a;
        sizes[a] += sizes[b];
    }
}

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int root=0;
        int n=grid.size();
        for(int i=0;i<n*n*4;i++)
        {
            make_set(i);
        }    
        for(int i=0;i<grid.size();i++)
        {
            cout<<grid[i]<<endl;
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==' ')
                {
                    union_sets(root,root+1);
                    union_sets(root+1,root+3);
                    union_sets(root+3,root+2);
                    union_sets(root,root+2);
                    union_sets(root,root+3);
                    union_sets(root+1,root+2);
                }
                else if(grid[i][j]=='/')
                {
                    union_sets(root,root+1);
                    union_sets(root+2,root+3);
                }
                else
                {
                    union_sets(root,root+2);
                    union_sets(root+1,root+3);
                }
                //Connect all 4 
                int topRoot=root-n*4;
                int bottomRoot=root+n*4;
                int leftRoot=root-4;
                int rightRoot=root+4;
                
                //TOP
                if(i>=1)union_sets(topRoot+3,root);
                //Bottom
                if(i<=n-2)union_sets(bottomRoot,root+3);
                //Left
                if(j>=1)union_sets(leftRoot+2,root+1);
                //Right
                if(j<=n-2)union_sets(rightRoot+1,root+2);
                root+=4;
            }
        }
        int answer=0;
        for(int i=0;i<n*n*4;i++)
        {
            if(i==parent[i])answer++;
        }
        return answer;
    }
};
