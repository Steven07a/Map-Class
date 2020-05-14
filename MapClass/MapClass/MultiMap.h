#ifndef MultiMap_H_
#define MultiMap_H_

#include <string>
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\BT-BTree-class\BT BTree Class\BT BTree Class\BT-BTree.h"
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\vector\vector\vector\Vector.h"
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\BTree-Functions\BTree-Functions\BTree-Functions\bTreeFunctions.h"

using namespace std;

template <typename K, typename V>
struct MPair {
    K key;
    Vector<V> value_list;

    //--------------------------------------------------------------------------------
    /*      MPair CTORs:
     *  must have these CTORs:
     *  - default CTOR / CTOR with a key and no value: this will create an empty vector
     *  - CTOR with a key AND a value: pushes the value into the value_list
     *  _ CTOR with a key and a vector of values (to replace value_list)
     */
     //--------------------------------------------------------------------------------
    MPair(const K& k = K()) {
        key = k;
        value_list += V();
    }
    MPair(const K& k, const V& v) {
        key = k;
        value_list += v;
    }
    MPair(const K& k, const Vector<V>& vlist) {
        k = key;
        value_list = vlist;
    }
    //--------------------------------------------------------------------------------

    //You'll need to overlod << for your vector:
    friend ostream& operator <<(ostream& outs, const MPair<K, V>& print_me) {
        outs << print_me.key << " " << print_me.value_list;
        return outs;
    }

    friend bool operator ==(const MPair<K, V>& lhs, const MPair<K, V>& rhs) {
        if (lhs.key == rhs.key) {
            return true;
        } else {
            return false;
        }
    }
    friend bool operator < (const MPair<K, V>& lhs, const MPair<K, V>& rhs) {
        if (lhs.key < rhs.key) {
            return true;
        } else {
            return false;
        }
    }
    friend bool operator <= (const MPair<K, V>& lhs, const MPair<K, V>& rhs) {
        if (lhs.key <= rhs.key) {
            return true;
        } else {
            return false;
        }
    }
    friend bool operator > (const MPair<K, V>& lhs, const MPair<K, V>& rhs) {
        if (lhs.key > rhs.key) {
            return true;
        } else {
            return false;
        }
    }
    friend bool operator >= (const MPair<K, V>& lhs, const MPair<K, V>& rhs) {
        if (lhs.key >= rhs.key) {
            return true;
        } else {
            return false;
        }
    }
    friend MPair<K, V> operator + (const MPair<K, V>& lhs, const MPair<K, V>& rhs) {
        if (lhs == rhs) {
            lhs.value_list += rhs.value_list;
        }
    }
};


template <typename K, typename V>
class MMap
{
public:
    /*typedef BPlusTree<MPair<K, V> > map_base;
    class Iterator {
    public:
        friend class MMap;
        Iterator(typename map_base::Iterator it);
        Iterator operator ++(int unused);
        Iterator operator ++();
        MPair<K, V> operator *();
        friend bool operator ==(const Iterator& lhs, const Iterator& rhs);
        friend bool operator !=(const Iterator& lhs, const Iterator& rhs);

    private:
        typename map_base::Iterator _it;
    };*/

    MMap();

    //  Iterators
    /*Iterator begin();
    Iterator end();*/

    //  Capacity
    int size() const;
    bool empty() const;

    //  Element Access
    const Vector<V>& operator[](const K& key) const;
    Vector<V>& operator[](const K& key);

    //  Modifiers
    void insert(const K& k, const V& v);
    void erase(const K& key);
    void clear();

    //  Operations:
    bool contains(const K& key) const;
    bool has(const K& key);
    Vector<V>& get(const K& key);

    //Iterator find(const K& key);
    int count(const K& key);
    // I have not writtent hese yet, but we will need them:
    //    int count(const K& key);
    //    lower_bound
    //    upper_bound
    //    equal_range:



    bool is_valid();

    friend ostream& operator<<(ostream& outs, const MMap<K, V>& print_me) {
        outs << print_me.mmap << endl;
        return outs;
    }

private:
    BTree<MPair<K, V> > mmap;
};

template <typename K, typename V>
int MMap<K, V>::size() const {
    return mmap.size();
}

template <typename K, typename V>
bool MMap<K, V>::empty() const {
    return mmap.size();
}

template <typename K, typename V>
void MMap<K, V>::insert(const K& k, const V& v) {
    if (mmap.contains(k)) {
        mmap.get(k).value_list += v;
    } else {
        MPair<K, V> temp(k, v);
        mmap.insert(temp);
    }
}

template <typename K, typename V>
void MMap<K, V>::erase(const K& key) {
    mmap.remove(key);
}

template <typename K, typename V>
void MMap<K, V>::clear() {
    mmap.clear_tree();
}

template <typename K, typename V>
Vector<V>& MMap<K,V>::operator[](const K& key) {
    return mmap.get(key).value_list;
}

template <typename K, typename V>
const Vector<V>& MMap<K, V>::operator[](const K& key) const {
    return mmap.get(key).value_list;
}

template <typename K, typename V>
MMap<K, V>::MMap() {
    mmap;
}

template <typename K, typename V>
bool MMap<K, V>::contains(const K& key) const {
    return mmap.contains(key);
}

template <typename K, typename V>
bool MMap<K,V>::has(const K& key) {
    if (mmap.contains(key)) {
        return true;
    } else {
        return false;
    }
}

#endif // !MultiMap_H_