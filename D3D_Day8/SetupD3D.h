#pragma once
#include "Init.h"

class SetupD3D : Init {
public:
    SetupD3D();
    ~SetupD3D();

    //D3D �ʱ�ȭ
    HRESULT InitD3D(HWND hWnd);
    //index buffer �ʱ�ȭ
    HRESULT InitIB();
    //texture �ʱ�ȭ
    HRESULT InitTexture();

    //���� ������ ����
    VOID MainRender();

    //���� ��ü �̵�
    VOID KeyControl();

    //�ʱ�ȭ
    VOID CleanUp();
protected:
    FLOAT g_fXmove = 0.0f, g_fZmove = 0.0f;				//�̵��� ���� ����
    FLOAT g_fRX = 0.0f, g_fRY = 0.0f, g_fRZ = 0.0f;	//ȸ���� ���� ����
    FLOAT g_fX = 0.0f, g_fY = 0.0f, g_fZ = 0.0f;	//��ǥ�� ���� ����
private:

};