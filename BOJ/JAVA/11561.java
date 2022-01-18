import java.util.*;
public class Main {
	
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
