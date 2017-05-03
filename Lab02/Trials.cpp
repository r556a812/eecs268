 
LinkedList::~LinkedList()
{
    while(!isEmpty())
    {
        removeFront();
    }
}


bool LinkedList::isEmpty() const
{
    if (m_size==0)
    {
        return (true);
    }
    else
    {
        return (false);
    }
}

int LinkedList::size() const
{
    return (m_size);
}

bool LinkedList::search(int value) const
{
    Node* search = m_front;

    if (isEmpty())
    {
        return (false);
    }
    else
    {
        if (search->getValue() == value)
        {
            return (true);


            while(search->getNext() != nullptr)
            {
               search = search->getNext();
               if (search->getValue() == value)
               {
                   return (true);
                   break;
               }
            }

        }

        search = nullptr;
        return (false);

    }
}

void LinkedList::addFront(int value)
{
    Node* temp = nullptr;
    Node* last = nullptr;

    if (isEmpty())
    {
        m_front = new Node();
        m_front->setValue(value);
        m_size++;
    }
    else
    {
        last = m_front;
        while (last->getNext() != nullptr)
        {
            last->getNext();
        }
        temp = new Node();
        temp->setValue(value);
        last->setNext(temp);
        m_size++;
    }
}

bool LinkedList::removeFront()
{
    if (isEmpty())
    {
        return(false);
    }
    else
    {
        Node* temp = m_front;
        m_front = m_front->getNext();
        delete temp;
        temp = nullptr;
        m_size--;
        return(true);
    }
}
