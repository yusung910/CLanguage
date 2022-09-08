#include "SetupD3D.h"

//������
SetupD3D::SetupD3D() {
    
}

//�Ҹ���
SetupD3D::~SetupD3D() {
}


/*
 *------------------------------------------------------------------------------
 * Direct3D �ʱ�ȭ : �ڼ��� ������� �� ���� �߿��� �Լ�.
 *------------------------------------------------------------------------------
 */
HRESULT SetupD3D::InitD3D(HWND hWnd)
{
    // ����̽��� �����ϱ����� D3D��ü ����
    if (NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
        return E_FAIL;
    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory(&d3dpp, sizeof(d3dpp));
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    d3dpp.EnableAutoDepthStencil = TRUE;
    d3dpp.AutoDepthStencilFormat = D3DFMT_D16;


    /* ����̽��� ������ ���� �������� �����Ѵ�.
         1. ����Ʈ ����ī�带 ���(��κ��� ����ī�尡 1�� �̴�.)
         2. HAL����̽��� �����Ѵ�.(HW������ġ�� ����ϰڴٴ� �ǹ�)
         3. ����ó���� ��� ī�忡�� �����ϴ� SWó���� �����Ѵ�.(HW�� �����Ұ�� ���� ���� ������ ����.) */

         // ���� ����̽��� �����ϴ� �Լ�. (�߿��ϴ�.)
    if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
        D3DDEVTYPE_HAL,
        hWnd,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING,
        &d3dpp,
        &g_pd3dDevice)))
    {
        return E_FAIL;
    }


    // ����̽� ���������� ó���Ұ�� ���⿡�� �Ѵ�.
    g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

    return S_OK;
}

/*
*-------------------------------------------------------------------------------
* Vertex�ʱ�ȭ
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

    //VERTEX BUFFER ����
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
    //������ VERTEX BUFFER�� LOCK()�Ͽ� ������ �ִ´�.
    if (FAILED(g_pVB->Lock(0, sizeof(vertices), (void**)&pVertices, 0)))
    {
        return E_FAIL;
    }

    //BUFFER(pVertices)�� ������ �����Ѵ�.
    memcpy(pVertices, vertices, sizeof(vertices));

    //�޸� ��� ����
    g_pVB->Unlock();
}

//Index Buffer �ʱ�ȭ
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

    //BUFFER(pVertices)�� ������ �����Ѵ�.
    memcpy(pIndices, iNumberOfIndex, sizeof(iNumberOfIndex));

    g_pIB->Unlock();
}


//Texture �ʱ�ȭ
HRESULT SetupD3D::InitTexture() {
    if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "plane.bmp", &g_ppTexture))) {
        return E_FAIL;
    }
}

/*------------------------------------------------------------------------------
 * �ʱ�ȭ�� ��ü���� �Ұ��Ѵ�.
 *------------------------------------------------------------------------------
 */
VOID SetupD3D::CleanUp()
{
    // ���� ����. ������ �ݵ�� ���� ������ �������� ���� ���� ��. 
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