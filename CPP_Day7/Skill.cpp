#include "Skill.h"

template <typename T>
Skill<T>::Skill() {
    //������
}

template <typename T>
Skill<T>::~Skill() {
    //�Ҹ���
}

template <typename T>
void Skill<T>::SetData(T d) {
    data = d;   
}

template class Skill<int>;
template class Skill<float>;
template class Skill<char>;
