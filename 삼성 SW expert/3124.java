import java.util.*;
import java.io.*;

// 3/30일 과제 
// sea 3124
class pair implements Comparable<pair>{
 	int x,y,z;
    pair (int x, int y, int z)
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
class Solution
{
    static int arr[] = new int[100002];
    static int find(int a)
    {   
        if (a == arr[a])
            return a;
        return arr[a] = find(arr[a]);
    }
    static void union_set(int a, int b)
	{
        int root1, root2;
        root1 = find(a);
        root2 = find(b);
        if (root1 != root2)
            arr[root1] = root2;
    }


    // 정답의 범위가 int 초과, 오버플로우에 주의할 것 
	public static void main(String args[]) throws Exception
	{
	
		Scanner scan = new Scanner(System.in);
		int T;
		T=scan.nextInt();
		for(int t = 1; t <= T; t++)
		{
			int v,e,a,b,c;
			long temp, ans = 0;
            v = scan.nextInt();
            e = scan.nextInt();
            for (int i=1; i<=v; i++)
                arr[i] = i;
            PriorityQueue<pair> q = new PriorityQueue<pair>();
            for (int i=0; i < e; i++)
            {
                a = scan.nextInt();
                b = scan.nextInt();
                c = scan.nextInt();
                q.add(new pair(a,b,c));
            }
            while (!q.isEmpty())
            {
                a = q.peek().x;
                b = q.peek().y;
                temp = q.peek().z;
                //System.out.println(q.peek().z);
             	if (find(a) != find(b))
                {
                 	union_set(a,b);
                 	find(a);
                 	find(b);
                    ans += temp;
                }
                q.poll();
            }
            System.out.println("#" + t + " " + ans);
		}
	}
}
