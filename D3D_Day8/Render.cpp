#include "Render.h"

Render::Render() {

}
Render::~Render() {

}
/*
 *------------------------------------------------------------------------------
 * ȭ���� �׸���.
 * Render() �Լ� �˰���
 * 1. ���� ȭ���� ������ �����. ( Clear() )
 * 2. �������� �׸��ڴٰ� D3D���� �˸�.( BeginScene() )
 * 3. �������� �� �׷ȴٰ� D3D���� �˸�.( EndScene() )
 * 4. ȭ�鿡 ��Ÿ���� �Ѵ�. ( Present() )
 *------------------------------------------------------------------------------
 */
VOID Render::MainRender() {
    g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(123, 123, 123), 1.0f, 0);
    if (SUCCEEDED(g_pd3dDevice->BeginScene()))
    {
        D3DXMATRIX tempTM, tempTM2;

        D3DXMatrixIdentity(&tempTM);
        g_pd3dDevice->SetTransform(D3DTS_VIEW, &tempTM);

        D3DXMATRIX tempProjection;
        D3DXMatrixPerspectiveFovLH(&tempProjection, 1.3f, 1 / 1, 2.f, 10000.0f);
        g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &tempProjection);


        {
            D3DXMatrixTranslation(&tempTM, g_fXmove, 0.0f, g_fZmove);		// 1. ��Ʈ���� �̵�

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
        }

        g_pd3dDevice->SetStreamSource(0, g_pVB, 0, sizeof(CUSTOMVERTEX));
        g_pd3dDevice->SetTexture(0, g_ppTexture);
        g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

        g_pd3dDevice->SetTransform(D3DTS_WORLD, &tempTM);
        g_pd3dDevice->SetIndices(g_pIB);
        g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 12, 0, 14);

        g_pd3dDevice->EndScene();
    }

    g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

VOID Render::KeyControl() {
    if (::GetKeyState(VK_LEFT) & 0x80) g_fXmove -= 0.1f;	//����Ű ���� : -X�� �̵�
    if (::GetKeyState(VK_RIGHT) & 0x80) g_fXmove += 0.1f;	//����Ű ������ : +X�� �̵�
    if (::GetKeyState(VK_UP) & 0x80) g_fZmove += 0.1f;		//����Ű ���� : +Z�� �̵�
    if (::GetKeyState(VK_DOWN) & 0x80) g_fZmove -= 0.1f;	//����Ű �Ʒ��� : -Z�� �̵�

    if (::GetKeyState('W') & 0x80) g_fRY -= 0.1f;	//���� �е� 1 : Y���� �������� -ȸ��
    if (::GetKeyState('S') & 0x80) g_fRY += 0.1f;	//���� �е� 3 : Y���� �������� +ȸ��
    if (::GetKeyState('Q') & 0x80)
        g_fRX -= 0.1f;	//���� �е� 5 : X���� �������� -ȸ��
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