#include "CreateVB.h"

CreateVB::CreateVB() {
    //생성자
    //VERTEX
    CUSTOMVERTEX vertices[] =
    {
        { -0.5F,  0.5F, -0.5F, 0.0F, 0.0F },                  // 0
        {  0.5F,  0.5F, -0.5F, 1.0F, 0.0F },                  // 1
        { -0.5F, -0.5F, -0.5F, 0.0F, 1.0F },                  // 2
        {  0.5F, -0.5F, -0.5F, 1.0F, 1.0F },                  // 3

        { -0.5F,  0.5F, 0.5F, 1.0F, 0.0F },                  // 4
        {  0.5F,  0.5F, 0.5F, 0.0F, 0.0F },                  // 5
        { -0.5F, -0.5F, 0.5F, 1.0F, 1.0F },                  // 6
        {  0.5F, -0.5F, 0.5F, 0.0F, 1.0F },                  // 7
    };
}

CreateVB::~CreateVB() {
    //소멸자

}

VOID CreateVB::SetVertices(CUSTOMVERTEX* vl) {

}

HRESULT CreateVB::GenerateVB(LPDIRECT3DVERTEXBUFFER9 g_pVB) {


    //VERTEX BUFFER 생성
    if (g_pd3dDevice->CreateVertexBuffer(
        sizeof(vertices),
        0,
        D3DFVF_CUSTOMVERTEX,
        D3DPOOL_DEFAULT,
        &g_pVB,
        NULL))
    {
        return E_FAIL;
    };

    VOID* pVertices;
    //생성된 VERTEX BUFFER를 LOCK()하여 내용을 넣는다.
    if (FAILED(g_pVB->Lock(0, sizeof(vertices), (void**)&pVertices, 0)))
    {
        return E_FAIL;
    }

    //BUFFER(pVertices)에 값들을 저장한다.
    memcpy(pVertices, vertices, sizeof(vertices));

    //메모리 잠금 해제
    g_pVB->Unlock();
}