import java.util.*;
public class Main {
	static int MAX = 100010;
	static int INF = 2000000010;
  
  // 투포인터 사용해서 차이가 m이상인 조합만 찾아내는 문제
  
	public static void main(String[] args) {
		long arr[] = new long[MAX];
		long ans = INF;
		long diff;
		int p1, p2;
		p1 = 0;
		p2 = 0;
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int m = scan.nextInt();
		for (int i=0; i<MAX; i++)
		{
			if (i < n)
				arr[i] = scan.nextInt();
			else
				arr[i] = INF;
		}
		Arrays.sort(arr);
		while(p1 <= p2 && p2 != n)
		{
			diff = Math.abs(arr[p2] - arr[p1]);
			if (diff < m)
			{
				if (p2 <= n - 1)
				{
					p2++;
					continue;
				}
			}
			else
			{
				ans = Math.min(ans, diff);
				p1++;
			}
		}
		System.out.println(ans);
	}
}
