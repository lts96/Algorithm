import java.io.*;
import java.util.*;

public class Main {
	
	static int n, k, ans;
	
	// 백준  회문 
  	// 문자열, 투포인터?
	// 회문일때 -1 리턴 
	static int check1(String s)
	{
		int m = s.length();
		char l, r;
		for (int i=0; i < m / 2; i++)
		{
			l = s.charAt(i);
			r = s.charAt(m - 1 - i);
			if (l != r)
				return i;
		}
		return -1;
	}
	/*
	 * 	양쪽 끝에서부터 비교하면서 한번 틀리면 유사회문인지 판정
		유사회문인지 판정은 문자열을 2가지 경우로 잘라서 각각 자른게 회문인지 확인하면 됨
	 */
	static boolean check2(String s, int idx)
	{
		String sub1 = s.substring(idx, s.length() - idx - 1);
		String sub2 = s.substring(idx + 1, s.length() - idx);
		if (check1(sub1) == -1 || check1(sub2) == -1)
			return true;
		return false;
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		for (int i=0; i<n; i++)
		{
			ans = 0;
			String s = scan.next();
			int idx = check1(s);
			if (idx == -1)
				ans = 0;
			else if (check2(s, idx))
				ans = 1;
			else
				ans = 2;
			System.out.println(ans);
		}
	}
}
