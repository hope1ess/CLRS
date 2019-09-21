/*
add in 2019/9/17 by yjy
*/
void insert_sort(int* a, int length);
void insert_sort_no_asc(int* a, int length);
void quick_sort(int* a, int left, int right);
int heap_parent(int i);
int heap_left(int i);
int heap_right(int i);
void max_heapify(int* a, int heapSize, int i);
void build_heap(int* a, int length);
void heap_sort(int* a, int length);
int memoized_cut_rod_aux(int* p, int n, int* r);
int memoized_cut_rod(int* p, int n);
int bottom_up_cut_rod(int* p, int n);

