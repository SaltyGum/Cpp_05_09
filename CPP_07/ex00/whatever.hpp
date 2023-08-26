#ifndef WHATEVER_
#define WHATEVER_

template <typename DataT>
void swap (DataT &a, DataT &b) {
	DataT c;
	c = a;
	a = b;
	b = c;
}

template <typename DataT>
DataT min (DataT a, DataT b){
	if(a < b)
		return a;
	return b;
}

template <typename DataT>
DataT max (DataT a, DataT b){
	if(a > b)
		return a;
	return b;
}

#endif