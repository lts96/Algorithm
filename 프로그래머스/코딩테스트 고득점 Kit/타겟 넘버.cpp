#include <string>
#include <vector>
using namespace std;
// 도달해야되는 숫자를 좌표라고 생각하면 된다 
// 이런 식으로 탐색이 아닌척 탐색인 문제는 항상 주의할 것 
vector<int> visit;
int n , ans , t;
void dfs(int index , int v)
{
    if(index == n)
    {
        if(v == t)
            ans++;
        return;   
    }
    int v1 = v + visit[index];
    int v2 = v - visit[index];
    dfs(index+1 ,v1 );
    dfs(index+1, v2);
        
}
int solution(vector<int> numbers, int target) {
    n = numbers.size();
    t = target;
    for(int i=0; i<n; i++)
        visit.push_back(numbers[i]);
    dfs(0 , 0);
    return ans;
}
