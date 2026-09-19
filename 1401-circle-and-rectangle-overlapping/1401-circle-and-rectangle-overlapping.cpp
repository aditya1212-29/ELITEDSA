class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int a, b;
        if(xCenter < x1) a = x1;
        else if(xCenter > x2) a = x2;
        else a = xCenter;
        if(yCenter < y1) b = y1;
        else if(yCenter > y2) b = y2;
        else b = yCenter;
        return radius * radius >= pow((a - xCenter), 2) + pow((b - yCenter), 2);
    }
};