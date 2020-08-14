#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> findSquare(vector<vector<int>>& matrix) {
		vector<int> ans(3, 0);
		int n = matrix.size();
		if (n == 0) return {};
		if (n == 1) {
			if (matrix[0][0] == 0)
				return { 0, 0, 1 };
			else
				return {};
		}
		//cnt[r][c][0/1],0�Ҳ�,1�²�
		vector<vector<vector<int>>> cnt(n, vector<vector<int>>(n, vector<int>(2)));
		for (int r = n - 1; r >= 0; r--) {
			for (int c = n - 1; c >= 0; c--) {
				if (matrix[r][c] == 1)
					cnt[r][c][0] = cnt[r][c][1] = 0;
				else {
					//ͳ��cnt[r][c][0/1]
					if (r < n - 1) cnt[r][c][1] = cnt[r + 1][c][1] + 1;
					else cnt[r][c][1] = 1;

					if (c < n - 1) cnt[r][c][0] = cnt[r][c + 1][0] + 1;
					else cnt[r][c][0] = 1;
					//���µ�ǰ����ӷ���
					int len = min(cnt[r][c][0], cnt[r][c][1]);//���Ŀ��ܵı߳�
					while (len >= ans[2]) {//Ҫ��r,c��С�����Դ��Ⱥ�
						if (cnt[r + len - 1][c][0] >= len && cnt[r][c + len - 1][1] >= len) {
							//���Թ��ɳ�Ϊlen�ķ���
							ans = { r, c, len };
							break;
						}
						len--;
					}
				}
			}
		}
		return ans;
	}
};

