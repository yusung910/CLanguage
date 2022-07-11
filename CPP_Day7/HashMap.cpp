#include "HashMap.h"

template <typename T1, typename T2, typename T3>
HashMap<T1, T2, T3>::HashMap() {
    //持失切
    m_nSize = 0;
}

template <typename T1, typename T2, typename T3>
HashMap<T1, T2, T3>::~HashMap() {
    //社瑚切
    delete[] m_Key;
    m_Key = NULL;
    delete[] m_Value;
    m_Value = NULL;
}

template <typename T1, typename T2, typename T3>
void HashMap<T1, T2, T3>::Put(T1 k, T2 v, T3 sv) {
    int tmpK = k;
    if (k > m_nSize) {
        SetArryAdd();
        tmpK = k - 1;
    }
    m_Key[tmpK] = tmpK;
    m_Value[tmpK] = v;
    m_SubValue[tmpK] = sv;

}

template <typename T1, typename T2, typename T3>
void HashMap<T1, T2, T3>::Put(T1 k, T3 sv) {
    int tmpK = k;
    if (k > m_nSize) {
        SetArryAdd();
        tmpK = k - 1;
    }
    m_Key[tmpK] = tmpK;
    m_SubValue[tmpK] = sv;
}

template <typename T1, typename T2, typename T3>
void HashMap<T1, T2, T3>::Put(T1 k, T2 v) {
    int tmpK = k;
    if (k > m_nSize) {
        SetArryAdd();
        tmpK = k - 1;
    }
    m_Key[tmpK] = tmpK;
    m_Value[tmpK] = v;
}

template <typename T1, typename T2, typename T3>
void HashMap<T1, T2, T3>::SetArryAdd() {

    T1* tmpKey = new T1[(sizeof(T1) * m_nSize) + sizeof(T1)];
    T2* tmpValue = new T2[(sizeof(T2) * m_nSize) + sizeof(T2)];
    T3* tmpSubValue = new T3[(sizeof(T3) * m_nSize) + sizeof(T3)];

    ::memcpy(tmpKey, m_Key, (sizeof(T1) * m_nSize) + sizeof(T1));
    ::memcpy(tmpValue, m_Value, (sizeof(T2) * m_nSize) + sizeof(T2));
    ::memcpy(tmpSubValue, m_SubValue, (sizeof(T3) * m_nSize) + sizeof(T3));

    m_nSize++;

    m_Key = new T1[(sizeof(T1) * m_nSize) + sizeof(T1)];
    m_Value = new T2[(sizeof(T2) * m_nSize) + sizeof(T2)];
    m_SubValue = new T3[(sizeof(T3) * m_nSize) + sizeof(T3)];


    for (int i = 0; i < (m_nSize - 1); i++) {
        m_Key[i] = tmpKey[i];
        m_Value[i] = tmpValue[i];
        m_SubValue[i] = tmpSubValue[i];
    }

    m_Key[m_nSize] = '\0';
    m_Value[m_nSize] = "\0";
    m_SubValue[m_nSize] = '\0';

    delete[] tmpKey;
    delete[] tmpValue;
    delete[] tmpSubValue;
}


template <typename T1, typename T2, typename T3>
void HashMap<T1, T2, T3>::Put(T2* v, T3* sv, int n_size) {
    
    if (m_Key != NULL) {
        delete[] m_Key;
    }

    if (m_Value != NULL) {
        delete[] m_Value;
    }

    if (m_SubValue != NULL) {
        delete[] m_SubValue;
    }


    m_Key = new T1[(n_size * sizeof(T1)) + sizeof(T1)];
    m_Value = new T2[(n_size * sizeof(T2)) + sizeof(T2)];
    m_SubValue = new T3[(n_size * sizeof(T3)) + sizeof(T3)];

    for (int i = 0; i < n_size; i++) {
        m_Key[i] = i;
        m_Value[i] = v[i];
        m_SubValue[i] = sv[i];
    }

    m_nSize = n_size;
}

template <typename T1, typename T2, typename T3>
T2 HashMap<T1, T2, T3>::GetValue(T1 k) {
    int tmp = k - 1;
    return m_Value[tmp];
}

template <typename T1, typename T2, typename T3>
T1 HashMap<T1, T2, T3>::GetKey(T2 v) {
    T1 ret_Key = NULL;
    for (int i = 0; i < m_nSize; i++) {
        if (v == m_Value[i]) {
            ret_Key = m_Key[i];
        }
    }
    return ret_Key;
}

template <typename T1, typename T2, typename T3>
bool HashMap<T1, T2, T3>::Is_valid(T1 k) {
    bool tmpRetBool = false;
    if (m_nSize > 0) {
        for (int i = 0; i < m_nSize; i++) {
            if (m_Key[i] == k) {
                tmpRetBool = true;
            }
        }
    }
    return tmpRetBool;
}

template <typename T1, typename T2, typename T3>
int HashMap<T1, T2, T3>::GetSize() {
    return m_nSize;
}

template class HashMap<int, String, float>;
template class HashMap<int, String, int>;
template class HashMap<int, String, double>;
