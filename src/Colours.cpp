#include "colours.h"

const Color emptyGrey = {26, 31, 40, 255};
const Color green = {106, 204, 109, 255};
const Color red = {250, 45, 45, 255};
const Color orange = {255, 167, 93, 255};
const Color yellow = {202, 204, 106, 255};
const Color purple = {162, 106, 204, 255};
const Color cyan = {106, 204, 204, 255};
const Color blue = {48, 45, 250, 255};
const Color lightGrey = {108, 108, 117, 255};
const Color darkGrey = {67, 66, 79, 255};

std::vector<Color> GetCellColours()
{
    return {emptyGrey, green, red, orange, yellow, purple, cyan, blue};
}