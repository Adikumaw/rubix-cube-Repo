#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include "makeCubie.h"

enum side
{
    face,
    back,
    left,
    right,
    top,
    bottom
};

#define F newCube.sideRotate(side::face, "clk");
#define L newCube.sideRotate(side::left, "clk");
#define R newCube.sideRotate(side::right, "clk");
#define U newCube.sideRotate(side::top, "clk");
#define D newCube.sideRotate(side::bottom, "clk");
#define B newCube.sideRotate(side::back, "clk");
#define FP newCube.sideRotate(side::face, "antclk");
#define LP newCube.sideRotate(side::left, "antclk");
#define RP newCube.sideRotate(side::right, "antclk");
#define UP newCube.sideRotate(side::top, "antclk");
#define DP newCube.sideRotate(side::bottom, "antclk");
#define BP newCube.sideRotate(side::back, "antclk");

using namespace std;
string sideColor(int colorAsci);

int main()
{
    makeCubie newCube;
    newCube.setcube();
    // F L R U D B FP LP RP UP DP BP
    // newCube.crossSolver(newCube);
    newCube.f2lSolver(newCube);
    newCube.getCrossSolution();
    cout << endl;
    // newCube.getcube();
    // faceTranspose(&cubeMain);
    // using namespace std::this_thread; // sleep_for, sleep_until
    // chrono::sleep_until(system_clock::now() + seconds(1));
    // using namespace std::chrono; // nanoseconds, system_clock, seconds
    // this_thread::sleep_for(chrono::nanoseconds(60000000));
    getchar();
}
