#pragma once

#include "Unit.h"

enum FeedType
{
	Apple,
	Banana,
};

class Feed : public Unit
{
	FeedType type;
};

