#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class LRUCache
{

private:
    template <typename K, typename V>
    struct Node
    {
        K key_;
        V val_;
        Node *next_;
        Node *pre_;
        Node(K key = K(), V val = V(), Node *pre = nullptr, Node *next = nullptr) : key_(key), val_(val), pre_(pre), next_(next_) {}
    };
    template <typename K, typename V>
    class List
    {
    public:
        List() : head_(new Node<K, V>()), size_(0)
        {
            tail_ = head_;
        }
        void push_back(Node<K, V> *p)
        {
            // Node *p = new Node(val);
            tail_->next_ = p;
            p->pre_ = tail_;
            tail_ = p;
            tail_->next_ = nullptr;
            ++size_;
        }
        void push_front(Node<K, V> *p)
        {
            p->next_ = head_->next_;
            p->pre_ = head_;
            head_->next_ = p;
            p->next_->pre_ = p;
            if (tail_ == head_)
            {
                tail_ = p;
            }
            ++size_;
        }
        Node<K, V> *front()
        {
            if (size_ == 0)
            {
                return nullptr;
            }
            return head_->next_;
        }
        Node<K, V> *back()
        {
            if (size_ == 0)
            {
                return nullptr;
            }
            return tail_;
        }
        void remove(Node<K, V> *p)
        {
            if (p == tail_)
            {
                tail_ = p->pre_;
                p->pre_->next_ = nullptr;
            }
            else
            {
                p->pre_->next_ = p->next_;
                p->next_->pre_ = p->pre_;
            }
            // delete p;
            // p = nullptr;
            --size_;
        }

        int size()
        {
            return size_;
        }
        void moveToTail(Node<K, V> *p)
        {
            if (p == tail_)
            {
                return;
            }
            else
            {
                p->pre_->next_ = p->next_;
                p->next_->pre_ = p->pre_;
                p->next_ = nullptr;
                p->pre_ = nullptr;
                // push_back(p);
                tail_->next_ = p;
                p->pre_ = tail_;
                tail_ = p;
            }
        }
        void pop_front()
        {
            // remove(head_->next_);
            if (size_ == 1)
            {
                tail_ = head_;
                head_->next_ = nullptr;
                --size_;
                return;
            }
            head_->next_ = head_->next_->next_;
            head_->next_->pre_ = head_;
            --size_;
        }
        void pop_back()
        {
            tail_ = tail_->pre_;
            tail_->next_ = nullptr;
            --size_;
        }

    private:
        Node<K, V> *head_;
        Node<K, V> *tail_;
        int size_;
    };

public:
    LRUCache(int capacity)
    {
        capacity_ = capacity;
        // size_ = 0;
    }

    int get(int key)
    {
        int ret = -1;
        if (map_.find(key) != map_.end())
        {
            Node<int, int> *p = map_[key];
            ret = map_[key]->val_;
            list_.moveToTail(p);
        }
        return ret;
    }

    void put(int key, int value)
    {

        if (map_.find(key) != map_.end())
        {
            Node<int, int> *p = map_[key];
            p->val_ = value;
            list_.moveToTail(p);
            return;
        }

        Node<int, int> *p = new Node<int, int>(key, value);
        map_.insert({key, p});
        if (list_.size() == capacity_)
        {
            Node<int, int> *tmp = list_.front();
            map_.erase(tmp->key_);
            list_.pop_front();
            list_.push_back(p);
        }
        else
        {
            list_.push_back(p);
        }
    }

private:
    // int size_;
    int capacity_;
    unordered_map<int, Node<int, int> *> map_;
    List<int, int> list_;
};

int main(int argc, char const *argv[])
{
    LRUCache cache = LRUCache(1);
    // cache.put(1, 0);
    // cache.put(2, 1);
    cout << cache.get(6);
    // cache.put(3, 2);
    cout << cache.get(8);
    cache.put(12, 1);
    cout << cache.get(2);
    cache.put(15, 11);
    cache.put(5, 2);
    cache.put(1, 15);
    cache.put(4, 2);
    cout << cache.get(5);
    cache.put(15, 15);
    // cout << cache.get(3);

    return 0;
}
