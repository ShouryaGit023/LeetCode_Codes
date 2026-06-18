class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h=hour%12;
        double m=minutes;
        double ah=(h)*30.00 + (m/2.0);
        double am=6*m;
        double sw=abs(ah-am);
        return min(360.00-sw,sw);
        
    }
};