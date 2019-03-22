// Matrix Chain Multiplication problem (DP)
// Optimally parenthesize a matrix chain.




void matrix_chain_order(int* p, int** m, int** s, int n) {
  for (int i = 0; i < n; i++) {
    m[i][i] = 0;
  }

  for (int l = 1; l < n; l++) {
    for (int i = 0; i < (n-l+1); i++) {
      int j = i + l - 1;
      m[i][j] = -1;

      
    }
  }
}



