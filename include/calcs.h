#ifndef CALCS_H
#define CALCS_H

#include <stdint.h>

#include "pitching_game.h"

// --------------- BASIC VECTOR FUNCTIONS
float calc_vector_x_comp(struct vector *vector);
float calc_vector_y_comp(struct vector *vector);
float calc_vector_length(struct vector *vector);
float calc_vector_rad(struct vector *vector);
float calc_rad_between_vectors(struct vector *vector1, struct vector *vector2);
float calc_vector_dot_product(struct vector *vector1, struct vector *vector2);
float calc_vector_dx(float length, float rad);
float calc_vector_dy(float length, float rad);

// --------------- MAIN() HELPER FUNCTIONS
void rotate_vector(struct vector *vector, float angle, int dirx, int diry);
void order_length_data(float *list, int *order_list, int size);
#endif //CALCS_H
