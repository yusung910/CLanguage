#include "CSystem.h"    

CSystem::CSystem() {
    //시스템 생성자
    system("mode con: cols=151 lines=50");
    //화면 영역이 저장된 2차원 배열을 초기화한다.
    InitBasicDisplayArea();
}

CSystem::~CSystem() {
    //시스템 소멸자
}

void CSystem::InitBasicDisplayArea() {
    //배경 영역을 land로 기본 초기화
    for (int i = 0; i < m_nDisplayX; i++) {
        for (int j = 0; j < m_nDisplayY; j++) {
            m_nBackground[j][i] = E_BG_TILE::LAND;
        }
    }

    //테두리 그리기
    //사각형 윗면
    for (int a = 0; a < m_nDisplayX; a++) {
        m_nBackground[0][a] = E_BG_TILE::WALL_HORIZONTAL;
        m_nBackground[1][a] = E_BG_TILE::WALL;
    }

    //사각형 오른쪽 면
    for (int b = 0; b < m_nDisplayY; b++) {
        m_nBackground[b][m_nDisplayX - 1] = E_BG_TILE::WALL_VERTICAL;
        m_nBackground[b][m_nDisplayX - 2] = E_BG_TILE::WALL;
    }

    //사각형 아랫면
    for (int c = m_nDisplayX - 1; c >= 0; c--) {
        m_nBackground[m_nDisplayY - 1][c] = E_BG_TILE::WALL_HORIZONTAL;
        if (c < (m_nDisplayX - 1)) {
            m_nBackground[m_nDisplayY - 2][c] = E_BG_TILE::WALL;
        }
        
    }

    //사각형 왼쪽면
    for (int d = m_nDisplayY - 1; d >= 0; d--) {
        int n_wall = (d < 2) ? 1 : d - 1;
        m_nBackground[d][0] = E_BG_TILE::WALL_VERTICAL;
        m_nBackground[n_wall][1] = E_BG_TILE::WALL;
    }

    //테두리의 귀퉁이들을 설정
    //왼쪽 위
    m_nBackground[0][0] = E_BG_TILE::WALL_LEFT_TOP;
    //오른쪽 위
    m_nBackground[0][m_nDisplayX - 1] = E_BG_TILE::WALL_RIGHT_TOP;
    //왼쪽 아래
    m_nBackground[m_nDisplayY - 1][0] = E_BG_TILE::WALL_LEFT_BOTTOM;
    //오른쪽 아래
    m_nBackground[m_nDisplayY - 1][m_nDisplayX - 1] = E_BG_TILE::WALL_RIGHT_BOTTOM;


    //배경 출력
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
                PrintString(i, j, "│");
                //PrintString(i, j, "2");
                break;
            case E_BG_TILE::WALL_HORIZONTAL:
                PrintString(i, j, "─");
                //PrintString(i, j, "3");
                break;
            case E_BG_TILE::WALL_LEFT_TOP:
                PrintString(i, j, "┌");
                //PrintString(i, j, "4");
                break;
            case E_BG_TILE::WALL_RIGHT_TOP:
                PrintString(i, j, "┐");
                //PrintString(i, j, "5");
                break;
            case E_BG_TILE::WALL_LEFT_BOTTOM:
                PrintString(i, j, "└");
                //PrintString(i, j, "6");
                break;
            case E_BG_TILE::WALL_RIGHT_BOTTOM:
                PrintString(i, j, "┘");
                //PrintString(i, j, "7");
                break;
            }
        }
    }
    SetPos(10, 10);
    Locate();
    _getch();
}