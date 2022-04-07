import java.util.*;
import java.io.*;
class pair implements Comparable<pair>{
	int x, y, z;
	pair(int x, int y, int z)
	{
		this.x = x;
		this.y = y;
		this.z = z;	
	}
	@Override
	public int compareTo(pair o) {
		// TODO Auto-generated method stub
		return this.z - o.z;
	}
	
}
// 다익스트라 문제 
// 경로가 4방향이라서 dp로는 안됨 
class Solution {
	static int n, m, k, ans;
	static int arr[][] = new int[101][101];
	static int visit[][] = new int[101][101];
	static int dx[] = {-1,1,0,0};
	static int dy[] = {0,0,-1,1};
	
	static int dijkstra(int sx, int sy, int ex, int ey)
	{
		PriorityQueue<pair> q = new PriorityQueue<pair>();
		q.add(new pair(sx, sy, arr[sx][sy]));
		visit[sx][sy] = arr[sx][sy];
		
		int x,y,nx,ny,w;
		while (!q.isEmpty())
		{
			x = q.peek().x;
			y = q.peek().y;
			w = q.peek().z;
			//System.out.println(x + " " + y + " " + w);
			q.poll();
			if (x == n-1 && y == n - 1)
				continue;
			for (int i=0; i<4; i++)
			{
				nx = x + dx[i];
				ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					continue;
				if (visit[nx][ny] > arr[x][y] + w)
				{
					visit[nx][ny] = arr[x][y] + w;
					q.add(new pair(nx, ny , arr[x][y] + w));
				}
			}
		}
		return visit[ex][ey];
	}
	
	public static void main(String args[]) throws Exception {
		Scanner scan = new Scanner(System.in);
		int test = scan.nextInt();
	
		for (int t = 1; t <= test; t++) {
			ans = Integer.MAX_VALUE;
			n = scan.nextInt();
			for (int i=0; i<n; i++)
			{
				String s = scan.next();
				for (int j=0; j<n; j++)
				{
					arr[i][j] = s.charAt(j) - '0';
					visit[i][j] = Integer.MAX_VALUE;
				}
			}
			ans = dijkstra(0,0,n-1,n-1);
			System.out.println("#" + t + " " + ans);
		}
	}
}
