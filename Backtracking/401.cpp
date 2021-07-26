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
