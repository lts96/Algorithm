// 전형적인 최소 스패닝 트리 문제
// costs 그대로 쓰면 가중치별 정렬이 제대로 안되므로 edge 배열에 가중치가 제일 우선순위가 되도록 옮김 
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int arr[103];
int find(int i)
{
    if(i == arr[i])
        return i;
    return arr[i] = find(arr[i]);
}
void union_set(int a, int b)
{
    int root1 = find(a);
    int root2 = find(b);
    if(root1 == root2)
        return;
    arr[root2] = root1;
    return;
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i=1; i<=n; i++)
        arr[i] =i;
    vector<pair <int , pair <int, int>>> edge;
    for(int i=0;i<costs.size(); i++)
        edge.push_back(make_pair(costs[i][2], make_pair(costs[i][0],costs[i][1])));
    sort(edge.begin(), edge.end());
    int weight,x,y;
    for (int i=0; i<edge.size(); i++)
    {
        weight = edge[i].first;
        x = edge[i].second.first;
        y = edge[i].second.second;
        if(find(x) == find(y))
            continue;
        else 
        {
            union_set(x,y);
            answer += weight;
        }
    }
    return answer;
}
