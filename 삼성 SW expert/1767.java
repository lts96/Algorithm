import java.io.*;
import java.util.*;

// sea 1767 프로세서 연결하기 -> 상시 역량 신청할때 예제로 나오는 문제 
// 백트래킹 + 구현으로 해결 
// 브루트포스만 하면 시간에 걸림 
public class Solution{
	
	static int n, m, k, ans, max;
	static int arr[][] = new int[20][20];
	
	// 코어 방향 설정  
	static int core[] = new int[13];
	static int pos[][] = new int[20][2];
	static int dx[] = {-1,1,0,0};
	static int dy[] = {0,0,-1,1};
	
	
	static void backtracking(int idx, int sum, int cnt)
	{
		if (idx == k)
		{
            // 최대 개수가 연결되었으면 갱신 
			if (cnt > max)
			{
				max = cnt;
				ans = sum;
			}
            // 그리고 그 중에서 전선 합이 제일 작은 경우를 찾는다 
			else if (cnt == max)
				ans = Math.min(ans, sum);
			return;
		}
		// 4방향을 돌면서 전원 연결이 가능한지 체크 
		int x = pos[idx][0];
		int y = pos[idx][1];
		// 벽면에 붙어있는 경우는 전선 연결 필요없음 
		if (x == 0 || y == 0 || x == n-1 || y == n-1)
		{
			backtracking(idx + 1, sum, cnt + 1);
			return;
		}
		int nx, ny, len;
		boolean connect;
		for (int i=0; i<4; i++)
		{
			len = 0;
			connect = false;
			for (int d = 1; d <=n; d++)
			{
				nx = x + dx[i] * d;
				ny = y + dy[i] * d;
				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					break;
				if (arr[nx][ny] != 0)
					break;
				arr[nx][ny] = 2;
				len = d;
				// 끝까지 가서 연결한 경우 
				if (nx == 0 || ny == 0 || nx == n-1 || ny == n-1)
					connect = true;
			}

            // 연결이 가능한 경우 
			if (connect)
				backtracking(idx + 1, sum + len, cnt + 1);
            // 연결이 불가능한 경우도 체크해서 넘겨줘야 모든 경우 탐색 가능 
			else
				backtracking(idx + 1, sum + len, cnt);
			// 전선 다시 지우기 
			for (int d =1; d <= len; d++)
			{
				nx = x + dx[i] * d;
				ny = y + dy[i] * d;
				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					break;
				if (arr[nx][ny] == 2)
					arr[nx][ny] = 0;
				else
					break;
			}
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner scan = new Scanner(System.in);
		int test = scan.nextInt();
		
		for (int t = 0; t < test; t++)
		{
			n = scan.nextInt();
			max = 0;
			k = 0;
			ans = 0;
			for (int i=0; i<n; i++)
			{
				for (int j=0; j<n; j++)
				{
					arr[i][j] = scan.nextInt();
					if (arr[i][j] == 1)
					{
						pos[k][0] = i;
						pos[k][1] = j;
						k++;
					}
				}
			}
			for (int i=0; i<k; i++)
				core[i] = 0;
			backtracking(0,0,0);
			System.out.println("#"+ (t+1) + " "+ans);
		}
	}
}
