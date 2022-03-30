import java.io.*;
import java.util.*;


public class Main {
	static int n, ans;
	static int arr[][] = new int[51][51];
	static boolean visit[][] = new boolean[51][51];
	static int r, c;
	static int px, py;
	static int dx[] = {-1,1,0,0};
	static int dy[] = {0,0,-1,1};
  
  
  // bfs 사용해서 용사와 불을 같이 움직이는 문제 
  // 용사 먼저 움직이고 불 충돌 처리를 하거나 불을 먼저 움직이고 용사 처리를 해줘야함 
  // 불이 여러개일 경우도 고려해야함 
	static void print()
	{
		System.out.println();
		for (int i=0; i<r; i++)
		{
			for (int j=0; j<c; j++)
				System.out.print(arr[i][j] + " ");
			System.out.println();
		}
	}
	static void bfs(int sx, int sy)
	{
		visit[px][py] = true;
		Queue<pair> q = new LinkedList<pair>();
		q.add(new pair(px, py, 0));
		for (int i=0; i<r; i++)
		{
			for (int j=0; j<c; j++)
			{
				if (arr[i][j] == 1)
					q.add(new pair(i, j, -1));
			}
		}
		int x, y, nx, ny, cnt;
		while (!q.isEmpty())
		{
			x = q.peek().x;
			y = q.peek().y;
			cnt = q.peek().z;
			/*
			if (cnt != -1)
			{
				System.out.println(x + " " + y + " " + cnt + " " + arr[x][y]);
				print();
			}
			*/
			q.poll();
			if (x < 0 || x >= r || y < 0 || y >= c)
				continue;
			if (cnt != -1 && arr[x][y] == 1)
				continue;
			if (arr[x][y] == 2)
			{
				ans = cnt;
				return;
			}
			for (int i=0; i<4; i++)
			{
				nx = x + dx[i];
				ny = y + dy[i];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c)
					continue;
				if (cnt != -1)
				{
					if (visit[nx][ny] || arr[nx][ny] == 1 || arr[nx][ny] == 3)
						continue;
					visit[nx][ny] = true;
					q.add(new pair(nx, ny, cnt + 1));
				}
				else
				{
					if (arr[nx][ny] != 0)
						continue;
					arr[nx][ny] = 1;
					q.add(new pair(nx, ny, cnt));
				}
			}
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner scan = new Scanner(System.in);
		r = scan.nextInt();
		c = scan.nextInt();
		int input;
		int sx = -1, sy = -1;
		for (int i = 0; i < r; i++)
		{
			String s = scan.next();
			for (int j = 0; j < s.length(); j++)
			{
				char c = s.charAt(j);
				if (c == 'S')
				{
					px = i;
					py = j;
				}
				else if (c == '*')
					arr[i][j] = 1;
				else if (c == 'X')
					arr[i][j] = 3;
				else if (c == 'D')
					arr[i][j] = 2;
			}
		}
		bfs(sx, sy);
		if (ans == -1 || ans == 0)
			System.out.println("impossible");
		else
			System.out.println(ans);
		return;
	}	
}
class pair{
	int x,y,z;
	pair(int x, int y, int z)
	{
		this.x = x;
		this.y = y;
		this.z = z;
	}
}
