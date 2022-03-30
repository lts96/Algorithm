import java.io.*;
import java.util.*;

//  문자열 구현 문제
// 뒤에서부터 거꾸로 로직을 적용하면서 시작 문자열과 일치하는지 체크하면 끝
public class Main {
	
	static int n, ans;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner scan = new Scanner(System.in);
		String s1 = scan.next();
		String s2 = scan.next();
		char c;
		while (s1.length() != s2.length())
		{
			n = s2.length() - 1;
			c = s2.charAt(n);
			s2 = s2.substring(0, n);
			if (c == 'B')
			{
				StringBuffer sb = new StringBuffer(s2);
				s2 = sb.reverse().toString();
			}
			//System.out.println(s2);
		}
		if (s1.equals(s2))
			ans = 1;
		System.out.println(ans);
	}
}
