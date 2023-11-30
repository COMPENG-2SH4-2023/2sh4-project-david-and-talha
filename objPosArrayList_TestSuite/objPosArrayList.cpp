#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP];
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize()
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    // Error check, what if listSize is at capacity?
    // - check if listSize is equal to arrayCapacity. If yes, at capacity, don't insert
    if(listSize == arrayCapacity)
    {
        listSize--;
    }
    
    for(int i = listSize; i>0; i--)
    {
        aList[i].setObjPos(aList[i-1]); // shuffle all elements towards the tail
    }

    aList[0].setObjPos(thisPos);
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize == arrayCapacity)
    {
        listSize--;
    }

    aList[listSize].setObjPos(thisPos);
    listSize++;
}

void objPosArrayList::removeHead()
{
    for(int i = 0; i<listSize; i++)
    {
        aList[i].setObjPos(aList[i+1]); // shuffle all elements towards the head
    }
    listSize--;
}

void objPosArrayList::removeTail()
{
    listSize--;
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[listSize-1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    returnPos.setObjPos(aList[index]);
}