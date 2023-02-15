#include "makeCubie.h"

#define F sideRotate(side::face, "clk")
#define L sideRotate(side::left, "clk")
#define R sideRotate(side::right, "clk")
#define U sideRotate(side::top, "clk")
#define D sideRotate(side::bottom, "clk")
#define B sideRotate(side::back, "clk")
#define FP sideRotate(side::face, "antclk")
#define LP sideRotate(side::left, "antclk")
#define RP sideRotate(side::right, "antclk")
#define UP sideRotate(side::top, "antclk")
#define DP sideRotate(side::bottom, "antclk")
#define BP sideRotate(side::back, "antclk")

string sideColor(int colorAsci);

// constructor...
makeCubie::makeCubie()
{
}
makeCubie::makeCubie(const makeCubie &source)
{
    for (int l{0}; l < 6; l++)
    {
        cubeMain.push_back(vector<vector<char>>());
        for (int m{0}; m < 3; m++)
        {
            cubeMain.at(l).push_back(vector<char>());
            for (int n{0}; n < 3; n++)
            {
                cubeMain.at(l).at(m).push_back(source.cubeMain.at(l).at(m).at(n));
            }
        }
    }
}

// GETTERS AND SETTERS......
void makeCubie::setcube()
{
    int temp{0};
    char ch{};
    string side{"NULL"};
    for (int l{0}; l < 6; l++)
    {
        side = sideColor(temp);
        std::cout << "Enter the colors of " << side << " side of cube rowvise: " << endl;
        cubeMain.push_back(vector<vector<char>>());
        for (int m{0}; m < 3; m++)
        {
            cubeMain.at(l).push_back(vector<char>());
            for (int n{0}; n < 3; n++)
            {
                cin >> ch;
                cubeMain.at(l).at(m).push_back(ch);
            }
        }
        temp++;
    }
}
void makeCubie::getcube()
{
    int temp{0};
    for (size_t i{0}; i < cubeMain.size(); i++)
    {
        std::cout << "\nElements on " << sideColor(temp) << " side is:" << endl;
        for (size_t j{0}; j < cubeMain.at(i).size(); j++)
        {
            for (size_t k{0}; k < cubeMain.at(i).at(j).size(); k++)
            {
                std::cout << cubeMain.at(i).at(j).at(k) << " ";
            }
            std::cout << endl;
        }
        temp++;
    }
};
void makeCubie::getCrossSolution()
{
    for (size_t i{0}; i < solution.size(); i++)
    {
        std::cout << solution.at(i) << " ";
    }
}

// SIDE ROTATE FUNCTIONS......
void makeCubie::sideRotate(int side, string direction)
{
    vector<char> sideBarBackup;
    faceTranspose(side, direction);
    if (side == face)
    {
        for (int i{0}; i < 3; i++)
            sideBarBackup.push_back(cubeMain[top].at(2).at(i));
        if (direction == "clk")
        {
            sideBarSender(left, "right", "rev.");
            sideBarReceiver(top, "bottom");
            sideBarSender(bottom, "top", "forward");
            sideBarReceiver(left, "right");
            sideBarSender(right, "left", "rev.");
            sideBarReceiver(bottom, "top");
            for (int i{0}; i < 3; i++)
                sideBar.push_back(sideBarBackup.at(i));
            sideBarReceiver(right, "left");
        }
        else
        {
            sideBarSender(right, "left", "forward");
            sideBarReceiver(top, "bottom");
            sideBarSender(bottom, "top", "rev.");
            sideBarReceiver(right, "left");
            sideBarSender(left, "right", "forward");
            sideBarReceiver(bottom, "top");
            for (int j{2}; j >= 0; j--)
                sideBar.push_back(sideBarBackup.at(j));
            sideBarReceiver(left, "right");
        }
    }
    else if (side == back)
    {
        for (int i{0}; i < 3; i++)
            sideBarBackup.push_back(cubeMain[top].at(0).at(i));
        if (direction == "clk")
        {
            sideBarSender(right, "right", "forward");
            sideBarReceiver(top, "top");
            sideBarSender(bottom, "bottom", "rev.");
            sideBarReceiver(right, "right");
            sideBarSender(left, "left", "forward");
            sideBarReceiver(bottom, "bottom");
            for (int j{2}; j >= 0; j--)
                sideBar.push_back(sideBarBackup.at(j));
            sideBarReceiver(left, "left");
        }
        else
        {
            sideBarSender(left, "left", "rev.");
            sideBarReceiver(top, "top");
            sideBarSender(bottom, "bottom", "forward");
            sideBarReceiver(left, "left");
            sideBarSender(right, "right", "rev.");
            sideBarReceiver(bottom, "bottom");
            for (int i{0}; i < 3; i++)
                sideBar.push_back(sideBarBackup.at(i));
            sideBarReceiver(right, "right");
        }
    }
    else if (side == left)
    {
        for (int i{0}; i < 3; i++)
            sideBarBackup.push_back(cubeMain[top].at(i).at(0));
        if (direction == "clk")
        {
            sideBarSender(back, "right", "rev.");
            sideBarReceiver(top, "left");
            sideBarSender(bottom, "left", "rev.");
            sideBarReceiver(back, "right");
            sideBarSender(face, "left", "forward");
            sideBarReceiver(bottom, "left");
            for (int i{0}; i < 3; i++)
                sideBar.push_back(sideBarBackup.at(i));
            sideBarReceiver(face, "left");
        }
        else
        {
            sideBarSender(face, "left", "forward");
            sideBarReceiver(top, "left");
            sideBarSender(bottom, "left", "forward");
            sideBarReceiver(face, "left");
            sideBarSender(back, "right", "rev.");
            sideBarReceiver(bottom, "left");
            for (int i{2}; i >= 0; i--)
                sideBar.push_back(sideBarBackup.at(i));
            sideBarReceiver(back, "right");
        }
    }
    else if (side == right)
    {
        for (int i{0}; i < 3; i++)
            sideBarBackup.push_back(cubeMain[top].at(i).at(2));
        if (direction == "clk")
        {
            sideBarSender(face, "right", "forward");
            sideBarReceiver(top, "right");
            sideBarSender(bottom, "right", "forward");
            sideBarReceiver(face, "right");
            sideBarSender(back, "left", "rev.");
            sideBarReceiver(bottom, "right");
            for (int i{2}; i >= 0; i--)
                sideBar.push_back(sideBarBackup.at(i));
            sideBarReceiver(back, "left");
        }
        else
        {
            sideBarSender(back, "left", "rev.");
            sideBarReceiver(top, "right");
            sideBarSender(bottom, "right", "rev.");
            sideBarReceiver(back, "left");
            sideBarSender(face, "right", "forward");
            sideBarReceiver(bottom, "right");
            for (int i{0}; i < 3; i++)
                sideBar.push_back(sideBarBackup.at(i));
            sideBarReceiver(face, "right");
        }
    }
    else if (side == top)
    {
        for (int i{0}; i < 3; i++)
            sideBarBackup.push_back(cubeMain[face].at(0).at(i));
        if (direction == "clk")
        {
            sideBarSender(right, "top", "forward");
            sideBarReceiver(face, "top");
            sideBarSender(back, "top", "forward");
            sideBarReceiver(right, "top");
            sideBarSender(left, "top", "forward");
            sideBarReceiver(back, "top");
            for (int i{0}; i < 3; i++)
                sideBar.push_back(sideBarBackup.at(i));
            sideBarReceiver(left, "top");
        }
        else
        {
            sideBarSender(left, "top", "forward");
            sideBarReceiver(face, "top");
            sideBarSender(back, "top", "forward");
            sideBarReceiver(left, "top");
            sideBarSender(right, "top", "forward");
            sideBarReceiver(back, "top");
            for (int i{0}; i < 3; i++)
                sideBar.push_back(sideBarBackup.at(i));
            sideBarReceiver(right, "top");
        }
    }
    else if (side == bottom)
    {
        for (int i{0}; i < 3; i++)
            sideBarBackup.push_back(cubeMain[face].at(2).at(i));
        if (direction == "clk")
        {
            sideBarSender(left, "bottom", "forward");
            sideBarReceiver(face, "bottom");
            sideBarSender(back, "bottom", "forward");
            sideBarReceiver(left, "bottom");
            sideBarSender(right, "bottom", "forward");
            sideBarReceiver(back, "bottom");
            for (int i{0}; i < 3; i++)
                sideBar.push_back(sideBarBackup.at(i));
            sideBarReceiver(right, "bottom");
        }
        else
        {
            sideBarSender(right, "bottom", "forward");
            sideBarReceiver(face, "bottom");
            sideBarSender(back, "bottom", "forward");
            sideBarReceiver(right, "bottom");
            sideBarSender(left, "bottom", "forward");
            sideBarReceiver(back, "bottom");
            for (int i{0}; i < 3; i++)
                sideBar.push_back(sideBarBackup.at(i));
            sideBarReceiver(left, "bottom");
        }
    };
}

// SIDE ROTATION's hellper modules......
void makeCubie::faceTranspose(int side, string direction)
{
    vector<vector<char>> tempVec{
        {'0', '0', '0'},
        {'0', '0', '0'},
        {'0', '0', '0'}};

    int i{0}, j{0};
    if (direction == "antclk")
    {
        j = 0;
        for (size_t l{0}; l < cubeMain[side].size(); l++)
        {
            i = 2;
            for (size_t m{0}; m < cubeMain[side].at(l).size(); m++)
            {
                tempVec[i][j] = cubeMain[side].at(l).at(m);
                i--;
            }
            j++;
        }
    }
    else if (direction == "clk")
    {
        j = 2;
        for (size_t l{0}; l < cubeMain[side].size(); l++)
        {
            i = 0;
            for (size_t m{0}; m < cubeMain[side].at(l).size(); m++)
            {
                tempVec[i][j] = cubeMain[side].at(l).at(m);
                ;
                i++;
            }
            j--;
        }
    }
    (cubeMain)[side] = tempVec;
}
void makeCubie::sideBarSender(int side, string sideBarDirection, string vectorStoringDirection)
{
    vector<char> sideBar;
    if (sideBarDirection == "left")
    {
        for (int i{0}; i < 3; i++)
        {
            sideBar.push_back(cubeMain[side].at(i).at(0));
        }
    }
    else if (sideBarDirection == "right")
    {
        for (int i{0}; i < 3; i++)
        {
            sideBar.push_back(cubeMain[side].at(i).at(2));
        }
    }
    else if (sideBarDirection == "top")
    {
        for (int i{0}; i < 3; i++)
        {
            sideBar.push_back(cubeMain[side].at(0).at(i));
        }
    }
    else if (sideBarDirection == "bottom")
    {
        for (int i{0}; i < 3; i++)
        {
            sideBar.push_back(cubeMain[side].at(2).at(i));
        }
    };
    if (vectorStoringDirection == "forward")
    {
        for (int j{0}; j < 3; j++)
        {
            this->sideBar.push_back(sideBar.at(j));
        }
    }
    else
    {
        for (int j{2}; j >= 0; j--)
        {
            this->sideBar.push_back(sideBar.at(j));
        }
    }
}
void makeCubie::sideBarReceiver(int side, string sideBarDirection)
{
    if (sideBarDirection == "bottom")
    {
        for (int i{0}; i < 3; i++)
        {
            cubeMain[side].at(2).at(i) = sideBar.at(i);
        }
    }
    else if (sideBarDirection == "left")
    {
        for (int i{0}; i < 3; i++)
        {
            cubeMain[side].at(i).at(0) = sideBar.at(i);
        }
    }
    else if (sideBarDirection == "top")
    {
        for (int i{0}; i < 3; i++)
        {
            cubeMain[side].at(0).at(i) = sideBar.at(i);
        }
    }
    else if (sideBarDirection == "right")
    {
        for (int i{0}; i < 3; i++)
        {
            cubeMain[side].at(i).at(2) = sideBar.at(i);
        }
    }
    sideBar.clear();
}
void makeCubie::f2lSolver(makeCubie &source)
{
    srand(time(NULL));
    int side, sentinal;
    bool cornerFound{false}, cornerLocMatch{false};
    while (!cornerFound)
    {
        side = ((rand() % (5 - 0 + 1)) + 0);

        if (side == 5)
        {
            if (cubeMain[side].at(0).at(0) == 'w')
            {
                cornerLocMatch = cornerColorsFinder(side, 0, 0);
                if (cornerLocMatch)
                {
                    edgeSetterOnTop(source, sideBar.at(0), sideBar.at(1));
                    sentinal = sideEdgeFinder(source, sideBar.at(0), sideBar.at(1), "callSetter");
                    if (sentinal == -1)
                    {
                        if (blockcolor == 'b')
                        {
                            U;
                            F;
                            UP;
                            FP;
                            UP;
                            LP;
                            U;
                            L;
                            solution.push_back("U");
                            solution.push_back("F");
                            solution.push_back("UP");
                            solution.push_back("FP");
                            solution.push_back("UP");
                            solution.push_back("LP");
                            solution.push_back("U");
                            solution.push_back("L");
                        }
                        else if (blockcolor == 'o')
                        {
                            UP;
                            LP;
                            U;
                            L;
                            U;
                            F;
                            UP;
                            FP;
                            solution.push_back("UP");
                            solution.push_back("LP");
                            solution.push_back("U");
                            solution.push_back("L");
                            solution.push_back("U");
                            solution.push_back("F");
                            solution.push_back("UP");
                            solution.push_back("FP");
                        }
                    }
                    else if (sentinal == 0)
                    {
                        F;
                        UP;
                        F;
                        F;
                        U;
                        U;
                        F;
                        UP;
                        LP;
                        U;
                        L;
                        solution.push_back("F");
                        solution.push_back("UP");
                        solution.push_back("F2");
                        solution.push_back("U2");
                        solution.push_back("F");
                        solution.push_back("UP");
                        solution.push_back("LP");
                        solution.push_back("U");
                        solution.push_back("L");
                    };
                }
                else
                {
                }
                sideBar.clear();
                cornerFound = true;
            }
            else if (cubeMain[side].at(0).at(2) == 'w')
            {
                cornerLocMatch = cornerColorsFinder(side, 0, 2);
                if (cornerLocMatch)
                {
                    edgeSetterOnTop(source, sideBar.at(0), sideBar.at(1));
                    sentinal = sideEdgeFinder(source, sideBar.at(0), sideBar.at(1), "callSetter");
                    if (sentinal == -1)
                    {
                        if (blockcolor == 'r')
                        {
                            U;
                            R;
                            UP;
                            RP;
                            UP;
                            FP;
                            U;
                            F;
                            solution.push_back("U");
                            solution.push_back("R");
                            solution.push_back("UP");
                            solution.push_back("RP");
                            solution.push_back("UP");
                            solution.push_back("FP");
                            solution.push_back("U");
                            solution.push_back("F");
                        }
                        else if (blockcolor == 'b')
                        {
                            UP;
                            FP;
                            U;
                            F;
                            U;
                            R;
                            UP;
                            RP;
                            solution.push_back("UP");
                            solution.push_back("FP");
                            solution.push_back("U");
                            solution.push_back("F");
                            solution.push_back("U");
                            solution.push_back("R");
                            solution.push_back("UP");
                            solution.push_back("RP");
                        }
                    }
                    else if (sentinal == 0)
                    {
                        R;
                        UP;
                        R;
                        R;
                        U;
                        U;
                        R;
                        UP;
                        FP;
                        U;
                        F;
                        solution.push_back("R");
                        solution.push_back("UP");
                        solution.push_back("R2");
                        solution.push_back("U2");
                        solution.push_back("R");
                        solution.push_back("UP");
                        solution.push_back("FP");
                        solution.push_back("U");
                        solution.push_back("F");
                    };
                }
                sideBar.clear();
                cornerFound = true;
            }
            else if (cubeMain[side].at(2).at(0) == 'w')
            {
                cornerLocMatch = cornerColorsFinder(side, 2, 0);
                if (cornerLocMatch)
                {
                    edgeSetterOnTop(source, sideBar.at(0), sideBar.at(1));
                    sentinal = sideEdgeFinder(source, sideBar.at(0), sideBar.at(1), "callSetter");
                    if (sentinal == -1)
                    {
                        if (blockcolor == 'o')
                        {
                            U;
                            L;
                            UP;
                            LP;
                            UP;
                            BP;
                            U;
                            B;
                            solution.push_back("U");
                            solution.push_back("L");
                            solution.push_back("UP");
                            solution.push_back("LP");
                            solution.push_back("UP");
                            solution.push_back("BP");
                            solution.push_back("U");
                            solution.push_back("B");
                        }
                        else if (blockcolor == 'g')
                        {
                            UP;
                            BP;
                            U;
                            B;
                            U;
                            L;
                            UP;
                            LP;
                            solution.push_back("UP");
                            solution.push_back("BP");
                            solution.push_back("U");
                            solution.push_back("B");
                            solution.push_back("U");
                            solution.push_back("L");
                            solution.push_back("UP");
                            solution.push_back("LP");
                        }
                    }
                    else if (sentinal == 0)
                    {
                        L;
                        UP;
                        L;
                        L;
                        U;
                        U;
                        L;
                        UP;
                        BP;
                        U;
                        B;
                        solution.push_back("L");
                        solution.push_back("UP");
                        solution.push_back("L2");
                        solution.push_back("U2");
                        solution.push_back("L");
                        solution.push_back("UP");
                        solution.push_back("BP");
                        solution.push_back("U");
                        solution.push_back("B");
                    };
                }
                sideBar.clear();
                cornerFound = true;
            }
            else if (cubeMain[side].at(2).at(2) == 'w')
            {
                cornerLocMatch = cornerColorsFinder(side, 2, 2);
                if (cornerLocMatch)
                {
                    edgeSetterOnTop(source, sideBar.at(0), sideBar.at(1));
                    sentinal = sideEdgeFinder(source, sideBar.at(0), sideBar.at(1), "callSetter");
                    if (sentinal == -1)
                    {
                        if (blockcolor == 'g')
                        {
                            U;
                            B;
                            UP;
                            BP;
                            UP;
                            RP;
                            U;
                            R;
                            solution.push_back("U");
                            solution.push_back("B");
                            solution.push_back("UP");
                            solution.push_back("BP");
                            solution.push_back("UP");
                            solution.push_back("RP");
                            solution.push_back("U");
                            solution.push_back("R");
                        }
                        else if (blockcolor == 'r')
                        {
                            UP;
                            RP;
                            U;
                            R;
                            U;
                            B;
                            UP;
                            BP;
                            solution.push_back("UP");
                            solution.push_back("RP");
                            solution.push_back("U");
                            solution.push_back("R");
                            solution.push_back("U");
                            solution.push_back("B");
                            solution.push_back("UP");
                            solution.push_back("BP");
                        }
                    }
                    else if (sentinal == 0)
                    {
                        B;
                        UP;
                        B;
                        B;
                        U;
                        U;
                        B;
                        UP;
                        RP;
                        U;
                        R;
                        solution.push_back("B");
                        solution.push_back("UP");
                        solution.push_back("B2");
                        solution.push_back("U2");
                        solution.push_back("B");
                        solution.push_back("UP");
                        solution.push_back("RP");
                        solution.push_back("U");
                        solution.push_back("R");
                    };
                }
                sideBar.clear();
                cornerFound = true;
            }
            else
            {
                cornerFound = false;
            }
        }
        else if (side == 4)
        {
            makeCubie temp_cube(source);
            if (cubeMain[side].at(0).at(0) == 'w')
            {
                cornerLocMatch = cornerColorsFinder(side, 0, 0);
                if (cornerLocMatch)
                {
                    sentinal = sideEdgeFinder(source, sideBar.at(0), sideBar.at(1), "doNotCall");

                    sideBar.clear();
                }
                else
                {
                    temp_cube.U;
                    cornerLocMatch = cornerColorsFinder(side, 0, 0);
                    if (cornerLocMatch)
                    {
                        U;
                        solution.push_back("U");
                        sideBar.clear();
                    }
                    else
                    {
                        temp_cube.U;
                        cornerLocMatch = cornerColorsFinder(side, 0, 0);
                        if (cornerLocMatch)
                        {
                            U;
                            U;
                            solution.push_back("U2");
                        }
                        else
                        {
                            UP;
                            solution.push_back("UP");
                        }
                        sideBar.clear();
                    }
                }

                cornerFound = true;
            }
            else if (cubeMain[side].at(0).at(2) == 'w')
            {
                cornerLocMatch = cornerColorsFinder(side, 0, 2);
                cornerFound = true;
            }
            else if (cubeMain[side].at(2).at(0) == 'w')
            {
                cornerLocMatch = cornerColorsFinder(side, 2, 0);
                cornerFound = true;
            }
            else if (cubeMain[side].at(2).at(2) == 'w')
            {
                cornerLocMatch = cornerColorsFinder(side, 2, 2);
                cornerFound = true;
            }
            else
            {
                cornerFound = false;
            }
        }
        else
        {
            if (cubeMain[side].at(0).at(0) == 'w')
            {
                // do not use side setter on top..
                cornerLocMatch = cornerColorsFinder(side, 0, 0);
                cornerFound = true;
            }
            else if (cubeMain[side].at(0).at(2) == 'w')
            {
                // do not use side setter on top..
                cornerLocMatch = cornerColorsFinder(side, 0, 2);
                cornerFound = true;
            }
            else if (cubeMain[side].at(2).at(0) == 'w')
            {
                cornerLocMatch = cornerColorsFinder(side, 2, 0);
                cornerFound = true;
            }
            else if (cubeMain[side].at(2).at(2) == 'w')
            {
                cornerLocMatch = cornerColorsFinder(side, 2, 2);
                cornerFound = true;
            }
            else
            {
                cornerFound = false;
            }
        }
    }
    if (side == 5 && cornerLocMatch)
    {
    }
}
bool makeCubie::cornerColorsFinder(int side, int row, int col)
{
    vector<int> sideloc;
    if ((side == face && row == 0 && col == 2) ||
        (side == top && row == 2 && col == 2) ||
        (side == right && row == 0 && col == 0))
    {
        sideloc.push_back(face);
        sideloc.push_back(top);
        sideloc.push_back(right);
        if (cubeMain[face].at(0).at(2) != 'w')
            sideBar.push_back(cubeMain[face].at(0).at(2));
        ;
        if (cubeMain[top].at(2).at(2) != 'w')
            sideBar.push_back(cubeMain[top].at(2).at(2));
        ;
        if (cubeMain[right].at(0).at(0) != 'w')
            sideBar.push_back(cubeMain[right].at(0).at(0));
        ;
    }
    else if ((side == face && row == 0 && col == 0) ||
             (side == top && row == 2 && col == 0) ||
             (side == left && row == 0 && col == 2))
    {
        sideloc.push_back(face);
        sideloc.push_back(top);
        sideloc.push_back(left);
        if (cubeMain[face].at(0).at(0) != 'w')
            sideBar.push_back(cubeMain[face].at(0).at(0));
        ;
        if (cubeMain[top].at(2).at(0) != 'w')
            sideBar.push_back(cubeMain[top].at(2).at(0));
        ;
        if (cubeMain[left].at(0).at(2) != 'w')
            sideBar.push_back(cubeMain[left].at(0).at(2));
        ;
    }
    else if ((side == left && row == 0 && col == 0) ||
             (side == top && row == 0 && col == 0) ||
             (side == back && row == 0 && col == 2))
    {
        sideloc.push_back(back);
        sideloc.push_back(top);
        sideloc.push_back(left);
        if (cubeMain[back].at(0).at(2) != 'w')
            sideBar.push_back(cubeMain[back].at(0).at(2));
        ;
        if (cubeMain[top].at(0).at(0) != 'w')
            sideBar.push_back(cubeMain[top].at(0).at(0));
        ;
        if (cubeMain[left].at(0).at(0) != 'w')
            sideBar.push_back(cubeMain[left].at(0).at(0));
        ;
    }
    else if ((side == back && row == 0 && col == 0) ||
             (side == top && row == 0 && col == 2) ||
             (side == right && row == 0 && col == 2))
    {
        sideloc.push_back(back);
        sideloc.push_back(top);
        sideloc.push_back(right);
        if (cubeMain[back].at(0).at(0) != 'w')
            sideBar.push_back(cubeMain[back].at(0).at(0));
        ;
        if (cubeMain[top].at(0).at(2) != 'w')
            sideBar.push_back(cubeMain[top].at(0).at(2));
        ;
        if (cubeMain[right].at(0).at(2) != 'w')
            sideBar.push_back(cubeMain[right].at(0).at(2));
        ;
    }
    // bottom corners...
    else if ((side == face && row == 2 && col == 2) ||
             (side == bottom && row == 0 && col == 2) ||
             (side == right && row == 2 && col == 0))
    {
        sideloc.push_back(face);
        sideloc.push_back(bottom);
        sideloc.push_back(right);
        if (cubeMain[face].at(2).at(2) != 'w')
            sideBar.push_back(cubeMain[face].at(2).at(2));
        ;
        if (cubeMain[bottom].at(0).at(2) != 'w')
            sideBar.push_back(cubeMain[bottom].at(0).at(2));
        ;
        if (cubeMain[right].at(2).at(0) != 'w')
            sideBar.push_back(cubeMain[right].at(2).at(0));
        ;
    }
    else if ((side == face && row == 2 && col == 0) ||
             (side == bottom && row == 0 && col == 0) ||
             (side == left && row == 2 && col == 2))
    {
        sideloc.push_back(face);
        sideloc.push_back(bottom);
        sideloc.push_back(left);
        if (cubeMain[face].at(2).at(0) != 'w')
            sideBar.push_back(cubeMain[face].at(2).at(0));
        ;
        if (cubeMain[bottom].at(0).at(0) != 'w')
            sideBar.push_back(cubeMain[bottom].at(0).at(0));
        ;
        if (cubeMain[left].at(2).at(2) != 'w')
            sideBar.push_back(cubeMain[left].at(2).at(2));
        ;
    }
    else if ((side == left && row == 2 && col == 0) ||
             (side == bottom && row == 2 && col == 0) ||
             (side == back && row == 2 && col == 2))
    {
        sideloc.push_back(left);
        sideloc.push_back(bottom);
        sideloc.push_back(back);
        if (cubeMain[left].at(2).at(0) != 'w')
            sideBar.push_back(cubeMain[left].at(2).at(0));
        ;
        if (cubeMain[bottom].at(2).at(0) != 'w')
            sideBar.push_back(cubeMain[bottom].at(2).at(0));
        ;
        if (cubeMain[back].at(2).at(2) != 'w')
            sideBar.push_back(cubeMain[back].at(2).at(2));
        ;
    }
    else if ((side == back && row == 2 && col == 0) ||
             (side == bottom && row == 2 && col == 2) ||
             (side == right && row == 2 && col == 2))
    {
        sideloc.push_back(back);
        sideloc.push_back(bottom);
        sideloc.push_back(right);
        if (cubeMain[back].at(2).at(0) != 'w')
            sideBar.push_back(cubeMain[back].at(2).at(0));
        ;
        if (cubeMain[bottom].at(2).at(2) != 'w')
            sideBar.push_back(cubeMain[bottom].at(2).at(2));
        ;
        if (cubeMain[right].at(2).at(2) != 'w')
            sideBar.push_back(cubeMain[right].at(2).at(2));
        ;
    }
    int x{0};
    for (int i{0}; i < 3; i++)
    {
        if (cubeMain.at(sideloc.at(i)).at(1).at(1) == sideBar.at(0) || cubeMain.at(sideloc.at(i)).at(1).at(1) == sideBar.at(1))
            x++;
    }
    if (x == 2)
        return true;
    else
        return false;
}
void makeCubie::edgeSetterOnTop(makeCubie &source, char color_1, char color_2)
{
    makeCubie temp_cube(source);
    bool pos{false};
    int temp{0};
    while (!pos)
    {
        if (cubeMain[face].at(0).at(1) == color_1 && cubeMain[top].at(2).at(1) == color_2)
        {
            if (color_1 == temp_cube.cubeMain[face].at(1).at(1))
                pos = true;
            else
            {
                temp_cube.U;
                temp++;
            }
            blockcolor = color_2;
        }
        else if (cubeMain[top].at(1).at(2) == color_2 && cubeMain[right].at(0).at(1) == color_1)
        {
            if (color_1 == temp_cube.cubeMain[right].at(1).at(1))
                pos = true;
            else
            {
                temp_cube.U;
                temp++;
            }
            blockcolor = color_2;
        }
        else if (cubeMain[top].at(1).at(0) == color_2 && cubeMain[left].at(0).at(1) == color_1)
        {
            if (color_1 == temp_cube.cubeMain[left].at(1).at(1))
                pos = true;
            else
            {
                temp_cube.U;
                temp++;
            }
            blockcolor = color_2;
        }
        else if (cubeMain[top].at(0).at(1) == color_2 && cubeMain[back].at(0).at(1) == color_1)
        {
            if (color_1 == temp_cube.cubeMain[back].at(1).at(1))
                pos = true;
            else
            {
                temp_cube.U;
                temp++;
            }
            blockcolor = color_2;
        }
        // if second color is not on the face.....
        else if (cubeMain[face].at(0).at(1) == color_2 && cubeMain[top].at(2).at(1) == color_1)
        {
            if (color_2 == temp_cube.cubeMain[face].at(1).at(1))
                pos = true;
            else
            {
                temp_cube.U;
                temp++;
            }
            blockcolor = color_1;
        }
        else if (cubeMain[top].at(1).at(2) == color_1 && cubeMain[right].at(0).at(1) == color_2)
        {
            if (color_2 == temp_cube.cubeMain[right].at(1).at(1))
                pos = true;
            else
            {
                temp_cube.U;
                temp++;
            }
            blockcolor = color_1;
        }
        else if (cubeMain[top].at(1).at(0) == color_1 && cubeMain[left].at(0).at(1) == color_2)
        {
            if (color_2 == temp_cube.cubeMain[left].at(1).at(1))
                pos = true;
            else
            {
                temp_cube.U;
                temp++;
            }
            blockcolor = color_1;
        }
        // back side edges
        else if (cubeMain[top].at(0).at(1) == color_1 && cubeMain[back].at(0).at(1) == color_2)
        {
            if (color_2 == temp_cube.cubeMain[back].at(1).at(1))
                pos = true;
            else
            {
                temp_cube.U;
                temp++;
            }
            blockcolor = color_1;
        }
        else
        {
            pos = true;
        }
    }
    switch (temp)
    {
    case 3:
        UP;
        source.solution.push_back("UP");
        break;
    case 2:
        U;
        U;
        source.solution.push_back("U");
        source.solution.push_back("U");
        break;
    case 1:
        U;
        source.solution.push_back("U");
        break;
    default:
        break;
    }
}
int makeCubie::sideEdgeFinder(makeCubie &source, char color_1, char color_2, string edgeSetter)
{
    /////////////////////////////////////////
    if (cubeMain[face].at(1).at(2) == color_1 && cubeMain[right].at(1).at(0) == color_2)
    {
        if (color_1 == cubeMain[face].at(1).at(1) && color_2 == cubeMain[right].at(1).at(1))
        {
            return 1;
        }
        else if (color_2 == cubeMain[face].at(1).at(1) && color_1 == cubeMain[right].at(1).at(1))
        {
            return 0;
        }
        else if (color_1 == cubeMain[face].at(1).at(1) || color_2 == cubeMain[face].at(1).at(1))
        {
            R;
            U;
            RP;
            solution.push_back("R");
            solution.push_back("U");
            solution.push_back("RP");
        }
        else if (color_1 == cubeMain[right].at(1).at(1) || color_2 == cubeMain[right].at(1).at(1))
        {
            FP;
            UP;
            F;
            solution.push_back("FP");
            solution.push_back("UP");
            solution.push_back("F");
        }
        else
        {
            R;
            UP;
            RP;
            solution.push_back("R");
            solution.push_back("UP");
            solution.push_back("RP");
        }
        if (edgeSetter == "callSetter")
            edgeSetterOnTop(source, color_1, color_2);
        blockcolor = color_1;
        return -1;
    }
    else if (cubeMain[face].at(1).at(2) == color_2 && cubeMain[right].at(1).at(0) == color_1)
    {
        if (color_2 == cubeMain[face].at(1).at(1) && color_1 == cubeMain[right].at(1).at(1))
        {
            return 1;
        }
        else if (color_1 == cubeMain[face].at(1).at(1) && color_2 == cubeMain[right].at(1).at(1))
        {
            return 0;
        }
        else if (color_1 == cubeMain[face].at(1).at(1) || color_2 == cubeMain[face].at(1).at(1))
        {
            R;
            U;
            RP;
            solution.push_back("R");
            solution.push_back("U");
            solution.push_back("RP");
        }
        else if (color_1 == cubeMain[right].at(1).at(1) || color_2 == cubeMain[right].at(1).at(1))
        {
            FP;
            UP;
            F;
            solution.push_back("FP");
            solution.push_back("UP");
            solution.push_back("F");
        }
        else
        {
            R;
            UP;
            RP;
            solution.push_back("R");
            solution.push_back("UP");
            solution.push_back("RP");
        }
        if (edgeSetter == "callSetter")
            edgeSetterOnTop(source, color_1, color_2);
        blockcolor = color_2;
        return -1;
    }
    else if (cubeMain[face].at(1).at(0) == color_1 && cubeMain[left].at(1).at(2) == color_2)
    {
        if (color_1 == cubeMain[face].at(1).at(1) && color_2 == cubeMain[left].at(1).at(1))
        {
            return 1;
        }
        else if (color_2 == cubeMain[face].at(1).at(1) && color_1 == cubeMain[left].at(1).at(1))
        {
            return 0;
        }
        else if (color_1 == cubeMain[face].at(1).at(1) || color_2 == cubeMain[face].at(1).at(1))
        {
            LP;
            UP;
            L;
            solution.push_back("LP");
            solution.push_back("UP");
            solution.push_back("L");
        }
        else if (color_1 == cubeMain[left].at(1).at(1) || color_2 == cubeMain[left].at(1).at(1))
        {
            F;
            U;
            FP;
            solution.push_back("F");
            solution.push_back("U");
            solution.push_back("FP");
        }
        else
        {
            LP;
            U;
            L;
            solution.push_back("LP");
            solution.push_back("U");
            solution.push_back("L");
        }
        if (edgeSetter == "callSetter")
            edgeSetterOnTop(source, color_1, color_2);
        blockcolor = color_1;
        return -1;
    }
    else if (cubeMain[face].at(1).at(0) == color_2 && cubeMain[left].at(1).at(2) == color_1)
    {
        if (color_2 == cubeMain[face].at(1).at(1) && color_1 == cubeMain[left].at(1).at(1))
        {
            return 1;
        }
        else if (color_1 == cubeMain[face].at(1).at(1) && color_2 == cubeMain[left].at(1).at(1))
        {
            return 0;
        }
        else if (color_1 == cubeMain[face].at(1).at(1) || color_2 == cubeMain[face].at(1).at(1))
        {
            LP;
            UP;
            L;
            solution.push_back("LP");
            solution.push_back("UP");
            solution.push_back("L");
        }
        else if (color_1 == cubeMain[left].at(1).at(1) || color_2 == cubeMain[left].at(1).at(1))
        {
            F;
            U;
            FP;
            solution.push_back("F");
            solution.push_back("U");
            solution.push_back("FP");
        }
        else
        {
            LP;
            U;
            L;
            solution.push_back("LP");
            solution.push_back("U");
            solution.push_back("L");
        }
        if (edgeSetter == "callSetter")
            edgeSetterOnTop(source, color_1, color_2);
        blockcolor = color_2;
        return -1;
    }
    // mid side edges
    else if (cubeMain[right].at(1).at(2) == color_1 && cubeMain[back].at(1).at(0) == color_2)
    {
        if (color_1 == cubeMain[right].at(1).at(1) && color_2 == cubeMain[back].at(1).at(1))
        {
            return 1;
        }
        else if (color_2 == cubeMain[right].at(1).at(1) && color_1 == cubeMain[back].at(1).at(1))
        {
            return 0;
        }
        else if (color_1 == cubeMain[right].at(1).at(1) || color_2 == cubeMain[right].at(1).at(1))
        {
            B;
            U;
            BP;
            solution.push_back("B");
            solution.push_back("U");
            solution.push_back("BP");
        }
        else if (color_1 == cubeMain[back].at(1).at(1) || color_2 == cubeMain[back].at(1).at(1))
        {
            RP;
            UP;
            R;
            solution.push_back("RP");
            solution.push_back("UP");
            solution.push_back("R");
        }
        else
        {
            RP;
            U;
            R;
            solution.push_back("RP");
            solution.push_back("U");
            solution.push_back("R");
        }
        if (edgeSetter == "callSetter")
            edgeSetterOnTop(source, color_1, color_2);
        blockcolor = color_2;
        return -1;
    }
    else if (cubeMain[right].at(1).at(2) == color_2 && cubeMain[back].at(1).at(0) == color_1)
    {
        if (color_2 == cubeMain[right].at(1).at(1) && color_1 == cubeMain[back].at(1).at(1))
        {
            return 1;
        }
        else if (color_1 == cubeMain[right].at(1).at(1) && color_2 == cubeMain[back].at(1).at(1))
        {
            return 0;
        }
        else if (color_1 == cubeMain[right].at(1).at(1) || color_2 == cubeMain[right].at(1).at(1))
        {
            B;
            U;
            BP;
            solution.push_back("B");
            solution.push_back("U");
            solution.push_back("BP");
        }
        else if (color_1 == cubeMain[back].at(1).at(1) || color_2 == cubeMain[back].at(1).at(1))
        {
            RP;
            UP;
            R;
            solution.push_back("RP");
            solution.push_back("UP");
            solution.push_back("R");
        }
        else
        {
            RP;
            U;
            R;
            solution.push_back("RP");
            solution.push_back("U");
            solution.push_back("R");
        }
        if (edgeSetter == "callSetter")
            edgeSetterOnTop(source, color_1, color_2);
        blockcolor = color_1;
        return -1;
    }
    else if (cubeMain[left].at(1).at(0) == color_1 && cubeMain[back].at(1).at(2) == color_2)
    {
        if (color_1 == cubeMain[left].at(1).at(1) && color_2 == cubeMain[back].at(1).at(1))
        {
            return 1;
        }
        else if (color_2 == cubeMain[left].at(1).at(1) && color_1 == cubeMain[back].at(1).at(1))
        {
            return 0;
        }
        else if (color_1 == cubeMain[left].at(1).at(1) || color_2 == cubeMain[left].at(1).at(1))
        {
            BP;
            U;
            B;
            solution.push_back("BP");
            solution.push_back("U");
            solution.push_back("B");
        }
        else if (color_1 == cubeMain[back].at(1).at(1) || color_2 == cubeMain[back].at(1).at(1))
        {
            L;
            U;
            LP;
            solution.push_back("L");
            solution.push_back("U");
            solution.push_back("LP");
        }
        else
        {
            L;
            UP;
            LP;
            solution.push_back("L");
            solution.push_back("UP");
            solution.push_back("LP");
        }
        if (edgeSetter == "callSetter")
            edgeSetterOnTop(source, color_1, color_2);
        blockcolor = color_2;
        return -1;
    }
    else if (cubeMain[left].at(1).at(0) == color_2 && cubeMain[back].at(1).at(2) == color_1)
    {
        if (color_2 == cubeMain[left].at(1).at(1) && color_1 == cubeMain[back].at(1).at(1))
        {
            return 1;
        }
        else if (color_1 == cubeMain[left].at(1).at(1) && color_2 == cubeMain[back].at(1).at(1))
        {
            return 0;
        }
        else if (color_1 == cubeMain[left].at(1).at(1) || color_2 == cubeMain[left].at(1).at(1))
        {
            BP;
            U;
            B;
            solution.push_back("BP");
            solution.push_back("U");
            solution.push_back("B");
        }
        else if (color_1 == cubeMain[back].at(1).at(1) || color_2 == cubeMain[back].at(1).at(1))
        {
            L;
            U;
            LP;
            solution.push_back("L");
            solution.push_back("U");
            solution.push_back("LP");
        }
        else
        {
            L;
            UP;
            LP;
            solution.push_back("L");
            solution.push_back("UP");
            solution.push_back("LP");
        }
        if (edgeSetter == "callSetter")
            edgeSetterOnTop(source, color_1, color_2);
        blockcolor = color_1;
        return -1;
    }
}
// SOLVING FUNCTIONS.....
void makeCubie::crossSolver(makeCubie &source)
{
    srand(time(NULL));
    long int trials{0};
    int moves{0};
    bool solve{false};
    makeCubie tempCube(source);
    std::cout << endl;
    while (!solve)
    {
        for (int l{0}; l < 6; l++)
        {
            for (int m{0}; m < 3; m++)
            {
                for (int n{0}; n < 3; n++)
                {
                    tempCube.cubeMain.at(l).at(m).at(n) = source.cubeMain.at(l).at(m).at(n);
                }
            }
        }
        while (tempCube.cubeMain[bottom].at(0).at(1) != 'w' || tempCube.cubeMain[bottom].at(1).at(0) != 'w' || tempCube.cubeMain[bottom].at(1).at(2) != 'w' || tempCube.cubeMain[bottom].at(2).at(1) != 'w' || tempCube.cubeMain[face].at(2).at(1) != 'b' || tempCube.cubeMain[right].at(2).at(1) != 'r' || tempCube.cubeMain[back].at(2).at(1) != 'g' || tempCube.cubeMain[left].at(2).at(1) != 'o')
        {
            moves = ((rand() % (12 - 1 + 1)) + 1);

            switch (moves)
            {
            case 1:
                source.solution.push_back("F");
                tempCube.F;
                break;
            case 2:
                source.solution.push_back("L");
                tempCube.L;
                break;
            case 3:
                source.solution.push_back("R");
                tempCube.R;
                break;
            case 4:
                source.solution.push_back("U");
                tempCube.U;
                break;
            case 5:
                source.solution.push_back("D");
                tempCube.D;
                break;
            case 6:
                source.solution.push_back("B");
                tempCube.B;
                break;
            case 7:
                source.solution.push_back("FP");
                tempCube.FP;
                break;
            case 8:
                source.solution.push_back("LP");
                tempCube.LP;
                break;
            case 9:
                source.solution.push_back("RP");
                tempCube.RP;
                break;
            case 10:
                source.solution.push_back("UP");
                tempCube.UP;
                break;
            case 11:
                source.solution.push_back("DP");
                tempCube.DP;
                break;
            case 12:
                source.solution.push_back("BP");
                tempCube.BP;
                break;
            default:
                break;
            }

            trials++;
            std::cout << "\r" << trials << " combinations tried!";
            solve = true;
            if ((trials % 10) == 0)
            {
                source.solution.clear();
                solve = false;
                break;
            }
        }
    }
    for (size_t i{0}; i < solution.size(); i++)
    {
        if (solution.at(i) == "F")
            F;
        else if (solution.at(i) == "L")
            L;
        else if (solution.at(i) == "R")
            R;
        else if (solution.at(i) == "U")
            U;
        else if (solution.at(i) == "D")
            D;
        else if (solution.at(i) == "B")
            B;
        else if (solution.at(i) == "FP")
            FP;
        else if (solution.at(i) == "LP")
            LP;
        else if (solution.at(i) == "RP")
            RP;
        else if (solution.at(i) == "UP")
            UP;
        else if (solution.at(i) == "DP")
            DP;
        else if (solution.at(i) == "BP")
            BP;
    }
    std::cout << "\ncross solved...." << endl;
}

string sideColor(int colorAsci)
{
    if (colorAsci == 0)
    {
        return "blue";
    }
    else if (colorAsci == 1)
    {
        return "green";
    }
    else if (colorAsci == 2)
    {
        return "orange";
    }
    else if (colorAsci == 3)
    {
        return "red";
    }
    else if (colorAsci == 4)
    {
        return "yellow";
    }
    else
    {
        return "white";
    }
}
