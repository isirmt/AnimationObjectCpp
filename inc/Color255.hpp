#pragma once
#include <stdexcept>
#include <string>

namespace Obj {

struct Color255 {
 public:
  union {
    struct {
      int r;
      int g;
      int b;
      int a;
    };
    int iValue[4];
  };

  union {
    struct {
      float fr;
      float fg;
      float fb;
      float fa;
    };
    float fValue[4];
  };
  Color255() : r(0), g(0), b(0), a(255) { CalcFloat(); }
  Color255(int _grayScale, int _a = 255)  // grayscale(0~255), alpha(0~255)
      : r(_grayScale), g(_grayScale), b(_grayScale), a(_a) {
    CalcFloat();
  }
  Color255(float _fgrayScale, float _fa = 1.f)  // grayscale(0~1), alpha(0~1)
      : fr(_fgrayScale), fg(_fgrayScale), fb(_fgrayScale), fa(_fa) {
    CalcInt();
  }
  Color255(int _r, int _g, int _b, int _a = 255)  // (r, g, b, alpha) each (0~255)
      : r(_r), g(_g), b(_b), a(_a) {
    CalcFloat();
  }
  Color255(float _fr, float _fg, float _fb, float _fa = 1.f)  // (r, g, b, alpha) each (0~1)
      : fr(_fr), fg(_fg), fb(_fb), fa(_fa) {
    CalcInt();
  }
  Color255(std::string _code)  // ("#00ff00"{or "00ff00"})
      : a(255) {
    std::string formalCode = _code;
    formalCode = SplitSharp(formalCode);
    int value = 0;
    try {
      value = std::stoi(formalCode, nullptr, 16);
    } catch (const std::invalid_argument &e) {
      value = 0;
    } catch (const std::out_of_range &e) {
      value = 0;
    }

    r = value / (256 * 256);
    g = (value / 256) % 256;
    b = value % 256;

    CalcFloat();
  }
  Color255(std::string _code, int _a)  // ("#00ff00"{or "00ff00"}, alpha) alpha:(0~255)
      : a(_a) {
    std::string formalCode = _code;
    formalCode = SplitSharp(formalCode);
    int value = 0;
    try {
      value = std::stoi(formalCode, nullptr, 16);
    } catch (const std::invalid_argument &e) {
      value = 0;
    } catch (const std::out_of_range &e) {
      value = 0;
    }

    r = value / (256 * 256);
    g = (value / 256) % 256;
    b = value % 256;

    CalcFloat();
  }

  // パラメータを再計算
  void CalcFloat() {
    fr = (float)r / 255.f;
    fg = (float)g / 255.f;
    fb = (float)b / 255.f;
    fa = (float)a / 255.f;
  }

  void CalcInt() {
    r = (int)(fr * 255.f);
    g = (int)(fg * 255.f);
    b = (int)(fb * 255.f);
    a = (int)(fa * 255.f);
  }

  Color255 operator*(float v) {
    Color255 res = Color255(fr * v, fg * v, fb * v, fa);
    CalcInt();
    return res;
  }
  Color255 operator/(float v) {
    float vInv = 1.f / v;
    Color255 res = Color255(fr * vInv, fg * vInv, fb * vInv, fa);
    CalcInt();
    return res;
  }

  operator float *() { return (float *)&fr; }
  operator const float *() { return (const float *)&fr; }

  Color255 &operator=(const Color255 &color255) {
    fr = color255.fr;
    fg = color255.fg;
    fb = color255.fb;
    fa = color255.fa;
    r = color255.r;
    g = color255.g;
    b = color255.b;
    a = color255.a;

    return (*this);
  }

 private:
  std::string SplitSharp(std::string _code) {
    std::string code = _code, result = code;
    if (code.find("#") != std::string::npos) {
      result = code.substr(1);
    }
    return result;
  }
};
}  // namespace Obj