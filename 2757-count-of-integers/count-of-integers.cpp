class Solution {
public:
int MOD = 1e9 + 7;
string s;
int target;
int low;

//states: Number-> req number formed (1e18~ 18 numbers)
//tight--> whether in the right boundary or not (1--> on the tight, 0--> can take any digit);
// prev---> prev digit --> apply condition on this then
// int zero--> check whether we are on leading zero or not
int dp[24][2][1000][2]; 

int ddp(int id,int tight,int cs,bool zero){
    if(cs>target)return 0;
    if(id==s.size() ){
        return (cs>=low);
    }
    if(dp[id][tight][cs][zero]!=-1)return dp[id][tight][cs][zero];
    int ans=0;
    int limit= (tight ? s[id]-'0' : 9); // if tight true --> can only take that id val, else take the max tight -->9

    //iterate through all digits inside limit;
    for(int i=0;i<=limit;i++){
        int nxtight= tight && (i==limit);

        //handling of zero
        //....
        if(zero){
            if(i==0){
                ans= (ans+ddp(id+1,nxtight,0,true))%MOD;
            }
            else{
                ans=(ans+ddp(id+1,nxtight,cs+i,false))%MOD;
            }
        }
        else{
            //handle the given condition
            
                ans=(ans+ddp(id+1,nxtight,cs+i,false))%MOD;
        
        }
    }
    return dp[id][tight][cs][zero] = ans;
}

int solve(string n) {
        s = n;
        memset(dp, -1, sizeof(dp));
        return ddp(0, true, 0, true);
    }

    // Helper to subtract 1 from string
    string subtractOne(string n) {
        int i = n.size() - 1;
        while (i >= 0) {
            if (n[i] > '0') {
                n[i]--;
                break;
            } else {
                n[i] = '9';
                i--;
            }
        }
        // Remove leading zero if necessary
        if (n.size() > 1 && n[0] == '0') n.erase(0, 1);
        return n;
    }

    int count(string num1, string num2, int min_sum, int max_sum) {
        target = max_sum;
        low = min_sum;
        
        int r = solve(num2);
        int l = solve(subtractOne(num1));
        
        return (r - l + MOD) % MOD;
    }
};