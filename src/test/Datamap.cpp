#include "Datamap.hpp"
#include "Range.hpp"

void printmap(Map & map)
{
    int w = map.GetWidth(), h = map.GetHeight();
    for (int i : range(w))
    {
        for (int j : range(h))
            if (map.IsWall(i, j))
                printf("%c", 219);
            else
                printf(" ");
        printf("\n");
    }
}
