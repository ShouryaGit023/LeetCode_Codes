class Solution {
public:
    int myAtoi(string s) {
        long ans=0;
        int sign=1;
        int i=0;
        while(i<s.length() && s[i]==' ') i++;

        if(i<s.length() && (s[i]=='+' || s[i]=='-') ){
            if(s[i]=='-') sign=-1;
            i++;
        }

        while(i<s.length() && s[i]=='0') i++;
        while(i<s.length()){
            if(s[i]==' ' || !isdigit(s[i])) break;
            ans=ans*10+s[i]-'0';

           if (  ans > INT_MAX && sign == 1) return INT_MAX;
    if ( ans > INT_MAX && sign == -1) return INT_MIN;


            i++;
        }
    return (int)(ans*sign);
    }
};