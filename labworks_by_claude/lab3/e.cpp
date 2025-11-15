#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Rectangle {
    int x1, y1, x2, y2;
};

bool canFit(vector<Rectangle>& rects, int k, int size) {
    int count = 0;
    for (int i = 0; i < rects.size(); i++) {
        if (rects[i].x2 <= size && rects[i].y2 <= size) {
            count++;
        }
    }
    return count >= k;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<Rectangle> rects(n);
    int maxCoord = 0;

    for (int i = 0; i < n; i++) {
        cin >> rects[i].x1 >> rects[i].y1 >> rects[i].x2 >> rects[i].y2;
        maxCoord = max(maxCoord, max(rects[i].x2, rects[i].y2));
    }

    int left = 1, right = maxCoord;
    int result = maxCoord;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canFit(rects, k, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << "\n";
    return 0;
}
