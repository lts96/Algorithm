import java.io.*;
import java.util.*;

// 백준 영역 구하기 
// 간단한 bfs 응용 문제 
public class Main {
	static int n,m,k;
	static int arr[][] = new int[101][101];
	static boolean visit[][] = new boolean[101][101];
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
	static int bfs(int sx, int sy)
	{
		int cnt = 0;
		visit[sx][sy] = true;
		Queue <pair> q = new LinkedList<pair>();
		q.add(new pair(sx, sy));
		int x,y,nx,ny;
		while (!q.isEmpty())
		{
			x = q.peek().first;
			y = q.peek().second;
			cnt++;
			q.poll();
			for (int i=0; i<4; i++)
			{
				nx = x + dx[i];
				ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					continue;
				if (!visit[nx][ny] && arr[nx][ny] == 0)
				{
					visit[nx][ny] = true;
					q.add(new pair (nx, ny));
				}
			}
		}
		return cnt;
	}
	static void coloring(int x1, int y1, int x2, int y2)
	{
		for (int i=x1; i < x2; i++)
		{
			for (int j = y1; j <y2; j++)
				arr[i][j] = 1;
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		m = scan.nextInt();
		k = scan.nextInt();
		int x1,y1,x2,y2;
		ArrayList <Integer> ans = new ArrayList<Integer>();
		for (int i=0; i<k; i++)
		{
			x1 = scan.nextInt();
			y1 = scan.nextInt();
			x2 = scan.nextInt();
			y2 = scan.nextInt();
			coloring(y1,x1,y2,x2);
		}
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<m; j++)
			{
				if (arr[i][j] == 0 && !visit[i][j])
					ans.add(bfs(i,j));
			}
		}
		System.out.println(ans.size());
		Collections.sort(ans);
		for (int i : ans)
			System.out.print(i + " ");
		return;
	}	
}
class pair {
	int first, second;
	pair(int x, int y){
		this.first = x;
		this.second = y;
	}
}
