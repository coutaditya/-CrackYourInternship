// If we calculate all distances between 4 points, 4 smaller distances should be equal (sides), and 2 larger distances should be equal too (diagonals). 
// As an optimization, we can compare squares of the distances, so we do not have to deal with the square root and precision loss.
// Therefore, our set will only contain 2 unique distances in case of square (beware of the zero distance though).

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<int, int> s; // <distance, counter>
        s[d(p1, p2)]++;
        s[d(p1, p3)]++;
        s[d(p1, p4)]++;
        s[d(p2, p3)]++;
        s[d(p2, p4)]++;
        s[d(p3, p4)]++;
        if (s.size() != 2) return false;
        return s.begin()->second == 4 && s.rbegin()->second == 2;    // rbegin() gives a reverse iterator pointing to the last element of the set
    }

    int d(vector<int>& p1, vector<int>& p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
};