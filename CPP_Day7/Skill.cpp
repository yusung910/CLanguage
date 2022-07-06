#include "Skill.h"

template <typename T>
Skill<T>::Skill() {
    //持失切
}

template <typename T>
Skill<T>::~Skill() {
    //社瑚切
}

template <typename T>
void Skill<T>::SetData(T d) {
    data = d;   
}

template class Skill<int>;
template class Skill<float>;
template class Skill<char>;
