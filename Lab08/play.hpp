#include "play.h"
#include "Node.h"



template <typename T>
play<T>::play()
{
    m_root = nullptr;
}


template <typename T>
play<T>::play(const play<T> &other)
{
    if (other.m_root == nullptr)
    {
        m_root = nullptr;
    }
    else
    {
        m_root = new Node<T>(other.m_root);
    }
}



template <typename T>
bool play<T>::isEmpty() const
{
    if (m_root == nullptr)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}



template <typename T>
bool play<T>::add(T value)
{
    bool a = false;

    if (isEmpty())
    {
        m_root = new Node<T>();
        m_root->setValue(value);
        return(true);
    }
    else if (value == m_root->getValue())
    {
        return (false);
    }
    else
    {
        Node<T>* temp = m_root;

        if (value < m_root->getValue())
        {
            temp = temp->getLeft();

            if(temp == nullptr)
            {
                temp = new Node<T>();
                temp -> setValue(value);
                return(true);
            }
            else
            {
                a = add(value, temp);
                return(a);
            }
        }
        if (value > m_root->getValue())
        {
            temp = temp->getRight();

            if (temp == nullptr)
            {
                temp = new Node<T>();
                temp->setValue(value);
                return(true);
            }
            else
            {
                a = add(value, temp);
                return(a);
            }
        }
    }
    return (a);
}



template <typename T>
bool play<T>::add(T value, Node<T> *subtree)
{
    bool a;

    if (subtree -> getValue() == value)
    {
        return (false);
    }
    else if (subtree->getValue() > value)
    {
        subtree = subtree -> getLeft();

        if (subtree == nullptr)
        {
            subtree = new Node<T>();
            subtree->setValue(value);
            return(true);
        }
        else
        {
            a = add(value, subtree);
        }
    }
    else if (subtree->getValue() < value)
    {
        subtree = subtree -> getRight();

        if (subtree == nullptr)
        {
            subtree = new Node<T>();
            subtree -> setValue(value);
            return(true);
        }
        else
        {
            a = add(value, subtree);
        }
    }

    return(a);
}


template <typename T>
bool play<T>::search(T value) const
{
    return (search(value, m_root));
}


template <typename T>
bool play<T>::search(T value, Node<T> *subtree) const
{
    if (subtree == nullptr)
    {
        return(false);
    }
    else if (value == subtree -> getValue())
    {
        return(true);
    }
    else if (value < subtree -> getValue() && subtree->getLeft() != nullptr)
    {
        search(value, subtree -> getLeft());
    }
    else if (value > subtree -> getValue() && subtree->getRight() != nullptr)
    {
        search(value, subtree -> getRight());
    }
    else
    {
        return (false);
    }
}




/*
if (subtree != nullptr)
{
    if (order == PRE_ORDER)
    {
        vec.push_back(subtree -> getValue());
        treeToVector(subtree -> getLeft(), order, vec);
        treeToVector(subtree -> getRight(), order, vec);
    }
    else if (order == IN_ORDER)
    {
        treeToVector(subtree -> getLeft(), order, vec);
        vec.push_back(subtree -> getValue());
        treeToVector(subtree -> getRight(), order, vec);
    }
    else if (order == POST_ORDER)
    {
        treeToVector(subtree -> getLeft(), order, vec);
        treeToVector(subtree -> getRight(), order, vec);
        vec.push_back(subtree -> getValue());
    }
}



    std::vector<T> vec;
    treeToVector(m_root, order, vec);
    return (vec);





