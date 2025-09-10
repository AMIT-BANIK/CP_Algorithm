#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;

struct Point {
    int x, y;
};

Point p0;

int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;      
    return (val > 0) ? -1 : 1;   
}

double dist(Point a, Point b) {
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool compareMinElement(const Point &a, const Point &b) {
    return (a.y < b.y) || (a.y == b.y && a.x < b.x);
}

bool compareSort(const Point &a, const Point &b) {
    double angA = atan2(a.y - p0.y, a.x - p0.x);
    double angB = atan2(b.y - p0.y, b.x - p0.x);
    if (angA == angB) return dist(p0,a) < dist(p0,b);
    return angA < angB;
}

vector<Point> graham(vector<Point> &points) {
    p0 = *min_element(points.begin(), points.end(), compareMinElement);
    
    sort(points.begin(), points.end(), compareSort);

    stack<Point> st;
    st.push(points[0]);
    st.push(points[1]);

    for (int i = 2; i < points.size(); i++) {
        Point top = st.top(); st.pop();
        while (!st.empty() && orientation(st.top(), top, points[i]) != 1) {
            top = st.top(); st.pop();
        }
        st.push(top);
        st.push(points[i]);
    }

    vector<Point> hull;
    while (!st.empty()) {
        hull.push_back(st.top());
        st.pop();
    }
    reverse(hull.begin(), hull.end()); 
    return hull;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    vector<Point> hull = graham(points);

    cout << "\nConvex Hull Points:\n";
    for (auto &p : hull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }
    return 0;
}
