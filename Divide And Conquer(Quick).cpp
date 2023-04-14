#include<bits/stdc++.h>
using namespace std;

#define iPair pair<int, int>
set<iPair> hull;

int findSide(iPair p1, iPair p2, iPair p)
{
    int val = (p.second - p1.second) * (p2.first - p1.first) - (p2.second - p1.second) * (p.first - p1.first);

    if (val > 0)
        return 1;
    if (val < 0)
        return -1;
    return 0;
}

int lineDist(iPair p1, iPair p2, iPair p)
{
    return abs ((p.second - p1.second) * (p2.first - p1.first) - (p2.second - p1.second) * (p.first - p1.first));
}

void quickHull(iPair a[], int n, iPair p1, iPair p2, int side)
{
    int ind = -1;
    int max_dist = 0;

    for (int i=0; i<n; i++)
    {
        int temp = lineDist(p1, p2, a[i]);
        if (findSide(p1, p2, a[i]) == side && temp > max_dist)
        {
            ind = i;
            max_dist = temp;
        }
    }

    if (ind == -1)
    {
        hull.insert(p1);
        hull.insert(p2);
        return;
    }

    quickHull(a, n, a[ind], p1, -findSide(a[ind], p1, p2));
    quickHull(a, n, a[ind], p2, -findSide(a[ind], p2, p1));
}

void printHull(iPair a[], int n)
{
    if (n < 3)
    {
        cout << "Convex hull not possible\n";
        return;
    }

    int min_x = 0, max_x = 0;
    for (int i=1; i<n; i++)
    {
        if (a[i].first < a[min_x].first)
            min_x = i;
        if (a[i].first > a[max_x].first)
            max_x = i;
    }

    quickHull(a, n, a[min_x], a[max_x], 1);
    quickHull(a, n, a[min_x], a[max_x], -1);

    cout << "The points in Convex Hull are:\n";
    while (!hull.empty())
    {
        cout << "(" <<( *hull.begin()).first << ", " << (*hull.begin()).second << ") "<<endl;
        hull.erase(hull.begin());
    }
}

int main()
{
    iPair a[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},{0, 0}, {1, 2}, {3, 1}, {3, 3},{1,4},{5,8},{3,5},{8,9},{100,67},{100,107},
    {10,50},{20,27},{12,17},{23,34},{200,34},{100,4},{34,56},{89,9},{57,69},{62,4},{20,45},{100,104},{20,220},{40,53}};
    int n = sizeof(a)/sizeof(a[0]);
    printHull(a, n);
    return 0;
}
