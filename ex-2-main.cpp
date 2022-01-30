#include <iostream>
#include <string>
#include <algorithm>

namespace cpp2 {
    /* --------------------------------------------------------------------- */
    /*
    mcxi

    mcxi 記法を解析するクラスです。
    */
    /* --------------------------------------------------------------------- */
    class mcxi {

    private:
        int value_;
        int unit(char c) {
            //発展課題１：2-9,m,c,x,i以外の文字の例外判定(1)
            try {
                switch (c) {
                case 'm': return 1000;
                case 'c': return  100;
                case 'x': return   10;
                case 'i': return    1;
                default: throw "2-9,m,c,x,i以外の文字列です。";
                }
            }
            catch (char* err) {
                std::cout << err << std::endl;
            }
            return -1;
        }

    public:
        /* ----------------------------------------------------------------- */
        /*
        mcxi

        指定された文字列を解析して、オブジェクトを初期化します。
        以下の場合には例外が創出されます。

        1. [2-9,m,c,x,i] 以外の文字が出現した場合
        2. 2 文字続けて数字 (2-9) が出現した場合
        3. m, c, x, i がこの順序で出現しなかった場合
        ただし、例えば mx のように、特定の文字をスキップする事は許容
        されます。
        */
        /* ----------------------------------------------------------------- */
        mcxi(const std::string& s) : value_(0) {
            int num = 0;
            int a = 1000;
            for (auto pos = s.begin(); pos != s.end(); ++pos) {
                //*pos は、char ! char ってことが分かってたら、もっと簡単にできるのでは？？
                if (*pos >= '2' && *pos <= '9') {
                    // 発展課題１：2文字続けて数字が出たときの例外判定(2)
                    if (num != 0) {
                        std::cout << "2文字続けて数字が出現しています。" << std::endl;
                    }
                    else {
                        num = *pos - '0';
                    }
                }
                else {
                    int u = unit(*pos);
                    // 発展課題１：m,c,x,iの順番の例外判定(3)
                    if (a >= u) {
                        value_ += std::max(num, 1) * u;
                        a = u;
                        num = 0;
                    }
                    else {
                        std::cout << "m,c,x,iの順番が不適切です。" << std::endl;
                        break;
                    }
                }
            }
        }

        /* ----------------------------------------------------------------- */
        /*
        operator+

        2 つのオブジェクトの加算結果を取得します。
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

        現在の値を mcxi 記法に変換します。
        */
        /* ----------------------------------------------------------------- */
        std::string to_string() const {
            std::string s;
            int value = value_;

            // 1000の位
            if (value / 1000 == 1) {
                s.append("m");
            }
            else if (value / 1000 > 1) {
                s.append(std::to_string(value / 1000) + "m");
            }
            value %= 1000;

            // 100の位
            if (value / 100 == 1) {
                s.append("c");
            }
            else if (value / 100 > 1) {
                s.append(std::to_string(value / 100) + "c");
            }
            value %= 100;

            // 10の位
            if (value / 10 == 1) {
                s.append("x");
            }
            else if (value / 10 > 1) {
                s.append(std::to_string(value / 10) + "x");
            }
            value %= 10;

            // 1の位
            if (value / 1 == 1) {
                s.append("i");
            }
            else if (value / 1 > 1) {
                s.append(std::to_string(value / 1) + "i");
            }
            return s;
        }
    };
}

/* ----------------------------------------------------------------- */
/*
compare_ans

to_stringで得られた結果をxに、正解の出力結果をyに代入し、
xとyが一致しているかどうかの判定を行い、それに対応した結果を出力する
*/
/* ----------------------------------------------------------------- */
void compare_ans(std::string x, std::string y) {
    if (x == y) {
        std::cout << "出力：" << x << "　正解〇" << std::endl;
    }
    else {
        std::cout << "出力：" << x << "　不正解×" << std::endl;
    }
}

int main() {
    cpp2::mcxi a0("xi");
    cpp2::mcxi b0("x9i");
    cpp2::mcxi result0 = a0 + b0;
    compare_ans(result0.to_string(), "3x");

    cpp2::mcxi a1("i");
    cpp2::mcxi b1("9i");
    cpp2::mcxi result1 = a1 + b1;
    compare_ans(result1.to_string(), "x");

    cpp2::mcxi a2("c2x2i");
    cpp2::mcxi b2("4c8x8i");
    cpp2::mcxi result2 = a2 + b2;
    compare_ans(result2.to_string(), "6cx");

    cpp2::mcxi a3("m2ci");
    cpp2::mcxi b3("4m7c9x8i");
    cpp2::mcxi result3 = a3 + b3;
    compare_ans(result3.to_string(), "5m9c9x9i");

    cpp2::mcxi a4("9c9x9i");
    cpp2::mcxi b4("i");
    cpp2::mcxi result4 = a4 + b4;
    compare_ans(result4.to_string(), "m");

    cpp2::mcxi a5("i");
    cpp2::mcxi b5("9m9c9x8i");
    cpp2::mcxi result5 = a5 + b5;
    compare_ans(result5.to_string(), "9m9c9x9i");

    cpp2::mcxi a6("m");
    cpp2::mcxi b6("i");
    cpp2::mcxi result6 = a6 + b6;
    compare_ans(result6.to_string(), "mi");

    cpp2::mcxi a7("i");
    cpp2::mcxi b7("m");
    cpp2::mcxi result7 = a7 + b7;
    compare_ans(result7.to_string(), "mi");

    cpp2::mcxi a8("m9i");
    cpp2::mcxi b8("i");
    cpp2::mcxi result8 = a8 + b8;
    compare_ans(result8.to_string(), "mx");

    cpp2::mcxi a9("9m8c7xi");
    cpp2::mcxi b9("c2x8i");
    cpp2::mcxi result9 = a9 + b9;
    compare_ans(result9.to_string(), "9m9c9x9i");

    std::cin.get();
}