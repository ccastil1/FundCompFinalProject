#include<stdio.h>
#include<math.h>
float mag(float x, float y)
        {
                float mag;
                mag = sqrt(x * x + y * y);
                return mag;
        }

	float theta(float x, float y)
        {
                float theta;
                theta = atan(y/x)* 180/3.14;
                return theta;
        }
