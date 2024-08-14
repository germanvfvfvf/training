#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();

	void push_front(T data);

	void push_back(T data);

	void insert(T data, int index);

	void removeAt(int index);

	void pop_front();

	void pop_back();

	void clear();

	void revers();

	int GetSise() { return Sise; }

	T& operator[](const int index);


private:

	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		Node* pPrev;
		T data;

		Node(T data=T(), Node* pNext = nullptr, Node* pPrev = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}

		~Node() {

		}
	};

	Node<T>* head_or_tail(int index)        
	{
		Node<T>* current = this->head;

		if (index == 0)
		{
			return current;
		}

		if (index <= (Sise) / 2 -1) 
		{
			for (int i = 0; i < index; i++)
			{
				current = current->pNext;
			}
			return current;
		}
		else
		{
			current = this->tail;

			for (int i = 0; i < Sise - index - 1; i++)
			{
				current = current->pPrev;
			}
			return current;
		}
	}

	int Sise;
	Node<T>* head;
	Node<T>* tail;
};

template<typename T>
List<T>::List()
{
	Sise = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_front(T data)
{
	Node<T>* current = head;

	head = new Node<T>(data, head);

	Sise++;

	if (Sise == 1)
	{
		tail = head;
	}
	else
	{
		current->pPrev = head;
	}
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);

		tail = head;

	}
	else
	{

		tail->pNext = new Node<T>(data, nullptr, tail);

		tail = tail->pNext;
	}

	Sise++;
}

template<typename T>
void List<T>::pop_front()
{

	Node<T>* temp = head;

	head = head->pNext;

	delete temp;

	Sise--;

}

template<typename T>       
void List<T>::pop_back()
{
	Node<T>* current = tail;

	tail = tail->pPrev;

	delete current;

	Sise--;
}

template<typename T>
void List<T>::clear()
{
	while (Sise)
	{
		pop_front();
	}
}

template<typename T>
void List<T>::insert(T data, int index)
{
	
	if (index == 0)
	{
		push_front(data);
	}
	if (index > Sise )
	{
		push_back(data);
	}
	else
	{
		Node<T>* current = head_or_tail(index);

		Node<T>* temp = current;

		
		
		temp = temp->pPrev;

		current->pPrev = new Node<T>(data, current, current->pPrev);

		temp->pNext = current->pPrev;

		Sise++;
	}
}

template<typename T>              
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else if (index >= Sise - 1)
	{
		pop_back();
	}

	else
	{
		Node<T>* current = head_or_tail(index);

		Node<T>* temp = current->pPrev;

		Node<T>* temp2 = current->pNext;

		temp->pNext = current->pNext;

		temp2->pPrev = temp;

		delete current;

		Sise--;
	}
}

template<typename T>
T& List<T>::operator[](int index)
{
	Node <T>* current = head_or_tail(index);

	return current->data;
}

template<typename T>
void List<T>::revers()
 {
	Node<T>* current = head;
	Node<T>* curPrev = nullptr;

	if (head == nullptr){}

	else
	{

		tail = current;

		while (current != nullptr)
		{
			auto temp = current->pNext;

			current->pNext = curPrev;

			curPrev = current;

			curPrev->pPrev = temp;

			current = temp;
		}

		head = curPrev;
	}
}


void rd_space(char *&s) //////////////
{
	int length = strlen(s) + 1;
	


	char* temp = new char[length];
	int j = 0;

	int new_length = length - 1;

	for (int i = 0; i < length ; i++)
	{
		if (temp[j] == ' ' && s[i] == ' ')
		{
			new_length--;
			i++;
		}
		else
		{
			temp[j++] = s[i];
		}
	}

	temp[new_length] = '\0';

	delete[] s;

	s = temp;
}

void TrimRight(char *&s)
{
	int length = strlen(s);

	while (s[length-1] == ' ')
	{
		length--;
	}

	char* temp = new char[length+1];

	for (int i = 0; i < length; i++)
	{
		temp[i] = s[i];
	}

	temp[length] = '\0';

	delete[] s;

	s = temp;
}

void Trim_right(char* s)
{
	int length = strlen(s);

	while (s[length-1] == ' ')
	{
		length--;
	}

	s[length] = '\0';
}

void print(char *s)
{
	int length = strlen(s);

	for (int i = 0; i < length; i++)
	{
		cout << s[i];
	}
}

void Array(int *&arr,int &it)
{
	it++;
	int* buff = new int[it];

	for (int i = 0; i < it; i++)
	{
		buff[i] = rand() % 10 +2;
	}

	delete[] arr;

	arr = new int[it];

	arr = buff;





}



template<typename T>
class circle_list
{
public:

	circle_list()
	{
		sise = 0;
		head = nullptr;
		tail = head;
	}

	void push_front(T data)
	{
		if (head == nullptr)
		{
			head = new Node<T>(data);
			tail = head;
			current_obj = head;
			sise++;
		}
		else
		{
			Node<T>* current = tail;
			current -> pNext = new Node<T>(data);
			tail = current -> pNext;
			sise++;
			tail->pNext = head;
		}
		current_obj = tail;

	}
	void pop_current()
	{
		if (sise != 0)
		{
			Node<T>* temp = current_obj;
			pointer_next();

			while (current_obj->pNext != temp)
			{
				pointer_next();
			}

			current_obj->pNext = temp->pNext;


			cout << "udalilsya ------" << temp->data << endl;

			sise--;
			delete temp;
		}
		else
		{
			current_obj->data = 0;
		}
	}

	void pointer_next() {current_obj = current_obj->pNext;}

	T& get_current_obj() 
	{ 
		return current_obj->data;
	}

	int get_sise() { return sise; }

	bool empty() {
		if (sise != 0)
		{
			return false;
		}
		return true;
	}

private:

	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	Node<T>* head;
	Node<T>* tail;
	Node<T>* current_obj = head;
	int sise;
};


class Solution {
public:
	vector<int> sum;

	vector<int> twoSum(vector<int>& nums, int target) {

		sum.clear();

		if (nums.size() > 1)
		{
			sum.reserve(2);
			sum.push_back(0);
			int it = 0;

			while (nums.size() > it )
			{
				sum[0] = it;

				for (int i = it + 1; i < nums.size(); i++)
				{
					if (nums[sum[0]] + nums[i] == target)
					{
						sum.push_back(i);
						return sum;
					}
				}
				it++;
			}
			sum.clear();
			return sum;
		}
		else
		{
			return sum;
		}
	}
};

 // Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
 
class Solution2
{
public:


	void reverse(ListNode *&list)
	{
		ListNode* pref = nullptr;
		int it = 0;

		while (list != nullptr)
		{
			auto temp = list;
			list = list->next;
			temp->next = pref;
			pref = temp;
			it++;
		}

		int number = 0;

		while (pref != nullptr)
		{
			number += pow(10, it -1) * pref->val;
			pref = pref->next;
			it--;
		}
		cout << number << endl;
	}

	void coutLTS(ListNode* list)
	{
		while (list != nullptr)
		{
			cout << list->val << endl;
			list = list->next;

		}
	}


	unsigned int combine(ListNode* list)
	{
		unsigned int number = 0;
		unsigned int a = 1;

		while (list != nullptr)
		{
			number += a * list->val;
			list = list->next;
			a *= 10;
		}
		return number;
	}

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		unsigned int a = combine(l1) + combine(l2);
		int b = a % 10;
		a /= 10;

		ListNode* current = new ListNode(b);
		ListNode* head = current;

		while (a > 0)
		{
			b = a % 10;
			current->next = new ListNode(b);
			current = current->next;
			a /= 10;
		}
		return head;
	}

	///////////////////

	ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {

		int a = 0;
		int b = l1->val + l2->val;
		ListNode* current = new ListNode(b %10);
		ListNode* head = current;

		if (l1->val + l2->val > 9) { a++; }

		l1 = l1->next;
		l2 = l2->next;
		/////////////////////////////////////
		/*ListNode head(0);
		ListNode* current = &head;
		int a = 0;*/

		while (l1 != nullptr || l2 != nullptr)
		{
			b = 0;

			if (l1 != nullptr) { 
				b += l1->val;
				l1 = l1->next;
			}
			if (l2 != nullptr) { 
				b += l2->val; 
				l2 = l2->next;
			}
			b += a;

			if (b > 9)
			{
				b %= 10;

				if (a == 0)	{ a = 1; }
				else{ a = 1; }
			}
			else
			{
				a = 0;
			}
			current->next = new ListNode(b);
			current = current->next;
		}
		if (a == 1)
		{
			current->next = new ListNode(1);
		}
		return head;
	}

	


};

class Solution3
{
public:

	int lengthOfLongestSubstring(string s) {

		int max = 0;
		string str;
		str.reserve(s.size());


		for (int i = 0; i < s.size(); i++)
		{
			bool dublicate = false;

			int j = 0;
			for ( ; j < str.size(); j++)
			{
				if (s[i] == str[j])
				{
					dublicate = true;
					break;
				}
			}
			if (!dublicate)
			{
				str.push_back(s[i]);
			}
			if (str.size() > max)
			{
				max = str.size();
			}
			else
			{
				if (str.size()> max)
				{
					max = str.size();
				}
				str.erase(str.begin(), str.begin() + j+1);
				str.push_back(s[i]);
			}
		}
		if (str.size() > max)
		{
			max = str.size();
		}

		return max;
	}
};


ListNode* reverse(ListNode *qwerty)
{
	ListNode* current = qwerty;
	ListNode* pref = nullptr;

	if (qwerty->next == nullptr)
	{
		return qwerty;
	}

	while (current!= nullptr)
	{
		auto* temp = current;
		current = current->next;
		temp->next = pref;
		pref = temp;
	}

	return pref;
}


class Solution4
{
public:

	double findMedianSortedArrays8(vector<int>& nums1, vector<int>& nums2)
	{
		bool even;
		if ((nums1.size() + nums2.size()) % 2 == 0)
		{
			even = true;
		}
		else
		{
			even = false;
		}

		int size = (nums1.size() + nums2.size()) / 2;
		double median = 0;

		vector<int>::iterator it1 = nums1.begin();
		vector<int>::iterator it2 = nums2.begin();

		int it = 0;

		while (it != size )
		{
			if (it1 == nums1.end() || it2 == nums2.end()) 
			{
				break;
			}
			if (*it1 <= *it2)
			{
				median = *it1;
				it1++;
			}
			else
			{
				median = *it2;
				it2++;
			}
			it++;
		}

		if (it1 == nums1.end() || it2 == nums2.end())
		{
			vector<int>::iterator temp;

			if (it1 == nums1.end())
			{
				temp = it2;
				
			}
			else
			{
				temp = it1;
			}

			if (size - it > 0)
			{
				temp += size - it - 1;

				if (even)
				{
					median = *temp;
					temp++;
					median += *temp;
					return median / 2;
				}
				else
				{
					temp++;
					median = *temp;
					return median;
				}
			}
			else
			{
				if (even)
				{
					median += *temp;
					return median / 2;
				}
				else
				{
					median = *temp;
					return median;
				}
			}
		}
		if (even)
		{
			if (*it1 <= *it2)
			{
				median += *it1;
				return median / 2;
			}
			else
			{
				median += *it2;
				return median / 2;
			}
		}
		else
		{
			if (*it1 <= *it2)
			{
				median = *it1;
				return median;
			}
			else
			{
				median = *it2;
				return median;
			}
		}
	}


	void func(vector<int> & nums, vector<int>::iterator &iter, int size, int &it, double &median)
	{
		if (size - it < 1)
		{
			iter += size - it;
		}
		else
		{
			iter += size - it - 1;
		}
	}

	

	double findMedianSortedArrays9(vector<int>& nums1, vector<int>& nums2)
	{
		int numsize1 = nums1.size();
		int numsize2 = nums2.size();
		int size = (numsize1 + numsize2) / 2 + 1;
		int it = 0;
		int it1 = 0;
		int it2 = 0;

		vector<int> nums(size);
		
		while (it1 < numsize1 && it2 < numsize2 && it < size)
		{
			if (nums1[it1] < nums2[it2])
			{
				nums[it++] = nums1[it1++];
			}
			else
			{
				nums[it++] = nums2[it2++];
			}
		}

		while (it1 < numsize1 && it < size)
		{
			nums[it++] = nums1[it1++];
		}

		while (it2 < numsize2 && it < size)
		{
			nums[it++] = nums2[it2++];
		}

		/*if (it1 == numsize1)
		{
			it2 += size - it - 1;
			nums[it-2] = nums2[it2++];
			nums[it -1] = nums2[it2++];
		}
		else if (it2 == numsize2)
		{
			it1 += size - it;
			nums[it ++] = nums1[it1++];
			nums[it ] = nums1[it1];
		}*/

		if ((numsize1 + numsize2) % 2 == 0)
		{
			double median;
			median = nums[it-1] + nums[it - 2];
			return median / 2;
		}
		else
		{
			return nums[it];
		}
	}





};






int main()
{


	/*vector<int> x{ 1,3 };
	vector<int> y{ 2,7 };*/

	vector<int> y{ };
	vector<int> x{ 2, 3};


	Solution4 sol;

	//sol.findMedianSortedArrays(x, y);

	//cout << sol.findMedianSortedArrays9(x, y) << endl;



	char inf[]{ "sfdsf"};

	//////////
	/*int a = 5;
	cout << a % 2 << endl;*/





	//////////////////////////////////////////// sol3
	/*string s{" "};

	Solution3 s2;

	cout << s2.lengthOfLongestSubstring(s) << endl;*/




	ListNode lst(3);
	ListNode lst2(2, &lst);
	ListNode lst3(1, &lst2);

	ListNode* ls = &lst3;

	for (int i = 0; i < 3; i++)
	{
		cout << i +1<< " = " << ls->val << endl;
		ls = ls->next;
	}

	ls = reverse(&lst3);


	ls;

	for (int i = 0; i < 3; i++)
	{
		cout << i+1 << " = " << ls->val << endl;
		ls = ls->next;
	}


	//////////////////////////////////
	//List<int>lst;
	//lst.push_back(00);
	//lst.push_back(11);
	//lst.push_back(22);
	//lst.push_back(33);
	//lst.push_back(44);
	//lst.push_back(55);
	//lst.push_back(66);
	//lst.push_back(77);
	//lst.push_back(88);
	//lst.push_back(99);
	//lst.push_back(100);


	//for (int i = 0; i < lst.GetSise(); i++)
	//{
	//	cout << i << " - " << lst[i] << endl;
	//}

	//lst.insert(1020, 12);
	//

	//for (int i = 0; i < lst.GetSise(); i++)
	//{
	//	cout << i << " - " << lst[i] << endl;
	//}


	//cout << "===================================" << endl;


	//lst.revers();

	//cout << "===================================" << endl;

	//for (int i = 0; i < lst.GetSise(); i++)
	//{
	//	cout << i << " - " << lst[i] << endl;
	//}

	//lst.revers();

	//cout << "===================================" << endl;

	//for (int i = 0; i < lst.GetSise(); i++)
	//{
	//	cout << i << " - " << lst[i] << endl;
	//}


	///*setlocale(LC_ALL, "ru");

	//string str = "Текст с несколькими  пробелами";

	//cout << str << endl;

	//*/

	//
	////char* str_ = new char [11] { "Лес  " };

	////print(str_);
	//////TrimRight(str_);
	//////Trim_right(str_);

	////print(str_);
	////print(str_);

	////cout << endl << "=======================" << endl;

	////rd_space(str_);

	////print(str_);
	////print(str_);
	////print(str_);
	////
	//////int sise = 5;
	//////int* arr = new int [sise] {1, 2, 4, 5, 7};

	//////Array(arr,sise);
	//////
	//////cout << endl;
	//////
	//////for (int i = 0; i < sise; i++)
	//////{
	//////	cout << i << "  " << *(arr + i) << endl;
	//////}

	//////cout << str_ << endl;

	//int v[] = {1,2,6,4,2};

	//sort(begin(v), end(v));

	////vector<string, int> vec;

	
	//////////////////////////////////////////////

	/*circle_list<int> crlst;

	
	crlst.push_front(4);
	crlst.push_front(11);
	crlst.push_front(15);
	crlst.push_front(17);
	crlst.push_front(22);



	for (int i = 0; i < 20; i++)
	{
		cout << crlst.get_current_obj() << " == " << i << endl;
		crlst.pointer_next();
	}

	cout << "--------------" << endl;

	crlst.pop_current();
	crlst.pop_current();
	crlst.pop_current();
	crlst.pop_current();
	crlst.pop_current();

	for (int i = 0; i < 20; i++)
	{
		cout << crlst.get_current_obj() << " == " << i << endl;
		crlst.pointer_next();
	}*/

///////////////////////////////////////////////////////////////////




	


	return 0;
}


