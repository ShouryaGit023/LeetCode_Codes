class Solution {
public:
typedef long long ll;
    string s;
    ll k;

//states: Number-> req number formed (1e18~ 18 numbers)
//tight--> whether in the right boundary or not (1--> on the tight, 0--> can take any digit);
// prev---> prev digit --> apply condition on this then
// ll zero--> check whether we are on leading zero or not
ll dp[20][2][11][2]; 

ll ddp(ll id,ll tight,ll prev,bool zero){
    if(id==s.size()){
        return 1;
    }
    if(dp[id][tight][prev+1][zero]!=-1)return dp[id][tight][prev+1][zero];
    ll ans=0;
    ll limit= (tight ? s[id]-'0' : 9); // if tight true --> can only take that id val, else take the max tight -->9

    //iterate through all digits inside limit;
    for(ll i=0;i<=limit;i++){
        ll nxtight= tight && (i==limit);

        //handling of zero
        //....
        if(zero){
            if(i==0){
                ans+=ddp(id+1,nxtight,-1,true);
            }
            else{
                ans+=ddp(id+1,nxtight,i,false);
            }
        }
        else{
            //handle the given condition
            if(abs(prev-i)<=k){
                ans+=ddp(id+1,nxtight,i,false);
            }
        }
    }
    return dp[id][tight][prev + 1][zero] = ans;
}
ll solve(ll n){
    if(n<0)return 0;
    if(n==0)return 1;
    s=to_string(n);
    memset(dp,-1,sizeof(dp));
    return ddp(0,1,1,true);
}
    long long goodIntegers(long long l, long long r, ll kk) {
        k=kk;
        return solve(r)-solve(l-1);
    }
};