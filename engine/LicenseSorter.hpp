#ifndef LICENSESORTER_HPP
#define LICENSESORTER_HPP

// get  N most recent or oldest drivers
template <typename Driver>
class LicenseSorter{
private:
    void merge(Driver** arr, int left, int mid, int right, bool newerFirst){
        int leftSize=mid-left+1;
        int rightSize=right-mid;

        Driver** L=new Driver*[leftSize];
        Driver** R=new Driver*[rightSize];

        for(int i=0;i<leftSize;i++){
            L[i]=arr[left+i];
        }
        for(int j=0;j<rightSize;j++){
            R[j]=arr[mid+1+j];
        }

        int i=0,j=0,k=left;
        while(i<leftSize&&j<rightSize){
            Date dL=L[i]->getLicenseDate();
            Date dR=R[j]->getLicenseDate();

            bool pickLeft;
            if(newerFirst){
                //newest to oldest
                pickLeft=(dL>dR)||(dL==dR);
            }
            else{
                // oldest to newest
                pickLeft=(dL<dR)||(dL==dR);
            }
            if(pickLeft){
                arr[k++]=L[i++];
            }
            else{
                arr[k++]=R[j++];
            }
        }
        while(i<leftSize){
            arr[k++]=L[i++];
        }
        while(j<rightSize){
            arr[k++]=R[j++];
        }

        delete[] L;
        delete[] R;
    }

    void mergeSort(Driver** arr, int left, int right, bool newerFirst){
        if (left>=right){
            return;
        }
        int mid=left+(right-left)/2;
        mergeSort(arr, left, mid, newerFirst);
        mergeSort(arr, mid+1, right, newerFirst);
        merge(arr, left, mid, right, newerFirst);
    }

public:
    // sort in place from newest to oldest
    void sortNewest(Driver** arr, int n){
        if(n<=1){
            return;
        }
        mergeSort(arr, 0, n-1, true);
    }

    // sort in place from oldest to newest
    void sortOldest(Driver** arr, int n){
        if(n<=1){
            return;
        }
        mergeSort(arr, 0, n-1, false);
    }

    Driver** topN(Driver** arr, int total, int n, bool newerFirst){
        Driver** copy=new Driver*[total];
        for(int i=0;i<total;i++){
            copy[i]=arr[i];
        }

        if(newerFirst){
            sortNewest(copy, total);
        }
        else{
            sortOldest(copy, total);
        }

        if(n>total){
            n=total;
        }

        Driver** result=new Driver*[n];
        for(int i=0;i<n;i++){
            result[i]=copy[i];
        }

        delete[] copy;
        return result;
    }
};

#endif
