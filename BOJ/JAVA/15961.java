import java.io.*;
import java.util.*;


public class Main {
	
	static int n, d, k, c, ans;
	static int arr[] = new int[6000007];
	static int food[] = new int[3002];
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s[] = br.readLine().split(" ");
		n = Integer.parseInt(s[0]);
		d = Integer.parseInt(s[1]);
		k = Integer.parseInt(s[2]);
		c = Integer.parseInt(s[3]);
		
		for (int i=0; i<n; i++)
		{
			arr[i] = Integer.parseInt(br.readLine());
			arr[i + n] = arr[i]; 
		}
		
		// 초기 세팅 
		int l = 0;
		int r = k-1;
		int cnt = 0;
		for (int i = l; i <= r; i++)
		{
			if (food[arr[i]] == 0)
				cnt++;
			food[arr[i]]++;
		}
		ans = Math.max(ans, cnt);
		if (food[c] == 0)
			ans++;
		// 슬라이딩 윈도우 
		while (r < n + k - 1)
		{
			if (food[arr[l]] > 0)
				food[arr[l]]--;
			if (food[arr[l]] == 0)
				cnt--;
			l++;
			r++;
			food[arr[r]]++;
			if (food[arr[r]] == 1)
				cnt++;
			if (food[c] == 0)
				ans = Math.max(ans, cnt + 1);
			else
				ans = Math.max(ans, cnt);
		}
		System.out.println(ans);
	}
}
