#pragma once
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>


struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};

TEST_CASE("List", "[list]")
{
    List l;
    SECTION("Check Empty list")
    {
        CHECK(l.Empty() == true);
    }
    SECTION("Check size list")
    {
        l.PushBack(23);
        l.PushBack(43);
        CHECK(l.Size() == 2);
    }
    SECTION("Clear Check")
    {
        for (int i = 0; i < 100; i++) {
            l.PushBack(i);
        }
        l.Clear();
        CHECK(l.Empty() == true);
    }
    SECTION("Check PushBack")
    {
        for (int i = 0; i < 4; i++) {
            l.PushBack(i);
            CHECK(l.Size() == i + 1);
        }
    }
    SECTION("Check PopBack or Popfron")
    {
        l.PushBack(20);
        l.PushBack(320);
        l.PushBack(88888);
        CHECK(l.PopBack() == 88888);
        CHECK(l.PopFront() == 20);
    }
    SECTION("Check popback or profront for empty list")
    {
        try
        {
            l.PopFront();
            l.PopBack();
        }
        catch (std::runtime_error& e)
        {
            CHECK(true);
        }
    }
}

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}