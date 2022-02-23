import java.io.*;
import java.util.*;

// mst 문제
// 모든 노드간 간선 가중치 계산해서 mst 구성하면 됨 

// 틀렸던 이유
// compareTo 에서 에러 발생 
// 마지막 우선순위큐에서 하나씩 뽑을때 for로 구현해서 꼬임
// 무조건 while 쓰자
class pair implements Comparable<pair>{
	int x, y;
	double z;
	public pair(int x, int y, double z) {
		this.x = x;
		this.y = y;
		this.z = z;
	}
	@Override
	public int compareTo(pair o) {
		if (this.z > o.z)
			return 1;
		else if (this.z == o.z)
			return 0;
		else 
			return -1;
	}
	
}

public class Main {
	
	static int arr[][] = new int[1003][2];
	static int parent[] = new int[1003];
	static int n;
	static double e;
	static int find(int i)
	{
		if (i == parent[i])
			return i;
		return parent[i] = find(parent[i]);
	}
	static void union(int a, int b)
	{
		int root1 = find(a);
		int root2 = find(b);
		if (root1 != root2)
			parent[root1] = root2;
	}
	static long dist(long x1, long y1, long x2, long y2)
	{
		long t1 = (x1 - x2) * (x1 - x2);
		long t2 = (y1 - y2) * (y1 - y2);
		return t1 + t2;
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner scan = new Scanner(System.in);
		int test = scan.nextInt();
		for (int t = 1; t <= test; t++)
		{
			PriorityQueue<pair> q = new PriorityQueue<pair>();
			double ans = 0;
			n = scan.nextInt();
			for (int i=1; i<=n; i++)
				parent[i] = i;
			for (int i=1; i<=n; i++)
				arr[i][0] = scan.nextInt();
			for (int i=1; i<=n; i++)
				arr[i][1] = scan.nextInt();
			e = scan.nextDouble();
			// 이중 for 돌면서 모든 간선 가중치를 계산해서 우선순위 큐에 삽입 
			for (int i=1; i<=n; i++)
			{
				for (int j=i + 1; j<=n; j++)
				{
					if (i == j)
						continue;
					double temp = dist(arr[i][0], arr[i][1], arr[j][0], arr[j][1]);
					q.add(new pair(i, j, temp));
				}
			}
			int x,y;
			double z;
			while (!q.isEmpty())
			{
				x = q.peek().x;
				y = q.peek().y;
				z = q.peek().z;
				if (find(x) != find(y))
				{
					union(x, y);
					ans += (z * e);
				}
				q.poll();
			}
			System.out.println("#" + t + " " + Math.round(ans));
		}
	
	}	
}
