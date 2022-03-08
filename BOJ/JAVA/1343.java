import java.io.*;
import java.util.*;
import java.awt.*;

public class Main {
	
	// 무조건 AAAA 출력 가능하면 출력 
	// 그리디적으로 앞에서부터 가능한걸 바로바로 출력 
	static int n, ans;
	static char arr[] = new char[53];
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner scan = new Scanner(System.in);
		String s = scan.next();
		n = s.length();
		int cnt = 0;
		boolean flag = true;
		for (int i=0; i<n; i++)
		{
			cnt = 0;
			if (s.charAt(i) == '.')
			{
				arr[i] = '.';
				continue;
			}
			for (int j = i; j < i + 4; j++)
			{
				if (j >= n || s.charAt(j) == '.')
					break;
				cnt++;
			}
			if (cnt == 4)
			{
				for (int j = i; j < i + 4; j++)
					arr[j] = 'A';
				i += 3;
				continue;
			}
			else if (cnt == 2)
			{
				for (int j = i; j < i + 2; j++)
					arr[j] = 'B';
				i += 1;
				continue;
			}
			else
			{
				System.out.println(-1);
				flag = false;
				break;
			}
		}
		if (flag)
		{
			for (int i=0; i<n; i++)
				System.out.print(arr[i]);
		}
	}
}
