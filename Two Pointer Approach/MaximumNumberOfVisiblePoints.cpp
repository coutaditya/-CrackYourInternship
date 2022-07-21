// Very beautiful sliding window solution
// We find and store angles made by each point from the location and then sort it and apply sliding window
// We add 360 to all angles so that we also consider the window that consists of below and above points
// Also we need to count thre points that are coinicident to the location, as they will always be included in the answer(also tan inverse infinite aata :p)

class Solution {
public:
    double getAngle(int x, int y){
        return atan2(y, x) * (180 / M_PI);
    }
    
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int res = 0;
        vector<double> angles;
        int n = points.size();
        for(int i=0; i<n; i++){
            int x = points[i][0] - location[0];
            int y = points[i][1] - location[1];
            
            if(x==0 && y==0){
                res++;
            }
            
            else{
                double an = getAngle(x, y);
                if(an<0){
                    an+=360;
                }
                angles.push_back(an);
            } 
        }
        
        sort(angles.begin(), angles.end());
        
        n = angles.size();
        for(int i=0; i<n; i++){
            angles.push_back(angles[i]+(double)360);
        }
        
        int start = 0, end = 0, ans = 0;
        while(end<2*n){
            if((angles[end]-angles[start])>(double)angle){
                start++;
            }
            
            ans = max(ans, (end-start+1));
            end++;
        }
        
        return ans+res;
        
    }
};