#pragma once

#include "CoreMinimal.h"
#include "SVONDefines.h"
#include "SVONLink.h"

struct UESVON_API SVONNode
{
	mortoncode_t myCode;

	SVONLink myParent;
	SVONLink myFirstChild;

	SVONLink myNeighbours[6];

	SVONNode()
		: myCode(0)
		, myParent(SVONLink::GetInvalidLink())
		, myFirstChild(SVONLink::GetInvalidLink())
	{
	}

	bool HasChildren() const { return myFirstChild.IsValid(); }
};

FORCEINLINE FArchive& operator<<(FArchive& Ar, SVONNode& aSVONNode)
{
	uint64 Temp = static_cast<uint64>(aSVONNode.myCode);
	Ar << Temp;
	Ar << aSVONNode.myParent;
	Ar << aSVONNode.myFirstChild;

	for (int i = 0; i < 6; i++)
	{
		Ar << aSVONNode.myNeighbours[i];
	}

	return Ar;
}
