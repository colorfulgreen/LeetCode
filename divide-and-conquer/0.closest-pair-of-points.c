#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

typedef struct {
    int x;
    int y;
} Point;


int distance(Point a, Point b) {
    return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}


int brutalClosest(Point *points, int n) {
    int min = INT_MAX, dis;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            dis = distance(points[i], points[j]);
            if(dis < min)
                min = dis;
        }
    }
    return min;
}


int stripClosest(Point *points, int n, int delta) {
    int min = INT_MAX, dis;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(abs(points[i].y - points[j].y) >= min)
                continue;
            dis = distance(points[i], points[j]);
            if(dis < min)
                min = dis;
        }
    }
    return min;
}


int closest(Point *points, int n) {
    if(n <= 3)
        return brutalClosest(points, n);
    int mid = n/2;
    Point midPoint = points[mid];
    /* NOTE 分而治之法的数组下标。两部分长度和为 n */
    int leftMin = closest(points, mid);
    int rightMin = closest(points + mid, n-mid);
    int min = leftMin < rightMin ? leftMin : rightMin;

    Point stripPoints[n];
    int nStripPoints;
    for(int i=0; i<n; i++) {
        if(abs(points[i].x - midPoint.x) < min)
            stripPoints[nStripPoints++] = points[i];
    }
    int stripMin = stripClosest(stripPoints, nStripPoints, min);
    printf("left=%d right=%d strip=%d min=%d\n", leftMin, rightMin, stripMin, min);
    return min < stripMin ? min : stripMin;
}


int cmp(const void *a, const void *b) {
    Point *pa = (Point*)a;
    Point *pb = (Point*)b;
    if(pa->x < pb->x)
        return -1;
    if(pa->x > pb->x)
        return 1;
    if(pa->y < pb->y)
        return -1;
    if(pa->y > pb->y)
        return 1;
    return 0;
}


int main(void) {
    int n, x, y;
    Point *points;
    scanf("%d", &n);
    points = malloc(sizeof(Point) * n);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
    qsort(points, n, sizeof(Point), cmp);
    int min = closest(points, n);
    printf("%d\n", min);

    return EXIT_SUCCESS;
}
