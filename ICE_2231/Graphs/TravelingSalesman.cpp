/*
TRAVELING SALESMAN PROBLEM (TSP)

Cities are numbered: 0, 1, 2, 3
We use an integer called "mask" to remember which cities are visited.

Example:
mask = 0001 (binary) -> only city 0 visited
mask = 0111 -> cities 0,1,2 visited
mask = 1111 -> all cities visited
*/

#include <iostream>
#include <climits>
using namespace std;

#define N 4

int graph[N][N] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}};

// dp[mask][pos] = minimum cost to visit remaining cities
int dp[16][N]; // 2^4 = 16 masks

int VISITED_ALL = 15; // 1111 in binary

int tsp(int mask, int pos)
{
    // If all cities visited, go back to start
    if (mask == VISITED_ALL)
        return graph[pos][0];

    // If already solved
    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    // Try visiting every city
    for (int city = 0; city < N; city++)
    {
        // Check if city is NOT visited
        // (mask >> city) & 1  -> checks city-th bit
        if (((mask >> city) & 1) == 0)
        {
            // Mark city as visited
            int newMask = mask | (1 << city);

            int cost = graph[pos][city] +
                       tsp(newMask, city);

            ans = min(ans, cost);
        }
    }

    dp[mask][pos] = ans;
    return ans;
}

int main()
{
    // Initialize dp table with -1
    for (int i = 0; i < 16; i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = -1;

    int startMask = 1; // 0001 -> start from city 0
    int minCost = tsp(startMask, 0);

    cout << "Minimum travelling cost: " << minCost << endl;
    return 0;
}
