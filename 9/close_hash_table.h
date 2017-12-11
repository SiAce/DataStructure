#ifndef CLOSE_HASH_TABLE_H_
#define CLOSE_HASH_TABLE_H_

template <class Type>
class hashTable
{
public:
	virtual bool find(const Type &x) const = 0;
	virtual bool insert(const Type &x) = 0;
	virtual bool remove(const Type &x) = 0;

protected:
	int(*key)(const Type &x);
	static int defaultKey(const int &k) { return k; }
};

template <class Type>
class closeHashTable :public hashTable<Type>
{
private:
	struct node
	{
		Type data;
		int state;

		node() { state = 0; }
	};

	node * array;
	int size;

public:
	closeHashTable(int length =, int(*f)(const Type &x) = defaultKey);
	~closeHashTable() { delete[] array; }
	bool find(const Type &x) const;
	bool insert(const Type &x);
	bool remove(const Type &x);

	void rehash();
};

#endif // CLOSE_HASH_TABLE_H_
