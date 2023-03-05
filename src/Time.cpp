#include "Time.hpp"

std::chrono::system_clock::time_point Obj::Time::previousTime = std::chrono::system_clock::time_point();
double Obj::Time::deltaTime = 0.;

void Obj::Time::Initialize() { previousTime = std::chrono::system_clock::now(); }

void Obj::Time::Update() {
  auto nowTime = std::chrono::system_clock::now();
  deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(nowTime - previousTime).count() / 1000.;
  previousTime = nowTime;
}