# uas

void MyList::hapusBelakang()
{
    if (isEmpty())
    {
        cout << "List kosong" << endl;
    }
    else if (head->next == NULL)
    {
        delete head;
        head = NULL;
    }
    else
    {
        Node *bantu = head;
        while (bantu->next->next != NULL)
        {
            bantu = bantu->next;
        }
        delete bantu->next;
        bantu->next = NULL;
    }
}
