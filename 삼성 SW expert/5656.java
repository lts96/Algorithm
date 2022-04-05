import java.util.*;
import java.io.*;

class Solution
{
    static int arr[][] = new int[20][20];
    static int arr_copy[][] = new int[20][20];
    static int n,w,h,ans;
    static int ball[][] = new int[5][2];
    static int dx[] = {-1,1,0,0};
    static int dy[] = {0,0,-1,1};
    
    static void print()
    {
    	for (int i=0; i<h; i++)
		{
    		System.out.println();
			for (int j=0; j<w; j++)
				System.out.print(arr[i][j] + " ");
		}
    	System.out.println();
    	return;
    }
    
    // 같은 자리에 또 떨어트릴수 있다 
    // 자리를 다 정하고 마지막에 떨어뜨리는 것보다 
    // dfs를 하면서 중간 중간에 폭파시키고 넘어가는게 백트래킹 효과가 생겨서 더 시간과 공간이 절약 
    static void select(int idx)
    {
    	if (idx == n)
    	{
    		int x,y, cnt = 0;
    		
    		for (int i=0; i<n; i++)
    		{
    			x = ball[i][0];
    			y = ball[i][1];
    			drop(x, y);
    			down();
    		}
    		// 배열 원상복구하면서 남은 벽돌 카운팅 
    		
    		for (int i=0; i<h; i++)
			{
				for (int j=0; j<w; j++)
				{
					if (arr[i][j] != 0)
						cnt++;
					arr[i][j] = arr_copy[i][j];
				}
			}
    		ans = Math.min(ans, cnt);
    		return;
    	}
      // 여기서 아예 폭파시키고 넘어가면 좀더 효율적이다
      // 가지치기 조건이 들어갈 수 있게됨 
    	for (int j=0; j<w; j++)
    	{
    		ball[idx][1] = j;
    		select(idx + 1);
    	}
    	return;
    }
    // 구슬 떨어뜨리기 
    static void drop(int sx, int sy)
    {
    	int x = -1;
    	int y = sy;
    	
    	for (int i=0; i<h; i++)
    	{
    		if (arr[i][y] != 0)
    		{
    			x = i;
    			break;
    		}
    	}
    	// 해당 줄에 벽돌이 1개도 없는 경우 -> 폭발 x
    	if (x == -1)
    		return;
    	bomb(x, y, arr[x][y]);	
    }
    static void bomb(int x, int y, int d)
    {
    	int nx, ny;
    	arr[x][y] = 0;
    	for (int k=0; k<4; k++)
    	{
    		for (int i=0; i<d; i++)
    		{
    			nx = x + dx[k] * i;
    			ny = y + dy[k] * i;
    			if (nx < 0 || nx >= h || ny < 0 || ny >= w)
    				continue;
    			if (arr[nx][ny] > 1)
    				bomb(nx, ny , arr[nx][ny]);
    			else if (arr[nx][ny] == 1)
    				arr[nx][ny] = 0;
    		}
    	}
    }
    
    // 벽돌 내리기 
    static void down()
    {
    	int cnt;
    	int temp[][] = new int[20][20];
    	for (int j=0; j<w; j++)
    	{
    		cnt = 0;
    		for (int i=h-1; i>=0; i--)
    		{
    			if (arr[i][j] == 0)
    				cnt++;
    			else
    				temp[i + cnt][j] = arr[i][j];
    		}
    	}
    	for (int i=0; i<h; i++)
		{
			for (int j=0; j<w; j++)
				arr[i][j] = temp[i][j];
		}
    }
	public static void main(String args[]) throws Exception
	{
		Scanner scan = new Scanner(System.in);
		int test = scan.nextInt();
		for (int t=1; t <= test; t++)
		{
			ans = Integer.MAX_VALUE;
			n = scan.nextInt();
			w = scan.nextInt();
			h = scan.nextInt();
			for (int i=0; i<h; i++)
			{
				for (int j=0; j<w; j++)
					arr_copy[i][j] = arr[i][j] = scan.nextInt();
			}
			select(0);
			System.out.println("#" + t + " " + ans);
		}
	}
}
