import java.io.*;
import java.util.*;


public class Main {
	
	static int n, m, k, ans;
	static int arr[] = new int[31];
	
	// 냅색의 시간복잡도에 대해 잘못 생각해서 못풀고 있었다.
	// 냅색의 시간 복잡도 = O (n * w)
	// 최악의 경우에도 모든 배열을 1번씩만 방문하기 때문이다 
	// dp[사용한 추의 개수][사용한 추의 무게 총합]
	static int cache[][] = new int[31][15001];
	
	public static void dp(int idx, int weight)
	{
		if (idx > n)
			return;
		if (cache[idx][weight] != -1)
			return;
		// 방문 처리 
		cache[idx][weight] = 1;
		// 구슬쪽에 놓는 경우
		// 여기서 절댓값으로 보정하는게 핵심 
		// 음수라는건 구슬쪽이 더 무겁다는 건데 그럴일이 없도록 항상 오른쪽이 더 무겁게 한다고 가정
		dp(idx + 1, Math.abs(weight - arr[idx]));
		// 놓지 않는 경우 
		dp(idx + 1, weight);
		// 구슬 반대쪽에 놓는 경우
		dp(idx + 1, weight + arr[idx]);
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		for (int i=0; i<n; i++)
			arr[i] = scan.nextInt();
		for (int i=0; i<=30; i++)
		{
			for (int j=0; j<=15000; j++)
				cache[i][j] = -1;
			
		}
		
		dp(0,0);
		
		m = scan.nextInt();
		for (int k=0; k<m; k++)
		{
			int target = scan.nextInt();
			ans = 0;
			if (target > 15000)
				ans = -1;
			else
			{
				// 뽑은 것 + 뽑지 않은 것 + 뺀 것  = n개 이므로 최종은 n
				// 목적지에 도달한 케이스가 있는 경우 
				if (cache[n][target] != -1)
					ans = 1;
				else
					ans = -1;
			}
			if (ans == -1)
				System.out.print("N ");
			else
				System.out.print("Y ");
		}
	}
}
