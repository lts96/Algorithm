import java.io.*;
import java.util.*;

public class Main {
	static boolean flag = false;
	static int arr[][] = new int[10][2];
	static boolean select[] = new boolean[10];
	static int n, ans = Integer.MAX_VALUE;
	public static void brute(int idx)
	{
		if (idx == n)
		{
			int cnt = 0;
			int sum1 = 1, sum2 = 0;
			for (int i=0; i<n; i++)
			{
				if (select[i])
				{
					cnt++;
					sum1 *= arr[i][0];
					sum2 += arr[i][1];
				}
			}
			if (cnt == 0)
				return;
			ans = Math.min(ans, Math.abs(sum1 - sum2));
			return;
		}
		select[idx] = true;
		brute(idx + 1);
		select[idx] = false;
		brute(idx + 1);
		return;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		int a,b;
		for (int i=0; i<n; i++)
		{
			arr[i][0] = scan.nextInt();
			arr[i][1] = scan.nextInt();			
		}
		brute(0);
		System.out.println(ans);
		return;
	}	
}
