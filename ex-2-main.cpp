// ex-2-main.cpp
#include <iostream>
#include <string>
using namespace std;

namespace cpp2 {
    /* --------------------------------------------------------------------- */
    /*
    mcxi
    mcxi 記法を解析するクラスです。
    */
    /* --------------------------------------------------------------------- */
class mcxi {
private:
    int result;
    int char_toInt;
public:
    mcxi(std::string s) {
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
            else if (s[i] == '2' || '3' || '4' || '5' || '6' || '7' || '8' || '9') {
                char_toInt = int(s[i] - '0');
            }
        }
        // 計算確認用
        cout << "入力：" << s << "変換後：" << result << endl;
    }

    std::string to_string() {
        return "a";
    }

    mcxi operator+(mcxi rhs) {
        return rhs;
    }
};
} // namespace cpp2

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
}