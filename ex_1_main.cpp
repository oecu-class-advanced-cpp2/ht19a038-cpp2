// ex_1_main.cpp
#include <iostream>
#include <math.h>
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

    if (s == 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(s); i++) {
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
            break;
        }
        num += d;
    }
    return num;
};

/* --------------------------------------------------------------- */
/*
* compare_prime
*
* nth_primeで得られた結果をxに、正解となる出力結果をyに代入し、
* xとyが一致しているかの判定を行い、それに対応した出力を行う
*
*/
/* -------------------------------------------------------------- */
int compare_prime(unsigned int x, unsigned int y) {
    if (x == y) {
        std::cout << "出力：" << x << " 正解出力：" << y << " 正解〇" << std::endl;
        return 0;
    }
    else {
        std::cout << "出力：" << x << " 正解出力：" << y << " 不正解×" << std::endl;
        return 0;
    }
}

int main() {
    compare_prime(nth_prime(367, 186, 151),92809);
    compare_prime(nth_prime(179, 10, 203), 6709);
    compare_prime(nth_prime(271, 37, 39), 12037);
    compare_prime(nth_prime(103, 230, 1), 103);
    compare_prime(nth_prime(27, 104, 185), 93523);
    compare_prime(nth_prime(253, 50, 85), 14503);
    compare_prime(nth_prime(1, 1, 1), 2);
    compare_prime(nth_prime(9075, 337, 210), 899429);
    compare_prime(nth_prime(307, 24, 79), 5107);
    compare_prime(nth_prime(331, 221, 177), 412717);
    compare_prime(nth_prime(259, 170, 40), 22699);
    compare_prime(nth_prime(269, 58, 102), 25673);
    // 以下、同様に、入出力例通りになるか確認せよ。
    return 0;
}