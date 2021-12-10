// ex_1_main.cpp
#include <iostream>
#include <math.h>
#define CPP2_PRIME_UPPER_LIMIT 1000000 //�T������l�̏���l�B

/* --------------------------------------------------------------- */
/*
* sosu_judge
*
* ������a��s�ɑ�����āAa���f�����ǂ�����ture��false�ŕԂ��B
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
* �^����ꂽ������ a �� d �� n �ɑ΂��āA���̓�������Ɋ܂܂�� n �Ԗڂ�
* �f����Ԃ��B
*
* TODO: ���� nth_prime �֐�����������B�K�v�ł���Α��Ɋ֐���
* �t�@�C�����쐬����B
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
* nth_prime�œ���ꂽ���ʂ�x�ɁA�����ƂȂ�o�͌��ʂ�y�ɑ�����A
* x��y����v���Ă��邩�̔�����s���A����ɑΉ������o�͂��s��
*
*/
/* -------------------------------------------------------------- */
int compare_prime(unsigned int x, unsigned int y) {
    if (x == y) {
        std::cout << "�o�́F" << x << " �����o�́F" << y << " �����Z" << std::endl;
        return 0;
    }
    else {
        std::cout << "�o�́F" << x << " �����o�́F" << y << " �s�����~" << std::endl;
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
    // �ȉ��A���l�ɁA���o�͗�ʂ�ɂȂ邩�m�F����B
    return 0;
}