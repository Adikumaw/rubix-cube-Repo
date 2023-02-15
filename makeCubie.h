#ifndef _MAKECUBIE_H_
#define _MAKECUBIE_H_

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

class makeCubie
{
private:
    vector<vector<vector<char>>> cubeMain{};
    vector<char> sideBar;
    vector<int> block;
    char blockcolor;
    vector<string> solution;
    enum side
    {
        face,
        back,
        left,
        right,
        top,
        bottom
    };

public:
    // constructor...
    makeCubie();
    makeCubie(const makeCubie &source);
    // GETTERS AND SETTERS......
    void setcube();
    void getcube();
    void getCrossSolution();

    // SIDE ROTATE FUNCTIONS......
    void sideRotate(int side, string direction);

    // SOLVING FUNCTIONS.....
    void crossSolver(makeCubie &source);
    void f2lSolver(makeCubie &source);
    // SIDE ROTATION's hellper modules......
    void faceTranspose(int side, string direction);
    void sideBarSender(int side, string sideBarDirection, string vectprStoringDirection);
    void sideBarReceiver(int side, string sideBarDirection);
    bool cornerColorsFinder(int side, int row, int col);
    int sideEdgeFinder(makeCubie &source, char color_1, char color_2, string edgeSetter);
    void edgeSetterOnTop(makeCubie &source, char color_1, char color_2);
};

#endif //_MAKECUBIE_H_