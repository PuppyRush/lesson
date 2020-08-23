#pragma once

#include "type.h"
#include "define.h"
#include "framework.h"

static const size_t INVALID_SIZE = UINT_MAX;

//���� ������ �ڵ鷯
static HWND g_hwndWnd = NULL;
static HWND g_hwndProc = NULL;


//extern�� static�� ����?
//https://dojang.io/mod/page/view.php?id=690
static	size_t g_width = 0;
static	size_t g_height = 0;


static Coord g_feed;
Map** g_map;

//�����̸� ���� ����
static WormNode* g_wormHead = NULL;
static WormNode* g_wormTail = NULL;
static size_t g_wormSize = 0; //��ü�� ����.

