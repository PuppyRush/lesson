#pragma once



typedef enum Type
{
	eWall,
	eFeed,
	eWorm,
	eRock,
	eNone,
}Type;

typedef enum Order
{
	eLeft,
	eRight,
	eUp,
	eDown
}Order;

typedef struct Coord
{
	size_t x;
	size_t y;
}Coord;


typedef struct Worm
{
	Coord coord;
	Order order;
}Worm;

typedef struct Map
{
	Type type;
	Coord coord;
}Map;
Map** g_map;
