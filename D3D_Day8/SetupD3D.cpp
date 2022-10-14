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
//Index Buffer �ʱ�ȭ
HRESULT SetupD3D::InitIB() {

    MYINDEX iNumberOfIndex[] = {
        { 0, 1, 2 },{ 2, 1, 3 },
        { 1, 5, 3 },{ 3, 5, 7 },
        { 5, 4, 7 },{ 7, 4, 6 },
        { 4, 0, 6 },{ 6, 0, 2 },
        { 4, 5, 0 },{ 0, 5, 1 },
        { 2, 3, 6 },{ 6, 3, 7 },
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

/*
 *------------------------------------------------------------------------------
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
    if (g_pd3dDevice != NULL)
        g_pd3dDevice->Release();
    if (g_pVB != NULL)
        g_pVB->Release();
    if (g_pD3D != NULL)
        g_pD3D->Release();


}

VOID SetupD3D::MainRender()
{
    g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(123, 123, 123), 1.0f, 0);
    if (SUCCEEDED(g_pd3dDevice->BeginScene()))
    {

        D3DXMATRIX tempTM, tempTM2, floorTM;

        D3DXMatrixIdentity(&tempTM);

        D3DXMATRIX tempViewTM;
        D3DXVECTOR3 v3Eye(10.0f, 10.0f, 10.0f);
        D3DXVECTOR3 v3LookAt(g_fRY, g_fRX, g_fRZ);
        D3DXVECTOR3 v3Up(0.0f, 1.0f, 0.0f);
        D3DXMatrixLookAtLH(&tempViewTM, &v3Eye, &v3LookAt, &v3Up);
        g_pd3dDevice->SetTransform(D3DTS_VIEW, &tempViewTM);


        D3DXMATRIX tempProjection;
        D3DXMatrixPerspectiveFovLH(&tempProjection, 1.3f, 1 / 1, 2.f, 10000.0f);
        g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &tempProjection);

        g_pd3dDevice->SetStreamSource(0, g_pVB, 0, sizeof(CUSTOMVERTEX));
        g_pd3dDevice->SetTexture(0, g_ppTexture);
        g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
        {
            //���� ��ü ����
            D3DXMatrixTranslation(&tempTM, g_fXmove, g_fZmove, 0.0f);		// 1. ��Ʈ���� �̵�

            D3DXMatrixRotationYawPitchRoll(&tempTM2, g_fRY, g_fRX, g_fRZ);	// 2. ��Ʈ���� ȸ��
            D3DXMatrixMultiply(&tempTM, &tempTM, &tempTM2);					// 3. �̵� �� ȸ�� ������ ����				

            g_fX += tempTM._41;
            g_fY += tempTM._42;
            g_fZ += tempTM._43;
            g_fXmove = 0;
            g_fZmove = 0;													// 4. �̵����� ��ǥ�� ���� ��ǥ ���� ������ �̵��� �ʱ�ȭ

            D3DXMatrixRotationYawPitchRoll(&tempTM, g_fRY, g_fRX, g_fRZ);	// 5. �ٽ� ��Ʈ���� ȸ��
            D3DXMatrixTranslation(&tempTM2, g_fX, g_fY, g_fZ);				// 6. ���� ��ǥ ������ ������ �̵�
            D3DXMatrixMultiply(&tempTM, &tempTM, &tempTM2);					// 7. ȸ�� �� �̵� ������ ����

            D3DXMatrixTranslation(&tempTM2, 0, 0, 5.5f);					// 8. ī�޶��� ���� ��ġ�� �̵�
            D3DXMatrixMultiply(&tempTM, &tempTM, &tempTM2);					// 9. �̵��� ����

            g_pd3dDevice->SetTransform(D3DTS_WORLD, &tempTM);
            g_pd3dDevice->SetIndices(g_pIB);
            g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 14);


            g_pd3dDevice->SetTexture(0, NULL);
            D3DXMatrixTranslation(&floorTM, -1.0f, 1.0f, 10.0f);
            D3DXMatrixScaling(&floorTM, 10.0f, -.1f, 10.1f);
            g_pd3dDevice->SetTransform(D3DTS_WORLD, &floorTM);
            g_pd3dDevice->SetIndices(g_pIB);
            g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 14);

            //�ٴ� �׸���
            


        }


        g_pd3dDevice->EndScene();
    }

    g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

VOID SetupD3D::KeyControl() {
    if (::GetKeyState(VK_LEFT) & 0x80) g_fXmove -= 0.1f;	//����Ű ���� : -X�� �̵�
    if (::GetKeyState(VK_RIGHT) & 0x80) g_fXmove += 0.1f;	//����Ű ������ : +X�� �̵�
    if (::GetKeyState(VK_UP) & 0x80) g_fZmove += 0.1f;		//����Ű ���� : +Z�� �̵�
    if (::GetKeyState(VK_DOWN) & 0x80) g_fZmove -= 0.1f;	//����Ű �Ʒ��� : -Z�� �̵�

    if (::GetKeyState('W') & 0x80) g_fRY -= 0.1f;	//���� �е� 1 : Y���� �������� -ȸ��
    if (::GetKeyState('S') & 0x80) g_fRY += 0.1f;	//���� �е� 3 : Y���� �������� +ȸ��
    if (::GetKeyState('Q') & 0x80) g_fRX -= 0.1f;	//���� �е� 5 : X���� �������� -ȸ��
    if (::GetKeyState('A') & 0x80) g_fRX += 0.1f;	//���� �е� 2 : X���� �������� +ȸ��
    if (::GetKeyState('E') & 0x80) g_fRZ += 0.1f;	//���� �е� 4 : Z���� �������� +ȸ��
    if (::GetKeyState('D') & 0x80) g_fRZ -= 0.1f;	//���� �е� 6 : Z���� �������� -ȸ��

    if (::GetKeyState(VK_SPACE) & 0x80)						//�����̵� �Է½� ��ġ �ʱ�ȭ
    {
        g_fXmove = 0.0f;
        g_fZmove = 0.0f;

        g_fRX = 0.0f;
        g_fRY = 0.0f;
        g_fRZ = 0.0f;

        g_fX = 0.0f;
        g_fY = 0.0f;
        g_fZ = 0.0f;
    }
}