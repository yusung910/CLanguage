#pragma once
#include "d3d9.h"
#include "d3dx9.h"
#include <d3dx9math.h>
#include "Init.h"

/*
*-------------------------------------------------------------------------------
* Vertex�ʱ�ȭ
*-------------------------------------------------------------------------------
*/

class CreateVB : Init{
public:
    //������
    CreateVB();
    //�Ҹ���
    ~CreateVB();
    //
    VOID SetVertices(CUSTOMVERTEX* vl);
    //vertext buffer ����
    HRESULT GenerateVB(LPDIRECT3DVERTEXBUFFER9 g_pVB);
protected:
    //vertext list
    CUSTOMVERTEX* vertices;
private:

};