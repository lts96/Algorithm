import java.util.*;
import java.io.*;

// 마법사 상어와 파이어볼 같은 빡구현 문제 
class Solution
{
    static int n, m, k, ans;
    static int dx[] = {0,-1,1,0,0};
    static int dy[] = {0,0,0,-1,1};
    static int arr[][][] = new int[101][101][2];
    static int arr_copy[][][] = new int[101][101][3];
    
    static void move(int x, int y)
    {
    	int d = arr[x][y][1];
    	int nx = x + dx[d];
    	int ny = y + dy[d];
    	// 약품에서 미생물이 합쳐지는 일은 없다
    	if (nx == 0 || ny == 0 || nx == n-1 || ny == n-1)
    	{
    		arr[x][y][0] /= 2;
    		if (d % 2 == 1)
    			arr[x][y][1] = d + 1;
    		else
    			arr[x][y][1] = d - 1;
    	}
    	// 이동
    	if (arr[x][y][0] > 0)
    	{
    		if (arr_copy[nx][ny][0] == 0 && arr_copy[nx][ny][2] == 0)
    		{
    			arr_copy[nx][ny][0] = arr[x][y][0];
    			arr_copy[nx][ny][1] = arr[x][y][1];
    			arr_copy[nx][ny][2] = arr[x][y][0];
    			arr[x][y][0] = arr[x][y][1] = 0;
    		}
    		else
    		{
    			// 겹쳐지는 것 중 누가 제일 큰지 판정해서 방향 정하기  
    			if (arr_copy[nx][ny][2] < arr[x][y][0])
    			{
    				arr_copy[nx][ny][2] = arr[x][y][0];
    				arr_copy[nx][ny][1] = arr[x][y][1];
    			}
    			arr_copy[nx][ny][0] += arr[x][y][0];
    			arr[x][y][0] = arr[x][y][1] = 0;
    		}
    	}
    }
    
    static void run()
    {
    	int x, y, c, d, nx, ny, idx;
    	for (int t=0; t<m; t++)
    	{
    		for (int i=0; i<n; i++)
    		{
    			for (int j=0; j<n; j++)
    			{
    				if (arr[i][j][0] == 0)
    					continue;
    				move(i, j);
    			}
    		}
    		for (int i=0; i<n; i++)
    		{
    			for (int j=0; j<n; j++)
    			{
    				if (arr_copy[i][j][0] == 0)
    					continue;
    				arr[i][j][0] = arr_copy[i][j][0];
    				arr[i][j][1] = arr_copy[i][j][1];
    				arr_copy[i][j][0] = arr_copy[i][j][1] = arr_copy[i][j][2] = 0;
    			}
    		}
    	}
    }
	public static void main(String args[]) throws Exception
	{
		Scanner scan = new Scanner(System.in);
		int test = scan.nextInt();
		int x,y,c,d;
		for (int t=1; t<=test; t++)
		{
			ans = 0;
			n = scan.nextInt();
			m = scan.nextInt();
			k = scan.nextInt();
			for (int i=0; i<k; i++)
			{
				x = scan.nextInt();
				y = scan.nextInt();
				c = scan.nextInt();
				d = scan.nextInt();
				arr[x][y][0] = c;
				arr[x][y][1] = d;
			}
			run();
			for (int i=0; i<=100; i++)
			{
				for (int j=0; j<=100; j++)
				{
					ans += arr[i][j][0];
					arr[i][j][0] = arr[i][j][1] = 0;
					arr_copy[i][j][0] = arr_copy[i][j][1] = 0;
				}
			}
			System.out.println("#" + t +" " + ans);
		}
	}
}
