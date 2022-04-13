import java.io.*;
import java.util.*;

// 백준 미로 탈출 
class pair {
	int first, second, third, fourth;
	pair(int x, int y, int z, int w){
		this.first = x;
		this.second = y;
		this.third = z;
		this.fourth = w;
	}
}
public class Main {
	static int n,m,k, ans = Integer.MAX_VALUE;
	static int hx,hy,ex,ey;
	static int arr[][] = new int[1001][1001];
	static boolean visit[][][] = new boolean[1001][1001][2];
	static int dx[] = {-1,1,0,0};
	static int dy[] = {0,0,-1,1};
	static void print()
	{
		System.out.println();
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<m; j++)
				System.out.print(arr[i][j] + " ");
			System.out.println();
		}
	}
	static void bfs(int sx, int sy, int crash)
	{
		int cnt = 0;
		visit[sx][sy][crash] = true;
		Queue <pair> q = new LinkedList<pair>();
		q.add(new pair(sx, sy, 0, crash));
		int x,y,nx,ny, d, c;
		while (!q.isEmpty())
		{
			x = q.peek().first;
			y = q.peek().second;
			d = q.peek().third;
			c = q.peek().fourth;
			q.poll();
			if (x == ex && y == ey)
			{
				ans = Math.min(ans, d);
				return;
			}
			for (int i=0; i<4; i++)
			{
				nx = x + dx[i];
				ny = y + dy[i];
				if (nx < 1 || nx > n || ny < 1 || ny > m)
					continue;
				if (!visit[nx][ny][c] && arr[nx][ny] == 0)
				{
					visit[nx][ny][c] = true;
					q.add(new pair (nx, ny, d + 1, c));
				}
				else if (!visit[nx][ny][c] && arr[nx][ny] == 1 && c == 0)
				{
					visit[nx][ny][c + 1] = true;
					q.add(new pair (nx, ny, d + 1, c + 1));
				}
			}
		}
		return;
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		m = scan.nextInt();
		hx = scan.nextInt();
		hy = scan.nextInt();
		ex = scan.nextInt();
		ey = scan.nextInt();
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=m; j++)
				arr[i][j] = scan.nextInt();
		}
		// 시작점부터 벽이 있다면? 
		bfs(hx, hy , arr[hx][hy]);
		if (ans == Integer.MAX_VALUE)
			System.out.println("-1");
		else
			System.out.println(ans);
	}	
}
