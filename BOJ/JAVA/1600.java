import java.io.*;
import java.util.*;

class pair{
	int x,y,z,w;
	pair(int x, int y, int z, int w){
		this.x = x;
		this.y = y;
		this.z = z;
		this.w = w;
	}
}
public class Main {
	
	static int n, k, ans;
	static int w,h;
	static int arr[][] = new int[201][201];
	static int dx[] = {-1,1,0,0};
	static int dy[] = {0,0,-1,1};
	static int dx2[] = {2,2,-2,-2,1,1,-1,-1};
	static int dy2[] = {-1,1,-1,1,2,-2,2,-2};
	
	// 3차원 방문으로 안하면 틀림 
	// 이유 : 원숭이로 하면 통과가 되는데 말로 먼저 도달해버려서 통과 불가능한 경우가 생김 
	static boolean visit[][][] = new boolean[201][201][31];
	
	static void print()
	{
		System.out.println();
		for (int i=0; i<h; i++)
		{
			for (int j=0; j<w; j++)
				System.out.print(arr[i][j] + " ");
			System.out.println();
		}
	}
	
	static void bfs(int sx, int sy)
	{
		visit[sx][sy][0] = true;
		Queue<pair> q = new LinkedList<pair>();
		q.add(new pair(0,0,0,0));
		int x, y, nx, ny, cnt, horse;
		while (!q.isEmpty())
		{
			x = q.peek().x;
			y = q.peek().y;
			cnt = q.peek().z;
			horse = q.peek().w;
			//System.out.println(x + " " + y + " " + cnt + " " + arr[x][y]);
			if (x == h - 1 && y == w - 1)
			{
				ans = cnt;
				return;
			}
			q.poll();
			if (horse < k)
			{
				for (int i=0; i<8; i++)
				{
					nx = x + dx2[i];
					ny = y + dy2[i];
					if (nx < 0 || nx >= h || ny < 0 || ny >= w)
						continue;
					if (visit[nx][ny][horse + 1] || arr[nx][ny] == 1)
						continue;
					visit[nx][ny][horse + 1] = true;
					q.add(new pair(nx, ny, cnt + 1, horse + 1));
				}
			}
			for (int i=0; i<4; i++)
			{
				nx = x + dx[i];
				ny = y + dy[i];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w)
					continue;
				if (visit[nx][ny][horse] || arr[nx][ny] == 1)
					continue;
				visit[nx][ny][horse] = true;
				q.add(new pair(nx, ny, cnt + 1, horse));
			}
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner scan = new Scanner(System.in);
		k = scan.nextInt();
		w = scan.nextInt();
		h = scan.nextInt();
		ans = -1;
		for (int i=0; i<h; i++)
		{
			for (int j=0; j<w; j++)
				arr[i][j] = scan.nextInt();
		}
		//print();
		bfs(0,0);
		System.out.println(ans);
	}
}
