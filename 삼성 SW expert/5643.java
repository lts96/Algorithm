import java.util.*;
import java.io.*;

// 0406 과제
// sea 5643번 키 순서 
// 위상정렬이랑 비슷한 문제 

// 푸는 방법 : 현재 노드에서 자식의 개수 + 나를 방문하는 부모 개수가 전체 노드 -1 인지 아닌지 확인하고 답찾기 
class Solution {
	static int n, m, k, ans;
	static ArrayList<ArrayList<Integer>> arr = new ArrayList<ArrayList<Integer>>();

	// i번째 노드를 방문하는 상위노드 개수
	static int up[] = new int[501];

	// i번째 노드에서 방문한 하위 노드들 개수
	static int down[] = new int[501];
	static boolean visit[] = new boolean[501];

	static void dfs(int idx, int root) {
		if (visit[idx])
			return;
		if (idx != root) {
			up[idx]++;
			down[root]++;
		}
		visit[idx] = true;
		int next, ret = 0;
		if (arr.get(idx).size() == 0)
			return;
		for (int i = 0; i < arr.get(idx).size(); i++) {
			next = arr.get(idx).get(i);
			dfs(next, root);
		}
		return;
	}

	public static void main(String args[]) throws Exception {
		Scanner scan = new Scanner(System.in);
		int test = scan.nextInt();
		int a, b;
		for (int i = 0; i <= 500; i++) {
			arr.add(new ArrayList<Integer>());
		}
		for (int t = 1; t <= test; t++) {
			ans = 0;
			n = scan.nextInt();
			m = scan.nextInt();
			for (int i = 0; i < m; i++) {
				a = scan.nextInt();
				b = scan.nextInt();
				arr.get(a).add(b);
			}
			for (int i = 1; i <= n; i++) {
				dfs(i, i);
				for (int j = 0; j <= 500; j++)
					visit[j] = false;
			}
			for (int i = 0; i <= n; i++) {
				// System.out.println(down[i] + " " + up[i]);
				if (down[i] + up[i] == n - 1)
					ans++;
				down[i] = up[i] = 0;
				arr.get(i).clear();
			}
			System.out.println("#" + t + " " + ans);
		}
	}
}
