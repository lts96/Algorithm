import java.io.*;
import java.util.*;

// 0222 과제 
// sea 7465 번
// 유니온 파인드로 집합을 만들고 서로 다른 집합의 개수를 세는 문제

public class Solution {
	static int n, m, ans;
	static int arr[] = new int[200001];
	
	static int find(int i)
	{
		if (i == arr[i])
			return i;
		return arr[i] = find(arr[i]);
	}
	static void union_set(int a, int b)
	{
		int root1 = find(a);
		int root2 = find(b);
		if (root1 == root2)
			return;
		arr[root1] = root2;
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner scan = new Scanner(System.in);
		int a,b,c;
		char cmd;
		int test = scan.nextInt();
		for (int t = 1; t<= test; t++)
		{
			ans = 0;
			n = scan.nextInt();
			m = scan.nextInt();
			for (int i=0; i<=n; i++)
				arr[i] = i;
			for (int i=0; i<m; i++)
			{
				a = scan.nextInt();
				b = scan.nextInt();				
				if (find(a) != find(b))
					union_set(a , b);
			}
            // 집합을 모두 구성한 다음 
            // 다시 find()를 해줘서 루트가 혹시 갱신 안된게 있으면 갱신 해주고 
            // 서로 다른 루트의 개수를 카운팅 하면 정답 
			int cnt[] = new int[n+1];
			for (int i=1; i<=n; i++)
			{
				find(i);
				cnt[arr[i]]++;
			}
			for (int i=1; i<=n; i++)
			{
				if (cnt[i] > 0)
					ans++;
			}
			System.out.println("#" + t + " " + ans);
		}
	}	
}
