#define pb push_back
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        
        vector<string>ans;
        for(int i=0;i<=pow(2,10)-1;i++)
        {
            int count=0;
            int hours=0;
            int minutes=0;
            for(int j=0;j<=9;j++)
            {
                if( (i&(1<<j)) )
                {
                    count++;
                    if(j<=5) //Minutes
                    {
                        minutes+=pow(2,j);
                    }
                    if(j>=6 && j<=9) //Hours
                    {
                        hours+=pow(2,j-6);
                    }
                }
            }
            if(count==turnedOn && hours<12 && minutes<60)
            {
                string hrs=to_string(hours);
                string mins=to_string(minutes);
                string temp=hrs;
                temp+=":";
                
                if(minutes/10==0)temp+='0';
                temp+=mins;
                
                ans.pb(temp);
            }
        }
        return ans;
    }
};

// Anshuman Soln

class Solution {
public:
    int fl=0;
    vector<string> ans;
    string get_time(vector<int> ons){
        int hrs=0;
        for(int i=0;i<4;i++){
            if(ons[i]==1){
                hrs+=pow(2,3-i);
            }
        }
        if(hrs>11){
            fl=1;
        }
        int mins=0;
        for(int i=4;i<10;i++){
            if(ons[i]==1){
                mins+=pow(2,9-i);
            }
        }
        if(mins>59){
            fl=1;
        }
        ostringstream str1;
        str1<<hrs;
        string my_hrs=str1.str();
        ostringstream str2;
        str2<<mins;
        string my_mins=str2.str();
        cout<<mins<<" minutes "<<my_mins<<"\n";
        if(mins==0){
            my_mins="00";
        }
        else if(my_mins.size()==1){
            string temp="0";
            temp.append(my_mins);
            my_mins=temp;
        }
        string ans="";
        ans.append(my_hrs);
        ans.push_back(':');
        ans.append(my_mins);
        return ans;
    }
    void recur(int i,int turnedOn,int cur,vector<int> curTurn){
        if(i>=10){
            if(cur==turnedOn){
                string time=get_time(curTurn);
                if(fl==0)
                    ans.push_back(time);
                else
                    fl=0;
            }
            return;
        }
        cout<<i<<"\n";
        if(cur==turnedOn){
            string time=get_time(curTurn);
            if(fl==0)
                ans.push_back(time);
            else
                fl=0;
        }
        else{
            recur(i+1,turnedOn,cur,curTurn);
            cur++;
            curTurn[i]=1;
            cout<<"setting "<<i<<" as 1\n";
            recur(i+1,turnedOn,cur,curTurn);
        }
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<int> curTurn(10,0);
        recur(0,turnedOn,0,curTurn);
        return ans;
    }
};
