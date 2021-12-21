#include <iostream>
#include <string>
#include <algorithm>

namespace cpp2 {
    /* --------------------------------------------------------------------- */
    /*
    mcxi

    mcxi �L�@����͂���N���X�ł��B
    */
    /* --------------------------------------------------------------------- */
    class mcxi {
    public:
        /* ----------------------------------------------------------------- */
        /*
        mcxi

        �w�肳�ꂽ���������͂��āA�I�u�W�F�N�g�����������܂��B
        �ȉ��̏ꍇ�ɂ͗�O���n�o����܂��B

        1. [2-9,m,c,x,i] �ȊO�̕������o�������ꍇ
        2. 2 ���������Đ��� (2-9) ���o�������ꍇ
        3. m, c, x, i �����̏����ŏo�����Ȃ������ꍇ
        �������A�Ⴆ�� mx �̂悤�ɁA����̕������X�L�b�v���鎖�͋��e
        ����܂��B
        */
        /* ----------------------------------------------------------------- */
        mcxi(const std::string& s) : value_(0) {
            int num = 0;
            for (auto pos = s.begin(); pos != s.end(); ++pos) {
                //*pos �́Achar ! char ���Ă��Ƃ��������Ă���A�����ƊȒP�ɂł���̂ł́H�H
                if (*pos >= '2' && *pos <= '9') {
                    num = *pos - '0';
                }
                else {
                    int u = unit(*pos);
                    value_ += std::max(num, 1) * u;
                    num = 0;
                }
            }
        }

        /* ----------------------------------------------------------------- */
        /*
        operator+

        2 �̃I�u�W�F�N�g�̉��Z���ʂ��擾���܂��B
        */
        /* ----------------------------------------------------------------- */
        mcxi operator+(const mcxi& rhs) {
            mcxi mcxi(rhs);
            mcxi.value_ = this->value_ + rhs.value_;
            return mcxi;
        };

        /* ----------------------------------------------------------------- */
        /*
        to_string

        ���݂̒l�� mcxi �L�@�ɕϊ����܂��B
        */
        /* ----------------------------------------------------------------- */
        std::string to_string() const {
            std::string s;
            int value = value_;

            // 1000�̈�
            if (value / 1000 == 1) {
                s.append("m");
            }
            else if (value / 1000 > 1) {
                s.append(std::to_string(value / 1000) + "m");
            }
            value %= 1000;

            // 100�̈�
            if (value / 100 == 1) {
                s.append("c");
            }
            else if (value / 100 > 1) {
                s.append(std::to_string(value / 100) + "c");
            };
            value %= 100;

            // 10�̈�
            if (value / 10 == 1) {
                s.append("x");
            }
            else if (value / 10 > 1) {
                s.append(std::to_string(value / 10) + "x");
            };
            value %= 10;

            // 1�̈�
            if (value / 1 == 1) {
                s.append("i");
            }
            else if (value / 1 > 1) {
                s.append(std::to_string(value / 1) + "i");
            };
            return s;
        }

        void debug_mcxi() {
            std::cout << "value_: " << value_ << std::endl;
        }

        // �����Z�m�F�p
        int get() {
            return value_;
        }

    private:
        int unit(char c) {
            switch (c) {
            case 'm': return 1000;
            case 'c': return  100;
            case 'x': return   10;
            case 'i': return    1;
            }
            return -1;
        }

    private:
        int value_;
    };
}

int main() {
    cpp2::mcxi a0("xi");
    cpp2::mcxi b0("x9i");
    cpp2::mcxi result0 = a0 + b0;
    std::cout << "3x" << " " << result0.to_string() << std::endl;

    cpp2::mcxi a1("i");
    cpp2::mcxi b1("9i");
    cpp2::mcxi result1 = a1 + b1;
    std::cout << "x" << " " << result1.to_string() << std::endl;

    cpp2::mcxi a2("c2x2i");
    cpp2::mcxi b2("4c8x8i");
    cpp2::mcxi result2 = a2 + b2;
    std::cout << "6cx" << " " << result2.to_string() << std::endl;

    cpp2::mcxi a3("m2ci");
    cpp2::mcxi b3("4m7c9x8i");
    cpp2::mcxi result3 = a3 + b3;
    std::cout << "5m9c9x9i" << " " << result3.to_string() << std::endl;

    cpp2::mcxi a4("9c9x9i");
    cpp2::mcxi b4("i");
    cpp2::mcxi result4 = a4 + b4;
    std::cout << "m" << " " << result4.to_string() << std::endl;

    cpp2::mcxi a5("i");
    cpp2::mcxi b5("9m9c9x8i");
    cpp2::mcxi result5 = a5 + b5;
    std::cout << "9m9c9x9i" << " " << result5.to_string() << std::endl;

    cpp2::mcxi a6("m");
    cpp2::mcxi b6("i");
    cpp2::mcxi result6 = a6 + b6;
    std::cout << "mi" << " " << result6.to_string() << std::endl;

    cpp2::mcxi a7("i");
    cpp2::mcxi b7("m");
    cpp2::mcxi result7 = a7 + b7;
    std::cout << "mi" << " " << result7.to_string() << std::endl;

    cpp2::mcxi a8("m9i");
    cpp2::mcxi b8("i");
    cpp2::mcxi result8 = a8 + b8;
    std::cout << "mx" << " " << result8.to_string() << std::endl;

    cpp2::mcxi a9("9m8c7xi");
    cpp2::mcxi b9("c2x8i");
    cpp2::mcxi result9 = a9 + b9;
    std::cout << "9m9c9x9i" << " " << result9.to_string() << std::endl;

    std::cin.get();
}