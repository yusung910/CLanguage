#include "SetupD3D.h"

//생성자
SetupD3D::SetupD3D() {
    
}

//소멸자
SetupD3D::~SetupD3D() {
}


/*
 *------------------------------------------------------------------------------
 * Direct3D 초기화 : 자세히 살펴봐야 할 가장 중요한 함수.
 *------------------------------------------------------------------------------
 */
HRESULT SetupD3D::InitD3D(HWND hWnd)
{
    // 디바이스를 생성하기위한 D3D객체 생성
    if (NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
        return E_FAIL;
    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory(&d3dpp, sizeof(d3dpp));
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    d3dpp.EnableAutoDepthStencil = TRUE;
    d3dpp.AutoDepthStencilFormat = D3DFMT_D16;


    /* 디바이스를 다음과 같은 설정으로 생성한다.
         1. 디폴트 비디오카드를 사용(대부분은 비디오카드가 1개 이다.)
         2. HAL디바이스를 생성한다.(HW가속장치를 사용하겠다는 의미)
         3. 정점처리는 모든 카드에서 지원하는 SW처리로 생성한다.(HW로 생성할경우 더욱 높은 성능을 낸다.) */

         // 실제 디바이스를 생성하는 함수. (중요하다.)
    if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
        D3DDEVTYPE_HAL,
        hWnd,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING,
        &d3dpp,
        &g_pd3dDevice)))
    {
        return E_FAIL;
    }


    // 디바이스 상태정보를 처리할경우 여기에서 한다.
    g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

    return S_OK;
}

/*
*-------------------------------------------------------------------------------
* Vertex초기화
*-------------------------------------------------------------------------------
*/
HRESULT SetupD3D::InitVB() {
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

        { -10.0F, 0.0F, 10.0F, 0.0F, 0.0F },				 // 8
        { 10.0F, 0.0F, 10.0F, 0.0F, 0.0F },					 // 9
        { -10.0F, 0.0F, -10.0F, 0.0F, 0.0F },				 // 10
        { 10.0F, 0.0F, -10.0F, 0.0F, 0.0F },				 // 11
    };

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

//Index Buffer 초기화
HRESULT SetupD3D::InitIB() {

    MYINDEX iNumberOfIndex[] = {
        { 0, 1, 2 },{ 2, 1, 3 },
        { 1, 5, 3 },{ 3, 5, 7 },
        { 5, 4, 7 },{ 7, 4, 6 },
        { 4, 0, 6 },{ 6, 0, 2 },
        { 4, 5, 0 },{ 0, 5, 1 },
        { 2, 3, 6 },{ 6, 3, 7 },

        { 8, 9, 10 },{ 8, 10, 11 },
    };
    g_pd3dDevice->CreateIndexBuffer(
        sizeof(iNumberOfIndex),
        0,
        D3DFMT_INDEX16,
        D3DPOOL_DEFAULT,
        &g_pIB,
        NULL);

    VOID *pIndices;

    if (g_pIB->Lock(0, sizeof(iNumberOfIndex), (void**)&pIndices, 0))
    {
        return E_FAIL;
    }

    //BUFFER(pVertices)에 값들을 저장한다.
    memcpy(pIndices, iNumberOfIndex, sizeof(iNumberOfIndex));

    g_pIB->Unlock();
}


//Texture 초기화
HRESULT SetupD3D::InitTexture() {
    if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "plane.bmp", &g_ppTexture))) {
        return E_FAIL;
    }
}

/*------------------------------------------------------------------------------
 * 초기화된 객체들을 소거한다.
 *------------------------------------------------------------------------------
 */
VOID SetupD3D::CleanUp()
{
    // 해제 순서. 해제시 반드시 생성 순서의 역순으로 해제 해줄 것. 
    if (g_ppTexture != NULL)
        g_ppTexture->Release();
    if (g_pIB != NULL)
        g_pIB->Release();
    if (g_pVB != NULL)
        g_pVB->Release();
    if (g_pd3dDevice != NULL)
        g_pd3dDevice->Release();
    if (g_pD3D != NULL)
        g_pD3D->Release();
}