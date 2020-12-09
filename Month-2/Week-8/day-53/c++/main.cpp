/**
 * DAY-53 C++ version
 * 
 * Just run 'make' to compile and run all the tests
 */
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../../../dependencies/c++/doctest.h" //https://github.com/onqtam/doctest

/**
 * Write a function that takes initial speed (v in m/s) and throw angle (a in degrees) and returns the maximum height and maximum range reached by javelin as a string.
 * 
 * @param v0 Initial speed (in m/s)
 * @param a Throw angle (a in degrees)
 * @return The maximum height and maximum range reached by javelin as a string.
 */  
std::string javelinThrow(double v0, double a) {
    const double ar = a * (M_PI / 180); //first, convert degrees to radians because is what trig functions use
    const double g = 9.81;
    
    /*
    DISCOVER THE PEAK HEIGHT (yMax):
    --------------------------------
    By “height” we mean the altitude or vertical position y above the starting point. 
    The highest point in any trajectory, called the apex, is reached when 𝑣𝑦=0. 
    Since we know the initial and final velocities, as well as the initial position, 
    use the following equation to find y: 
    
    𝑣𝑦² = 𝑣0𝑦² − 2𝑔(𝑦 − 𝑦0)

    Because 𝑦0 and 𝑣𝑦 are both zero, the equation simplifies to:

    0 = 𝑣0𝑦² − 2𝑔 * 𝑦

    Solving for 𝑦 gives:

    𝑦 = 𝑣0𝑦² / 2𝑔

    Now we must find 𝑣0𝑦, the component of the initial velocity in the y direction. 
    It is given by 𝑣0𝑦 = 𝑣0 * sin𝜃0, where 𝑣0 is the initial velocity of "v" m/s and 𝜃0="ar" is the initial angle. Thus,

    𝑣0𝑦 = 𝑣0 * sin𝜃 

    and y is (where g = 9.81 m/s²):

    𝑦 = 𝑣0𝑦² / 2g 
    */
        
    double v0y = v0 * sin(ar);
    double y = pow(v0y, 2) / (2 * g); //<- peak height

    /**
     * DISCOVER THE HORIZONTAL DISPLACEMENT (xMax):
     * --------------------------------------------     
     * 
     * Based on the equation below, we can discover TIME 𝑡
     * 𝑦 = 𝑦0 + 𝑣0𝑦 * 𝑡 − (1/2) * 𝑔 * 𝑡²
     * 
     * We know that at the end, 𝑦 = 0 and the initial height 𝑦0 = 0, so:      
     * 𝑡 = ((1/2) * 𝑔 * 𝑡²) / 𝑣0𝑦
     * 
     * We must find 𝑣0𝑦, the component of the initial velocity in the y direction. 
     * 𝑣0𝑦 = 𝑣0 * sin𝜃 
     * 
     * 𝑡 = ((1/2) * 𝑔 * 𝑡²) / 𝑣0𝑦
     * 𝑡 = ((1/2) * 𝑔 * 𝑡²) / 𝑣0𝑦
     * 𝑣0𝑦 = ((1/2) * 𝑔 * 𝑡²) / 𝑡 
     * 𝑣0𝑦 = (1/2) * 𝑔 * 𝑡
     * 𝑡 = 2 * 𝑣0𝑦 / g         <- time discovered!
     * 
     * 
     * Now to the distance, by using:
     * 𝑥 = 𝑥0 + 𝑣𝑥 * 𝑡
     * 
     * We know that starting 𝑥0 = 0.
     * 
     * We must find 𝑣𝑥, the component of the initial velocity in the x direction. 
     * 𝑣𝑥 = 𝑣0 * cos𝜃 
     * 
     */ 
    double t = 2 * v0y / g;
    double vx = v0 * cos(ar);
    double x = 0 + vx * t;

    std::ostringstream ssY;
    ssY << std::fixed << std::setprecision(0) << y;

    std::ostringstream ssX;
    ssX << std::fixed << std::setprecision(0) << x;

    return "Ymax=" + ssY.str() + "m, Xmax=" +  ssX.str() + "m";
}

/**
 * Tests
 */
TEST_CASE("Tests")
{
    CHECK(javelinThrow(36.7, 45) == "Ymax=34m, Xmax=137m");
    CHECK(javelinThrow(51.3, 20) == "Ymax=16m, Xmax=172m");
    CHECK(javelinThrow(100.1, 89) == "Ymax=511m, Xmax=36m");    
}