import java.util.*;
import java.io.*;

class Solution
{
    static int arr[][] = new int[20][20];
    static int a[][] = new int[20][20];
    static int b[][] = new int[20][20];
    static int n, m, k, ans;
    static int select[] = new int[20];
    static int data[][] = new int[20][20];
    // 3^13에다가 배열 돌면서 판정까지 하려면 브루트포스론 힘듬 
    // 가지치기 몇가지 해야됨 
    // 가장 기본적인것은 정답보다 크면 잘라버리기 
    // 추가적으로 필름을 안쓰는 것부터 해서 가지치기 가능성을 높이기 
    
    // a또는 b로 마킹할 경우 어차피 a와 b로만 채워질테니 미리 만들어두고 가져다 쓰자 
  
    // 최적화를 연습하기 
    static boolean check(int y)
    {
    	int curr = data[0][y];
    	int cnt = 1;
    	for (int i=1; i<n; i++)
    	{
    		if (curr == data[i][y])
    			cnt++;
    		else
    		{
    			cnt = 1;
    			curr = data[i][y];
    		}
    		if (cnt == k)
    			return true;
    	}
    	return false;
    }
    static void print()
    {
    	System.out.println();
    	for (int i=0; i<n; i++)
    	{
    		for (int j=0; j<m; j++)
    		{
    			System.out.print(data[i][j] + " ");
    		}
    		System.out.println();
    	}
    }
    static void backtracking(int idx, int cnt)
    {
    	if (idx == n)
    	{
    		// 세로 판정을 하면서 하나라도 걸리면 통과 x
    		//print();
    		boolean flag = true;
    		for (int i=0; i<m; i++)
    		{
    			if (check(i) == false)
    			{
    				flag = false;
    				break;
    			}
    		}
    		if (flag)	
    			ans = Math.min(ans, cnt);
    		return;
    	}
    	select[idx] = 0;
    	// 배열의 주소를 바꿔서 가져다 씀
    	data[idx] = arr[idx];
    	backtracking(idx + 1, cnt);
    	if (cnt < ans)
    	{
    		select[idx] = 1;
    		data[idx] = a[idx];
    		backtracking(idx + 1, cnt + 1);
    		select[idx] = 2;
    		data[idx] = b[idx];
    		backtracking(idx + 1, cnt + 1);
    	}
    	return;
    }
   
	public static void main(String args[]) throws Exception
	{
		Scanner scan = new Scanner(System.in);
		int test = scan.nextInt();
		for (int i=0; i<20; i++)
		{
			for (int j=0; j<20; j++)
			{
				a[i][j] = 0;
				b[i][j] = 1;
			}
		}
		for (int t=1; t <= test; t++)
		{
			ans = Integer.MAX_VALUE;
			n = scan.nextInt();
			m = scan.nextInt();
			k = scan.nextInt();
			for (int i=0; i<n; i++)
			{
				for (int j=0; j<m; j++)
					arr[i][j] = scan.nextInt();
			}
			backtracking(0, 0);
			System.out.println("#" + t + " " + ans);
		}
	}
}
