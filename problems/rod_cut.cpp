

/*
 * Rod cut problem.
 * 
 * Given a rod of lenght $n$ inches and a table of prices
 * $p_i$ for $i=1,2,3...$, determine the max revenue $r_n$
 * obtainable by cutting up the rod and selling the pieces.
 * 
 */

#include <iostream>
#include <algorithm>

float pri[] = {1, 5, 8, 9, 10, 17, 17, 21, 22};


// $r_n = max_{1<=i<=n} (p_i + r_{n-i})$
// You have to do the first cut.
// **Time consuming**
float cut_rod(float* price, int length) {
  if (length == 0) return 0.;
  float q = -1;

  for (int i = 0; i < length; i++) {
    q = std::max(q, price[i] + cut_rod(price, length-i));
  }

  return q;
}

// top-down with memory
float cut_rod_v1(float* price, int length) {
  float* r = new float[length];
  for (int i = 0; i < length, i++) r[i] = -1;
  return cut_rod_v1_aux(price, length, r);
}

float cut_rod_v1_aux(float* p, int n, float* r) {
  if (r[n - 1] >= 0) return r[n - 1];
  float q;
  if (n == 0) q = 0.;
  else {
    q = -1.;
    for (int i = 0; i < n; i++) {
      q = std::max(q, p[i] + cut_rod_v1_aux(p, n-i, r));
    }
  }
  r[n - 1] = q;
  return q;
}

// bottom-up
float cut_rod_v2(float* price, int length) {
  float* r = new float[length];
  for (int i = 0; i < length, i++) r[i] = -1;

  for (int i = 0; i < lenght; i++) {
    float q = -1;
    for (int j = 0; j < i; j++) {
      q = std::max(q, price[j] + r[i - j]);
    }
    r[j - 1] = q;
  }
  return r[length - 1];
}






