#pragma once
#include <chrono>

namespace Obj {
class Time {
 public:
  static void Initialize();
  static void Update();
  static double DeltaTime() { return deltaTime; }

 private:
  static std::chrono::system_clock::time_point previousTime;
  static double deltaTime;
};

}  // namespace Obj