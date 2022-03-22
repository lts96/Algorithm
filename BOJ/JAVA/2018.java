import java.io.*;
import java.util.*;

// 두포인터 + 간단한 수학 문제

public class Main {
	static int ans;
	static int n;
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		long left = 0;
		long right = 1;
		long temp, result, t1, t2;
		while (left < right)
		{
			if (left > n || right > n)
				break;
			t1 = right * (right + 1) / 2;
			t2 = left * (left + 1) / 2;
			result = t1 - t2;
			temp = n;
			if (result == temp)
			{
				ans++;
				right++;
			}
			else if (result > temp)
				left++;
			else
				right++;
		}
		System.out.println(ans);
	}
}
