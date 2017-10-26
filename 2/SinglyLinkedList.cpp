using namespace std;

template <class elemType>
class SinglyLinkedList
{
private:
	struct Node {
	};

public:
	int FindLastNumber(int k, SinglyLinkedList<int> sll, Node *list) {

		Node *p1, *p2 = list;

		for (int i = 0; i < k; i++) {
			if (p1->next) {
				p1 = p1->next;
			}
			else {
				return 0;
			}
		}

		while (p1) {
			p1 = p1->next;
			p2 = p2->next;
		}

		cout << p1->data << endl;
		return 1;
	}
};
