#pragma once
typedef unsigned int uint;

template<typename T>
void Merge(T * arr, uint p, uint q, uint r)
{
	uint leftEnd = q - p + 1;
	uint rightEnd = r - q;

	T * L = new T[leftEnd];
	T * R = new T[rightEnd];

	for (int i = 0; i < leftEnd; i++)
		L[i] = arr[p + i];
	for (int j = 0; j < rightEnd; j++)
		R[j] = arr[q + j + 1];

	uint i = 0;
	uint j = 0;

	for (int k = p; k <= r; k++)
	{
		if ((j >= rightEnd) || (i < leftEnd && L[i] <= R[j]))
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
	}
}

template<typename T>
void MergeSort(T * arr, uint p, uint r)
{
	if (p < r)
	{
		uint q = (p + r) / 2;
		MergeSort(arr, p, q);
		MergeSort(arr, q + 1, r);
		Merge(arr, p, q, r);
	}
}

template<typename T>
void Merge(vector<T> * arr, uint p, uint q, uint r)
{
	uint leftEnd = q - p + 1;
	uint rightEnd = r - q;

	vector<T> L;
	L.reserve(leftEnd);
	vector<T> R;
	R.reserve(rightEnd);

	for (int i = 0; i < leftEnd; i++)
		L.push_back(arr->at(p + i));
	//L->at(i) = arr[p + i];

	for (int j = 0; j < rightEnd; j++)
		R.push_back(arr->at(q + j + 1));
	//R->at(j) = arr[q + j + 1];

	uint i = 0;
	uint j = 0;

	for (int k = p; k <= r; k++)
	{
		if ((j >= rightEnd) || (i < leftEnd && L[i] <= R[j]))
		{
			arr->at(k) = L[i];
			i++;
		}
		else
		{
			arr->at(k) = R[j];
			j++;
		}
	}
};

template<typename T>
void MergeSort(vector<T> * arr, uint p, uint r)
{
	if (p < r)
	{
		uint q = (p + r) / 2;
		MergeSort(arr, p, q);
		MergeSort(arr, q + 1, r);
		Merge(arr, p, q, r);
	}
};