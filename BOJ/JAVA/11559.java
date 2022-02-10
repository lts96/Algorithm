import java.io.*;
import java.util.*;

class pair {
	int x;
	int y;
	public pair(int x, int y){
		this.x = x;
		this.y = y;
	}
}

public class Main {
	
	// . = 0 R = 1 G = 2 B = 3 P = 4 Y = 5
	static int arr[][] = new int[13][7];
	static int visit[][] = new int[13][7];
	static int dx[] = {-1,1,0,0};
	static int dy[] = {0,0,-1,1};
	static int n = 12;
	static int m = 6;
	static int ans = 0;
	
	public static void print()
	{
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<m; j++)
				System.out.print(arr[i][j] + " ");
			System.out.println();
		}
		System.out.println();
	}
	public static int search()
	{
		int turn = 1, cnt = 0;
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<m; j++)
				visit[i][j] = -1;
		}
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<m; j++)
			{
				if (arr[i][j] != 0 && visit[i][j] == -1)
				{
					if(bfs(i, j, arr[i][j], turn++) != 0)
						cnt++;
				}
			}
		}
		return cnt;
	}
	public static int bfs(int sx, int sy , int color, int turn)
	{
		Queue <pair> q = new LinkedList<pair>();
		visit[sx][sy] = turn;
		q.add(new pair(sx, sy));
		
		int x,y,nx,ny,cnt = 1;
		while (!q.isEmpty())
		{
			x = q.peek().x;
			y = q.peek().y;
			q.poll();
			for (int i=0; i<4; i++)
			{
				nx = x + dx[i];
				ny = y + dy[i];
				if (nx < 0 || nx > n || ny < 0 || ny > m)
					continue;
				if (visit[nx][ny] == -1 && arr[nx][ny] == color)
				{
					cnt++;
					visit[nx][ny] = turn;
					q.add(new pair(nx, ny));
				}
			}
		}
		if (cnt >= 4)
		{
			for (int i=0; i<n; i++)
			{
				for (int j=0; j<m; j++)
				{
					if (visit[i][j] == turn)
						arr[i][j] = 0;
				}
			}
			return 1;
		}
		else
			return 0;
	}
	// 중간이 먼저 사라지는 경우를 고려하지 않음  + 색깔을 3개만 설정해서 틀림 
	public static void down()
	{
		int cnt;
		int temp[][] = new int[13][7];
		int d[][] = new int[13][7];
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<m; j++)
				d[i][j] = temp[i][j] = 0;
		}
		for (int j = 0; j < m; j++)
		{
			cnt = 0;
			for (int i = n - 1; i >= 0; i--)
			{
				d[i][j] = cnt;
				if (arr[i][j] == 0)
					cnt++;
			}
			if (cnt != 0 && cnt != 12)
			{
				for (int i = 0; i < n; i++)
				{
					if (arr[i][j] != 0)
						temp[i + d[i][j]][j] = arr[i][j]; 
				}
				for (int i = 0; i < n; i++)
					arr[i][j] = temp[i][j]; 
			}
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner scan = new Scanner(System.in);
		String s;
		for (int i=0; i<n; i++)
		{
			s = scan.next();
			for (int j=0; j<s.length(); j++)
			{
				if (s.charAt(j) == '.')
					continue;
				else if (s.charAt(j) == 'R')
					arr[i][j] = 1;
				else if (s.charAt(j) == 'G')
					arr[i][j] = 2;
				else if (s.charAt(j) == 'B')
					arr[i][j] = 3;
				else if (s.charAt(j) == 'P')
					arr[i][j] = 4;
				else if (s.charAt(j) == 'Y')
					arr[i][j] = 5;
			}
		}
		while (search() != 0)
		{
			down();
			ans++;
		}
		System.out.println(ans);
	}	
}
