#pragma once

namespace Obj {
struct Vector3D {
  float x;
  float y;
  float z;

  Vector3D() : x(0), y(0), z(0) {}
  Vector3D(float _x, float _y) : x(_x), y(_y), z(0) {}
  Vector3D(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

  Vector3D operator+(const Vector3D& vector3D) {
    return Vector3D(x + vector3D.x, y + vector3D.y, z + vector3D.z);
  }
  Vector3D operator-(const Vector3D& vector3D) {
    return Vector3D(x - vector3D.x, y - vector3D.y, z - vector3D.z);
  }

  Vector3D operator*(float scalar) {
    return Vector3D(x * scalar, y * scalar, z * scalar);
  }
  Vector3D operator/(float scalar) {
    return Vector3D(x / scalar, y / scalar, z / scalar);
  }
};

}  // namespace Obj