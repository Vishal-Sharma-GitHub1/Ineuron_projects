// Trigonometry Library
//
// Copyright (c) 2022  Vishal Sharma
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265

// Here is a brief description of all the functions defined in this file below

// 1.  Function to convert degrees into radians
// 2.  Function to convert radians into degrees
// 3.  Function to calculate the distance between two places on earth
// 4.  Function to calculate the distance between two points on plane
// 5.  Function to find the slope of a line using coordinates of two points
// 6.  Function to find the slope of a line using equation
// 7.  Function to calculate the area of triangle using coordinates of three points
// 8.  Function to check given three points are collinear or not
// 9.  Function to find the angle of two lines using slopes
// 10. Function to find the angle of two lines using equations
// 11. Function to find the angle of two lines using the coordinates of three points
// 12. Function to identify the quadrant of a point on a coordinate plane
// 13. Function to find midpoint of a line



// @desc: Utility function for converting degrees to radians
long double radian(long double degree)
{
    // If we want to convert degrees to radians then ,
    // we have to multiply given value by PI/180 , And the value of PI/180 is approximately 0.017453

    return degree * 0.017453 ;
}

// @desc: Utility function for converting radians to degrees
long double degree(long double radian)
{
    // If we want to convert radians to degrees then ,
    // we have to multiply given value by 180/PI , And the value of 180/PI is approximately 57.295780

    return radian * 57.295780 ;
}

// @desc: Function to calculate the distance between two places on earth
double find_distance(long double lat1, long double long1, long double lat2, long double long2)
{
    // Co-ordinates of point A in terms of latitude (lat1) and longitude (long1) and
    // Co-ordinates of point B in terms of latitude (lat2) and longitude (long2)

    // converting the latitudes and longitudes from degrees to radian
    lat1  = radian(lat1);
    long1 = radian(long1);
    lat2  = radian(lat2);
    long2 = radian(long2);

    // Formula = d * acos[(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long2 – long1)]

    //  where 'd' is the radius of earth ,
    //      If you want to calculate the distance between two places in miles, use the value of d as 3,956
    //      If you want to calculate the distance between two places in kilometers, use the value of d as 6,371

    return 6371.0 * acos( sin(lat1)*sin(lat2) + cos(lat1)*cos(lat2)*cos(long2-long1) );  // returning distance in kilometers
}

// @desc: Function to calculate the distance between two points on plane
double distance(double x1, double y1, double x2, double y2)
{
    // (x1, y1)	=	coordinates of first point in the line
    // (x2, y2)	=	coordinates of second point in the line

    // Distance between two points is the length of the line segment that connects the two points in a plane.

    // Formula d = √( (x2 – x1)² + (y2 – y1)² )

    return sqrt( pow(x1-x2, 2) + pow(y1-y2, 2) ) ;
}

// @desc: Function to find the slope of a line using coordinates of two points
double slope_using_points(double x1, double y1, double x2, double y2)
{
    // (x1, y1)	=	coordinates of first point in the line
    // (x2, y2)	=	coordinates of second point in the line

    // The slope or gradient of a line is a number that describes both the direction X and Y and the steepness of the line

    // Formula m = (y2 – y1) / (x2 – x1)

    return (y2-y1) / (x2-x1) ;
}

// @desc: Function to find the slope of a line using equation
double slope_using_equation(double a, double b)
{
    // If the user has an equation in the form of  " ax + by + c = 0 " , then user can simply call this function

    // a = x-term of equation
    // b = y-term of equation

    // We all know if equation in this form " y = mx + c " then, the the slope is 'm'
    // Now we'll try to convert this equation " ax + by + c = 0 " into this equation " y = mx + c "

    // Conversion -->
    //      ax + by + c = 0
    //      by = -ax - c
    //      y  = -(a/b)x - (c/b)
    //      Therefore value of 'm' is -(a/b), which is slope

    return -(a/b) ;
}

// @desc: Function to calculate the area of triangle using coordinates of three points
double area_of_triangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
    // (x1, y1)	=	coordinates of first point in the line
    // (x2, y2)	=	coordinates of second point in the line
    // (x3, y3)	=	coordinates of third point in the line

    // The area of a triangle is defined as the total region that is enclosed by the three sides of any particular triangle

    // Formula a = x1(y2-y3) + x2(y3-y1) + x3(y1-y2)

    return ( x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) ) ;
}

// @desc: Function to check given three points are collinear or not
int isCollinear(double x1, double y1, double x2, double y2, double x3, double y3)
{
    // (x1, y1)	=	coordinates of first point in the line
    // (x2, y2)	=	coordinates of second point in the line
    // (x3, y3)	=	coordinates of third point in the line

    // Collinear points are the points that lie on the same straight line or in a single line
    // If we say, that three objects are placed in a line, that means the objects are collinear.

    /*
        Using the Area of Triangle Formula

        If the area of triangle formed by three points is zero, then they are said to be collinear.
        It means that if three points are collinear, then they cannot form a triangle.
    */

    return ( area_of_triangle(x1,y1,x2,y2,x3,y3) == 0 ) ;   // return 1 if points are collinear otherwise return 0
}

// @desc: Function to find the angle of two lines using slopes
double angle_using_slopes(double m1, double m2)
{
    // If the user has two equations in the form of  " y = mx + c " , then user can simply call this function

    // m1 = slope of first line
    // m2 = slope of second line

    // Formula Tanθ = ±( m1-m2 / 1+m1m2 )

    double res = (m1-m2) / (1+m1*m2);

    double angle = atan(res);           // "atan" function returns value in radian

    angle = round(degree(angle));       // we are converting radian to degree

    return angle;   // angle can be positive or negative
}

// @desc: Function to find the angle of two lines using equations
double angle_using_equations(double a1, double b1, double a2, double b2)
{
    // If the user has two equations in the form of  " ax + by + c = 0 " , then user can simply call this function

    // a1 = x-term of first equation
    // b1 = y-term of first equation
    // a2 = x-term of second equation
    // b2 = y-term of second equation

    // Formula Tanθ = ±( a2b1-a1b2 / a1a2+b1b2 )

    double res = ( (a2*b1)-(a1*b2) ) / ( (a1*a2) + (b1*b2) );

    double angle = atan(res);           // "atan" function returns value in radian

    angle = round(degree(angle));       // we are converting radian to degree

    return angle;   // angle can be positive or negative

}

// @desc: Function to find the angle of two lines using the coordinates of three points
double angle_using_points(double x1, double y1, double x2, double y2, double x3, double y3)
{
    // (x1, y1)	=	coordinates of first point in the line
    // (x2, y2)	=	coordinates of second point in the line
    // (x3, y3)	=	coordinates of third point in the line

    // firstly we'll find slopes

    double m1 = slope_using_points(x1,y1,x2,y2);
    double m2 = slope_using_points(x2,y2,x3,y3);

    // Now we can simply call to "angle_using_slopes" function

    return angle_using_slopes(m1, m2);
}

// @desc: Function to identify the quadrant of a point on a coordinate plane
int quadrant(double x, double y)
{
    // If x_coordinate is positive and y_coordinate is positive     -->  In First  Quadrant
    // If x_coordinate is negative and y_coordinate is positive     -->  In Second Quadrant
    // If x_coordinate is negative and y_coordinate is negative     -->  In Third  Quadrant
    // If x_coordinate is positive and y_coordinate is negative     -->  In Fourth Quadrant

    // If x_coordinate is zero and y_coordinate is also zero        -->  Origin condition
    // If x_coordinate is zero                                      -->  On Y - Axis
    // If y_coordinate is zero                                      -->  On X - Axis

    if(x > 0 && y > 0)
        return 1 ;          // In First  Quadrant

    if(x < 0 && y > 0)
        return 2 ;          // In Second Quadrant

    if(x < 0 && y < 0)
        return 3 ;          // In Third  Quadrant

    if(x > 0 && y < 0)
        return 4 ;          // In Fourth Quadrant

    if(x == 0 && y == 0)
        return 0 ;          // Origin points

    if(x == 0)
        return 25 ;         // On Y - Axis

    if(y == 0)
        return 24 ;         // On X - Axis
}

// @desc: Function to find midpoint of a line
double* midpoint(double x1, double y1, double x2, double y2)
{
    // (x1, y1)	=	coordinates of first point
    // (x2, y2)	=	coordinates of second point

    // A midpoint is a point lying between two points and is in the middle of the line joining the two points

    // Formula  -->
    //      x_coordinate = (x1+x2)/2
    //      y_coordinate = (y1+y2)/2

    double *arr = (double*)malloc(2*sizeof(double));    // allocation of memory

    arr[0] = (x1+x2) / 2;
    arr[1] = (y1+y2) / 2;

    return arr;     // we can't return two values , that's why we are returning the array which contains x and y coordinate of midpoint

    // please free the memory after use it
}
