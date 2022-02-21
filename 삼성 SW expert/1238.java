import java.io.*;
import java.util.*;

// 노드 번호와 depth를 같이 이동시키기 위해 pair 구현 
class pair {
	int x,y;
	public pair(int x,int y) {
		this.x = x;
		this.y = y;
	}
}
public class Solution {
	
	static int ans, n, start;
	static int arr[][] = new int[110][110];
	static boolean visit[] = new boolean[110];
    // 각 노드를 방문할때마다 해당 노드의 depth를 저장하기 위한 배열 
	static int depth[] = new int[110];
	static void bfs(int s)
	{
		Queue <pair> q = new LinkedList<pair>();
		visit[s] = true;
		depth[s] = 0;
		q.add(new pair(s, 0));
		int x,d;
        // bfs를 돌면서 해당 노드의 depth를 기록 
		while (!q.isEmpty())
		{
			x = q.peek().x;
			d = q.peek().y;
			depth[x] = d;
			q.poll();
			for (int i=1; i<=100; i++)
			{
                // 간선이 없거나 이미 방문한 노드는 제외하고 탐색 
				if (arr[x][i] == 1 && !visit[i])
				{
					visit[i] = true;
					q.add(new pair(i, d + 1));
				}
			}
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner scan = new Scanner(System.in);
		int test = 10,a,b;
		for (int t = 1; t <= test; t++)
		{
			for (int i=1; i<=100; i++)
			{
				visit[i] = false;
				depth[i] = -1;
				for (int j=1; j<=100; j++)
					arr[i][j] = 0;
			}
			n = scan.nextInt();
			start = scan.nextInt();
			for (int i=0; i<n/2; i++)
			{
				a = scan.nextInt();
				b = scan.nextInt();
				arr[a][b] = 1;
			}
			ans = 0;
			bfs(start);

            // 가장 깊은 depth를 우선 찾음 
			int md = -1;
			for (int i=1; i<= 100; i++)
				md = Math.max(md, depth[i]);
            // 가장 깊은 depth 중에서 제일 노드값이 큰 걸 찾음 
			for (int i=1; i<=100; i++)
			{
				if (depth[i] == md)
					ans = Math.max(ans, i);
			}
			System.out.println("#" + t + " " +ans);
			
		}
	}	
}
