#include "CSystem.h"    

CSystem::CSystem() {
    //�ý��� ������
    system("mode con: cols=151 lines=50");
    //ȭ�� ������ ����� 2���� �迭�� �ʱ�ȭ�Ѵ�.
    InitBasicDisplayArea();
}

CSystem::~CSystem() {
    //�ý��� �Ҹ���
}

void CSystem::InitBasicDisplayArea() {
    //��� ������ land�� �⺻ �ʱ�ȭ
    for (int i = 0; i < m_nDisplayX; i++) {
        for (int j = 0; j < m_nDisplayY; j++) {
            m_nBackground[j][i] = E_BG_TILE::LAND;
        }
    }

    //�׵θ� �׸���
    //�簢�� ����
    for (int a = 0; a < m_nDisplayX; a++) {
        m_nBackground[0][a] = E_BG_TILE::WALL_HORIZONTAL;
        m_nBackground[1][a] = E_BG_TILE::WALL;
    }

    //�簢�� ������ ��
    for (int b = 0; b < m_nDisplayY; b++) {
        m_nBackground[b][m_nDisplayX - 1] = E_BG_TILE::WALL_VERTICAL;
        m_nBackground[b][m_nDisplayX - 2] = E_BG_TILE::WALL;
    }

    //�簢�� �Ʒ���
    for (int c = m_nDisplayX - 1; c >= 0; c--) {
        m_nBackground[m_nDisplayY - 1][c] = E_BG_TILE::WALL_HORIZONTAL;
        if (c < (m_nDisplayX - 1)) {
            m_nBackground[m_nDisplayY - 2][c] = E_BG_TILE::WALL;
        }
        
    }

    //�簢�� ���ʸ�
    for (int d = m_nDisplayY - 1; d >= 0; d--) {
        int n_wall = (d < 2) ? 1 : d - 1;
        m_nBackground[d][0] = E_BG_TILE::WALL_VERTICAL;
        m_nBackground[n_wall][1] = E_BG_TILE::WALL;
    }

    //�׵θ��� �����̵��� ����
    //���� ��
    m_nBackground[0][0] = E_BG_TILE::WALL_LEFT_TOP;
    //������ ��
    m_nBackground[0][m_nDisplayX - 1] = E_BG_TILE::WALL_RIGHT_TOP;
    //���� �Ʒ�
    m_nBackground[m_nDisplayY - 1][0] = E_BG_TILE::WALL_LEFT_BOTTOM;
    //������ �Ʒ�
    m_nBackground[m_nDisplayY - 1][m_nDisplayX - 1] = E_BG_TILE::WALL_RIGHT_BOTTOM;


    //��� ���
    for (int i = 0; i < m_nDisplayX; i++) {
        for (int j = 0; j < m_nDisplayY; j++) {
            switch (m_nBackground[j][i]) {
            //case E_BG_TILE::LAND :
            //    PrintString(i, j, "0");
            //    break;
            //case E_BG_TILE::WALL:
            //    PrintString(i, j, "1");
            //    break;
            case E_BG_TILE::WALL_VERTICAL:
                PrintString(i, j, "��");
                //PrintString(i, j, "2");
                break;
            case E_BG_TILE::WALL_HORIZONTAL:
                PrintString(i, j, "��");
                //PrintString(i, j, "3");
                break;
            case E_BG_TILE::WALL_LEFT_TOP:
                PrintString(i, j, "��");
                //PrintString(i, j, "4");
                break;
            case E_BG_TILE::WALL_RIGHT_TOP:
                PrintString(i, j, "��");
                //PrintString(i, j, "5");
                break;
            case E_BG_TILE::WALL_LEFT_BOTTOM:
                PrintString(i, j, "��");
                //PrintString(i, j, "6");
                break;
            case E_BG_TILE::WALL_RIGHT_BOTTOM:
                PrintString(i, j, "��");
                //PrintString(i, j, "7");
                break;
            }
        }
    }
    SetPos(10, 10);
    Locate();
    _getch();
}