// I will try to do searching by myself and later name them appropritaily 

#include <iostream>
#include <vector>

#define SWAP(a,b) {int t = a; a=b; b=t;}

//template<typename T>
//std::ostream& operator<<(std::ostream& out, T v) {
//	for (auto i : v) {
//		std::cout << *i << " ";
//	}
//	std::cout << std::endl;
//	return out;
//}

// Print an array
template<typename T1, size_t arrSize,
	typename = std::enable_if_t<!std::is_same<T1, char>::value>>
std::ostream& operator <<(std::ostream& out, const T1(&arr)[arrSize])
{
	out << "[";
	if (arrSize)
	{
		const char* separator = "";
		for (const auto& element : arr)
		{
			out << separator;
			out << element;
			separator = ", ";
		}
	}
	out << "]";
	return out;
}
template <typename T>
void swap(T *i, T *j) {
	T tmp= *i;
	*i = *j;
	*j = tmp;
}

template <typename T, std::size_t N>
void sort1(T (&arr)[N]) {
	int itr = 0;
	int cmp = 0;
	bool flag = true;
	for (int i = 0; i < N - 1; i++) {
		itr++;
		for (int j = i+1; j <= N ; j++) {
			cmp++;

			if (arr[i] < arr[j]) {
				swap(&arr[i], &arr[j]);
			}
		}
	}
	std::cout << "Iterations = " << itr << "  Comparisions " << cmp << std::endl;
}

template <typename T, std::size_t N>
void sort2(T(&arr)[N]) {
	int itr = 0;
	int cmp = 0;
	bool flag = true;
	for (int i = 0; i < N-1 && flag; i++) {
		itr++;
		flag = false;
		for (int j = 0; j < N-1; j++) {
			cmp++;
			if (arr[j] > arr[j+1]) {
				flag = true;
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
	std::cout << "Iterations = " << itr << "  Comparisions " << cmp << std::endl;
}

template <typename T, size_t N>
void sort3(T (&arr)[N]) {
	int itr = 0;
	int cmp = 0;
	for (int i = 1; i < N; i++) {
		itr++;
		int j = i - 1;
		int key = arr[i];
		while (j >= 0 && arr[j] > key) {
			cmp++;
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
	std::cout << "Iterations = " << itr << "  Comparisions " << cmp << std::endl;
}

int main()
{
	int v[] = { 6, 5, 3 , 1, 8, 7, 2, 4 };
	std::cout << v << std::endl;
	sort3(v);
	std::cout << v << std::endl;
	return 0;
}