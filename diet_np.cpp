#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

#define MAX_N (100+1)

int dp[MAX_N][MAX_N];

/*
http://cpp.sh/4cbkp
ex1
5 70 3 2
4 6 2 5 3
ex2
20 70 3 2
4 6 2 5 3 4 5 4 1 3 4 3 2 1 2 1 4 2 1 3
*/

void constuct_table(int dp[MAX_N][MAX_N], int N, int W, int A, int B, vector<int> &C) {
    dp[0][0] = W;
    
    for(int col = 1; col <= N; ++col) {
        // find min in the col-1 column
        int tmp_row = 0;
        int tmp = dp[tmp_row][col-1];
        for(int row = 1; row <= col-1; ++row)
            if(dp[row][col-1] < tmp) {
                tmp = dp[row][col-1];
                tmp_row = row;
            }
        // then fill stress point = 0 case
        dp[0][col] = tmp + C[col-1];
        dp[col][0] = tmp_row;
        
        // fill stress point = 1 case
        for(int row = 1; row <= col; ++row)
            dp[row][col] = dp[row-1][col-1] - A + B * row;
    }
}

void find_opt_plan(int dp[MAX_N][MAX_N], int N) {
    int tmp_row = 0;
    int tmp = dp[tmp_row][N];
    for(int row = 1; row <= N; ++row)
        if(dp[row][N] < tmp) {
            tmp = dp[row][N];
            tmp_row = row;
        }
    
    vector<int> history;
    history.reserve(N);
    for(int col = N; col > tmp_row;) {
        std::cout << col << "\t" << tmp_row << std::endl;
		col -= tmp_row;
        history.push_back(col);
        tmp_row = dp[col][0];
        --col;
    }
    
    for(auto it = history.rbegin(); it != history.rend(); ++it)
        cout << "day #" << *it << " eat" << endl;
        
    cout << "minimum weight is " << tmp << "kg." << endl;;
}

void print_table(int dp[MAX_N][MAX_N], int N) {
    for(int i = 0; i <= N; ++i) {
        for(int j = 0; j <= N; ++j)
            cout << setw(4) << dp[i][j] << ' ';
        cout << endl;
    }
}

int main() {
    int N, W, A, B;
	std::fstream myfile("D:\\program\\C-programming-quiz.git\\diet_case1.txt", std::ios_base::in);
	myfile >> N >> W >> A >> B;
	
	vector<int> C;
	C.reserve(N);
	for(int i = 0; i < N; ++i) {
	    int input;
	    myfile >> input;
	    C.push_back(input);
	}
	
	constuct_table(dp, N, W, A, B, C);
	find_opt_plan(dp, N);
	print_table(dp, N);
	return 0;
}