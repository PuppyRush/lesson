#pragma once

#include "type.h"
#include "define.h"
#include "framework.h"

static const size_t INVALID_SIZE = UINT_MAX;

//메인 윈도우 핸들러
static HWND g_hwndWnd = NULL;
static HWND g_hwndProc = NULL;


//extern과 static의 차이?
//https://dojang.io/mod/page/view.php?id=690
static	size_t g_width = 0;
static	size_t g_height = 0;


static Coord g_feed;
Map** g_map;

//지렁이를 위한 변수
static WormNode* g_wormHead = NULL;
static WormNode* g_wormTail = NULL;
static size_t g_wormSize = 0; //몸체의 갯수.

