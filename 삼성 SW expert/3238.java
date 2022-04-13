import java.util.*;
import java.io.*;

class Solution {
	static long n, r, p, m, k, ans;
	static long div = 1000000007;
	
	
	// 도저히 못풀겠어서 검색 
    // 뤼카의 정리를 이해하는게 필수적인 문제 
    // sea 3238
  // 백준에도 똑같이 있음   이항계수 4
	public static void main(String args[]) throws Exception {
		Scanner scan = new Scanner(System.in);
		int test = scan.nextInt();
		for (int t = 1; t <= test; t++)
		{
			ans = 1;
			n = scan.nextLong();
			r = scan.nextLong();
			p = scan.nextLong();
			long arr[] = new long[(int) (p + 1)];
			arr[0] = arr[1] = 1;
			for (int i=2; i<= p; i++)
				arr[i] = (i * arr[i - 1]) % p;
			
			// p로 계속 나눠주면서 n과 r을 p진수로 변환 
			// 뤼카의 정리를 사용가능하게 만들자 
			long a, b;
			while (n > 0 || r > 0)
			{
				a = n % p;
				b = r % p;
				
				// 중간이 하나라도 0이면 어차피 결과는 0
				if (b > a)
	            {
	                ans = 0;
	                break;
	            }
				
				// 뤼카의 정리대로 도중에 나온 걸 계속 곱해가면서 진행 
	            ans = (ans * arr[(int)a]) % p;
	            // 페르마의 소정리
	            for (int i = 0; i < p - 2; i++)
	                ans = (ans * arr[(int)(a - b)] * arr[(int)b]) % p;
	            n /= p;
	            r /= p;
			}
			ans %= p;
			System.out.println("#" + t + " " + ans);
		}
	}
}
