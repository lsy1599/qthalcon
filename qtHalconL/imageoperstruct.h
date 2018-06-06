#pragma once
#ifndef IMAGEOPERSTRUCT_H_
#define IMAGEOPERSTRUCT_H_


#if defined(QTHALCONL_LIBRARY)
#  define QTHALCONLSHARED_EXPORT __declspec(dllexport)
#else
#  define QTHALCONLSHARED_EXPORT __declspec(dllimport)
#endif

#include "HalconCpp.h"
#include "vector"
#include "algorithm"


using namespace HalconCpp;
typedef void(*CallBackDisp)(void *);
struct QTHALCONLSHARED_EXPORT Rect
{
    double nTop;
    double nLeft;
    double nBottom;
    double nRight;
    Rect(double top = 0, double left = 0, double bottom = 0, double right = 0)
    {
        nTop = top;
        nLeft = left;
        nBottom = bottom;
        nRight = right;
    }
    ~Rect()
    {
        nTop = 0;
        nLeft = 0;
        nBottom = 0;
        nRight = 0;
    }
};
struct  rectDrawed
{
    HObject rectObj;
    HTuple rectColor;
};
struct InitDisp
{
    Rect rect;
};

#endif
