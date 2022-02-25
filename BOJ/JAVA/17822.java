import java.io.*;
import java.util.*;

class pair {
	int x, y, z;

	public pair(int x, int y, int z) {
		this.x = x;
		this.y = y;
		this.z = z;
	}
}
// 생각보다 시간이 오래걸렸음
// 1시간 안쪽으로 해결하게끔 연습
public class Main {
	static int ans, n, m, t;
	static int arr[][] = new int[51][51];
	static int arr_copy[][] = new int[51][51];
	static boolean visit[][] = new boolean[51][51];
	static int dx[] = { 0, 0, -1, 1 };
	static int dy[] = { -1, 1, 0, 0 };
	static int direct[] = { 1, -1 };

	public static void clear() {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				arr_copy[i][j] = 0;
				visit[i][j] = false;
			}
		}
	}
	public static void print() {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
			{
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}
		System.out.println();
	}

	public static void rotate(int x, int d, int k) {
		clear();
		// i는 원판의 번호를 의미
		int next;
		for (int i = 1; i <= n; i++) {
			// xi의 배수가 아닌 원판은 회전에서 제외
			if (i % x != 0)
				continue;
			// 임시 배열로 회전한 값을 이동
			for (int j = 1; j <= m; j++) {
				next = j + k * direct[d];
				if (next > m)
					next %= m;
				else if (next < 1)
				{
					if (next != 0)
						next = (next + m) % m;
					else
						next = m;
				}
				arr_copy[i][next] = arr[i][j];
			}
			// 다시 원래 배열에 갱신
			for (int j = 1; j <= m; j++) {
				arr[i][j] = arr_copy[i][j];
			}
		}
		//print();
	}

	public static int check_num() {
		int nx, ny, target, cnt = 0;
		boolean erase = false;
		boolean check[][] = new boolean[51][51];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (arr[i][j] == 0)
					continue;
				target = arr[i][j];
				erase = false;
				for (int k = 0; k <4; k++)
				{
					nx = i + dx[k];
					ny = j + dy[k];
					if (nx == 0 || nx == n + 1)
						continue;
					if (ny == 0)
						ny = m;
					else if (ny == m + 1)
						ny = 1;
					if (target == arr[nx][ny])
					{
						erase = true;
						cnt++;
						check[i][j] = true;
					}
				}
				if (erase)
					check[i][j] = true;
			}
		}
		// 지울때도 한꺼번에 지워야 오류가 안생긴다
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (check[i][j])
					arr[i][j] = 0;
			}
		}
		return cnt;
	}
	// 평균은 모든 수의 숫자를 세고 개수만큼 나눠준다
	public static void average() {
		double cnt = 0, sum = 0;
		double avg = 0, temp;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				sum += arr[i][j];
				if (arr[i][j] > 0)
					cnt++;
			}
		}
		avg = sum / cnt;
		//System.out.println(sum + " " + cnt + " " + avg);
		// 평균과 비교해서 큰 수는 -1 작은 수는 +1
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				temp = arr[i][j];
				if (arr[i][j] == 0)
					continue;
				if (temp > avg)
					arr[i][j]--;
				else if (temp < avg)
					arr[i][j]++;
			}
		}
	}

	public static void main(String[] args) throws NumberFormatException, IOException {
		Scanner scan = new Scanner(System.in);
		n = scan.nextInt();
		m = scan.nextInt();
		t = scan.nextInt();
		int pos = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				arr[i][j] = scan.nextInt();
		}
		int x, d, k;
		int flag;
		for (int i = 0; i < t; i++) {
			x = scan.nextInt();
			d = scan.nextInt();
			k = scan.nextInt();
			rotate(x, d, k);
			//print();
			flag = check_num();
			//print();
			if (flag == 0)
			{
				average();
				//print();
			}
			//System.out.println("--------");
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				ans += arr[i][j];
		}
		System.out.println(ans);
	}
}
