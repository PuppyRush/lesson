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
	eLeft = 0,
	eRight,
	eUp,
	eDown,
	eOrder
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

typedef struct WormNode
{
	struct Worm worm;
	struct WormNode* next;
	struct WormNode* prev;
}WormNode;

typedef struct Map
{
	Type type;
}Map;
Map** g_map;
