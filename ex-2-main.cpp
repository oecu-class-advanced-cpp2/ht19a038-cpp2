// ex-2-main.cpp
#include <iostream>
#include <string>
using namespace std;

namespace cpp2 {
    /* --------------------------------------------------------------------- */
    /*
    mcxi
    mcxi �L�@����͂���N���X�ł��B
    */
    /* --------------------------------------------------------------------- */
    class mcxi {
    private:
        int result;
        int char_toInt;
    public:
        mcxi(const std::string s) {
            result = 0;
            char_toInt = 1;
            for (int i = 0; s[i]; i++) {
                if (s[i] == 'm') {
                    result += 1000 * char_toInt;
                    char_toInt = 1;
                }
                else if (s[i] == 'c') {
                    result += 100 * char_toInt;
                    char_toInt = 1;
                }
                else if (s[i] == 'x') {
                    result += 10 * char_toInt;
                    char_toInt = 1;
                }
                else if (s[i] == 'i') {
                    result += 1 * char_toInt;
                    char_toInt = 1;
                }
                // char�̐�����int�ɕϊ�
                else {
                    char_toInt = int(s[i] - '0');
                }
            }
            // �v�Z�m�F�p
            cout << "���́F" << s << "�ϊ���F" << result << endl;
        }

        std::string to_string() {
            return "a";
        }

        mcxi operator +(const mcxi& rhs) {
            mcxi mcxi(rhs);
            mcxi.result = result + rhs.result;
            return mcxi;
        }
        // �����Z�m�F�p
        int get() {
            return result;
        }
    };
} // namespace cpp2

int main() {
    cpp2::mcxi a0("xi");
    cpp2::mcxi b0("x9i");
    cpp2::mcxi result0 = a0 + b0;
    // �����Z�m�F
    std::cout << "�����Z���ʁF" << result0.get() << std::endl;
    std::cout << "3x" << " " << result0.to_string() << std::endl;

    cpp2::mcxi a1("i");
    cpp2::mcxi b1("9i");
    cpp2::mcxi result1 = a1 + b1;
    std::cout << "�����Z���ʁF" << result1.get() << std::endl;
    std::cout << "x" << " " << result1.to_string() << std::endl;

    cpp2::mcxi a2("c2x2i");
    cpp2::mcxi b2("4c8x8i");
    cpp2::mcxi result2 = a2 + b2;
    std::cout << "�����Z���ʁF" << result2.get() << std::endl;
    std::cout << "6cx" << " " << result2.to_string() << std::endl;
}