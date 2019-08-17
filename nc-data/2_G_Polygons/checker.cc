#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr int AC = 0;
constexpr int NA = 1;
inline void Exit(int exit_code, const char* msg = "") {
#ifdef LOCAL
  if (exit_code == AC)
    printf("Accepted");
  if (exit_code == NA)
    printf("Not Accepted");
  if (strlen(msg)) {
    printf(", %s", msg);
  }
  puts("");
#endif
  exit(exit_code);
}

constexpr double eps = 1e-4;
bool equal(double a, double b, double e) {
  if (fabs(a - b) < e) {
    return true;
  }
  if (fabs(a) < e) {
    return false;
  }
  return (fabs(a - b) / fabs(a)) < e;
}


int main(int argc, char **argv) {
#ifdef LOCAL
  if (argc != 4) {
    puts("LOCAL TEST ONLY!");
    puts("USAGE: %s [INPUT_FILE] [ANSWER_FILE] [USER_OUTPUT]");
    exit(0);
  }
  ifstream input(argv[1]);
  ifstream output(argv[2]);
  ifstream user_output(argv[3]);
#else
  ifstream input("input");
  ifstream output("output");
  ifstream user_output("user_output");
#endif

  string token, user_token;
  while (output >> token) {
    if ( not(user_output >> user_token)) {
      Exit(NA, "Output expected but EOF");
    }
    if (isalpha(token[0])) {
      if (token != user_token) {
        Exit(NA, "String doesn't match");
      }
      continue;
    }
    double val, user_val;
    sscanf(token.c_str(), "%lf", &val);
    if (not sscanf(user_token.c_str(), "%lf", &user_val)) {
      Exit(NA, "Read value failed");
    }
    if (not equal(val, user_val, eps)) {
      Exit(NA, "Given values differs");
    }
  }
  Exit(AC);
}
