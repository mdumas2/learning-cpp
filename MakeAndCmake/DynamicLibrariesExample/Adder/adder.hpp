#pragma once

#define MYLIB_API __declspec(dllexport)

namespace mylib
{
    MYLIB_API  int add(int a, int b);
    MYLIB_API  float add(float a, float b);
}