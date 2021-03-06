//
//  radialGeometry.c
//
//  Created by Constantine Karlis on 05/04/12.
//

// Copyright (c) 2013 Constantine Karlis
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include <QuartzCore/QuartzCore.h>
#include "radialGeometry.h"

float degreesToRadians(float degrees)  
{
    return M_PI * degrees / 180;
}

float radiansToDegrees(float radians)
{
    return 180 / M_PI * radians;
}

radialPoint radialPointMake(float radius , float angle)
{
    radialPoint p;
    p.radius = radius;
    p.angle = angle;
    return p;
}

CGPoint polarToCartesian(radialPoint point)
{
    float x = point.radius * cosf(point.angle);
    float y = point.radius * sinf(point.angle);
    return CGPointMake(x, y);
}

radialPoint cartesianToPolar(CGPoint point)
{
    float radius = sqrtf(powf(point.x, 2.0) + powf(point.y , 2.0));
    float angle = atan2f(point.y , point.x);
    return radialPointMake(radius, angle);
}