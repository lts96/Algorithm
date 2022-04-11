import java.util.*;
import java.io.*;

// 분할 정복 + 페르마의 소정리 활용
/*
페르마의 소정리 -> p가 소수, a가 p의 배수가 아닐때 a^p = a (mod p)
여기서 p를 반대로 나눠서 a^ (p-1) = 1/a 를 이용해 분모 부분을 구할 수 있다는 게 핵심이다.
1,000,000,007 은 소수다
팩토리얼을 구하면서 미리 dp처럼 저장해두면 한번만 구해도 된다
 */
class Main {
	static long n, m, k, ans;
	static long div = 1000000007;
	
	// 분할정복으로 지수 p 구하기 
	static long divide(long base, long p)
	{
		if (p == 0)
			return 1;
		if (p == 1)
			return base;
		// 한번만 계산하고 같은 값을 2번 사용하자 
		long temp;
		if (p % 2 != 0)
		{
			temp = divide(base, p - 1);
			return (temp * base) % div;
		}
		else
		{
			temp = divide(base, p / 2);
			return (temp * temp) % div;
		}
	}
	
	public static void main(String args[]) throws Exception {
		Scanner scan = new Scanner(System.in);
		long a,b,c, d, e;
		ans = 0;
		n = scan.nextLong();
		k = scan.nextLong();
		if (k == 0)
			System.out.println(1);
        // 팩토리얼을 미리 저장하지 않으면 런타임에 걸림 
        // 재귀로 구현해서 더욱 오래걸렸음 
    else{
		    long[] arr = new long[(int) (n + 1)];
            arr[0] = 1;
		    arr[1] = 1; 			
		    for (int i = 2; i <= n; i++) {
			    arr[i] = (arr[i - 1] * i) % div;
		    }
		    a = arr[(int) n];
		    b = arr[(int) k];
		    c = arr[(int) (n - k)];
		    d = (b * c) % div;
		    e = divide(d, div - 2);
			  System.out.println((a * e) % div);
    }
	}
}
