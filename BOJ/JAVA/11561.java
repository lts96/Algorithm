import java.util.*;
public class Main {
	// 이분 탐색 문제
	// 1 + 2 + .. m 을 더한 값이 n이하로 가능할때 최대 m값을 찾는 파라메트릭 서치 문제
	// 근데 그냥 m(m+1)/2 <= n으로 하면 long 넘어가므로 아래 식으로 바꿔서 비교
	public static long solve(long n) {
		long l = 1,r = n,m,ans = 0;
		while(l <= r)
		{
			m = (l + r) / 2;
			if (m <=(Math.sqrt(8*n+1)-1) / 2)
			{
				ans = Math.max(ans, m);
				l = m + 1;
			}
			else
				r = m - 1;
		}
		return ans;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int test = scan.nextInt();
		long input;
		for (int t=0; t<test; t++)
		{
			input = scan.nextLong();
			System.out.println(solve(input));
		}
	}
}
