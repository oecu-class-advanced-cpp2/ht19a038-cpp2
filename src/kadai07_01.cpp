// kadai07_01.cpp
#include <iostream>
#define CPP2_PRIME_UPPER_LIMIT 1000000 //探索する値の上限値。

/* --------------------------------------------------------------- */
/*
* sosu_judge
*
* 正整数aをsに代入して、aが素数かどうかをtureかfalseで返す。
*
*/
/* -------------------------------------------------------------- */
int sosu_judge(unsigned int s) {
    for (int i = 2; i <= s / 2; i++) {
        if (s % i == 0) {
            return false;
        }
    }
    return true;
};

/* --------------------------------------------------------------- */
/*
* nth_prime
*
* 与えられた正整数 a と d と n に対して、この等差数列に含まれる n 番目の
* 素数を返す。
*
* TODO: この nth_prime 関数を実装せよ。必要であれば他に関数や
* ファイルを作成せよ。
*/
/* -------------------------------------------------------------- */
int nth_prime(unsigned int a, unsigned int d, unsigned int n) {
    int num = a;
    int count = 0;
    for (int i = 1; i < CPP2_PRIME_UPPER_LIMIT; i++) {
        if (sosu_judge(num) == true) {
            count++;
        }
        if (count == n) {
            std::cout << num << std::endl;
            break;
        }
        num += d;
    }
    return 0;
};

int main() {
    std::cout << nth_prime(367, 186, 151) << std::endl;
    std::cout << nth_prime(179, 10, 203) << std::endl;
    std::cout << nth_prime(271, 37, 39) << std::endl;
    std::cout << nth_prime(103, 230, 1) << std::endl;
    std::cout << nth_prime(27, 104, 185) << std::endl;
    std::cout << nth_prime(253, 50, 85) << std::endl;
    std::cout << nth_prime(1, 1, 1) << std::endl;
    std::cout << nth_prime(9075, 337, 210) << std::endl;
    std::cout << nth_prime(307, 24, 79) << std::endl;
    std::cout << nth_prime(331, 221, 177) << std::endl;
    std::cout << nth_prime(259, 170, 40) << std::endl;
    std::cout << nth_prime(269, 58, 102) << std::endl;
    // 以下、同様に、入出力例通りになるか確認せよ。
    return 0;
}