import java.io.*;
import java.util.*;

public class Main {
	static int n, ans;
	static boolean select[] = new boolean[30];
	static int word[] = new int[30];
	static int check = (int) (Math.pow(2, 26) - 1);
	
	// 브루트포스로 모든 경우의 수 탐색 
	static void subset(int idx, int bit)
	{
		if (idx == n)
		{
			// 모든 알파벳이 출현 = 모든 비트가 1로 채워짐
			if (bit == check)
				ans++;
			return;
		}
		subset(idx + 1, bit | word[idx]);
		subset(idx + 1, bit);
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		String s;
		int temp;
		// 입력받으면서 단어에 어떤 알파벳이 있는지 비트마스크 전처리 
		for (int i=0; i<n; i++)
		{
			temp = 0;
			s = scan.next();
			for (int j = 0; j < s.length(); j++)
				temp |= (1 << (s.charAt(j) - 'a'));
			word[i] = temp;
		}
		subset(0,0);
		System.out.println(ans);
	}	
}
