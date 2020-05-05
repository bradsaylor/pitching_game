#include <stdio.h>
#include <math.h>

#include "calcs.h"

// ---------------- BASIC VECTOR FUNCTIONS

float calc_vector_x_comp(struct vector *vector) {
    float x_comp = (float)((float)vector->P2.x - (float)vector->P1.x);
    return x_comp;
}

float calc_vector_y_comp(struct vector *vector) {
    float y_comp = (float)((float)vector->P2.y - (float)vector->P1.y);
    return y_comp;
}

float calc_vector_dot_product(struct vector *vector1, struct vector *vector2) {
    float DP = 0;
    DP = (calc_vector_x_comp(vector1) * calc_vector_x_comp(vector2)) +
         (calc_vector_y_comp(vector1) * calc_vector_y_comp(vector2));

    return DP;
}

float calc_vector_length(struct vector *vector) {
    float length = 0;

    length = sqrt( pow(calc_vector_x_comp(vector), 2) + pow(calc_vector_y_comp(vector), 2) );
    return length;
}

float calc_vector_rad(struct vector *vector) {
    float rad = 0;
    rad = atan((calc_vector_y_comp(vector)) / (calc_vector_x_comp(vector)));
    return rad;
}

float calc_rad_between_vectors(struct vector *vector1, struct vector *vector2) {
    float rad_between = 0;
    rad_between = calc_vector_rad(vector2) - calc_vector_rad(vector1);
    return rad_between;
}

float calc_vector_dx(float length, float rad) {
    float dx = 0;
    dx = length / sqrt(1 + pow(tan(rad),2));    
    return dx;
}

float calc_vector_dy(float length, float rad) {
    float dy = 0;
    dy = length / sqrt(1 + pow(tan(rad),-2));    
    return dy;
}



// ---------------- MAIN() HELPER FUNCTIONS

void find_smallest_length(int *length_data, int *smallest, int size) {
    int loop_flag = 0;
    
    for(int count = 0; count < size; count++) {
	loop_flag = 0;
	for(int count2 = 0; count2 < size; count2++) {
	    if(count2 != count) {
		if (length_data[count] <= length_data[count2]) {
		    loop_flag += 1;
		    if (loop_flag == (size - 1)) {
			*smallest = count;
			count2 = size;
			count = size;
		    }
		}
	    }
	}
    }
}

void rotate_vector(struct vector *vector, float angle, int dirx, int diry) {
    struct vector temp_vector = *vector;
    vector->P2.x = vector->P1.x + (dirx) * calc_vector_dx(calc_vector_length(&temp_vector), angle);
    vector->P2.y = vector->P1.y + (diry) * calc_vector_dy(calc_vector_length(&temp_vector), angle);
}

void order_length_data(float *list, int *order_list, int size, int index_of_smallest_length) {
    int num_smaller = 0;
    float list_minus_smallest[size - 1];

    int index = 0;
    for(int count = 0; count < size; count++) {
	if(count != index_of_smallest_length) {
	    list_minus_smallest[index] = list[count];
	    index++;
	}
    }

    for(int count = 0; count < (size - 1); count++) {
	num_smaller = 0;
	for(int count2 = 0; count2 < size; count2++) {
	    if(list_minus_smallest[count2] >= list_minus_smallest[count]) num_smaller++;
	}
	order_list[count] = (size) - num_smaller;
    }
}
