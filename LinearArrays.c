/******** All sorts of functionalities in a linear, unordered array of integer type ********/
/*Author: Choudhury S. Mahmid (Sandy)
 * Date: 27 June, 2017
 * */


#include <stdio.h>

int linear_array[] = {5,21,16,2,9};   //linear, unordered array of type int

void traversal(int array_size);   //function to traverse through the array
int insertion(int item, int index, int array_size);   //function to insert an item in the array
int deletion(int index, int array_size);   //function to delete an item from the array
int searching(int item, int array_size);   //function to search for an item in the array
void update(int item, int index, int array_size);    //function to update a specific index in the array


int main() {

    int searching_item;   //int type variable for item to be searched in the array
    int searching_item_position;  //int type variable for position of the search item in the array
    int insertion_item;    //int type variable for item to be inserted in the array
    int updating_item;    //int type variable for item to be updated in the array
    int array_current_size = 5;    //current size of the array
    int array_insertion_index;    //index of the array where item will be inserted
    int array_deletion_index;    //index of the array where item will be deleted
    int array_update_index;    //index of the array where item will be updated
    int temp = array_current_size;  // a temporary variable for holding the current size of the array


    //view the current array
    traversal(temp);


    //inserting item
    //user will select an index in the array where they will insert the item
    printf("Enter item you want to insert: ");
    scanf("%d", &insertion_item);
    printf("Enter index where you want to insert item: ");
    scanf("%d", &array_insertion_index);
    if(array_insertion_index >=0 && array_insertion_index < 5){
        temp = insertion(insertion_item, array_insertion_index, temp);
        printf("New item %d added successfully to the array in index: %d.\n", insertion_item, array_insertion_index);
    }
    else{
        printf("Index is out of bounds of the array! Please try again. \n");
    }

    //view the current array
    traversal(temp);


    //deleting item
    //user will select an index in the array from where they will delete an item
    printf("Enter index from where you want to delete item: ");
    scanf("%d", &array_deletion_index);
    if(array_deletion_index >=0 && array_deletion_index < 5) {
        temp = deletion(array_deletion_index, temp);
        printf("Item deleted successfully from index: %d.\n", array_deletion_index);
    }
    else{
        printf("Index is out of bounds of the array! Please try again. \n");
    }

    //view the current array
    traversal(temp);


    //searching item
    //user will input a search item of their choice
    printf("Enter item you want to search: ");
    scanf("%d", &searching_item);
    searching_item_position = searching(searching_item, temp);
    if(searching_item_position == 0){
        printf("Item not found in array.\n");
    }
    else {
        printf("Item %d found at position: %d, index: %d.\n", searching_item, searching_item_position,
               searching_item_position - 1);
    }


    //updating item in an index
    //user will input an item of their choice for updating item
    //user will select an index in the array from where they will delete an item
    printf("Enter item for updating the array: ");
    scanf("%d", &updating_item);
    printf("Enter index where you want to update array: ");
    scanf("%d", &array_update_index);
    if(array_update_index >=0 && array_insertion_index < 5) {
        update(updating_item, array_update_index, temp);
        printf("Array updated successfully with item %d in index: %d.\n", updating_item, array_update_index);
    }
    else{
        printf("Index is out of bounds of the array! Please try again. \n");
    }

    //view the current array
    traversal(temp);

    return 0;

}


//the following function implements traversal
void traversal(int array_size){
    printf("Current array: ");
    for(int i = 0; i < array_size; i++){
        printf("%d ", linear_array[i]);
    }
    printf("\t");
    printf("Size: %d\n", array_size);
}


//the following function implements insertion
int insertion(int item, int index, int array_size){
    ++array_size;   //re-sizing the array to accommodate an extra item

    /*in the following loop, we shift the array elements one-by-one
     * to the right, starting from the index where we want to
     * insert our item*/
    for(int j = array_size; j >= index; j--){
        linear_array[j+1] = linear_array[j];
    }

    //now we insert the item
    linear_array[index] = item;

    return array_size;

}


//the following function implements deletion
int deletion(int index, int array_size){
   //re-sizing the array to accommodate an extra item

    /*in the following loop, we shift the array elements one-by-one
     * to the left, starting from the last index, to the
     * index where we want to remove our item*/
    for(int k = index; k <array_size; k++){
        linear_array[k] = linear_array[k+1];
    }

    array_size--;   //re-sizing the array

    return array_size;
}


//the following function implements searching
int searching(int item, int array_size){

    /*in the following loop, we search for a
     * particular item by traversing the
     * entire array and comparing the item
     * one-by-one with each element of the array*/
    for(int m = 0; m <array_size; m++) {
        if (linear_array[m] == item) {
            return m+1;
        }
    }
    return 0;
}

//the following function implements updating
void update(int item, int index, int array_size){
    for(int n = 0; n < array_size; n++){
        if(n == index){
            linear_array[n] = item;
            break;
        }
    }
}

