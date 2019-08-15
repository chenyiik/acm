#include <climits>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <iostream>

[[noreturn]] void usage(const char* name) {
    fprintf(stderr,
        "Usage: %s input_file < user_output | diff - ans_file\n"
        "This is the special judge for Acesrc and Hunting.\n"
        , name);
    std::exit(EXIT_FAILURE);
}

[[noreturn]] void wa(std::string reason = "") {
    std::cout << "[SPJ] Wrong Answer" << std::endl;
    if (reason.size()) std::cout << reason << std::endl;
    std::exit(0);
}

std::string readToken() {
    std::string token;
    if (!(std::cin >> token)) wa("error occurred on reading token");
    return token;
}

int readInt(int minv = INT_MIN, int maxv = INT_MAX) {
    std::string token = readToken();
    size_t idx;
    try {
        int ret = std::stoi(token, &idx);
        if (token.size() != idx) wa("expected integer, but not found");
        if (ret < minv || ret > maxv) 
            wa("input integer out of range: expected " + 
                std::to_string(minv) + " ~ " + std::to_string(maxv) +
                ", found " + std::to_string(ret));
        return ret;
    } catch (std::out_of_range &ex) {
        wa("input integer overflow");
    } catch (std::invalid_argument &ex) {
        wa("expected integer, but not found");
    }
}

void check(int m, int n) {
    std::string res = readToken();
    for (char &ch : res) ch = toupper(ch);
    if (res == "NO") {
        std::cout << "NO" << std::endl;
    } else if (res == "YES") {
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n));
        int u = readInt(1, m) - 1, v = readInt(1, n) - 1;
        visited[u][v] = true;
        for (int i = 1; i < m * n; i++) {
            int uu = readInt(1, m) - 1, vv = readInt(1, n) - 1;
            int d2 = (u - uu) * (u - uu) + (v - vv) * (v - vv);
            if (d2 <= 1 || d2 >= 9) wa("distance not between 1 and 3");
            if (visited[uu][vv]) wa("a trap visited twice");
            visited[uu][vv] = true;
            u = uu; v = vv;
        }
        std::cout << "YES" << std::endl;
    } else wa("expected YES/NO, found " + res);
}

int main(int argc, char *argv[]) {
    if (argc != 2) usage(argv[0]);
    std::ifstream fin(argv[1]);
    int T; fin >> T;
    while (T--) {
        int m, n; fin >> m >> n;
        check(m, n);
    }
    return 0;
}
