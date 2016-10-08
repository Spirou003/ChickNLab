#include "CirclesBased.hpp"
#include "../NumberGenerator/Zero.hpp"
#include "../Map.hpp"

MapGeneratorCirclesBased::MapGeneratorCirclesBased():rng(00){}
MapGeneratorCirclesBased::~MapGeneratorCirclesBased(){}

void MapGeneratorCirclesBased::Generate(uint16_t width, uint16_t height, MapWriter & map)
{
    if (rng == 0)
        rng = Zero::GetInstance();
    if (map.GetWidth() < 3 || map.GetHeight() < 3)
        return;
    //if (symetric)
    {
        //todo
    }
    //else
    {
        int i = 1, j = 1, k = 0;
        map.Clear(MapCell::WALL);
        while (i < width-1)
        {
            map.SetEmpty(i, 1);
            map.SetEmpty(i, height-2);
            i++;
        }
        j = 1;
        while (j < height-1)
        {
            map.SetEmpty(1, j);
            map.SetEmpty(width-2, j);
            j++;
        }
        k = 3;
        bool topleft = false, bottomright = false;
        while (k < width/2+width%2 && k < height/2+height%2 && k+1 != width-k-1 && k+1 != height-k-1)
        {
            i = k;
            j = k;
            topleft = false;
            bottomright = false;
            while (i < width-k)
            {
                if ((not topleft) and rng->NextInt()%q < p)
                {
                    map.SetEmpty(i, k-1);
                    topleft = true;
                }
                else
                {
                    topleft = false;
                }
                if ((not bottomright) and rng->NextInt()%q < p)
                {
                    map.SetEmpty(i, height-k);
                    bottomright = true;
                }
                else
                {
                    bottomright = false;
                }
                map.SetEmpty(i, height-k-1);
                map.SetEmpty(i, k);
                i++;
            }
            topleft = false;
            bottomright = false;
            while (j < height-k)
            {
                if ((not topleft) and rng->NextInt()%q < p)
                {
                    map.SetEmpty(k-1, j);
                    topleft = true;
                }
                else
                {
                    topleft = false;
                }
                if ((not bottomright) and rng->NextInt()%q < p)
                {
                    map.SetEmpty(width-k, j);
                    bottomright = true;
                }
                else
                {
                    bottomright = false;
                }
                map.SetEmpty(width-k-1, j);
                map.SetEmpty(k, j);
                j++;
            }
            k += 2;
        }
        /*
        trouer le rectangle de murs central s'il y en a un, différencier vertical / horizontal
        */
    }
}
