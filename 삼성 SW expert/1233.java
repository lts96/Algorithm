import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 말은 트리문제지만 규칙만 찾으면 끝인 문제
// 트리의 리프들은 무조건 숫자고 리프가 아니면 무조건 연산자여야함
// 배열 돌면서 조건이 맞는지 확인하고 답 바꾸면 끝

public class Solution {
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder("");
		StringTokenizer st;
		for (int t = 1; t<=10; t++) {
			String arr[] = new String[1000];
			boolean isLeaf[] = new boolean[1000];
			int ans = 1;
			int n = Integer.parseInt(br.readLine());
			char v;
			int idx;
			for (int i=1; i<=n; i++)
			{
				st = new StringTokenizer(br.readLine());
				arr[Integer.parseInt(st.nextToken())] = st.nextToken();
			}
			for (int i=1; i<=n; i++)
			{
				char c = arr[i].charAt(0);
				if (i > n / 2)
				{
					if (c == '-' || c == '+' || c == '*' || c == '/')
					{
						ans = 0;
						break;
					}
				}
				else
				{
					if (c >= '0' && c <= '9')
					{
						ans = 0;
						break;
					}
				}
			}
			System.out.println("#" + t + " " + ans);
		}
	}
}
