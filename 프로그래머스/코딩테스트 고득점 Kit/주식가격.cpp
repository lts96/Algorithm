#include <string>
#include <vector>
#include <stack>
using namespace std;
stack <int> s;

// n^2으로 그냥 품, 하지만 스택을 활용하는 방법도 있으니 구글링 ㄱㄱ
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    answer.assign(prices.size(),0);
    for(int i=0; i<prices.size(); i++)
    {
        for(int j=i+1; j< prices.size(); j++)
        {
            if(prices[i] > prices[j])
            {
                answer[i] = j-i;
                break;
            }
        }
        if(answer[i] == 0)
            answer[i] = prices.size()-1-i;
    }
    return answer;
}
