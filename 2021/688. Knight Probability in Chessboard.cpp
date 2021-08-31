class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {        
        vector<vector<int>> dir{{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
		vector<vector<double>> dp(N,vector<double>(N,0));
		dp[r][c]=1;
		for(int i=1;i<=K;i++){
			vector<vector<double>> tem(N,vector<double>(N,0));
			for(int j=0;j<N;j++){
				for(int k=0;k<N;k++){
					for(int v=0;v<8;v++){
						int x=j+dir[v][0];
						int y=k+dir[v][1];
						if(x<0 || y<0 || x>=N || y>=N){
							continue;
						}
						tem[j][k]+=dp[x][y];
					}
				}
			}
			dp=tem;
		}
		double rec=0;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++){
				rec+=dp[i][j];
			}
		double res=rec/pow(8,K);
		return res;
    }
};