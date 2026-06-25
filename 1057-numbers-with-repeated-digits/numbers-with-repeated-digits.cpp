class Solution {
public:
string s;

//states: Number-> req number formed (1e18~ 18 numbers)
//tight--> whether in the right boundary or not (1--> on the tight, 0--> can take any digit);
// prev---> prev digit --> apply condition on this then
// int zero--> check whether we are on leading zero or not
int dp[20][2][1024][2]; 

int ddp(int id,int tight,int mask,bool zero){
    if(id==s.size()){
        return 1;
    }
    if(dp[id][tight][mask][zero]!=-1)return dp[id][tight][mask][zero];
    int ans=0;
    int limit= (tight ? s[id]-'0' : 9); // if tight true --> can only take that id val, else take the max tight -->9

    //iterate through all digits inside limit;
    for(int i=0;i<=limit;i++){
        int nxtight= tight && (i==limit);

        //handling of zero
        //....
        if(zero){
            if(i==0){
                ans+=ddp(id+1,nxtight,0,true);
            }
            else{
                ans+=ddp(id+1,nxtight,(1<<i),false);
            }
        }
        else{
            //handle the given condition
            if(!(mask & (1<<i))){
                ans+=ddp(id+1,nxtight,mask|(1<<i),false);
            }
        }
    }
    return dp[id][tight][mask][zero] = ans;
}

int solve(int n){
    if(n<0)return 0;
    if(n==0)return 1;
    s=to_string(n);
    memset(dp,-1,sizeof(dp));
    return ddp(0,1,0,true);
}
    int numDupDigitsAtMostN(int n) {
        int bad=solve(n)-1;
        return n-bad;
    }
};