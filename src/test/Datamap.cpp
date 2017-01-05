#include "Datamap.hpp"

void printmap(Map & map)
{
    int i = 0, j = 0, w = map.GetWidth(), h = map.GetHeight();
    while (i < w)
    {
        j = 0;
        while (j < h)
        {
            if (map.IsWall(i, j))
            {
                printf("%c", 219);
            }
            else
            {
                printf(" ");
            }
            j++;
        }
        printf("\n");
        i++;
    }
}
