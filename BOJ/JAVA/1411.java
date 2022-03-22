import java.io.*;
import java.util.*;


// 문제를 이해하기가 까다로웠음
// a -> b로 변환할때 b로 이미 변환된 문자가 있으면 안된다는 조건
// 문자열 + 브루트포스 
public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		String arr[] = new String[n];
		for (int i=0; i<n; i++)
			arr[i] = scan.next();
		int ans = 0;
		boolean flag;
		char a,b;
		for (int i=0; i<n; i++)
		{
			for (int j=i+1; j<n; j++)
			{
				char alpha[] = new char[26];
				boolean visit[] = new boolean[26];
				for (int k = 0; k<26; k++)
				{
					alpha[k] = '.';
					visit[k] = false;
				}
				flag = true;
				for (int k=0; k<arr[i].length(); k++)
				{
					a = arr[i].charAt(k);
					b = arr[j].charAt(k);
					int idx = a - 'a';
					int idx2 = b - 'a';
					// 아직 갱신되지 않았으면 + 누군가가 해당 알파벳으로 변환하지 않았다면
					if (alpha[idx] == '.' && !visit[idx2])
					{
						alpha[idx] = b;
						visit[idx2] = true;
					}
					else
					{
						if (alpha[idx] != b)
						{
							flag = false;
							break;
						}
					}
				}
				if (flag)
				{
					//System.out.println(arr[i] + " " + arr[j]);
					ans++;
				}
			}
		}
		System.out.println(ans);
	}
}
