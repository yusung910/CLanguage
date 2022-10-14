#pragma once
#include "d3d9.h"
#include "d3dx9.h"
#include <d3dx9math.h>
#include "Init.h"

/*
*-------------------------------------------------------------------------------
* Vertex초기화
*-------------------------------------------------------------------------------
*/

class CreateVB : Init{
public:
    //생성자
    CreateVB();
    //소멸자
    ~CreateVB();
    //
    VOID SetVertices(CUSTOMVERTEX* vl);
    //vertext buffer 생성
    HRESULT GenerateVB(LPDIRECT3DVERTEXBUFFER9 g_pVB);
protected:
    //vertext list
    CUSTOMVERTEX* vertices;
private:

};