#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class point {
public:
    float x;
    float y;
    point() {
        x = 0.0;
        y = 0.0;
    }
    point(float X, float Y) {
        x = X;
        y = Y;
    }
    void setX(float X) {
        x = X;
    }
    void setY(float Y) {
        y = Y;
    }
    float getX() {
        return x;
    }
    float getY() {
        return y;
    }
    void display() {

    }
    float distance(point p) {
        float d = sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
        return d;
    }
};

point Center(point* C, int n) {
    float x_sum = 0.0, y_sum = 0.0;
    for (int i = 0; i < n; i++) {
        x_sum += C[i].getX();
        y_sum += C[i].getY();
    }
    float x_avg = x_sum / n;
    float y_avg = y_sum / n;
    point center(x_avg, y_avg);
    return center;
}



int main() {
    const int n = 200;
    const int m = 20;
    point A[n];
    point B[n];
    point p[m];

    for (int i = 0; i < n; i++) {
        float x = (float)rand() / RAND_MAX * 20 + 70;
        float y = (float)rand() / RAND_MAX * 20 + 70;
        A[i] = point(x, y);
    }

    for (int i = 0; i < n; i++) {
        float x = (float)rand() / RAND_MAX * 20 + 20;
        float y = (float)rand() / RAND_MAX * 20 + 20;
        B[i] = point(x, y);
    }

    for (int i = 0; i < m; i++) {
        float x = (float)rand() / RAND_MAX * 95 + 5;
        float y = (float)rand() / RAND_MAX * 95 + 5;
        p[i] = point(x, y);
    }

    point center_A = Center(A, n);
    point center_B = Center(B, n);



    return 0;
}
