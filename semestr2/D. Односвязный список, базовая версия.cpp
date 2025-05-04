template <typename T>
class ForwardList {
public:
    struct Node
    {
        T value;
        Node* next = nullptr;
    };

    ~ForwardList()
    {
        while (head)
        {
            PopFront();
        }
    }

    void PushFront(const T& value)
    {
        Node* node = new Node();
        node->value = value;
        node->next = head;
        head = node;
    }
    
    void InsertAfter(Node* node, const T& value)
    {
        if (!node)
        {
            PushFront(value);
        }
        else
        {
            Node* find = head;
            while (find != node)
            {
                find = find->next;
            }
            
            if (find != node)
            {
                return;
            }
            
            Node* newNode = new Node();
            newNode->value = value;
            newNode->next = find->next;
            find->next = newNode;
        }
    }
    
    void RemoveAfter(Node* node)
    {
        if (!node)
        {
            PopFront();
        }
        else
        {
            Node* find = head;
            while (find != node)
            {
                find = find->next;
            }
            
            if (find != node || !find->next)
            {
                return;
            }
            
            Node* temp = find->next;
            find->next = temp->next;
            delete temp;
            temp = nullptr;
        }
    }
    
    void PopFront()
    {
        if (head)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    Node* GetHead() { return head; }
    const Node* GetHead() const { return head; }

private:
    Node* head = nullptr;
};

int main()
{
    ForwardList<int> list;
    list.PopFront();
    list.PopFront();
    list.PopFront();
}