// Anshuman Soln

class CombinationIterator {
public:
    void print_all(vector<string> all){
        for(int i=0;i<all.size();i++){
            cout<<all[i]<<" ";
        }
        cout<<"\n";
    }
    
    vector<string> all_sub;
    int ind=0;
    void make_sub(int i,string characs,int combinationLength,string curStr){
        if(i>=characs.length()){
            if(curStr.length()==combinationLength){
                all_sub.push_back(curStr);
            }
        }
        else{
            make_sub(i+1,characs,combinationLength,curStr);
            curStr.push_back(characs[i]);
            make_sub(i+1,characs,combinationLength,curStr);
        }
    }
    CombinationIterator(string characters, int combinationLength) {
        string cur="";
        make_sub(0,characters,combinationLength,cur);
        // print_all(all_sub);
        ind=all_sub.size()-1;
    }
    
    string next() {
        if(ind>=0){
            string temp = all_sub[ind];
            ind--;
            // cout<<"now ind: "<<ind<<"\n";
            return temp;
        }
        return "";
    }
    
    bool hasNext() {
        return ind>=0;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
