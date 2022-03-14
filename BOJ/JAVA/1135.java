import java.io.*;
import java.util.*;

// 그리디 + 정렬로 해결 
// 트리 + dp로도 해결가능하다는데 나중에 해보기 
public class Main {
	static int ans;
	static int cache[] = new int[51];
	static int n;
	static ArrayList<ArrayList<Integer>> tree = new ArrayList<ArrayList<Integer>>();
	
	static int dp(int idx)
	{
		if (idx < 0 || idx >= n)
			return 0;
		if (cache[idx] != -1)
			return cache[idx];
		// 리프노드라면 
		if (tree.get(idx).size() == 0)
			return cache[idx] = 1;
		// 리프가 아닐 경우 
		else
		{
			ArrayList<Integer> v = new ArrayList<Integer>();
			int next, ret = 0, k = 0, m = 0, temp, time = 0;
			for (int i=0; i< tree.get(idx).size(); i++)
			{
				next = tree.get(idx).get(i);
				v.add(dp(next));
			}
			Collections.sort(v);
			// 현재 서브트리중 제일 시간 오래걸리는거부터 추가 
			// 자식들 중 내가 자식을 호출하는 시간 k와 해당 서브트리의 시간 총합 temp의 값이 
			// 제일 큰 것을 찾으면서 이전에 찾은 제일 큰 시간을 빼주면 순수하게 전파되는 시간만 구할 수 있다.
			for (int i = v.size()-1; i>=0; i--)
			{
				temp = v.get(i);
				if (m < temp + k)
				{
					ret += (temp + k - m);
					m = temp + k;
				}
				k++;
			}
			if (idx != 0)
				ret++;
			return cache[idx] = ret;
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner scan = new Scanner(System.in);
		for (int i=0; i<=50; i++)
		{
			tree.add(new ArrayList<Integer>());
			cache[i] = -1;
		}
		n = scan.nextInt();
		for (int i=0; i<n; i++)
		{
			int p = scan.nextInt(); 
			if (p != -1)
				tree.get(p).add(i);
		}
		ans = dp(0);
		// n이 1이면 나만 있는것이므로 전파 시간은 0이다 -> 안하면 틀림 
		if (n == 1)
			ans = 0;
		System.out.println(ans);
	}
}
